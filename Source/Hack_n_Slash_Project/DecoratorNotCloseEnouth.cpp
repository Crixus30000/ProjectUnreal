// Fill out your copyright notice in the Description page of Project Settings.


#include "DecoratorNotCloseEnouth.h"
#include "AIController.h"
#include "Math/Vector.h"
#include "BehaviorTree/BlackboardComponent.h"

bool UDecoratorNotCloseEnouth::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	AAIController* MyAIController = Cast<AAIController>(OwnerComp.GetOwner());

	if (MyAIController != nullptr && OwnerComp.GetBlackboardComponent() != nullptr)
	{
		AActor* TargetActor = Cast<AActor>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(TargetKey.SelectedKeyName));

		AActor* MyPawn = MyAIController->GetPawn();


		if (TargetActor != nullptr && MyPawn != nullptr)
		{
			float Distace = (TargetActor->GetActorLocation() - MyPawn->GetActorLocation()).Size();

			if (Distace > AccetanceRadius)
			{
				return true;
			}
		}
	}
	return false;
}