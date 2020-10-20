#include<iostream>
#include <string>
#include "Elf.h"
#include "Warrior.h"
#include "Wizard.h"

using namespace std;

Warrior::Warrior(
	const string& name,
	const double& health,
	const double& attackStrength,
	string allegiance)
	:Character(WARRIOR, name, health, attackStrength), allegiance(allegiance)
{}
void Warrior::damage(double d)
{
	health = health - d;
}
void Warrior::attack(Character& opponent)
{
	double dmgDealt;
	if (opponent.getType() == WARRIOR)
	{
		Warrior& opp = dynamic_cast<Warrior&>(opponent);
		if (allegiance == opp.allegiance)
		{
			cout << "Warrior " << name << " does not attack Warrior " << opp.name << "." << endl;
			cout << "They share an allegiance with " << allegiance << "." << endl;
		}
		else
		{
			cout << "Warrior " << name << " attacks " << opp.name << " --- SLASH!!" << endl;
			dmgDealt = attackStrength * (health / MAX_HEALTH);
			cout << opp.name << " takes " << dmgDealt << " damage." << endl;
			opp.damage(dmgDealt);
		}
	}
	if(opponent.getType() == ELF)
	{
		Elf& opp = dynamic_cast<Elf&>(opponent);
		cout << "Warrior " << name << " attacks " << opp.getName() << " --- SLASH!!" << endl;
		dmgDealt = attackStrength * (health / MAX_HEALTH);
		cout << opp.getName() << " takes " << dmgDealt << " damage." << endl;
		opp.damage(dmgDealt);
	}
	if (opponent.getType() == WIZARD)
	{
		Wizard& opp = dynamic_cast<Wizard&>(opponent);
		cout << "Warrior " << name << " attacks " << opp.getName() << " --- SLASH!!" << endl;
		dmgDealt = attackStrength * (health / MAX_HEALTH);
		cout << opp.getName() << " takes " << dmgDealt << " damage." << endl;
		opp.damage(dmgDealt);
	}
}