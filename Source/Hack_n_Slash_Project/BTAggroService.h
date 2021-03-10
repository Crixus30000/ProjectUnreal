// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BTAggroService.generated.h"

/**
 * 
 */
UCLASS()
class HACK_N_SLASH_PROJECT_API UBTAggroService : public UBTService
{
	GENERATED_BODY()

protected:


	UBTAggroService(const FObjectInitializer& ObjectIn);

	virtual void OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)override;

	UPROPERTY()
	class AAIController * SelfController;

	UPROPERTY()
	class UBlackboardComponent* CurrentBlackBoard;


	UPROPERTY(EditAnywhere, Category = Blackboard)
		TArray<TEnumAsByte<EObjectTypeQuery>> FilterArrayType;

	UPROPERTY(EditAnywhere, Category = Blackboard)
		AActor* NullPointer;
public:
	UPROPERTY(EditAnywhere, Category = Blackboard)
		struct FBlackboardKeySelector TargetLocation;

	UPROPERTY(EditAnywhere, Category = Blackboard)
		struct FBlackboardKeySelector TargetRef;

	UPROPERTY(EditAnywhere, Category = Blackboard)
		TSubclassOf<AActor> RefAAICharacter;
	
};
