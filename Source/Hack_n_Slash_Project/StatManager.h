// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StatManager.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class HACK_N_SLASH_PROJECT_API UStatManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UStatManager();
	UPROPERTY(EditAnywhere, Category = "Character_Stat")
		int CurrentLife;
	UPROPERTY(EditAnywhere, Category = "Character_Stat")
		int CurrentMana;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = "Character_Stat")
		int Life;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character_Stat")
		int Mana;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character_Stat")
		int Force;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character_Stat")
		int Dexterity;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character_Stat")
		int Armor;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character_Stat")
		int RegenLife;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character_Stat")
		int RegenMana;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character_Stat")
		int Speed;


	UPROPERTY(EditAnywhere, Instanced, Category = "Character_BaseStat")
	class UCharacterStat*  CharacterStat;


	UPROPERTY(EditAnywhere, Instanced, Category = "Item_List")
	class UObjectStat* ObjectList[8];

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character_REF")
	 class AHack_n_Slash_ProjectCharacter * CharacterRef;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void UpdateStatCharacter();

	UFUNCTION(BlueprintCallable)
	float GetPercentLife();
	UFUNCTION(BlueprintCallable)
		float GetPercentMana();
	UFUNCTION(BlueprintCallable)
		void looseLife(int32 _Damage);

	UFUNCTION(BlueprintCallable)
		int CheckLife();

		UFUNCTION(BlueprintCallable)
		void UpdateAllStat();
};
