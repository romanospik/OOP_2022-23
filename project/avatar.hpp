#ifndef _AVATAR_H
#define _AVATAR_H

#include <cstring>
#include <iostream>
#include <string.h>
#include <vector>
#include "living.hpp"



using namespace std;

class avatar : public living
{

public:
    // constructor
    avatar(string s){
        int i=rand()%5;
        setPotion(i);
        if(s=="avatarw"){
            setName("avatarw");
        }else if(s=="avatarv"){
            setName("avatarv");
        }
    }
    // destructor
   virtual ~avatar(){


   }
};
#endif