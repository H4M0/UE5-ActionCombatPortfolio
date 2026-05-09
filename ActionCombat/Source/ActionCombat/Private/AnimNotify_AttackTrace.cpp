// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimNotify_AttackTrace.h"

#include "CombatComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/Actor.h"

void UAnimNotify_AttackTrace::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

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
		UE_LOG(LogTemp, Warning, TEXT("AnimNotify_AttackTrace: CombatComponent not found on %s"),
			*OwnerActor->GetActorNameOrLabel());

		return;
	}

	CombatComponent->PerformAttackTrace();
}
