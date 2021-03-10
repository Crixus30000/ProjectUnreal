// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "TaskSetValueBB.generated.h"

/**
 * 
 */
UCLASS()
class HACK_N_SLASH_PROJECT_API UTaskSetValueBB : public UBTTaskNode
{
	GENERATED_BODY()
protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;


	UPROPERTY(EditAnywhere, Category = Blackboard)
		struct FBlackboardKeySelector AlreadyReachTargetLoc;
	UPROPERTY(EditAnywhere, Category = Blackboard)
		struct FBlackboardKeySelector AtHomeLoc;


	UPROPERTY(EditAnywhere, Category = Blackboard)
		bool SetAllreadyRTL;
	UPROPERTY(EditAnywhere, Category = Blackboard)
		bool SetAtHomeLocation;
};
