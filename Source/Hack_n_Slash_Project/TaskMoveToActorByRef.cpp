// Fill out your copyright notice in the Description page of Project Settings.


#include "TaskMoveToActorByRef.h"
#include "AI_BaseController.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Navigation/PathFollowingComponent.h"


//Task for Move AICharacter to move to Target By Reference
 EBTNodeResult::Type UTaskMoveToActorByRef::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	AAI_BaseController * MyAIController = Cast<AAI_BaseController>(OwnerComp.GetAIOwner());


	if (MyAIController != nullptr && OwnerComp.GetBlackboardComponent() != nullptr)
	{
		AActor * MyTarget = Cast<AActor>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(TargetKeyCharacter.SelectedKeyName));

		AActor * MyAIPawn = Cast<AActor>(MyAIController->GetPawn());


		if (MyTarget != nullptr && MyAIPawn != nullptr)
		{
			EPathFollowingRequestResult::Type RequestResult = MyAIController->MoveToActor(MyTarget, 10.0);

			if (RequestResult == EPathFollowingRequestResult::Failed)
			return EBTNodeResult::InProgress;
			else
			return EBTNodeResult::Succeeded;
		}

		
	}
	return EBTNodeResult::Failed;
}