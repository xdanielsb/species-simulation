#ifndef _CLazy
#define _CLazy
#include"./IBehaviour.hpp"

/**
 * Implementation of behaviour Lazy
 *
 * When the number of animals around a lazy animal becomes too large,
 * it flees at high speed in the opposite direction before resuming
 * cruise speed.
 *
 *
 */
class LazyB: public Behaviour{
private:
  const double MINDIS = 5;
  const int MinAnimalChangeDirection = 4;
public:
    LazyB(){}
    ~LazyB(){}
    void move(Animal* a, vector<Animal*> listAnimals){
    	int beastInMyRegion=1;
    	for(Animal*  b:listAnimals){
          if( b->getId() == a->getId() )continue;
      		if(a->getDistance(  b->getPosition()) < MINDIS)
        		beastInMyRegion +=1;
    	}
    	if(beastInMyRegion > MinAnimalChangeDirection){
      	a->setDirX(a->getDirX()*-1);
				a->setDirY(a->getDirY()*-1);
    	}
    	if(isOutOfBoundaryX(a)) a->setDirX(a->getDirX()*-1);
  		if(isOutOfBoundaryY(a)) a->setDirY(a->getDirY()*-1);
      a->setPosX(a->getPosX()+a->getDirX() * a->getSpeed());
      a->setPosY(a->getPosY()+a->getDirY() * a->getSpeed());
      #ifdef DEBUG
    	 printf("->L{%.2f, %.2f}\n", a->getPosX(), a->getPosY());
      #endif
	}
	const double getMINDIS(){
		return this->MINDIS;
	}
};
#endif
