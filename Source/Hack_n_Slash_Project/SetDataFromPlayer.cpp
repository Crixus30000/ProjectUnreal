// Fill out your copyright notice in the Description page of Project Settings.


#include "SetDataFromPlayer.h"
#include "BehaviorTree/BTService.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "Hack_n_Slash_ProjectPlayerController.h"
#include "AI_BaseCharacterCpp.h"
USetDataFromPlayer::USetDataFromPlayer(const FObjectInitializer& ObjectIn) : Super(ObjectIn)
{
	NodeName = "DataFromPlayer";
	bNotifyCeaseRelevant = true;
	bNotifyBecomeRelevant = true;
	Interval = 0.5f;
	RandomDeviation = 0.0f;
}

void USetDataFromPlayer::OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::OnBecomeRelevant(OwnerComp, NodeMemory);
	//InitAtt Start
	if (OwnerComp.GetBlackboardComponent() != nullptr)
	{
		CurrentBlackBoard = OwnerComp.GetBlackboardComponent();
		SelfController = Cast<AAIController>(OwnerComp.GetAIOwner());
		OwnerComp.GetBlackboardComponent()->SetValueAsObject(PlayerActor.SelectedKeyName, GetWorld()->GetFirstPlayerController()->GetPawn());
	}
}

void USetDataFromPlayer::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);


	AHack_n_Slash_ProjectPlayerController* PC = Cast<AHack_n_Slash_ProjectPlayerController>(GetWorld()->GetFirstPlayerController());


	if (!AsTarget && PC->HasTarget)
	{
		if (PC->Target->Tags.Num()>0)
		{
			CurrentBlackBoard->SetValueAsObject(PlayerActor.SelectedKeyName, PC->Target);
			CurrentBlackBoard->SetValueAsBool(SetHomeLocationBool.SelectedKeyName, false);

			AsTarget = true;
		}

	}
	else if (!AsTarget)
	{
		CurrentBlackBoard->SetValueAsObject(PlayerActor.SelectedKeyName, GetWorld()->GetFirstPlayerController()->GetPawn());
		CurrentBlackBoard->SetValueAsBool(SetHomeLocationBool.SelectedKeyName, true);

	}

	if (AsTarget && Cast<AAI_BaseCharacterCpp>(CurrentBlackBoard->GetValueAsObject(PlayerActor.SelectedKeyName))->IsDeadCaracter)
	{
		CurrentBlackBoard->SetValueAsObject(PlayerActor.SelectedKeyName, nullptr);

		AsTarget = false;
	}




}