// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CharacterStat.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType, EditInLineNew)
class HACK_N_SLASH_PROJECT_API UCharacterStat : public UObject
{
	GENERATED_BODY()

	public :

	UPROPERTY(EditAnywhere)
		int Life;
	UPROPERTY(EditAnywhere)
		int Mana;
	UPROPERTY(EditAnywhere)
		int Force;
	UPROPERTY(EditAnywhere)
		int Dexterity;
	UPROPERTY(EditAnywhere)
		int Armor;
	UPROPERTY(EditAnywhere)
		int RegenLife;
	UPROPERTY(EditAnywhere)
		int RegenMana;
	UPROPERTY(EditAnywhere)
		int Speed;
};
