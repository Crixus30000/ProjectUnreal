// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SkillByRef.h"
#include "SkillEnemyByRef.generated.h"

/**
 * 
 */
UCLASS()
class HACK_N_SLASH_PROJECT_API USkillEnemyByRef : public USkillBase
{
	GENERATED_BODY()

public:
	class IDamagable* damagableRef;


	UFUNCTION()
		virtual void Execute() override;
	
};
