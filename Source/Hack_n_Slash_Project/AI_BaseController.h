// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"

#include "AI_BaseController.generated.h"
/**
 *
 */
UCLASS()
class HACK_N_SLASH_PROJECT_API AAI_BaseController : public AAIController
{
	GENERATED_BODY()


	public :

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	bool IsDead;
protected:



	UPROPERTY(EditAnywhere, Category = "Controller")
		class UBehaviorTree* BTRef;


	UPROPERTY(EditAnywhere, Category = "Controller")
		class UBlackboardData* BBData;


	UPROPERTY()
		class UBlackboardComponent* BBRef;

	virtual void  BeginPlay()override;

	UFUNCTION(BlueprintCallable)//Function Call In BP with Delay 0.1 for waiting init of blackboard
		void InitBB();

};
