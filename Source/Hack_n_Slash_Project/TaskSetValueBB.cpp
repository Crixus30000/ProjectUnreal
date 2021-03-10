// Fill out your copyright notice in the Description page of Project Settings.


#include "TaskSetValueBB.h"
#include "AI_BaseController.h"
#include "Kismet/KismetMathLibrary.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Navigation/PathFollowingComponent.h"
EBTNodeResult::Type UTaskSetValueBB::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	AAI_BaseController* MyAIController = Cast<AAI_BaseController>(OwnerComp.GetAIOwner());


	if (MyAIController != nullptr && OwnerComp.GetBlackboardComponent() != nullptr)
	{
			OwnerComp.GetBlackboardComponent()->SetValueAsBool(AlreadyReachTargetLoc.SelectedKeyName, SetAllreadyRTL);
			OwnerComp.GetBlackboardComponent()->SetValueAsBool(AtHomeLoc.SelectedKeyName, SetAtHomeLocation);
	}
	return EBTNodeResult::Failed;
}

