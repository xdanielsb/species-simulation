#ifndef _CBehaviour
#define _CBehaviour
#include"../beast/Animal.hpp"

using namespace std;

class Behaviour{
public:
 virtual void move(Animal *animal, vector<Animal*> listBeast);
 ~Behaviour() = default;
};
#endif
