//
// 2e3 lab3
// (c) 2010 Trinity College Dublin
//

#include "NPC.h"
#include <iostream>
using namespace std;

// Print out the character's statistics
void NPC::print()
{
	cout << "Alive? = " << m_alive << endl;
	cout << "Strength = " << m_strength << endl;
	cout << "Skill = " << m_skill << endl;
}

// Attack: roll a dice (6 sides), multiply result by
// strength and return this as an attack strength
int NPC::attack()
{
	int roll = 1 + rand()%6;
	cout << "attack strength: " << roll*m_skill <<endl;
	return roll*m_skill;
}

// Defend: take an attack strength, roll a dice (6 sides)
// multiply this by the character's strength and subject
// the result from the attack strength.  The remainder is
// subtracted from the character's strength.  The character
// dies if this falls below zero
void NPC::defend(int attack_strength)
{
	int roll = 1 + rand()%6;
	int damage = attack_strength - roll*m_skill;
	cout <<"damage suffered: " <<damage << endl;

	if(damage > 0)
	{
		m_strength = m_strength - damage;
	}

	if(m_strength <= 0)
	{ 
		m_strength = 0;
		m_alive = false;
	}
}

// Return a boolean indicating whether the character is
// still alive.
bool NPC::isAlive() const
{
	return m_alive;
}

void NPC::setIsAlive(bool a) 
{
	m_alive = a;
}
// Default constructor, will set strength and skill to
// a random value in the appropriate range.
NPC::NPC()
{
	m_alive = true;
	m_strength = 1 + rand()%50;
	m_skill = 1 + rand()%5;
}

// Constructor which specifies a starting strength and
// skill for the character
NPC::NPC(int strength, int skill)
: m_strength(strength), m_skill(skill), m_alive(true)
{
	// Nothing to do here.
}

int NPC::getSkill() const{
	return m_skill;
}
int NPC::getStrength() const{
	return m_strength;
}
void NPC::setSKill(int s){
	m_skill=s;

}
void NPC::setStrength(int s){
	m_strength=s;
}