// Copyright Epic Games, Inc. All Rights Reserved.

#include "Hack_n_Slash_ProjectPlayerController.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Runtime/Engine/Classes/Components/DecalComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Hack_n_Slash_ProjectCharacter.h"
#include "Engine/World.h"
#include "Hack_n_Slash_ProjectCharacter.h"
#include "AI_BaseCharacterCpp.h"
#include "Kismet/KismetMathLibrary.h"
#include "highlightable.h"
#include "BaseActorObject.h"
#include "BagComponent.h"
AHack_n_Slash_ProjectPlayerController::AHack_n_Slash_ProjectPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
}
void AHack_n_Slash_ProjectPlayerController::BeginPlay()
{
	Super::BeginPlay();
	CharacterRef = Cast<AHack_n_Slash_ProjectCharacter>(GetPawn());

}
void AHack_n_Slash_ProjectPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	if (!IsOnUIblockRay)
	{
		GetHitResultUnderCursor(ECC_Camera, false, Hit);

		if (CharacterRef != nullptr)
		{
			FVector temp = Hit.ImpactPoint;
			temp.Z = CharacterRef->GetActorLocation().Z;
			CharacterRef->LastMousePos = temp;
		}
		Ihighlightable* castHigh = Cast<Ihighlightable>(Hit.Actor);


		if (Cast<AAI_BaseCharacterCpp>(Hit.Actor))
		{
			Target = Cast<AActor>(Hit.Actor);
			HasTarget = true;
		}
		else
			HasTarget = false;

		if (castHigh != nullptr)
		{
			IsHighLightSomthing = true;
		}
		else
		{
			IsHighLightSomthing = false;
		}



		if (!IsAlreadyHighLight && IsHighLightSomthing && castHigh != nullptr)
		{
			TargetHighlight = castHigh;
			TargetHighlight->Execute_SeeHighlight(Cast<UObject>(TargetHighlight));
			
			IsAlreadyHighLight = true;
		}
		else if (IsAlreadyHighLight && castHigh != nullptr && TargetHighlight != nullptr && castHigh != TargetHighlight)
		{

			TargetHighlight->Execute_UnSeeHighlight(Cast<UObject>(TargetHighlight));
			castHigh->Execute_SeeHighlight(Cast<UObject>(castHigh));
			
			TargetHighlight = castHigh;
		}
		else if (IsAlreadyHighLight && castHigh == nullptr && TargetHighlight != nullptr)
		{
			TargetHighlight->Execute_UnSeeHighlight(Cast<UObject>(TargetHighlight));
			TargetHighlight = nullptr;
			IsAlreadyHighLight = false;
		}




		// keep updating the destination every tick while desired
		if (bMoveToMouseCursor)
		{
			MoveToMouseCursor();
		}
		else if (MoveToTarget)
		{
			if (!CharacterRef->CloseEnoughTarget())//if target isn t near of character
				SetNewMoveDestination(Target->GetActorLocation());
			else//if target is close enough then ask action
			{

				//TO DO inside 
				//if target is not enemy do other action 
				MoveToTarget = false;

				FRotator Rot = UKismetMathLibrary::FindLookAtRotation(CharacterRef->GetActorLocation(), Target->GetActorLocation());

				FVector newVec = Rot.Vector();
				newVec.X = 0;
				newVec.Z = 0;
				FRotator newrot = FRotator::MakeFromEuler(newVec);
				CharacterRef->SetActorRotation(Rot);

				if (IsRightClick)
				AskRequestForSkillClickRight();
				else
				AskRequestForSkillClickLeft();




			}

		}
	}

}

void AHack_n_Slash_ProjectPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	//BIND CLICK LEFT AND RIGHT
	InputComponent->BindAction("LeftMouse", IE_Pressed, this, &AHack_n_Slash_ProjectPlayerController::DoRayCastToLeftClic);
	InputComponent->BindAction("LeftMouse", IE_Released, this, &AHack_n_Slash_ProjectPlayerController::OnSetDestinationReleased);
	InputComponent->BindAction("RightMouse", IE_Pressed, this, &AHack_n_Slash_ProjectPlayerController::DoRayCastToRightClic);
	InputComponent->BindAction("RightMouse", IE_Released, this, &AHack_n_Slash_ProjectPlayerController::OnSetDestinationReleased);
	//BIND ACTION SKILL
	InputComponent->BindAction("Skill1", IE_Pressed, this, &AHack_n_Slash_ProjectPlayerController::AskRequestForSkill1);
	InputComponent->BindAction("Skill2", IE_Pressed, this, &AHack_n_Slash_ProjectPlayerController::AskRequestForSkill2);
	InputComponent->BindAction("Skill3", IE_Pressed, this, &AHack_n_Slash_ProjectPlayerController::AskRequestForSkill3);

	//OtherBind
	InputComponent->BindAction("Inventory", IE_Pressed, this, &AHack_n_Slash_ProjectPlayerController::SetInventoryVisibility);




	InputComponent->BindAction("ResetVR", IE_Pressed, this, &AHack_n_Slash_ProjectPlayerController::OnResetVR);
}

void AHack_n_Slash_ProjectPlayerController::OnResetVR()
{
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

//Update no Target Bool data to move on specific location 
void AHack_n_Slash_ProjectPlayerController::MoveToMouseCursor()
{
	// Trace to see what is under the mouse cursor

	if (Hit.bBlockingHit)
	{
		SetNewMoveDestination(Hit.ImpactPoint);
		HasTarget = false;
		MoveToTarget = false;
		Target = nullptr;
	}
}

void AHack_n_Slash_ProjectPlayerController::SetNewMoveDestination(const FVector DestLocation)
{
	APawn* const MyPawn = GetPawn();
	if (MyPawn)
	{
		float const Distance = FVector::Dist(DestLocation, MyPawn->GetActorLocation());
		// We need to issue move command only if far enough in order for walk animation to play correctly
		if ((Distance > 120.0f))
		{
			UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, DestLocation);
		}
	}
}

void AHack_n_Slash_ProjectPlayerController::OnSetDestinationPressed()
{
	// set flag to keep updating destination until released
	bMoveToMouseCursor = true;
}

void AHack_n_Slash_ProjectPlayerController::OnSetDestinationReleased()
{
	// clear flag to indicate we should stop updating the destination
	bMoveToMouseCursor = false;
}

void AHack_n_Slash_ProjectPlayerController::DoRayCastToRightClic()
{
	IsRightClick = true;
	SetTarget(1);//Send Right 
}

void AHack_n_Slash_ProjectPlayerController::DoRayCastToLeftClic()
{
	IsRightClick = false;

	SetTarget(2);//Send Left 
}

void AHack_n_Slash_ProjectPlayerController::SetTarget(AActor* _Target)
{
	if (!IsOnUIblockRay)
	{
		Target = _Target;
		CharacterRef->Target = _Target;
	}
}

void AHack_n_Slash_ProjectPlayerController::SetTarget(int32 _LR)
{


	//Set Target if She as a Tag
	//Set Bool To Do A Specific Action
	if (!IsOnUIblockRay)
	{
		ABaseActorObject* Object = Cast<ABaseActorObject>(Hit.Actor);


		if (Hit.GetActor()->Tags.Num() > 0)//if as target update data Target and bool condition
		{
			SetTarget(Hit.GetActor());
			HasTarget = true;
			MoveToTarget = true;
		}
		else if (TargetHighlight != nullptr && Object != nullptr)
		{

			AHack_n_Slash_ProjectCharacter* PCH = Cast<AHack_n_Slash_ProjectCharacter>(GetPawn());
			if (PCH->BagRef->GetBagfreeAsSpace())
			{
				OnCallCatchLoot.Broadcast(Object->StatObject);
				GetWorld()->DestroyActor(Object);
			}

		}
		else
		{
			OnSetDestinationPressed();// if not tag on target just move to location
		}
	}
}

void AHack_n_Slash_ProjectPlayerController::AskRequestForSkillClickRight()
{

	if (!IsOnUIblockRay)
	OnCallSkillDeleguate.Broadcast(2);//broadcast to character for skill 1 activation
}

void AHack_n_Slash_ProjectPlayerController::AskRequestForSkillClickLeft()
{

	if (!IsOnUIblockRay)
	OnCallSkillDeleguate.Broadcast(1);//broadcast to character for skill 2 activation
}

void AHack_n_Slash_ProjectPlayerController::AskRequestForSkill1()
{

	if (!IsOnUIblockRay)
	OnCallSkillDeleguate.Broadcast(3);//broadcast to character for skill 3 activation
}
void AHack_n_Slash_ProjectPlayerController::AskRequestForSkill2()
{
	if (!IsOnUIblockRay)
	OnCallSkillDeleguate.Broadcast(4);//broadcast to character for skill 4 activation
}
void AHack_n_Slash_ProjectPlayerController::AskRequestForSkill3()
{
	if (!IsOnUIblockRay)
	OnCallSkillDeleguate.Broadcast(5);//broadcast to character for skill 5 activation
}

void AHack_n_Slash_ProjectPlayerController::SetInventoryVisibility()
{
	InventoryVisible = !InventoryVisible;
	OnInventoryVisible.Broadcast(InventoryVisible);
}
