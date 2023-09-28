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
	while (!checkIfDead()) {
		if (dieRoll(50)) {
			//#1 is first
			attack(Combatant1, Combatant2);
			if (checkIfDead()) {
				break;
			}
			attack(Combatant2, Combatant1);
			if (checkIfDead()) {
				break;
			}
		}
		else {
			//#2 is first
			attack(Combatant2, Combatant1);
			if (checkIfDead()) {
				break;
			}			
			attack(Combatant1, Combatant2);
			if (checkIfDead()) {
				break;
			}
		}
	}
} 

void ACombatManager::fightABunch(int32 fightCount)
{
	for (int i = 0; i < fightCount; i++) {
		Combatant1->resetHp();
		Combatant2->resetHp();
		fight();
	}
}

void ACombatManager::attack(ACombatant* attacker, ACombatant* defender) 
{
		if (!dieRoll(defender->getDodgeChance())) {
			//you hit
			if (dieRoll(attacker->getCritChance())) {
				//you crit
				attackOccurred(attacker, true, true, ((attacker->getCritEffect()) - defender->getDefence()));
				defender->setHp(defender->getHp() - (attacker->getCritEffect()) - defender->getDefence());
			}
			else {
				//you dont crit
				attackOccurred(attacker, true, false, ((attacker->getAtkEffect()) - defender->getDefence()));
				defender->setHp(defender->getHp() - (attacker->getAtkEffect() - defender->getDefence()));
			}
		}
		else {
			//you miss
			attackOccurred(attacker, false, false, 0);

		}


}

bool ACombatManager::dieRoll(int32 odds) {
	int roll = FMath::RandRange(1, 100);
	if (roll <= odds) {
		return true;
	}
	else {
		return false;
	}
}

bool ACombatManager::checkIfDead() {
	if (Combatant1->getHp() <= 0) {
		characterDied(Combatant1);
		return true;
	}
	else if (Combatant2->getHp() <= 0) {
		characterDied(Combatant2);
		return true;
	}
	else {
		return false;
	}
}



