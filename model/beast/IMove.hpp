#ifndef _CMove
#define _CMove
#include"./Animal.hpp"
class IMove{
public:
  virtual void move(Animal *animal, vector<Animal> neighbors) =0;
};
#endif
