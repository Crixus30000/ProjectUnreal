// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BagComponent.generated.h"

class UObjectStat;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent),Blueprintable )
class HACK_N_SLASH_PROJECT_API UBagComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBagComponent();

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TArray<UObjectStat*> Bag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 sizeMax = 60;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Isfull;


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
		UFUNCTION(BlueprintCallable)
			UObjectStat* GetItem(int _index);

		UFUNCTION(BlueprintCallable)
			bool GetBagfreeAsSpace();



};
