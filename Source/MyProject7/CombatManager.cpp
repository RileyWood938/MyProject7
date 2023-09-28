// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatManager.h"

// Sets default values
ACombatManager::ACombatManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACombatManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACombatManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACombatManager::fight() 
{
	if (dieRoll(50)) {
		//#1 is first
		attack(Combatant1, Combatant2);
		checkIfDead();
		attack(Combatant2, Combatant1);
		checkIfDead();
	}
	else {
		//#2 is first
		attack(Combatant2, Combatant1);
		checkIfDead();
		attack(Combatant1, Combatant2);
		checkIfDead();
	}
}

void ACombatManager::attack(ACombatant attacker, ACombatant defender) 
{
		if (!dieRoll(defender->getDodgeChance())) {
			//you hit
			if (dieRoll(attacker->getCritChance())) {
				//you crit
				defender->setHp(defender->getHp() - (attacker->getCritEffect())- defender->getDefence());
			}
			else {
				//you dont crit
				defender->setHp(defender->getHp() - (attacker->getDamage()- defender->getDefence()));
			}
		}
		else {
			//you miss
		}


}

bool ACombatManager::checkIfDead() {
	if (Combatant1->getHp <= 0 || Combatant2->getHP <= 0) {
		return true;
	}
	else {
		return false;
	}
}

