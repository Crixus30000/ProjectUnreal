// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ItemEnum.h"
#include "ObjectStat.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType, EditInLineNew)
class HACK_N_SLASH_PROJECT_API UObjectStat : public UObject
{
	GENERATED_BODY()
	public :
		UObjectStat();
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
			EItemRarety Rarety;
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
			ItemType TypeItem;
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
			FColor ColorRarty;
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
			int Life=0;
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
			int Mana=0;
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
			int Force=0;
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
			int Dexterity=0;
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
			int Armor=0;
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
			int RegenLife=0;
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
			int RegenMana=0;
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
			int Speed=0;
		//UPROPERTY(EditAnywhere)
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
			class UTexture2D* Icon;
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
			FName NameObject;
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
			int32 Price;
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
			class UStaticMesh* MeshObject;
	
};
