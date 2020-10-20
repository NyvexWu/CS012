#include<iostream>
#include <string>
#include "Elf.h"
#include "Warrior.h"
#include "Wizard.h"

using namespace std;

Wizard::Wizard(
	const string& name,
	const double& health,
	const double& attackStrength,
	int rank)
	:Character(WIZARD, name, health, attackStrength), rank(rank)
{}
void Wizard::damage(double d)
{
	health = health - d;
}
void Wizard::attack(Character& opponent)
{
	double dmgDealt;
	if (opponent.getType() == WIZARD)
	{
		Wizard& opp = dynamic_cast<Wizard&>(opponent);
		cout << "Wizard " << name << " attacks " << opp.name << " --- POOF!!" << endl;
		dmgDealt = (rank / (double)opp.rank) * attackStrength;
		cout << opp.name << " takes " << dmgDealt << " damage." << endl;
		opp.damage(dmgDealt);
	}
	if (opponent.getType() == WARRIOR)
	{
		Warrior& opp = dynamic_cast<Warrior&>(opponent);
		cout << "Wizard " << name << " attacks " << opp.getName() << " --- POOF!!" << endl;
		cout << opp.getName() << " takes " << attackStrength << " damage." << endl;
		opp.damage(attackStrength);
	}
	if (opponent.getType() == ELF)
	{
		Elf& opp = dynamic_cast<Elf&>(opponent);
		cout << "Wizard " << name << " attacks " << opp.getName() << " --- POOF!!" << endl;
		cout << opp.getName() << " takes " << attackStrength << " damage." << endl;
		opp.damage(attackStrength);
	}
}