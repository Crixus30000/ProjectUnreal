// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ItemEnum.h"
#include "LootSystemComponent.generated.h"

class UObjectStat;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class HACK_N_SLASH_PROJECT_API ULootSystemComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	ULootSystemComponent();


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UMaterialInterface* MaterialInterface;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UStaticMesh* ItemlootSkin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<class ABaseActorObject> Object;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	 TArray< UObjectStat*>  statObject ;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<EItemRarety, float> ItemRaretyLootMap;

	UPROPERTY(VisibleAnywhere)
	float ValueMapItem = 0.0f;




protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		UFUNCTION(BlueprintCallable)
		void GenerateItemList();
		
		UFUNCTION(BlueprintCallable)
		UObjectStat * CreateItem(int Lvl);

		UFUNCTION(BlueprintCallable)
		void SpawnLoot();

		UFUNCTION(BlueprintCallable)
			EItemRarety ReturnRarety();

		UFUNCTION(BlueprintCallable)
			void ResetValue();
};
