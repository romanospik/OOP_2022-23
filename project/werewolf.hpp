#ifndef _WEREWOLF_H
#define _WEREWOLF_H

#include <cstring>
#include <iostream>
#include "vampire.hpp"
#include "living.hpp"

using namespace std;

class werewolf : public living
{
private:

public:
	
	// constructor
	werewolf(){
		setName("werewolf");
		int i=rand()% 1+4;
		setDamage(i);
		i=rand()%1+3;
		setArmor(i);
		i=rand()%+3;
		setPotion(i);
	}
	
	

	// destructor
	virtual ~werewolf(){}


};
#endif