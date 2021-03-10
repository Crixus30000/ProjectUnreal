// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "Skill1CooldowCheckService.generated.h"

/**
 * 
 */
UCLASS()
class HACK_N_SLASH_PROJECT_API USkill1CooldowCheckService : public UBTService
{
	GENERATED_BODY()

protected:
	USkill1CooldowCheckService(const FObjectInitializer& ObjectIn);

	virtual void OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)override;

	UPROPERTY()
		class AAIController* SelfController;

	UPROPERTY()
		class UBlackboardComponent* CurrentBlackBoard;

		UPROPERTY()
		class USkillManagerComponent * SkillManager;
	
};
