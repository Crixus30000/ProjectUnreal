// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SkillBase.h"
#include "SkillAutodestruction.generated.h"

/**
 * 
 */
UCLASS()
class HACK_N_SLASH_PROJECT_API USkillAutodestruction : public USkillBase
{
	GENERATED_BODY()
public:

	UPROPERTY()
		AActor* FXActor;

	UPROPERTY()
		FVector FXLocation;


	UPROPERTY(EditAnywhere)
		TSubclassOf<class AActor> FX;


	

	UFUNCTION()
		virtual void Execute() override;


};
