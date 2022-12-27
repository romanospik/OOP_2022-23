#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string> 
#include<vector>
#include "map.hpp"
#include "Movement.hpp"
#include <random>
using namespace std;



int main(){
    string ch;

    cout<<"please select team by typing either 'w' for werewolf or 'v' for vampire! "<<endl;
    cin>>ch;
    string sib=ch;
    while(1){

    if(sib=="w"){
        cout<<"you have selected the werewolf team!"<<endl;
        cout<<"       OOOoooowwWWwWwWww!!!"<<endl;
        break;
    }else if(sib=="v"){
        cout<<"you have selected the vampire team!"<<endl;
        cout<<"       *bat sounds*!!!"<<endl;
        break;
    }else{
        cout<<"please select either werewolf or vampire!!";
    }
    
   }



    cout<<"please enter x and then y of the map,only nummbers allowed...otherwise your PC explodes "<<endl;
    int coords;
    cin>>coords;
    int x=coords;
    cin>>coords;
    int y=coords;
    cout<<endl;

    Map* map=new Map(x,y);
    // puts werewolves on random blocks in the map
    
    int wolfs=0;
    for(int i=0;i<(x*y)/15;i++){
        int z=rand()% (x-1);
        int l=rand()% (y-1);
        if(map->get(z,l)->getTerrain()->getName()=="grass"&&map->get(z,l)->getLiving()->getName()==""){
                map->get(z,l)->changeLiving("werewolf");
                map->get(z,l)->setX(z);
                map->get(z,l)->setY(l);    
                wolfs++;
        }
    }
    
    // puts trees on random blocks in the map
    
    for(int i=0;i<(x*y)/15;i++){
        int z=rand()% x;
        int l=rand()% y;

        if(map->get(z,l)->getTerrain()->getName()=="grass"&&map->get(z,l)->getLiving()->getName()==""){
            map->get(z,l)->getTerrain()->setName("tree");
            map->get(z,l)->setX(z);
            map->get(z,l)->setY(l);
        }
    }
    // puts vampires on random blocks in the map
    int vamps=0;
    for(int i=0;i<(x*y)/15;i++){
       int z=rand()% x;
       int l=rand()% y;

       if(map->get(z,l)->getTerrain()->getName()=="grass"&&map->get(z,l)->getLiving()->getName()==""){
            map->get(z,l)->changeLiving("vampire");
            map->get(z,l)->setX(z);
            map->get(z,l)->setY(l);
            vamps++;
        }
    }
    // puts lakes on random blocks in the map

       for(int i=0;i<(x*y)/15;i++){
        int z=rand()% x;
        int l=rand()% y;
            
        if(map->get(z,l)->getTerrain()->getName()=="grass"&&map->get(z,l)->getLiving()->getName()==""){
            map->get(z,l)->getTerrain()->setName("lake");
            map->get(z,l)->setX(z);
            map->get(z,l)->setY(l);
        }
    }
        string input;
        string day="day";
        Movement* mov=new Movement;
        int xi=rand()%x;
        int yi=rand()%y;
        int r;
        int p=0;
    while(1){
        // we add the avatar in the map
        if(map->get(xi,yi)->getLiving()->getName()==""&&map->get(xi,yi)->getTerrain()->getName()=="grass"){
        if(sib=="w"){map->get(xi,yi)->changeLiving("avatarw");
        map->get(xi,yi)->setX(xi);
        map->get(xi,yi)->setY(yi);}
        else if(sib=="v"){
        map->get(xi,yi)->changeLiving("avatarv");
        map->get(xi,yi)->setX(xi);
        map->get(xi,yi)->setY(yi);

        }
        break;
        }
    else{
        xi=rand()%x;
        yi=rand()%y;
    }
    }

    map->get(map->getWx()-1,map->getWy()-1)->getTerrain()->setName("lake");
    while(1){
        //default message of the game
        cout<<"to move up press 'W'"<<endl<<"to move down press 'S'"<<endl<<"to move right press 'D'"<<endl<<"to move left press 'A'"<<endl<<"for map press'M'"<<endl<<"for info press 'i'"<<endl<<"to end the game press 'q'"<<endl;
        cin>>input;
        if(input=="h"){
        cout<<"to move up press 'W'"<<endl<<"to move down press 'S'"<<endl<<"to move right press 'D'"<<endl<<"to move left press 'A'"<<endl<<"for map press'M'"<<endl<<"for info press 'i'"<<endl;
}
        //if you press'p' you heal the team you support
        if (input=="p"){
            if(map->get(xi,yi)->getLiving()->getName()=="avatarw"&&map->get(xi,yi)->getLiving()->getPotion()>0){
                 for(int i=0;i<map->getWy();i++){
                    for(int j=0;j<map->getWx();j++){
                        if(map->get(j,i)->getLiving()->getName()=="werewolf"&&day=="night"){
                            map->get(j,i)->getLiving()->increase_health(1);
                            map->get(xi,yi)->getLiving()->setPotion(0);
                        }
                    }
                }
                            cout<<"all werewolves were healed!"<<endl;
                }
            if(map->get(xi,yi)->getLiving()->getName()=="avatarv"&&map->get(xi,yi)->getLiving()->getPotion()>0){
                 for(int i=0;i<map->getWy();i++){
                    for(int j=0;j<map->getWx();j++){
                        if(map->get(j,i)->getLiving()->getName()=="werewolf"&&day=="day"){
                            map->get(j,i)->getLiving()->increase_health(1);
                            map->get(xi,yi)->getLiving()->setPotion(0);
                        }
                    }
                }
                            cout<<"all vampires were healed!"<<endl;
            }
        }
        //if you press 'i' you get the info of the game!
        if(input=="i"){
            cout<< "number of vampires : "<<vamps<<endl<<"number of werewolfs: "<<wolfs<<endl;
            cout<<"number of potions: "<<map->get(xi,yi)->getLiving()->getPotion()<<endl<<endl;

        }
        //if you press 'w' you go up
        if(input=="w"){

            if(yi-1>=0&&map->get(xi,yi-1)->getLiving()->getName()==""&&map->get(xi,yi-1)->getTerrain()->getName()=="grass"){
                mov->moveUp(map,map->get(xi,yi));
                yi-=1;
            }

        }
        //if you press 's' you go down
        if(input=="s"){

            if(yi+1<map->getWy()&&map->get(xi,yi+1)->getLiving()->getName()==""&&map->get(xi,yi+1)->getTerrain()->getName()=="grass"){
                mov->moveDown(map,map->get(xi,yi));
                
                yi+=1;
            }
        }
        //if you press 'a' you go left
        if(input=="a"){

            if(xi-1>=0&&map->get(xi-1,yi)->getLiving()->getName()==""&&map->get(xi-1,yi)->getTerrain()->getName()=="grass"){
                mov->moveLeft(map,map->get(xi,yi));
                xi-=1;
            }

        }
        //if you press 'd' you go right
        if(input=="d"){
            
            if(xi+1<map->getWx()&&map->get(xi+1,yi)->getLiving()->getName()==""&&map->get(xi+1,yi)->getTerrain()->getName()=="grass"){
                mov->moveRight(map,map->get(xi,yi));
                xi+=1;
            }
        }
        //if you press 'q' the game ends
        if(input=="q"){
            cout<<"Thank you for playing the game"<<endl;
            break;
        }
        // if you press 'm' you can see the map
        if(input=="m"){
        map->print();
            
        }
        //random movements of the game creatures
        for(int i=0;i<map->getWy();i++){
            for(int j=0;j<map->getWx();j++)
            {
                if(map->get(j,i)->getLiving()->getName()=="werewolf"){
                    r=rand()%4;
                    if(r==0){
                    if(i-1>=0&&map->get(j,i-1)->getLiving()->getName()==""&&map->get(j,i-1)->getTerrain()->getName()=="grass"){
                        mov->moveUp(map,map->get(j,i));
                    }}else if (r==1)
                    {
                        if(j+1<map->getWx()&&map->get(xi+1,yi)->getLiving()->getName()==""&&map->get(j+1,i)->getTerrain()->getName()=="grass"){             
                        mov->moveRight(map,map->get(j,i));
                        if(j+1<map->getWx()){j++;}}
                    }else if (r==2)
                    {
                        if(i+1<map->getWy()-1&&map->get(j,i+1)->getLiving()->getName()==""&&map->get(j,i+1)->getTerrain()->getName()=="grass"){
                        mov->moveDown(map,map->get(j,i));}
                    }else if (r==3)
                    {   
                        if(j-1>=0&&map->get(j-1,i)->getLiving()->getName()==""&&map->get(j-1,i)->getTerrain()->getName()=="grass"){
                        mov->moveLeft(map,map->get(j,i));}
                    }}
                    if(map->get(j,i)->getLiving()->getName()=="vampire"){
                    r=rand()%8;
                    if(r==0){
                        if(i-1>=0&&map->get(j,i-1)->getLiving()->getName()==""&&map->get(j,i-1)->getTerrain()->getName()=="grass"){
                        mov->moveUp(map,map->get(j,i));}
                    }else if (r==1)
                    {
                        if(j+1<map->getWx()&&map->get(xi+1,yi)->getLiving()->getName()==""&&map->get(j+1,i)->getTerrain()->getName()=="grass"){
                        mov->moveRight(map,map->get(j,i));
                        if(j+1<map->getWx()){j++;}}
                        
                    }else if (r==2)
                    {
                        if(i+1<map->getWy()-1&&map->get(j,i+1)->getLiving()->getName()==""&&map->get(j,i+1)->getTerrain()->getName()=="grass"){
                        mov->moveDown(map,map->get(j,i));}

                    }else if (r==3)
                    {   
                        if(j-1>=0&&map->get(j-1,i)->getLiving()->getName()==""&&map->get(j-1,i)->getTerrain()->getName()=="grass"){
                        mov->moveLeft(map,map->get(j,i));}
                    }
                    else if (r==4)
                    {
                        if(j-1>=0&&i-1>=0&&map->get(j-1,i-1)->getLiving()->getName()==""&&map->get(j-1,i-1)->getTerrain()->getName()=="grass"){
                        mov->moveUpLeft(map,map->get(j,i));}
                    }
                    else if (r==5)
                    {
                        if(j+1<map->getWx()-1&&i-1>0&&map->get(j+1,i-1)->getLiving()->getName()==""&&map->get(j+1,i-1)->getTerrain()->getName()=="grass"){
                        mov->moveUpRight(map,map->get(j,i));}
                    }
                    else if (r==6)
                    {   
                        if((i+1)<(map->getWy()-1)&&(j+1)<(map->getWx()-1)&&map->get(j+1,i+1)->getLiving()->getName()==""&&map->get(j+1,i+1)->getTerrain()->getName()=="grass"){
                        mov->moveDownRight(map,map->get(j,i));
                        }
                    }
                    else if (r==7)
                    {   
                        if(i<(map->getWy()-1)&&j-1>0&&map->get(j-1,i+1)->getLiving()->getName()==""&&map->get(j-1,i+1)->getTerrain()->getName()=="grass"){
                        mov->moveDownLeft(map,map->get(j,i));}
                    }
                    
                    }
                    
                }
        //random actions of the game creatres
        for(int i=0;i<map->getWy();i++){
            for(int j=0;j<map->getWx();j++)
            {
                if(map->get(j,i)->getLiving()->getName()=="werewolf"){
                    if(i-1>0){
                        if(map->get(j,i-1)->getLiving()->getName()=="werewolf"){
                            int k =rand()%1;
                            if(k==0){
                                if(map->get(j,i)->getLiving()->getHealth()>1&&map->get(j,i)->getLiving()->getPotion()>1){
                                map->get(j,i-1)->getLiving()->increase_health(1);
                                map->get(j,i)->getLiving()->decrease_health(1);
                                map->get(j,i)->getLiving()->setPotion(map->get(j,i)->getLiving()->getPotion()-1);
                                }
                            }

                        }
                    if(map->get(j,i-1)->getLiving()->getName()=="vampire"){
                            int k =rand()%1;
                            if(k==0){
                                
                                map->get(j,i)->getLiving()->attack(map->get(j,i-1)->getLiving());
                                if(map->get(j,i-1)->getLiving()->getHealth()==0){
                                    map->get(j,i-1)->changeLiving("");
                                    vamps--;
                                }
                                }
                            }
                    }

                        if(j+1<map->getWx()-1){
                        if(map->get(j+1,i)->getLiving()->getName()=="werewolf"){
                            int k =rand()%1;
                            if(k==0){
                                if(map->get(j,i)->getLiving()->getHealth()>1&&map->get(j,i)->getLiving()->getPotion()>1){
                                map->get(j+1,i)->getLiving()->increase_health(1);
                                map->get(j,i)->getLiving()->decrease_health(1);
                                map->get(j,i)->getLiving()->setPotion(map->get(j,i)->getLiving()->getPotion()-1);
                                }
                            }

                        }
                    if(map->get(j+1,i)->getLiving()->getName()=="vampire"){
                            int k =rand()%1;
                            if(k==0){
                                
                                map->get(j,i)->getLiving()->attack(map->get(j+1,i)->getLiving());
                                if(map->get(j+1,i)->getLiving()->getHealth()==0){
                                    map->get(j+1,i)->changeLiving("");
                                    vamps--;
                                }
                                }
                    }
                    }
                    if(i+1<map->getWy()-1){
                        if(map->get(j,i+1)->getLiving()->getName()=="werewolf"){
                            int k =rand()%1;
                            if(k==0){
                                if(map->get(j,i)->getLiving()->getHealth()>1&&map->get(j,i)->getLiving()->getPotion()>1){
                                map->get(j,i+1)->getLiving()->increase_health(1);
                                map->get(j,i)->getLiving()->decrease_health(1);
                                map->get(j,i)->getLiving()->setPotion(map->get(j,i)->getLiving()->getPotion()-1);
                                }
                            }

                        }
                    if(map->get(j,i+1)->getLiving()->getName()=="vampire"){
                            int k =rand()%1;
                            if(k==0){
                                
                                map->get(j,i)->getLiving()->attack(map->get(j,i+1)->getLiving());
                                if(map->get(j,i+1)->getLiving()->getHealth()==0){
                                    map->get(j,i+1)->changeLiving("");
                                    vamps--;
                                }
                                }
                    }
                    }
                    if(j-1>0){
                        if(map->get(j-1,i)->getLiving()->getName()=="werewolf"){
                            int k =rand()%1;
                            if(k==0){
                                if(map->get(j,i)->getLiving()->getHealth()>1&&map->get(j,i)->getLiving()->getPotion()>1){
                                map->get(j-1,i)->getLiving()->increase_health(1);
                                map->get(j,i)->getLiving()->decrease_health(1);
                                map->get(j,i)->getLiving()->setPotion(map->get(j,i)->getLiving()->getPotion()-1);
                                }
                            }

                        }
                    if(map->get(j-1,i)->getLiving()->getName()=="vampire"){
                            int k =rand()%1;
                            if(k==0){
                                
                                map->get(j,i)->getLiving()->attack(map->get(j-1,i)->getLiving());
                                if(map->get(j-1,i)->getLiving()->getHealth()==0){
                                    map->get(j-1,i)->changeLiving("");
                                    vamps--;
                                }
                                }
                    }
                    }
                        }
                if(map->get(j,i)->getLiving()->getName()=="vampire"){
                    if(i-1>0){
                        if(map->get(j,i-1)->getLiving()->getName()=="vampire"){
                            int k =rand()%1;
                            if(k==0){
                                if(map->get(j,i)->getLiving()->getHealth()>1&&map->get(j,i)->getLiving()->getPotion()>1){
                                map->get(j,i-1)->getLiving()->increase_health(1);
                                map->get(j,i)->getLiving()->decrease_health(1);
                                map->get(j,i)->getLiving()->setPotion(map->get(j,i)->getLiving()->getPotion()-1);
                                }
                            }

                        }
                    if(map->get(j,i-1)->getLiving()->getName()=="werewolf"){
                            int k =rand()%1;
                            if(k==0){
                                
                                map->get(j,i)->getLiving()->attack(map->get(j,i-1)->getLiving());
                                if(map->get(j,i-1)->getLiving()->getHealth()==0){
                                    map->get(j,i-1)->changeLiving("");
                                    wolfs--;
                                }
                                }
                            }
                    }

                        if(j+1<map->getWx()-1){
                        if(map->get(j+1,i)->getLiving()->getName()=="vampire"){
                            int k =rand()%1;
                            if(k==0){
                                if(map->get(j,i)->getLiving()->getHealth()>1&&map->get(j,i)->getLiving()->getPotion()>1){
                                map->get(j+1,i)->getLiving()->increase_health(1);
                                map->get(j,i)->getLiving()->decrease_health(1);
                                map->get(j,i)->getLiving()->setPotion(map->get(j,i)->getLiving()->getPotion()-1);
                                }
                            }

                        }
                    if(map->get(j+1,i)->getLiving()->getName()=="werewolf"){
                            int k =rand()%1;
                            if(k==0){
                                
                                map->get(j,i)->getLiving()->attack(map->get(j+1,i)->getLiving());
                                if(map->get(j+1,i)->getLiving()->getHealth()==0){
                                    map->get(j+1,i)->changeLiving("");
                                    wolfs--;
                                }
                                }
                    }
                    }
                    if(i+1<map->getWy()){
                        if(map->get(j,i+1)->getLiving()->getName()=="vampire"){
                            int k =rand()%1;
                            if(k==0){
                                if(map->get(j,i)->getLiving()->getHealth()>1&&map->get(j,i)->getLiving()->getPotion()>1){
                                map->get(j,i+1)->getLiving()->increase_health(1);
                                map->get(j,i)->getLiving()->decrease_health(1);
                                map->get(j,i)->getLiving()->setPotion(map->get(j,i)->getLiving()->getPotion()-1);
                                }
                            }

                        }
                    if(map->get(j,i+1)->getLiving()->getName()=="werewolf"){
                            int k =rand()%1;
                            if(k==0){
                                
                                map->get(j,i)->getLiving()->attack(map->get(j,i+1)->getLiving());
                                if(map->get(j,i+1)->getLiving()->getHealth()==0){
                                    map->get(j,i+1)->changeLiving("");
                                    wolfs--;
                                }
                                }
                    }
                    }
                    if(j-1>0){
                        if(map->get(j-1,i)->getLiving()->getName()=="vampire"){
                            int k =rand()%1;
                            if(k==0){
                                if(map->get(j,i)->getLiving()->getHealth()>1&&map->get(j,i)->getLiving()->getPotion()>1){
                                map->get(j-1,i)->getLiving()->increase_health(1);
                                map->get(j,i)->getLiving()->decrease_health(1);
                                map->get(j,i)->getLiving()->setPotion(map->get(j,i)->getLiving()->getPotion()-1);
                                }
                            }

                        }
                    if(map->get(j-1,i)->getLiving()->getName()=="werewolf"){
                            int k =rand()%1;
                            if(k==0){
                                
                                map->get(j,i)->getLiving()->attack(map->get(j-1,i)->getLiving());
                                if(map->get(j-1,i)->getLiving()->getHealth()==0){
                                    map->get(j-1,i)->changeLiving("");
                                    wolfs--;
                                }
                                }
                    }
                    }
                        }


                        

                        
                }
        }
      }
           //game end conditions
    if (vamps==0){
        cout<<"werewolves won!"<<endl;
        break;
    }
    if (wolfs==0){
        cout<<"vampires won!"<<endl;
        break;
    }
    //night day exchange
    if(p%5==0){
        if(day=="day"){
        day="night";
        cout<<"it is night now"<<endl;
        }
        else if(day=="night"){
            day="day";
        cout<<"it is day now"<<endl;

        }
    }
    
    p++;

    }
  
    
   
           delete mov;
           delete map;   
}