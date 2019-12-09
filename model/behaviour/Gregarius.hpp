#ifndef _CGregarius
#define _CGregarius
#include"./Behaviour.hpp"

using namespace std;

class Gregarius:public Behaviour{
public:
    void move(Animal* animal, vector<Animal*> listAnimals){
        float moyenDirX = 0;
        float moyenDirY = 0;
        int countAnimal =1;
	ii posSelf = animal->getPosition();

        for(auto ptr:listAnimals){

            ii posA = ptr->getPosition();   // not defind in the class beast, return type pair<int, int>
            ii dirA = ptr->getDirection();  // not defind in the class beast, return type pair<int, int>

            //To verify the beast is next to this beast or not and the range of detection is 30, variable count will count the number of beast in the range of detection
            if(sqrt((posA.X- posSelf.X)*(posA.X- posSelf.X)+(posA.Y- posSelf.Y)*(posA.Y- posSelf.Y))< 30) {
                countAnimal +=1;
                moyenDirX+=dirA.X;
                moyenDirY+=dirA.Y;
            }
        }
	countAnimal-=1;
        moyenDirX/=countAnimal;
        moyenDirY/=countAnimal;
        //change the direction
        animal->dir.X = moyenDirX;
        animal->dir.Y = moyenDirY;
        // change the position
        animal->pos.X+= animal->dir.X;
        animal->pos.Y+= animal->dir.Y;

    }
};
#endif
