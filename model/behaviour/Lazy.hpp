#ifndef _CLazy
#define _CLazy
#include"./IBehaviour.hpp"

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
      		if(a->getDistance( b->getPosition()) < MINDIS) {
        		beastInMyRegion +=1;
		      }
    	}
    	if(beastInMyRegion > MinAnimalChangeDirection){
      	a->setDirX(a->getDirX()*-1);
				a->setDirY(a->getDirY()*-1);
    	}
    	if(isOutOfBoundaries(a)){
    		a->setDirX(a->getDirX()*-1);
				a->setDirY(a->getDirY()*-1);
    	}
    	a->setPosX(a->getPosX()+a->getDirX());
    	a->setPosY(a->getPosY()+a->getDirY());
    	printf("->L{%.2f, %.2f}\n", a->getPosX(), a->getPosY());
	}
	const double getMINDIS(){
		
		return this->MINDIS;
	}
};
#endif
