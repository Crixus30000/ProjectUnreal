// Fill out your copyright notice in the Description page of Project Settings.


#include "TaskResetValue.h"
#include "AI_BaseController.h"
#include "Kismet/KismetMathLibrary.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Navigation/PathFollowingComponent.h"
EBTNodeResult::Type UTaskResetValue::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	AAI_BaseController* MyAIController = Cast<AAI_BaseController>(OwnerComp.GetAIOwner());


	if (MyAIController != nullptr && OwnerComp.GetBlackboardComponent() != nullptr)
	{


	if (ResetTargetRef)
	{
	OwnerComp.GetBlackboardComponent()->SetValueAsObject(TargetKeyCharacter.SelectedKeyName , nullptr);
	}
	if (ResetTargetLocation)
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsVector(KeyTargetLocation.SelectedKeyName, FVector::ZeroVector);
	}
	if (ResetHomeLocation)
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsVector(KeyHomeLocation.SelectedKeyName, FVector::ZeroVector);
	}

		


	}
	return EBTNodeResult::Failed;
}
