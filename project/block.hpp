#ifndef _BLOCK_H_
#define _BLOCK_H_
#include "living.hpp"
#include "Terrain.hpp"





class Block
{
    private:
        Terrain* pterrain;
        living* pliving;
        int x,y;
    public:
        Block(string s)  {
            pterrain=new Terrain("grass");
            if(s=="werewolf"){
            pliving=new werewolf;
            }else if (s=="vampire")
            {
                pliving=new vampire;
            }else if (s=="avatarw")
            {
                pliving=new avatar("avatarw");
            }else if (s=="avatarv")
            {
                pliving=new avatar("avatarv");
            }else{
                pliving=new living;
                pliving->setName("");
            }
            
        };
        int getX(){
            return x;
        }
        int getY(){
            return y;
        }
        void setX(int xi){
            x=xi;
        }
        void setY(int yi){
            y=yi;
        }
        ~Block() {
            delete pliving;
            delete pterrain;
            
        };
        Terrain* getTerrain() {
            return pterrain;
        }
        void changeLiving(string s){
            delete pliving;
            if(s=="werewolf"){
                pliving=new werewolf;
            }if(s=="vampire"){
                pliving=new vampire;
            }if(s=="avatarw"){
                pliving=new avatar("avatarw");
            }if(s=="avatarv"){
                pliving=new avatar("avatarv");
            }if(s==""){
                pliving=new living();
                pliving->setName("");
                pliving->setArmor(0);
                pliving->setDamage(0);
                pliving->setPotion(0);
                pliving->setHealth(0);
            }

        }
        living* getLiving() {
            return pliving;
        }
        bool operator==(Block &other) {
            return (this == &other);
        }
};
#endif