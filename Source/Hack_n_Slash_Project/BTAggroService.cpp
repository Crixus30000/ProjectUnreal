// Fill out your copyright notice in the Description page of Project Settings.


#include "BTAggroService.h"
#include "BehaviorTree/BTService.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Object.h"
#include "AIController.h"
#include "GameFramework/Character.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Engine/EngineTypes.h"
#include "Containers/EnumAsByte.h"
#include "Engine/World.h"
#include "AI_BaseController.h"

UBTAggroService::UBTAggroService(const FObjectInitializer& ObjectIn) : Super(ObjectIn)
{
	NodeName = "AggroService";
	bNotifyCeaseRelevant = true;
	bNotifyBecomeRelevant = true;
	Interval = 0.5f;
	RandomDeviation = 0.0f;
}

void UBTAggroService::OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::OnBecomeRelevant(OwnerComp, NodeMemory);
    //InitAtt Start
	if (OwnerComp.GetBlackboardComponent() != nullptr)
	{
		CurrentBlackBoard = OwnerComp.GetBlackboardComponent();
		SelfController = Cast<AAIController>(OwnerComp.GetAIOwner());
		OwnerComp.GetBlackboardComponent()->SetValueAsObject("SelfRef", OwnerComp.GetAIOwner());
		OwnerComp.GetBlackboardComponent()->SetValueAsVector("HomeLocation", OwnerComp.GetAIOwner()->GetPawn()->GetActorLocation());
	}
}

void UBTAggroService::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

    //Do RayCast Between IA And PlayerCharacter And check if Ray Collide With None 
    // and Set Target ref And Target Location 

	if (SelfController != nullptr)//Security
	{
		FVector MyPawnLocation = SelfController->GetPawn()->GetActorLocation();

 		TArray<AActor*> FoundActorsAI;
 		UGameplayStatics::GetAllActorsOfClass(GetWorld(), RefAAICharacter, FoundActorsAI);
 
 		if (FoundActorsAI.Num() > 0)
 		{
 			TArray<AActor*> OverlapActor;
 			UKismetSystemLibrary::SphereOverlapActors(GetWorld(), MyPawnLocation,1500.0f, FilterArrayType,NULL, FoundActorsAI, OverlapActor);
 			for (int i = 0 ; i < OverlapActor.Num();i++)
 			{
 				FCollisionQueryParams Param;
 				
 				Param.AddIgnoredActor(SelfController->GetPawn());
 				FHitResult Result;

 				GetWorld()->LineTraceSingleByChannel(Result,MyPawnLocation,OverlapActor[i]->GetActorLocation(),ECollisionChannel::ECC_Camera,Param);
 
 				if (Result.Actor == OverlapActor[i] && CurrentBlackBoard!= nullptr)//Security
 				{
 					CurrentBlackBoard->SetValueAsObject("TargetRef", OverlapActor[i]);
					CurrentBlackBoard->SetValueAsVector("TargetLocation", OverlapActor[i]->GetActorLocation());
 				}
                else 
                {
                    CurrentBlackBoard->SetValueAsObject("TargetRef", NullPointer);
                }
 			}
 
 		}
	}

}