#include<iostream>
#include <string>
#include "Elf.h"
#include "Warrior.h"
#include "Wizard.h"
using namespace std;

Elf::Elf(
		 const string& name,
		 const double& health,
		 const double& attackStrength,
		 string family)
	:Character(ELF, name, health, attackStrength),family(family)
{}
void Elf::damage(double d)
{
	health = health - d;
}
void Elf::attack(Character& opponent) 
{
	double dmgDealt;
	if (opponent.getType() == ELF)
	{
		Elf& opp = dynamic_cast<Elf&>(opponent);
		if (family == opp.family)
		{
			cout << "Elf " << name << " does not attack Elf " << opp.name << "." << endl;
			cout << "They are both members of the " << family << " family." << endl;
		}
		else
		{
			cout << "Elf " << name << " shoots an arrow at " << opp.name << " --- TWANG!!" << endl;
			dmgDealt = attackStrength * (health / MAX_HEALTH);
			cout << opp.name << " takes " << dmgDealt << " damage." << endl;
			opp.damage(dmgDealt);
		}
	}
	if (opponent.getType() == WARRIOR)
	{
		Warrior& opp = dynamic_cast<Warrior&>(opponent);
		cout << "Elf " << name << " shoots an arrow at " << opponent.getName() << " --- TWANG!!" << endl;
		dmgDealt = attackStrength * (health / MAX_HEALTH);
		cout << opp.getName() << " takes " << dmgDealt << " damage." << endl;
		opp.damage(dmgDealt);
	}
	if (opponent.getType() == WIZARD)
	{
		Wizard& opp = dynamic_cast<Wizard&>(opponent);
		cout << "Elf " << name << " shoots an arrow at " << opponent.getName() << " --- TWANG!!" << endl;
		dmgDealt = attackStrength * (health / MAX_HEALTH);
		cout << opp.getName() << " takes " << dmgDealt << " damage." << endl;
		opp.damage(dmgDealt);
	}
}