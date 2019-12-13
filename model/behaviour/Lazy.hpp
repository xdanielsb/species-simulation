#ifndef _CLazy
#define _CLazy
#include"./IBehaviour.hpp"

class LazyB: public Behaviour{
private:
  const double MINDIS = 5;
  const int MinAnimalChangeDirection = 4;
  double getDistance(const ii &a1, const ii &a2){
      return hypot( a1.X - a2.X , a1.Y - a2.Y );
  }
public:
    LazyB(){}
    ~LazyB(){}
    void move(Animal* a, vector<Animal*> listAnimals){
    	int beastInMyRegion=1;
    	for(Animal*  b:listAnimals){
          if( b->getId() == a->getId() )continue;
      		if(a->getDistance(  b->getPosition()) < MINDIS) {
        		beastInMyRegion +=1;
		      }
    	}
    	if(beastInMyRegion > MinAnimalChangeDirection){
      	a->setDirX(a->getDirX()*-1);
				a->setDirY(a->getDirY()*-1);
    	}
    	if(isOutOfBoundaryX(a)){
				a->setDirX(a->getDirX()*-1);
			}
  		if(isOutOfBoundaryY(a)){
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
