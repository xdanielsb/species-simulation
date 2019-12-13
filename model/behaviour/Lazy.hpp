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

  bool changeDirection(const Animal* a){
      float futurePositionX = a->pos.X += a->dir.X;
      float futurePositionY = a->pos.Y += a->dir.Y;
      if(futurePositionX<0 || futurePositionY<0 || futurePositionX > MaxX || futurePositionY > MaxY){
		return true;	
	}else{
		return false;	
	}
  }
public:
    LazyB(){}
    ~LazyB(){}
    void move(Animal* a, vector<Animal*> listAnimals){
    	int beastInMyRegion=1;
    	for(Animal*  b:listAnimals){
          if( b->getId() == a->getId() )continue;
      		if(getDistance( a->getPosition(), b->getPosition()) < MINDIS) {
        		beastInMyRegion +=1;
		      }
    	}
    	if(beastInMyRegion > MinAnimalChangeDirection){
      		a->dir.X *= -1;
      		a->dir.Y *= -1;
    	}
	if(changeDirection(a)){
		a->dir.X *= -1;
      		a->dir.Y *= -1;	
	}
    	a->pos.X += a->dir.X;
    	a->pos.Y += a->dir.Y;
      printf("->L{%.2f, %.2f}\n", a->pos.X, a->pos.Y);
	}
};
#endif
