#ifndef _VAMPIRE_H
#define _VAMPIRE_H

#include <cstring>
#include <iostream>

#include "living.hpp"
#include"werewolf.hpp"
using namespace std;

class vampire : public living
{
private:

public:
	
	// constructor
	vampire()
	{
		setName("vampire");
		int i=rand()% 1+4;
		setDamage(i);
		i=rand()%1+3;
		setArmor(i);
		i=rand()%+3;
		setPotion(i);
	}
	
	void attack(living* v){
		v->decrease_health(getDamage());
	}

	
	// destructor
	virtual ~vampire()
	{

	}


};
#endif