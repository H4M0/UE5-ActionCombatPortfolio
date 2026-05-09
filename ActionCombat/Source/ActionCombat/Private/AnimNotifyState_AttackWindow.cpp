// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimNotifyState_AttackWindow.h"

#include "CombatComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/Actor.h"

void UAnimNotifyState_AttackWindow::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration, EventReference);

	if (!MeshComp)
	{
		return;
	}

	AActor* OwnerActor = MeshComp->GetOwner();
	if (!OwnerActor)
	{
		return;
	}

	UCombatComponent* CombatComponent = OwnerActor->FindComponentByClass<UCombatComponent>();
	if (!CombatComponent)
	{
		UE_LOG(LogTemp, Warning, TEXT("AnimNotifyState_AttackWindow: CombatComponent not found on %s"),
			*OwnerActor->GetActorNameOrLabel());

		return;
	}

	CombatComponent->BeginAttackTrace();
}

void UAnimNotifyState_AttackWindow::NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyTick(MeshComp, Animation, FrameDeltaTime, EventReference);

	if (!MeshComp)
	{
		return;
	}

	AActor* OwnerActor = MeshComp->GetOwner();
	if (!OwnerActor)
	{
		return;
	}

	UCombatComponent* CombatComponent = OwnerActor->FindComponentByClass<UCombatComponent>();
	if (!CombatComponent)
	{
		return;
	}

	CombatComponent->PerformAttackTrace();
}

void UAnimNotifyState_AttackWindow::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyEnd(MeshComp, Animation, EventReference);

	if (!MeshComp)
	{
		return;
	}

	AActor* OwnerActor = MeshComp->GetOwner();
	if (!OwnerActor)
	{
		return;
	}

	UCombatComponent* CombatComponent = OwnerActor->FindComponentByClass<UCombatComponent>();
	if (!CombatComponent)
	{
		return;
	}

	CombatComponent->EndAttackTrace();
}
