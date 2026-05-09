// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatComponent.h"

#include "StatComponent.h"
#include "GameFramework/Character.h"
#include "Animation/AnimInstance.h"
#include "Animation/AnimMontage.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"

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

	FOnMontageEnded MontageEndedDelegate;
	MontageEndedDelegate.BindUObject(this, &UCombatComponent::OnAttackMontageEnded);
	AnimInstance->Montage_SetEndDelegate(MontageEndedDelegate, AttackMontage);

	UE_LOG(LogTemp, Warning, TEXT("StartAttack Called"));

	PerformAttackTrace();
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

void UCombatComponent::PerformAttackTrace()
{
	ACharacter* OwnerCharacter = Cast<ACharacter>(GetOwner());
	if (!OwnerCharacter)
	{
		return;
	}

	UWorld* World = GetWorld();
	if (!World)
	{
		return;
	}

	const FVector Start = OwnerCharacter->GetActorLocation() + FVector(0.0f, 0.0f, 50.0f);
	const FVector Forward = OwnerCharacter->GetActorForwardVector();
	const FVector End = Start + Forward * AttackRange;

	TArray<FHitResult> HitResults;

	FCollisionObjectQueryParams ObjectQueryParams;
	ObjectQueryParams.AddObjectTypesToQuery(ECC_Pawn);

	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(OwnerCharacter);

	const FCollisionShape CollisionShape = FCollisionShape::MakeSphere(AttackRadius);

	const bool bHit = World->SweepMultiByObjectType(
		HitResults,
		Start,
		End,
		FQuat::Identity,
		ObjectQueryParams,
		CollisionShape,
		QueryParams
	);

	DrawDebugLine(World, Start, End, FColor::Red, false, 1.0f, 0, 2.0f);
	DrawDebugSphere(World, End, AttackRadius, 16, FColor::Red, false, 1.0f);

	if (!bHit)
	{
		UE_LOG(LogTemp, Warning, TEXT("Attack Trace: No Hit"));
		return;
	}

	TSet<AActor*> DamagedActors;

	for (const FHitResult& HitResult : HitResults)
	{
		AActor* HitActor = HitResult.GetActor();

		if (!HitActor || DamagedActors.Contains(HitActor))
		{
			continue;
		}

		UStatComponent* TargetStatComponent = HitActor->FindComponentByClass<UStatComponent>();
		if (!TargetStatComponent)
		{
			continue;
		}

		DamagedActors.Add(HitActor);

		TargetStatComponent->ApplyDamage(AttackDamage);

		UE_LOG(LogTemp, Warning, TEXT("Attack hit: %s"), *HitActor->GetActorNameOrLabel());
	}
}

void UCombatComponent::OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted)
{
	if (Montage != AttackMontage)
	{
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("Attack Montage Ended. Interrupted: %s"), bInterrupted ? TEXT("true") : TEXT("false"));

	EndAttack();
}

