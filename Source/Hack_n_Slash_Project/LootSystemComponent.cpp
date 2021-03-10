// Fill out your copyright notice in the Description page of Project Settings.


#include "LootSystemComponent.h"
#include "ObjectStat.h"
#include "BaseActorObject.h"
#include "Kismet/KismetMathLibrary.h"
#include "BaseActorObject.h"
#include "ItemEnum.h"
// Sets default values for this component's properties
ULootSystemComponent::ULootSystemComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
		ItemRaretyLootMap.Add(EItemRarety::Common,0.6);
		ItemRaretyLootMap.Add(EItemRarety::UnCommon,0.2);
		ItemRaretyLootMap.Add(EItemRarety::Rare,0.1);
		ItemRaretyLootMap.Add(EItemRarety::Epic,0.05);
		ItemRaretyLootMap.Add(EItemRarety::Legendary,0.03);
		ItemRaretyLootMap.Add(EItemRarety::Mythical,0.01);


	// ...
}


// Called when the game starts
void ULootSystemComponent::BeginPlay()
{
	Super::BeginPlay();


	//Get the Total of Droprate in Map
	for (auto& Elem : ItemRaretyLootMap)
	{
		ValueMapItem += Elem.Value;
	}

	GenerateItemList();
}


// Called every frame
void ULootSystemComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void ULootSystemComponent::GenerateItemList()
{
	for (int i = 0; i < UKismetMathLibrary::RandomIntegerInRange(0, 10); i++)
	{
		statObject.Add(CreateItem(1));
	}
}

UObjectStat* ULootSystemComponent::CreateItem(int Lvl)
{

	
	int StatBase = Lvl*10;
	int StatMax = StatBase*2;


	UObjectStat* ObjectCreate = NewObject<UObjectStat>(UObjectStat::StaticClass());

	EItemRarety rarety  = ReturnRarety();


	ObjectCreate->Rarety = rarety;

	//Create coeficient of power Item
	float CoefPower = 0.0;
	switch (rarety)
	{
	case EItemRarety::Common: CoefPower = 1.0;
		break;
	case EItemRarety::UnCommon: CoefPower = 1.2;
		break;
	case EItemRarety::Rare: CoefPower = 1.4;
		break;
	case EItemRarety::Epic: CoefPower = 1.6;
		break;
	case EItemRarety::Legendary: CoefPower = 1.8;
		break;
	case EItemRarety::Mythical: CoefPower = 2;
		break;
	default:
		break;
	}
	//Select ItemCrate
	//UKismetMathLibrary::RandomIntegerInRange(0,(uint8) ItemType::EndList);
	
	ItemType ItemSelected =(ItemType)UKismetMathLibrary::RandomIntegerInRange(0, (uint8)ItemType::EndList-1);;
	

	switch (ItemSelected)
	{
	case ItemType::Head:
		ObjectCreate->Life = UKismetMathLibrary::RandomIntegerInRange(StatBase, StatMax) * CoefPower;
		ObjectCreate->Mana = UKismetMathLibrary::RandomIntegerInRange(StatBase, StatMax) * CoefPower;
		ObjectCreate->Armor = UKismetMathLibrary::RandomIntegerInRange(StatBase, StatMax) * CoefPower;
		ObjectCreate->RegenLife = UKismetMathLibrary::RandomIntegerInRange(StatBase, StatMax) * CoefPower;
		ObjectCreate->RegenMana = UKismetMathLibrary::RandomIntegerInRange(StatBase, StatMax) * CoefPower;
		break;
	case ItemType::Shoulders:
		ObjectCreate->Life = UKismetMathLibrary::RandomIntegerInRange(StatBase, StatMax) * CoefPower;
		ObjectCreate->Mana = UKismetMathLibrary::RandomIntegerInRange(StatBase, StatMax) * CoefPower;
		ObjectCreate->Armor = UKismetMathLibrary::RandomIntegerInRange(StatBase, StatMax) * CoefPower;
		ObjectCreate->RegenLife = UKismetMathLibrary::RandomIntegerInRange(StatBase, StatMax) * CoefPower;
		ObjectCreate->RegenMana = UKismetMathLibrary::RandomIntegerInRange(StatBase, StatMax) * CoefPower;
		break;
	case ItemType::Torso:
		ObjectCreate->Life = UKismetMathLibrary::RandomIntegerInRange(StatBase, StatMax) * CoefPower;
		ObjectCreate->Mana = UKismetMathLibrary::RandomIntegerInRange(StatBase, StatMax) * CoefPower;
		ObjectCreate->Armor = UKismetMathLibrary::RandomIntegerInRange(StatBase, StatMax) * CoefPower;
		ObjectCreate->RegenLife = UKismetMathLibrary::RandomIntegerInRange(StatBase, StatMax) * CoefPower;
		ObjectCreate->RegenMana = UKismetMathLibrary::RandomIntegerInRange(StatBase, StatMax) * CoefPower;
		break;
	case ItemType::Cuffs:
		ObjectCreate->Life = UKismetMathLibrary::RandomIntegerInRange(StatBase, StatMax) * CoefPower;
		ObjectCreate->Mana = UKismetMathLibrary::RandomIntegerInRange(StatBase, StatMax) * CoefPower;
		ObjectCreate->Armor = UKismetMathLibrary::RandomIntegerInRange(StatBase, StatMax) * CoefPower;
		ObjectCreate->RegenLife = UKismetMathLibrary::RandomIntegerInRange(StatBase, StatMax) * CoefPower;
		ObjectCreate->RegenMana = UKismetMathLibrary::RandomIntegerInRange(StatBase, StatMax) * CoefPower;
		break;
	case ItemType::Hands:
		ObjectCreate->Life = UKismetMathLibrary::RandomIntegerInRange(StatBase, StatMax) * CoefPower;
		ObjectCreate->Mana = UKismetMathLibrary::RandomIntegerInRange(StatBase, StatMax) * CoefPower;
		ObjectCreate->Armor = UKismetMathLibrary::RandomIntegerInRange(StatBase, StatMax) * CoefPower;
		ObjectCreate->RegenLife = UKismetMathLibrary::RandomIntegerInRange(StatBase, StatMax) * CoefPower;
		ObjectCreate->RegenMana = UKismetMathLibrary::RandomIntegerInRange(StatBase, StatMax) * CoefPower;
		break;
	case ItemType::Legs:
		ObjectCreate->Life = UKismetMathLibrary::RandomIntegerInRange(StatBase, StatMax) * CoefPower;
		ObjectCreate->Mana = UKismetMathLibrary::RandomIntegerInRange(StatBase, StatMax) * CoefPower;
		ObjectCreate->Armor = UKismetMathLibrary::RandomIntegerInRange(StatBase, StatMax) * CoefPower;
		ObjectCreate->RegenLife = UKismetMathLibrary::RandomIntegerInRange(StatBase, StatMax) * CoefPower;
		ObjectCreate->RegenMana = UKismetMathLibrary::RandomIntegerInRange(StatBase, StatMax) * CoefPower;
		ObjectCreate->Speed = UKismetMathLibrary::RandomIntegerInRange(StatBase/4, StatMax/4) * CoefPower;
		break;
	case ItemType::Feet:
		ObjectCreate->Life = UKismetMathLibrary::RandomIntegerInRange(StatBase, StatMax) * CoefPower;
		ObjectCreate->Mana = UKismetMathLibrary::RandomIntegerInRange(StatBase, StatMax) * CoefPower;
		ObjectCreate->Armor = UKismetMathLibrary::RandomIntegerInRange(StatBase, StatMax) * CoefPower;
		ObjectCreate->RegenLife = UKismetMathLibrary::RandomIntegerInRange(StatBase, StatMax) * CoefPower;
		ObjectCreate->RegenMana = UKismetMathLibrary::RandomIntegerInRange(StatBase, StatMax) * CoefPower;
		ObjectCreate->Speed = UKismetMathLibrary::RandomIntegerInRange(StatBase/2, StatMax/2) * CoefPower;
		break;
	case ItemType::Left_hand:
		ObjectCreate->Armor = UKismetMathLibrary::RandomIntegerInRange(StatBase*2, StatMax*2) * CoefPower;
		ObjectCreate->RegenLife = UKismetMathLibrary::RandomIntegerInRange(StatBase, StatMax) * CoefPower;
		ObjectCreate->Life = UKismetMathLibrary::RandomIntegerInRange(StatBase, StatMax) * CoefPower;

		break;
	case ItemType::right_hand:
		ObjectCreate->Life = UKismetMathLibrary::RandomIntegerInRange(StatBase, StatMax)* CoefPower;
		ObjectCreate->Mana = UKismetMathLibrary::RandomIntegerInRange(StatBase, StatMax) * CoefPower;
		ObjectCreate->Force = UKismetMathLibrary::RandomIntegerInRange(StatBase, StatMax) * CoefPower;
		ObjectCreate->Dexterity = UKismetMathLibrary::RandomIntegerInRange(StatBase, StatMax) * CoefPower;
		ObjectCreate->RegenLife = UKismetMathLibrary::RandomIntegerInRange(StatBase, StatMax) * CoefPower;
		ObjectCreate->RegenMana = UKismetMathLibrary::RandomIntegerInRange(StatBase, StatMax) * CoefPower;
		break;
	case ItemType::Jewelry:
		ObjectCreate->RegenLife = UKismetMathLibrary::RandomIntegerInRange(0, 10) * CoefPower;
		ObjectCreate->RegenMana = UKismetMathLibrary::RandomIntegerInRange(0, 10) * CoefPower;
		break;
	case ItemType::EndList:
		ObjectCreate->Life = UKismetMathLibrary::RandomIntegerInRange(0, 10) * CoefPower;
		ObjectCreate->Mana = UKismetMathLibrary::RandomIntegerInRange(0, 10) * CoefPower;
		ObjectCreate->Force = UKismetMathLibrary::RandomIntegerInRange(0, 10) * CoefPower;
		ObjectCreate->Dexterity = UKismetMathLibrary::RandomIntegerInRange(0, 10) * CoefPower;
		ObjectCreate->Armor = UKismetMathLibrary::RandomIntegerInRange(0, 10) * CoefPower;
		ObjectCreate->RegenLife = UKismetMathLibrary::RandomIntegerInRange(0, 10) * CoefPower;
		ObjectCreate->RegenMana = UKismetMathLibrary::RandomIntegerInRange(0, 10) * CoefPower;
		ObjectCreate->Speed = UKismetMathLibrary::RandomIntegerInRange(0, 10) * CoefPower;
		break;
	default:GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Red, "DEFAULT -> MESSAGE FROM CREATE OBJECT LOOT SYSTEM");
		break;
	};
	ObjectCreate->TypeItem = ItemSelected;

	//PopulateStat
	

	//Selected Mesh
	


	return ObjectCreate;
}



void ULootSystemComponent::SpawnLoot()
{

	for (int i = 0; i < statObject.Num(); i++)
	{
		//Create Transform Random Location for loot
		FTransform Pos = FTransform(
		GetOwner()->GetActorRotation()+FRotator(0, UKismetMathLibrary::RandomFloatInRange(0, 360),0),
		GetOwner()->GetActorLocation() + FVector(
			UKismetMathLibrary::RandomFloatInRange(0, 100),
			UKismetMathLibrary::RandomFloatInRange(0, 100),
			0),
			GetOwner()->GetActorScale()
			);
		
	ABaseActorObject* ObjectContain;
	ObjectContain = GetWorld()->SpawnActorDeferred<ABaseActorObject>(Object, Pos);
	ObjectContain->StatObject = statObject[i];
	//statObject[i]->Icon = ObjectContain->Icon;

	ObjectContain->FinishSpawning(Pos);
	ObjectContain->MaterialInterface = MaterialInterface;
	ObjectContain->SetAllMeshObject(ItemlootSkin);
	ObjectContain->MeshObject->SetSimulatePhysics(true);
	}
	
// 		int Life;
// 		int Mana;
// 		int Force;
// 		int Dexterity;
// 		int Armor;
// 		int RegenLife;
// 		int RegenMana;
// 		int Speed;
}

EItemRarety ULootSystemComponent::ReturnRarety()
{

	float randomValue = UKismetMathLibrary::RandomFloatInRange(0, ValueMapItem);

	for (auto It = ItemRaretyLootMap.CreateConstIterator(); It; ++It)
	{

		if (randomValue < It.Value())
		{

			return It.Key();
		}
		else
		{
			
			randomValue -= It.Value();
		}

	}
	return EItemRarety::Mythical;
}

void ULootSystemComponent::ResetValue()
{
	if (statObject.Num() > 0 )
	{
		statObject.Empty();
		GenerateItemList();
	}
}

