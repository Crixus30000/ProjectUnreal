// Copyright Epic Games, Inc. All Rights Reserved.

#include "Hack_n_Slash_ProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/DecalComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Materials/Material.h"
#include "Engine/World.h"
#include "SkillManagerComponent.h"
#include "Hack_n_Slash_ProjectPlayerController.h"
#include "Engine/GameEngine.h"
#include "StatManager.h"
#include "SkillBase.h"
#include "BagComponent.h"
#include "ObjectStat.h"
AHack_n_Slash_ProjectCharacter::AHack_n_Slash_ProjectCharacter()
{
	// Set size for player capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when character does
	CameraBoom->TargetArmLength = 800.f;
	CameraBoom->SetRelativeRotation(FRotator(-60.f, 0.f, 0.f));
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level
	
	// Create a camera...
	TopDownCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	TopDownCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	TopDownCameraComponent->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Activate ticking in order to update the cursor every frame.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

	TeamId = FGenericTeamId(2);



	


}

 void AHack_n_Slash_ProjectCharacter::BeginPlay()
{
	Super::BeginPlay();

	AHack_n_Slash_ProjectPlayerController * ControllerTemp = Cast<AHack_n_Slash_ProjectPlayerController>(GetController());
	if (ControllerTemp != nullptr)
	{
		ControllerTemp->OnCallSkillDeleguate.AddUniqueDynamic(this, &AHack_n_Slash_ProjectCharacter::CallRequestSkill);
		ControllerTemp->OnCallCatchLoot.AddUniqueDynamic(this, &AHack_n_Slash_ProjectCharacter::CallCatchLoot);
	}
	EmptyPart = NewObject<UObjectStat>();

	Head = EmptyPart;
	Shoulder = EmptyPart;
	jewels = EmptyPart;
	Torso = EmptyPart;
	Legs = EmptyPart;
	Feet = EmptyPart;
	RightHand = EmptyPart;
	LeftHand = EmptyPart;
	Hands = EmptyPart;
	Cuffs = EmptyPart;
}

void AHack_n_Slash_ProjectCharacter::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

	if (CursorToWorld != nullptr)
	{
	
		 if (APlayerController* PC = Cast<APlayerController>(GetController()))
		{
			FHitResult TraceHitResult;
			PC->GetHitResultUnderCursor(ECC_Visibility, true, TraceHitResult);
			FVector CursorFV = TraceHitResult.ImpactNormal;
			FRotator CursorR = CursorFV.Rotation();
			CursorToWorld->SetWorldLocation(TraceHitResult.Location);
			CursorToWorld->SetWorldRotation(CursorR);
		}
	}
}

void AHack_n_Slash_ProjectCharacter::CallRequestSkill(int32 _index)
{

	if (SkillManager->OnSkillRequest(_index))
	{
		currentSkill = _index;
	}
	
}

void AHack_n_Slash_ProjectCharacter::CallCatchLoot(UObjectStat* _Statobject)
{
	BagRef->Bag.Add(_Statobject);
	OnCallCatchlootToUI.Broadcast(_Statobject);
}

bool AHack_n_Slash_ProjectCharacter::CloseEnoughTarget()
{
	if (Target != nullptr)
	{
		float CurrentDistance = (Target->GetActorLocation() - GetActorLocation()).Size();
		if (CurrentDistance <= MinDistanceTarget)
			return true;
	}
	return false;
}

void AHack_n_Slash_ProjectCharacter::SkillNotify()
{
	SkillManager->Skills[currentSkill-1]->Execute();
}

void AHack_n_Slash_ProjectCharacter::EndSkillnotify()
{
	SkillManager->Skills[currentSkill-1]->EndExecution();

}
void AHack_n_Slash_ProjectCharacter::TakeDamage_Implementation(int32 _Damage)
{

}

