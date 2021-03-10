// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SkillBase.h"
#include "invocationSkill.generated.h"

/**
 *
 */
UCLASS()
class HACK_N_SLASH_PROJECT_API UinvocationSkill : public USkillBase
{
	GENERATED_BODY()

public:

	UPROPERTY()
		AActor * FXActor;

	UPROPERTY()
		FVector FXLocation;

	UPROPERTY(EditAnywhere)
		TSubclassOf<class AAI_BaseCharacterCpp> BaseCharacter;

	UPROPERTY(EditAnywhere)
		TSubclassOf<class AAI_BaseController> AIController;


	UPROPERTY(EditAnywhere)
		TSubclassOf<class AActor> FX;

	UPROPERTY(EditAnywhere, Category = "Controller")
		class UBehaviorTree* BTRef;


	UPROPERTY(EditAnywhere, Category = "Controller")
		class UBlackboardData* BBData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		 int StepInvocation = 0;

	UFUNCTION()
		virtual void Execute() override;

};
