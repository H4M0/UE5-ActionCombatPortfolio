// Fill out your copyright notice in the Description page of Project Settings.


#include "ANS_DodgeInvincible.h"

#include "StatComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/Actor.h"

void UANS_DodgeInvincible::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
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

	UStatComponent* StatComponent = OwnerActor->FindComponentByClass<UStatComponent>();
	if (!StatComponent)
	{
		UE_LOG(LogTemp, Warning, TEXT("DodgeInvincibility: StatComponent not found on %s"),
			*OwnerActor->GetActorNameOrLabel());

		return;
	}

	StatComponent->SetInvincible(true);

	UE_LOG(LogTemp, Warning, TEXT("Dodge Invincibility Begin"));
}

void UANS_DodgeInvincible::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
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

	UStatComponent* StatComponent = OwnerActor->FindComponentByClass<UStatComponent>();
	if (!StatComponent)
	{
		return;
	}

	StatComponent->SetInvincible(false);

	UE_LOG(LogTemp, Warning, TEXT("Dodge Invincibility End"));
}
