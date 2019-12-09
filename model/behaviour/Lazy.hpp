
#ifndef _CLazy
#define _CLazy
#include"./Behaviour.hpp"

using namespace std;

class Lazy:public Behaviour{
public:
    void move(Animal* animal, vector<Animal*> listAnimals){
    	int countAnimal=1;
	ii posSelf = animal->getPosition();
    	for(auto ptr:listAnimals){
		
      		ii posA = ptr->getPosition(); 

      		//To verify the beast is next to this beast or not and the range of detection is 30, variable count will count the number of beast in the range of detection
      		if(sqrt((posA.X- posSelf.X)*(posA.X- posSelf.X)+(posA.Y- posSelf.Y)*(posA.Y- posSelf.Y))< 30) {
        		countAnimal +=1;
		}
    	}
    //Set the alert number equals to 3(3+1+1(himself)), if the number of beast around is bigger than this value, the beast will change the direction to the opposite one.
    	if(countAnimal<=5){

    	}else{
      		animal->dir.X = -animal->dir.X;
      		animal->dir.Y = -animal->dir.Y;
    	}
    	// change the position
    	animal->pos.X+= animal->dir.X;
    	animal->pos.Y+= animal->dir.Y;


	}
};
#endif
