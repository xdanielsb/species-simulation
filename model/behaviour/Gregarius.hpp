#ifndef _CGregarius
#define _CGregarius
#include"./Behaviour.hpp"

using namespace std;

class Gregarius:public Behaviour{
public:
    void move(Animal *animal, vector<Animal*> listBeast){
        float moyenDirX = 0;
        float moyenDirY = 0;
        int count =0;

        for(auto ptr=listBeast.begin(); ptr!=listBeast.end(); ptr++){

            ii posA = ptr->getPosition();   // not defind in the class beast, return type pair<int, int>
            ii dirA = ptr->getDirection();  // not defind in the class beast, return type pair<int, int>

            //To verify the beast is next to this beast or not and the range of detection is 30, variable count will count the number of beast in the range of detection
            if(sqrt((posA.first- posActual.first)*(posA.first- posActual.first)+(posA.second- posActual.second)*(posA.second- posActual.second))< 30) {
                count +=1;
                moyenDirX+=dirA.first;
                moyenDirY+=dirA.second;
            }
        }
        moyenDirX/=count;
        moyenDirY/=count;
        //change the direction
        dirActual.first = moyenDirX;
        dirActual.second = moyenDirY;
        // change the position
        animal.posActual.first+=dirActual.first;
        animal.posActual.second+=dirActual.second;

    }
};
#endif
