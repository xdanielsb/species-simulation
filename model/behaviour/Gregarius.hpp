#ifndef _CGregarius
#define _CGregarius
#include"./IBehaviour.hpp"

using namespace std;

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
            if(getDistance(a->getPosition(), b->getPosition()) < MINDIS) {
                beastInMyRegion +=1;
                sumDirX+=b->dir.X;
                sumDirY+=b->dir.Y;
            }
        }
        if( beastInMyRegion){
         a->dir.X = sumDirX / beastInMyRegion;
         a->dir.Y = sumDirY / beastInMyRegion;
        }
	if(isOutOfBoundaries(a)){
		a->dir.X *= -1;
      		a->dir.Y *= -1;
	}
        a->pos.X+= a->dir.X;
        a->pos.Y+= a->dir.Y;
        printf("->G{%.2f, %.2f}\n", a->pos.X, a->pos.Y);
    }
};
#endif
