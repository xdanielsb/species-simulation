#ifndef _CBehaviour
#define _CBehaviour
#include"../beast/Animal.hpp"
class Behaviour{
 public:
 virtual ii move( Animal *animal, vector< Animal*> neighbors);
 ~Behaviour() = default;
};
#endif
