#ifndef _TERRAIN_H_
#define _TERRAIN_H_
#include <cstring>
#include <iostream>

using namespace std;


//this class describes the type of terrain in each block of the map

class Terrain 
{
private:
    string name;
public:
    // constructor
    Terrain(string s) : name(s)
    {
    }
    void setName(string s){
        name=s;
    }

    string getName(){
        return name;
    }

    

    // destructor
    virtual ~Terrain(){

       
    }
};

#endif