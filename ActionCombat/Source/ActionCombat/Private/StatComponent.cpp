// Fill out your copyright notice in the Description page of Project Settings.


#include "StatComponent.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UStatComponent::UStatComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

float UStatComponent::ApplyDamage(float DamageAmount)
{
	if (bIsDead)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s is already dead. Damage ignored."),
			*GetOwner()->GetActorNameOrLabel());

		return 0.0f;
	}

	if (DamageAmount <= 0.0f)
	{
		return 0.0f;
	}

	const float PreviousHealth = CurrentHealth;

	CurrentHealth = FMath::Clamp(CurrentHealth - DamageAmount, 0.0f, MaxHealth);

	const float ActualDamage = PreviousHealth - CurrentHealth;

	UE_LOG(LogTemp, Warning, TEXT("%s took %.1f damage. HP: %.1f / %.1f"),
		*GetOwner()->GetActorNameOrLabel(),
		ActualDamage,
		CurrentHealth,
		MaxHealth);

	if (CurrentHealth <= 0.0f)
	{
		bIsDead = true;

		UE_LOG(LogTemp, Warning, TEXT("%s is dead."),
			*GetOwner()->GetActorNameOrLabel());
	}

	return ActualDamage;
}


// Called when the game starts
void UStatComponent::BeginPlay()
{
	Super::BeginPlay();

	CurrentHealth = MaxHealth;
	bIsDead = false;

	UE_LOG(LogTemp, Warning, TEXT("%s Stat Initialized. HP: %.1f / %.1f"),
		*GetOwner()->GetActorNameOrLabel(),
		CurrentHealth,
		MaxHealth);

	// ...
	
}


// Called every frame
void UStatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

