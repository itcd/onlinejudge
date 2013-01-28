//
// 2e3 lab3
// (c) 2010 Trinity College Dublin
//

#pragma once

class NPC
{
private:
	bool m_alive;		// Is the character still alive?
	int m_strength;		// 0 to 50
	int m_skill;		// 0 to 5
public:
	// Print out the character's statistics

	int getSkill() const;
	int getStrength() const;
	void setSKill(int s);
	void setStrength(int s);
	

	void print();

	// Attack: roll a dice (6 sides), multiply result by
	// skill and return this as an attack strength
	int attack();

	// Defend: take an attack strength, roll a dice (6 sides)
	// multiply this by the character's strength and subtract
	// the result from the attack strength.  The remainder is
	// subtracted from the character's strength.  The character
	// dies if this falls below zero
	void defend(int attack_strength);

	// Return a boolean indicating whether the character is
	// still alive.
	bool isAlive() const;
	void setIsAlive(bool a);

	// Default constructor, will set strength and skill to
	// a random value in the appropriate range.
	NPC();

	// Constructor which specifies a starting strength and
	// skill for the character
	NPC(int strength, int skill);
};