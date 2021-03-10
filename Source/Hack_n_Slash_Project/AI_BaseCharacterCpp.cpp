// Fill out your copyright notice in the Description page of Project Settings.


#include "AI_BaseCharacterCpp.h"
#include "SkillManagerComponent.h"
#include "SkillBase.h"
// Sets default values
AAI_BaseCharacterCpp::AAI_BaseCharacterCpp()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TeamId = FGenericTeamId(0);
	
}

// Called when the game starts or when spawned
void AAI_BaseCharacterCpp::BeginPlay()
{
	Super::BeginPlay();
	Tags.Add("Enemy");
}

// Called every frame
void AAI_BaseCharacterCpp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAI_BaseCharacterCpp::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AAI_BaseCharacterCpp::TakeDamage_Implementation(int32 _Damage)
{

}

void AAI_BaseCharacterCpp::SkillNotify()
{
	SkillManager->Skills[currentSkill - 1]->Execute();
}

void AAI_BaseCharacterCpp::EndSkillnotify()
{
	SkillManager->Skills[currentSkill - 1]->EndExecution();

}

void AAI_BaseCharacterCpp::CallRequestSkill(int32 _index)
{
	if (SkillManager->Skills.Num() > 0 && SkillManager->OnSkillRequest(_index) )
	{

		currentSkill = _index;
	}

}

void AAI_BaseCharacterCpp::SeeHighlight_Implementation()
{
}

void AAI_BaseCharacterCpp::UnSeeHighlight_Implementation()
{
}
