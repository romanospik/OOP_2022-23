#ifndef _MAP_H_
#define _MAP_H_


#include <cstring>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <string>
#include "avatar.hpp"
#include "werewolf.hpp"
#include "vampire.hpp"
#include "living.hpp"
using namespace std;


#include "Terrain.hpp"
#include "block.hpp"
//this class has all the data of the map and prints them
class Map {
    private:int worldx,worldy;
    vector<Block*> world;
  public: 
  //constructor
     Map(int x,int y) : worldx(x), worldy(y) {
        world.resize(x*y);
        int size=world.size();
        for(int i=0;i<size;i++){
            world[i]=new Block("");
        }
    
        
    }
    vector<Block*> getWorld(){
        return world;
    }

    Block* get(int x, int y) {
        return world.at(x+(y*worldx));
    }
    
    int getWx(){
        return worldx;
    }
    int getWy(){
        return worldy;
    }
    // this function  prints the map;
    void print(){
       for(int i=0;i<worldy;i++)
       {
           for(int j=0;j<worldx;j++)
           {

                Block* b = get(j,i);
                if (b->getLiving()->getName()=="vampire"&&b->getTerrain()->getName()=="grass") 
                {
                    cout<<"[v]";
                }
                else if (b->getLiving()->getName()=="werewolf"&&b->getTerrain()->getName()=="grass")
                {
                    cout<<"[w]";
                }else if(b->getLiving()->getName()=="avatarw"&&b->getTerrain()->getName()=="grass")
                {
                    cout<<"[W]";
                }else if(b->getLiving()->getName()=="avatarv"&&b->getTerrain()->getName()=="grass")
                {
                    cout<<"[V]";
                }else if(b->getTerrain()->getName()=="tree")
                {
                    cout<<"[T]";
                }else if(b->getTerrain()->getName()=="lake")
                {
                    cout<<"[L]";
                }else
                {
                    cout<<"[ ]";
                }
                

           }     
           cout<<endl;
        
        }
    }
    //destructor
    ~Map(){

      int size=world.size();
        for(int i=0;i<size;i++){
            delete world[i];
            
        }
    }
};


#endif