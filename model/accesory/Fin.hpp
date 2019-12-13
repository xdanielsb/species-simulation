#ifndef _CFin
#define _CFin
#include "./Accessory.hpp"
class Fin: public Accessory{
private:
  double cspeed;
public:
  Fin( double fin_limit){
    this->cspeed = fmod(rand(),(fin_limit-1)) + 1;
  }
  ~Fin(){}
  double get_cspeed(){
    return this->cspeed;
  }
};
#endif
