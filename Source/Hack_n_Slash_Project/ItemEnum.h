// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 *
 */
UENUM(BlueprintType)
enum class EItemRarety : uint8
{
	Common UMETA(DisplayName = "Common"),
	UnCommon UMETA(DisplayName = "UnCommon"),
	Rare UMETA(DisplayName = "Rare"),
	Epic UMETA(DisplayName = "Epic"),
	Legendary UMETA(DisplayName = "Legendary"),
	Mythical UMETA(DisplayName = "Mythical"),
};

UENUM(BlueprintType)
enum class ItemType : uint8
{
	Head UMETA(DisplayName = "Head"), 
	Shoulders UMETA(DisplayName = "Shoulders"),
	Torso UMETA(DisplayName = "Torso"), 
	Cuffs UMETA(DisplayName = "Cuffs"), 
	Hands UMETA(DisplayName = "Hands"), 
	Legs UMETA(DisplayName = "Legs"), 
	Feet UMETA(DisplayName = "Feet"), 
	Left_hand UMETA(DisplayName = "Left_hand"), 
	right_hand UMETA(DisplayName = "right_hand"), 
	Jewelry UMETA(DisplayName = "Jewelry"), 
	EndList UMETA(DisplayName = "EndList"),
};
