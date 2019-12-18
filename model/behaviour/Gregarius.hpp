#ifndef _CGregarius
#define _CGregarius
#include"./IBehaviour.hpp"

using namespace std;

/**
 * Implementation of behaviour Gregarius
 *
 * A Gregarius animal adjusts its direction to the average direction
 * of the surroundings.
 *
 *
 */
class GregariusB:public Behaviour{
private:
  const double MINDIS = 5;
  double getDistance(const ii &a1, const ii &a2){
      return hypot( a1.X - a2.X , a1.Y - a2.Y );
  }
public:
    void move(Animal* a, vector<Animal*> list){
        double sumDirX = 0;
        double sumDirY = 0;
        int beastInMyRegion = 0;
        for(Animal *b:list){
            if( b->getId() == a->getId() )continue;
            if(a->getDistance(b->getPosition()) < MINDIS) {
                beastInMyRegion +=1;
                sumDirX+=b->getDirX();
                sumDirY+=b->getDirY();
            }
        }
        if( beastInMyRegion){
         a->setDirX(sumDirX / beastInMyRegion);
         a->setDirY(sumDirY / beastInMyRegion);
        }
        if(isOutOfBoundaryX(a)) a->setDirX(a->getDirX()*-1);
        if(isOutOfBoundaryY(a)) a->setDirY(a->getDirY()*-1);
        a->setPosX(a->getPosX()+a->getDirX() * a->getSpeed());
      	a->setPosY(a->getPosY()+a->getDirY() * a->getSpeed());
        #ifdef CLI
      	 printf("->G{%.2f, %.2f}\n", a->getPosX(), a->getPosY());
        #endif
    }
};
#endif
