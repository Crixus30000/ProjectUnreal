// Fill out your copyright notice in the Description page of Project Settings.


#include "TaskLookTarget.h"
#include "AI_BaseController.h"
#include "Kismet/KismetMathLibrary.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Navigation/PathFollowingComponent.h"
#include "AI_BaseCharacterCpp.h"
EBTNodeResult::Type UTaskLookTarget::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	AAI_BaseController* MyAIController = Cast<AAI_BaseController>(OwnerComp.GetAIOwner());


	if (MyAIController != nullptr && OwnerComp.GetBlackboardComponent() != nullptr)
	{
		AActor* MyTarget = Cast<AActor>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(TargetKeyCharacter.SelectedKeyName));

		

		AActor* MyAIPawn = Cast<AActor>(MyAIController->GetPawn());

		AAI_BaseCharacterCpp* ClassOwner = Cast<AAI_BaseCharacterCpp>(MyAIController->GetPawn());

		ClassOwner->Target = MyTarget;
		if (MyTarget != nullptr && MyAIPawn != nullptr)
		{
			FRotator Rot = UKismetMathLibrary::FindLookAtRotation(MyAIPawn->GetActorLocation() ,MyTarget->GetActorLocation());
		
			FVector newVec =  Rot.Vector();
			newVec.X = 0;
			newVec.Z = 0;
			FRotator newrot = FRotator::MakeFromEuler(newVec);
			MyAIPawn->SetActorRotation(Rot);
		}


	}
	return EBTNodeResult::Failed;
}