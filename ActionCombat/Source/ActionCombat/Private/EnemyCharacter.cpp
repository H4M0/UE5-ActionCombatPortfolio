// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCharacter.h"
#include "StatComponent.h"
#include "Animation/AnimMontage.h"

// Sets default values
AEnemyCharacter::AEnemyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	StatComponent = CreateDefaultSubobject<UStatComponent>(TEXT("StatComponent"));
}

// Called when the game starts or when spawned
void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	if (StatComponent)
	{
		StatComponent->OnDamageTaken.AddDynamic(this, &AEnemyCharacter::HandleDamageTaken);
	}
}

// Called every frame
void AEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemyCharacter::HandleDamageTaken(float DamageAmount, float CurrentHealth, float MaxHealth)
{
	UE_LOG(LogTemp, Warning, TEXT("%s Hit Reaction. Damage: %.1f, HP:%.1f / %.1f"),
		*GetActorNameOrLabel(),
		DamageAmount,
		CurrentHealth,
		MaxHealth);

	if (HitReactionMontage)
	{
		PlayAnimMontage(HitReactionMontage);
	}
}

