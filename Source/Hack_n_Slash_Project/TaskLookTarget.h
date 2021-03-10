// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "TaskLookTarget.generated.h"

/**
 * 
 */
UCLASS()
class HACK_N_SLASH_PROJECT_API UTaskLookTarget : public UBTTaskNode
{
	GENERATED_BODY()
	

protected:
		virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;


	UPROPERTY(EditAnywhere, Category = Blackboard)
		struct FBlackboardKeySelector TargetKeyCharacter;
};
