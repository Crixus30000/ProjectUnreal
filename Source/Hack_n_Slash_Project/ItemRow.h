// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemEnum.h"
#include "Engine/DataTable.h"
#include "ItemRow.generated.h"
/**
 * 
 */
 USTRUCT(BlueprintType)
struct  FItemRow : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
public:

		UPROPERTY(EditAnywhere,BlueprintReadWrite)
		class UTexture2D *ICon;
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
			ItemType Typeitem;
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
			 EItemRarety Raretyitem;
		
};
