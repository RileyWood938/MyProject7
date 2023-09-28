// Fill out your copyright notice in the Description page of Project Settings.


#include "Combatant.h"

// Sets default values
ACombatant::ACombatant()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACombatant::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACombatant::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int32 ACombatant::getHp()
{
	return hp;
}
int32 ACombatant::getAtkEffect()
{
	return atkEffect;
}
int32 ACombatant::getDefence()
{
	return defence;
}
int32 ACombatant::getDodgeChance()
{
	return dodgeChance;
}int32 ACombatant::getCritChance()
{
	return critChance;
}int32 ACombatant::getCritEffect()
{
	return critEffect;
}

void ACombatant::setHp(int32 newHp) {
	hp = newHp;
}

