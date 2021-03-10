// Fill out your copyright notice in the Description page of Project Settings.


#include "StatManager.h"
#include "ObjectStat.h"
#include "CharacterStat.h"
#include "Hack_n_Slash_ProjectCharacter.h"
// Sets default values for this component's properties
UStatManager::UStatManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UStatManager::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UStatManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UStatManager::UpdateStatCharacter()
{
// 		int Life;
// 		int Mana;
// 		int Force;
// 		int Dexterity;
// 		int Armor;
// 		int RegenLife;
// 		int RegenMana;
// 		int Speed;

	Life += CharacterStat->Life;
	Mana += CharacterStat->Mana;
	Force += CharacterStat->Force;
	Dexterity += CharacterStat->Dexterity;
	Armor += CharacterStat->Armor;
	RegenLife += CharacterStat->RegenLife;
	RegenMana += CharacterStat->RegenMana;
	Speed += CharacterStat->Speed;

	for (int i = 0; i < 8; i++)
	{
		if (ObjectList[i] != nullptr)
		{
			Life += ObjectList[i]->Life;
			Mana += ObjectList[i]->Mana;
			Force += ObjectList[i]->Force;
			Dexterity += ObjectList[i]->Dexterity;
			Armor += ObjectList[i]->Armor;
			RegenLife += ObjectList[i]->RegenLife;
			RegenMana += ObjectList[i]->RegenMana;
			Speed += ObjectList[i]->Speed;
		}
	}
}

float UStatManager::GetPercentLife()//return Percent life
{
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::FromInt(Life));

	return ((float)CurrentLife/(float)Life);
}

float UStatManager::GetPercentMana()
{
	return ((float)CurrentMana / (float)Mana);
}

void UStatManager::looseLife(int32 _Damage)
{
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red,  FString::FromInt(_Damage));
	CurrentLife -= _Damage;
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::FromInt(CurrentLife));
}

int UStatManager::CheckLife()
{
	return CurrentLife;
}
void UStatManager::UpdateAllStat()
{
	Life = CharacterRef->Head->Life + CharacterRef->Shoulder->Life + CharacterRef->jewels->Life + CharacterRef->Torso->Life + CharacterRef->Legs->Life + CharacterRef->Feet->Life + CharacterRef->RightHand->Life + CharacterRef->LeftHand->Life + CharacterRef->Hands->Life + CharacterRef->Cuffs->Life + CharacterStat->Life;
	Mana = CharacterRef->Head->Mana + CharacterRef->Shoulder->Mana + CharacterRef->jewels->Mana + CharacterRef->Torso->Mana + CharacterRef->Legs->Mana + CharacterRef->Feet->Mana + CharacterRef->RightHand->Mana + CharacterRef->LeftHand->Mana + CharacterRef->Hands->Mana + CharacterRef->Cuffs->Mana + CharacterStat->Mana;
	Armor = CharacterRef->Head->Armor + CharacterRef->Shoulder->Armor + CharacterRef->jewels->Armor + CharacterRef->Torso->Armor + CharacterRef->Legs->Armor + CharacterRef->Feet->Armor + CharacterRef->RightHand->Armor + CharacterRef->LeftHand->Armor + CharacterRef->Hands->Armor + CharacterRef->Cuffs->Armor+ CharacterStat->Armor;
	Dexterity = CharacterRef->Head->Dexterity + CharacterRef->Shoulder->Dexterity + CharacterRef->jewels->Dexterity + CharacterRef->Torso->Dexterity + CharacterRef->Legs->Dexterity + CharacterRef->Feet->Dexterity + CharacterRef->RightHand->Dexterity + CharacterRef->LeftHand->Dexterity + CharacterRef->Hands->Dexterity + CharacterRef->Cuffs->Dexterity+ CharacterStat->Dexterity;
	RegenLife = CharacterRef->Head->RegenLife + CharacterRef->Shoulder->RegenLife + CharacterRef->jewels->RegenLife + CharacterRef->Torso->RegenLife + CharacterRef->Legs->RegenLife + CharacterRef->Feet->RegenLife + CharacterRef->RightHand->RegenLife + CharacterRef->LeftHand->RegenLife + CharacterRef->Hands->RegenLife + CharacterRef->Cuffs->RegenLife+ CharacterStat->RegenLife;
	RegenMana = CharacterRef->Head->RegenMana + CharacterRef->Shoulder->RegenMana + CharacterRef->jewels->RegenMana + CharacterRef->Torso->RegenMana + CharacterRef->Legs->RegenMana + CharacterRef->Feet->RegenMana + CharacterRef->RightHand->RegenMana + CharacterRef->LeftHand->RegenMana + CharacterRef->Hands->RegenMana + CharacterRef->Cuffs->RegenMana+ CharacterStat->RegenMana;
	
	float PercentSpeed = ((float)(CharacterRef->Head->Speed + CharacterRef->Shoulder->Speed + CharacterRef->jewels->Speed + CharacterRef->Torso->Speed + CharacterRef->Legs->Speed + CharacterRef->Feet->Speed + CharacterRef->RightHand->Speed + CharacterRef->LeftHand->Speed + CharacterRef->Hands->Speed + CharacterRef->Cuffs->Speed)/100 * CharacterStat->Speed);//+ CharacterStat->Speed;
	GEngine->AddOnScreenDebugMessage(-1,3,FColor::Red, FString::SanitizeFloat(PercentSpeed));
		Speed =(int)PercentSpeed + CharacterStat->Speed;
}
	
