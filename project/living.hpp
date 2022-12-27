#ifndef _LIVING_H
#define _LIVING_H

#include <cstring>
#include <iostream>


using namespace std;

class living
{
private:
    int health;
    int damage;
    int armor;
    int potion;
    string name;
public:
    // constructor
    living(){
        setHealth(2);
        
    }

	void setHealth(int a){
		health=a;
	}
	int  getHealth(){
		return health;
	}
    void setPotion(int a){
		potion=a;
	}
	int  getPotion(){
		return potion;
	}
    void setDamage(int a){
		damage=a;
	}
    void setArmor(int a){
		armor=a;
	}
	int  getArmor(){
		return armor;
	}
	int  getDamage(){
		return damage;
	}
    string getName(){
		return name;
	}
    void setName(string s){
		name=s;
	}

    virtual void increase_health(int c)
    {

        health = health + c;
    }
    void attack(living* v){
		v->decrease_health(getDamage()-getArmor());
	}
    void decrease_health(const int c)
    {
        
        if (health >= c){

            health -= c;
        }

        else{

            health = 0;
        }
    }



    // destructor
   virtual ~living(){}

};

#endif