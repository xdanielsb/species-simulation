#ifndef _CGregarius
#define _CGregarius
#include"./IBehaviour.hpp"

using namespace std;

class GregariusB:public Behaviour{
private:
  const double MINDIS = 5;
public:
  void move(Animal* a, vector<Animal*> list){
    double sumDirX = 0;
    double sumDirY = 0;
    int beastInMyRegion = 0;
    for(Animal *b:list){
      if( b->getId() == a->getId() )continue;
      if(a->getDistance( b->getPosition()) < MINDIS) {
        beastInMyRegion +=1;
        sumDirX+=b->getDirX();
        sumDirY+=b->getDirY();
      }
    }
    if( beastInMyRegion){
      a->setDirX(sumDirX / beastInMyRegion);
      a->setDirY(sumDirY / beastInMyRegion);
    }
  	if(isOutOfBoundaries(a)){
  		a->setDirX(a->getDirX()*-1);
  		a->setDirY(a->getDirY()*-1);
  	}
    a->setPosX(a->getPosX()+a->getDirX());
  	a->setPosY(a->getPosY()+a->getDirY());
  	printf("->G{%.2f, %.2f}\n", a->getPosX(), a->getPosY());
  }
};
#endif
