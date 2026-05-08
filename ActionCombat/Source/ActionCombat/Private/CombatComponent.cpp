// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatComponent.h"

#include "GameFramework/Character.h"
#include "Animation/AnimInstance.h"
#include "Animation/AnimMontage.h"

// Debugging purposes
#include "TimerManager.h"

// Sets default values for this component's properties
UCombatComponent::UCombatComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UCombatComponent::StartAttack()
{
	if (bIsAttacking)
	{
		UE_LOG(LogTemp, Warning, TEXT("Attack ignored: Already attacking"));
		return;
	}

	if (!AttackMontage)
	{
		UE_LOG(LogTemp, Warning, TEXT("AttackMontage is not assigned"));
		return;
	}

	ACharacter* OwnerCharacter = Cast<ACharacter>(GetOwner());
	if (!OwnerCharacter)
	{
		UE_LOG(LogTemp, Warning, TEXT("Owner is not a Character"));
		return;
	}

	UAnimInstance* AnimInstance = OwnerCharacter->GetMesh()->GetAnimInstance();
	if (!AnimInstance)
	{
		UE_LOG(LogTemp, Warning, TEXT("AnimInstance is invalid"));
		return;
	}

	bIsAttacking = true;

	const float MontageDuration = AnimInstance->Montage_Play(AttackMontage);

	if (MontageDuration <= 0.0f)
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to play AttackMontage"));
		EndAttack();
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("StartAttack Called"));

	GetWorld()->GetTimerManager().SetTimer(
		AttackTimerHandle,
		this,
		&UCombatComponent::EndAttack,
		MontageDuration,
		false
	);
}

void UCombatComponent::EndAttack()
{
	bIsAttacking = false;

	UE_LOG(LogTemp, Warning, TEXT("EndAttack Called"));
}


// Called when the game starts
void UCombatComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UCombatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

