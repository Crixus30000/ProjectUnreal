// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
//#include "Kismet/BlueprintFunctionLibrary.h"
#include "ItemEnum.h"
#include "ItemGeneratorLibrary.generated.h"




/**
 * 
 */
UCLASS()
class HACK_N_SLASH_PROJECT_API UItemGeneratorLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	public: 

	UFUNCTION(BlueprintCallable)
	static void FunctionPrint();



};
