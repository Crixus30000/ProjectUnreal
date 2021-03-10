// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "DecoratorNotCloseEnouth.generated.h"

/**
 * 
 */
UCLASS()
class HACK_N_SLASH_PROJECT_API UDecoratorNotCloseEnouth : public UBTDecorator
{
	GENERATED_BODY()

protected:

	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;

	UPROPERTY(EditAnywhere, Category = Blackboard)
		struct FBlackboardKeySelector TargetKey;

	UPROPERTY(EditAnywhere, Category = "Distance")
		float AccetanceRadius = 50.0;
	
};
