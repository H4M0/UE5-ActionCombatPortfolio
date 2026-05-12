// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CombatComponent.generated.h"

// Forward declaration to avoid including the entire header for UAnimMontage, AActor
class UAnimMontage;
class AActor;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ACTIONCOMBAT_API UCombatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCombatComponent();

	void StartAttack();
	void EndAttack();

	void BeginAttackTrace();
	void PerformAttackTrace();
	void EndAttackTrace();

	void StartDodge();
	void EndDodge();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	bool bIsAttacking = false;
	bool bIsAttackTraceActive = false;
	bool bIsDodging = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combat|Attack", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UAnimMontage> AttackMontage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combat|Dodge", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UAnimMontage> DodgeMontage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combat", meta = (AllowPrivateAccess = "true", ClampMin = "0.0"))
	float AttackDamage = 20.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combat", meta = (AllowPrivateAccess = "true", ClampMin = "0.0"))
	float AttackRange = 150.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combat", meta = (AllowPrivateAccess = "true", ClampMin = "0.0"))
	float AttackRadius = 60.0f;

	TSet<AActor*> HitActorsThisAttack;

	void OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted);
	void OnDodgeMontageEnded(UAnimMontage* Montage, bool bInterrupted);
};
