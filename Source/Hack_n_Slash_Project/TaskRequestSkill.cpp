// Fill out your copyright notice in the Description page of Project Settings.


#include "TaskRequestSkill.h"

#include "AI_BaseCharacterCpp.h"
#include "AI_BaseController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Navigation/PathFollowingComponent.h"
#include "SkillManagerComponent.h"


EBTNodeResult::Type UTaskRequestSkill::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	AAI_BaseController* MyAIController = Cast<AAI_BaseController>(OwnerComp.GetAIOwner());


	if (MyAIController != nullptr && OwnerComp.GetBlackboardComponent() != nullptr)
	{
		USkillManagerComponent* SkillManager = Cast<USkillManagerComponent>(OwnerComp.GetBlackboardComponent()->GetValueAsObject("SkillManager"));
		AAI_BaseCharacterCpp* Characterref = Cast<AAI_BaseCharacterCpp>(MyAIController->GetPawn());
		if (SkillManager!= nullptr)
		{
			//SkillManager->OnSkillRequest(1);
			Characterref->CallRequestSkill(1);
		}

	}
	return EBTNodeResult::Failed;
}