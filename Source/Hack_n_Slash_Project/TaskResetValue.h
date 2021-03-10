// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "TaskResetValue.generated.h"

/**
 * 
 */
UCLASS()
class HACK_N_SLASH_PROJECT_API UTaskResetValue : public UBTTaskNode
{
	GENERATED_BODY()
	
protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;


	UPROPERTY(EditAnywhere, Category = Blackboard)
		struct FBlackboardKeySelector TargetKeyCharacter;
	UPROPERTY(EditAnywhere, Category = Blackboard)
		struct FBlackboardKeySelector KeyTargetLocation;
	UPROPERTY(EditAnywhere, Category = Blackboard)
		struct FBlackboardKeySelector KeyHomeLocation;

	UPROPERTY(EditAnywhere, Category = Blackboard)
		bool ResetTargetRef;
	UPROPERTY(EditAnywhere, Category = Blackboard)
		bool ResetTargetLocation;
	UPROPERTY(EditAnywhere, Category = Blackboard)
		bool ResetHomeLocation;



};
