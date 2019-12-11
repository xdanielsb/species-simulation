#ifndef _CBehaviour
#define _CBehaviour
#include"../beast/Animal.hpp"
#include<vector>

using namespace std;

class Behaviour{
public:
 virtual void move(Animal* animal, vector<Animal*> listAnimals) = 0;
 virtual ~Behaviour() {};
};
#endif
