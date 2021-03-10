// Fill out your copyright notice in the Description page of Project Settings.


#include "SkillManagerComponent.h"
#include "SkillBase.h"
#include "Hack_n_Slash_ProjectCharacter.h"
// Sets default values for this component's properties
USkillManagerComponent::USkillManagerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USkillManagerComponent::BeginPlay()
{
	Super::BeginPlay();
	UpDateSkillM();
	// ...

}


// Called every frame
void USkillManagerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	CallTickOfSkills(DeltaTime);
	// ...
}

void USkillManagerComponent::UpDateSkillM()//Update into skill var SkillManagerOwner
{
	for (int i = 0; i < Skills.Num(); i++)
	{
		Skills[i]->SkillManagerOwner = this;
	}
}

void USkillManagerComponent::CallTickOfSkills(float _deltaTime)//Update All Skills(Cooldown etc...)
{

	for (int i = 0; i < Skills.Num(); i++)
	{
		Skills[i]->TickSkill(_deltaTime);
	}
}


bool USkillManagerComponent::ASkillIsExecuting()//Check if skill isExecuting
{
	if (Skills.Num() > 0)
	{
		for (int i = 0; i < Skills.Num(); i++)
		{
			if (Skills[i]->IsExecuting)
				return true;
		}
	}
	return false;
}

bool USkillManagerComponent::OnSkillRequest(int32 _SkillIndex)//Call Animation montage for SkillSelected
{
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::FromInt(_SkillIndex));

	if (_SkillIndex <= Skills.Num() && !ASkillIsExecuting())
	{
		if (Skills[_SkillIndex - 1]->RequestExecution())
		{
			PlayAnimationSKM(Skills[_SkillIndex - 1]->AnimMontage);
			return true;
		}
	}
	return false;
}

AHack_n_Slash_ProjectCharacter* USkillManagerComponent::GetOwnerCharacter()
{
	return Cast<AHack_n_Slash_ProjectCharacter>(GetOwner());
}

AAI_BaseCharacterCpp* USkillManagerComponent::GetIAOwnerCharacter()
{
	return Cast<AAI_BaseCharacterCpp>(GetOwner());
}

float USkillManagerComponent::GetSkillCoolDown(int32 _SkillIndex)
{
	return 1 - Skills[_SkillIndex]->GetCooldown();
}





