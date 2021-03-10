// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "SetDataFromPlayer.generated.h"

/**
 * 
 */
UCLASS()
class HACK_N_SLASH_PROJECT_API USetDataFromPlayer : public UBTService
{
	GENERATED_BODY()
protected:


	USetDataFromPlayer(const FObjectInitializer& ObjectIn);

	virtual void OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)override;

	UPROPERTY()
		class AAIController* SelfController;

	UPROPERTY()
		class UBlackboardComponent* CurrentBlackBoard;

	UPROPERTY(EditAnywhere, Category = Blackboard)
		struct FBlackboardKeySelector PlayerActor;

	UPROPERTY(EditAnywhere, Category = Blackboard)
		struct FBlackboardKeySelector SetHomeLocationBool;

		UPROPERTY()
		bool TargetDead = false;
		UPROPERTY()
		bool AsTarget = false;

public:



};
