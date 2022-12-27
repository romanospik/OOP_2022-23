#ifndef _MOVEMENT_H
#define _MOVEMENT_H


#include "map.hpp"
#include "block.hpp"

//this class handles the movement of trhe block in the map!
class Movement{
private:
public:

    Movement(){}
  
    void moveUp(Map* map,Block* block){
        int x=block->getX();
        int y=block->getY();
        string name=block->getLiving()->getName();
        int health=block->getLiving()->getHealth();
        int damage=block->getLiving()->getDamage();
        if(y-1>=0&&map->get(x,y-1)->getLiving()->getName()==""&&map->get(x,y-1)->getTerrain()->getName()=="grass"){
        map->get(x,y-1)->changeLiving(name);
        map->get(x,y-1)->getLiving()->setHealth(health);
        map->get(x,y-1)->getLiving()->setDamage(damage);
        map->get(x,y-1)->setX(x);
        map->get(x,y-1)->setY(y-1);
        map->get(x,y)->changeLiving("");
        }else{}
        
    }
    void moveUpLeft(Map* map,Block* block){
        int x=block->getX();
        int y=block->getY();
        string name=block->getLiving()->getName();
        int health=block->getLiving()->getHealth();
        int damage=block->getLiving()->getDamage();
        if(y-1>=0&&x-1>=0&&map->get(x-1,y-1)->getLiving()->getName()==""&&map->get(x-1,y-1)->getTerrain()->getName()=="grass"){
        map->get(x-1,y-1)->changeLiving(name);
        map->get(x-1,y-1)->getLiving()->setHealth(health);
        map->get(x-1,y-1)->getLiving()->setDamage(damage);
        map->get(x-1,y-1)->setX(x-1);
        map->get(x-1,y-1)->setY(y-1);
        map->get(x,y)->changeLiving("");
        }else{}
        
    }
    void moveUpRight(Map* map,Block* block){
        int x=block->getX();
        int y=block->getY();
        int health=block->getLiving()->getHealth();
        int damage=block->getLiving()->getDamage();
        string name=block->getLiving()->getName();
        if(y-1>=0&&x+1<map->getWx()&&map->get(x+1,y-1)->getLiving()->getName()==""&&map->get(x+1,y-1)->getTerrain()->getName()=="grass"){
        map->get(x+1,y-1)->changeLiving(name);
        map->get(x+1,y-1)->getLiving()->setHealth(health);
        map->get(x+1,y-1)->getLiving()->setDamage(damage);
        map->get(x+1,y-1)->setX(x+1);
        map->get(x+1,y-1)->setY(y-1);
        map->get(x,y)->changeLiving("");
        }else{

        }
        
    }
    void moveDownLeft(Map* map,Block* block){
        int x=block->getX();
        int y=block->getY();
        string name=block->getLiving()->getName();
        int health=block->getLiving()->getHealth();
        int damage=block->getLiving()->getDamage();
        if(y+1<map->getWy()-1 && x-1>=0&&map->get(x-1,y+1)->getLiving()->getName()=="" && map->get(x-1,y+1)->getTerrain()->getName()=="grass"){
        map->get(x-1,y+1)->changeLiving(name);
        map->get(x-1,y+1)->getLiving()->setHealth(health);
        map->get(x-1,y+1)->getLiving()->setDamage(damage);
        map->get(x-1,y+1)->setX(x-1);
        map->get(x-1,y+1)->setY(y+1);
        map->get(x,y)->changeLiving("");
        }else{}
        
    }
    void moveDownRight(Map* map,Block* block){
        int x=block->getX();
        int y=block->getY();
        string name=block->getLiving()->getName();
        int health=block->getLiving()->getHealth();
        int damage=block->getLiving()->getDamage();
        if(y+1<map->getWy()-1&&x+1<map->getWx()-1&&map->get(x+1,y+1)->getLiving()->getName()==""&&map->get(x+1,y+1)->getTerrain()->getName()=="grass"){
        map->get(x+1,y+1)->changeLiving(name);
        map->get(x+1,y+1)->getLiving()->setHealth(health);
        map->get(x+1,y+1)->getLiving()->setDamage(damage);
        map->get(x+1,y+1)->setX(x+1);
        map->get(x+1,y+1)->setY(y+1);
        map->get(x,y)->changeLiving("");
        }else{}
        
    }
    void moveDown(Map* map,Block* block){
        int x=block->getX();
        int y=block->getY();
        string name=block->getLiving()->getName();
        int health=block->getLiving()->getHealth();
        int damage=block->getLiving()->getDamage();
        if(y+1<map->getWy()&&map->get(x,y+1)->getLiving()->getName()==""&&map->get(x,y+1)->getTerrain()->getName()=="grass"){
        map->get(x,y+1)->changeLiving(name);
        map->get(x,y+1)->getLiving()->setHealth(health);
        map->get(x,y+1)->getLiving()->setDamage(damage);
        map->get(x,y+1)->setX(x);
        map->get(x,y+1)->setY(y+1);
        map->get(x,y)->changeLiving("");
        }else{}
        
    }
    void moveRight(Map* map,Block* block){
        int x=block->getX();
        int y=block->getY();
        string name=block->getLiving()->getName();
        int health=block->getLiving()->getHealth();
        int damage=block->getLiving()->getDamage();
        if(x+1<map->getWx()&&map->get(x+1,y)->getLiving()->getName()==""&&map->get(x+1,y)->getTerrain()->getName()=="grass"){
        map->get(x+1,y)->changeLiving(name);
        map->get(x+1,y)->getLiving()->setHealth(health);
        map->get(x+1,y)->getLiving()->setDamage(damage);
        map->get(x+1,y)->setX(x+1);
        map->get(x+1,y)->setY(y);
        map->get(x,y)->changeLiving("");
        }else{}
        
    }
    void moveLeft(Map* map,Block* block){
        int x=block->getX();
        int y=block->getY();
        string name=block->getLiving()->getName();
        int health=block->getLiving()->getHealth();
        int damage=block->getLiving()->getDamage();
        if(x-1>=0&&map->get(x-1,y)->getLiving()->getName()==""&&map->get(x-1,y)->getTerrain()->getName()=="grass"){
        map->get(x-1,y)->changeLiving(name);
        map->get(x-1,y)->getLiving()->setHealth(health);
        map->get(x-1,y)->getLiving()->setDamage(damage);
        map->get(x-1,y)->setX(x-1);
        map->get(x-1,y)->setY(y);
        map->get(x,y)->changeLiving("");}
        else{}
        
    }

    ~Movement(){}

};














#endif