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

	if (bIsDodging)
	{
		UE_LOG(LogTemp, Warning, TEXT("Attack ignored: Currently dodging"));
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
	bIsAttackTraceActive = false;

	HitActorsThisAttack.Empty();

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
}

void UCombatComponent::EndAttack()
{
	bIsAttacking = false;
	bIsAttackTraceActive = false;
	HitActorsThisAttack.Empty();

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

void UCombatComponent::BeginAttackTrace()
{
	if (!bIsAttacking)
	{
		UE_LOG(LogTemp, Warning, TEXT("BeginAttackTrace ignored: Not attacking"));
		return;
	}

	bIsAttackTraceActive = true;

	UE_LOG(LogTemp, Warning, TEXT("Attack Trace Window Begin"));
}

void UCombatComponent::PerformAttackTrace()
{
	if (!bIsAttacking || !bIsAttackTraceActive)
	{
		return;
	}

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

	for (const FHitResult& HitResult : HitResults)
	{
		AActor* HitActor = HitResult.GetActor();

		if (!HitActor)
		{
			continue;
		}

		if (HitActorsThisAttack.Contains(HitActor))
		{
			UE_LOG(LogTemp, Warning, TEXT("Attack ignored: %s was already hit in this attack"),
				*HitActor->GetActorNameOrLabel());

			continue;
		}

		UStatComponent* TargetStatComponent = HitActor->FindComponentByClass<UStatComponent>();
		if (!TargetStatComponent)
		{
			continue;
		}

		HitActorsThisAttack.Add(HitActor);

		TargetStatComponent->ApplyDamage(AttackDamage);

		UE_LOG(LogTemp, Warning, TEXT("Attack hit: %s"),
			*HitActor->GetActorNameOrLabel());
	}
}

void UCombatComponent::EndAttackTrace()
{
	if (!bIsAttackTraceActive)
	{
		return;
	}

	bIsAttackTraceActive = false;

	UE_LOG(LogTemp, Warning, TEXT("Attack Trace Window End"));
}

void UCombatComponent::StartDodge(const FVector& DodgeInputDirection)
{
	if (bIsDodging)
	{
		UE_LOG(LogTemp, Warning, TEXT("Dodge ignored: Already dodging"));
		return;
	}

	if (bIsAttacking)
	{
		UE_LOG(LogTemp, Warning, TEXT("Dodge ignored: Currently attacking"));
		return;
	}

	if (!DodgeMontage)
	{
		UE_LOG(LogTemp, Warning, TEXT("DodgeMontage is not assigned"));
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

	bIsDodging = true;

	FVector DodgeDirection = DodgeInputDirection;
	DodgeDirection.Z = 0.0f;

	if (!DodgeDirection.Normalize())
	{
		DodgeDirection = -OwnerCharacter->GetActorForwardVector();
	}

	const FVector LaunchVelocity = DodgeDirection * DodgeStrength + FVector(0.0f, 0.0f, DodgeUpStrength);

	OwnerCharacter->LaunchCharacter(LaunchVelocity, true, true);

	const float MontageDuration = AnimInstance->Montage_Play(DodgeMontage);

	if (MontageDuration <= 0.0f)
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to play DodgeMontage"));
		EndDodge();
		return;
	}

	FOnMontageEnded MontageEndedDelegate;
	MontageEndedDelegate.BindUObject(this, &UCombatComponent::OnDodgeMontageEnded);
	AnimInstance->Montage_SetEndDelegate(MontageEndedDelegate, DodgeMontage);

	UE_LOG(LogTemp, Warning, TEXT("StartDodge Called"));
	UE_LOG(LogTemp, Warning, TEXT("Dodge Input Direction: %s"), *DodgeInputDirection.ToString());
	UE_LOG(LogTemp, Warning, TEXT("Dodge Dodge Direction: %s"), *DodgeDirection.ToString());
}

void UCombatComponent::EndDodge()
{
	bIsDodging = false;

	if (AActor* OwnerActor = GetOwner())
	{
		if (UStatComponent* StatComponent = OwnerActor->FindComponentByClass<UStatComponent>())
		{
			StatComponent->SetInvincible(false);
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("EndDodge Called"));
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

void UCombatComponent::OnDodgeMontageEnded(UAnimMontage* Montage, bool bInterrupted)
{
	if (Montage != DodgeMontage)
	{
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("Dodge Montage Ended. Interrupted: %s"),
		bInterrupted ? TEXT("true") : TEXT("false"));

	EndDodge();
}

