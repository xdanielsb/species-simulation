#ifndef _CFin
#define _CFin
#include "./Accessory.hpp"
class Fin: public Accessory{
private:
  double cspeed;
public:
  FinS( double speed){
    this->cspeed = speed;
  }
  ~FinS(){}
  double getSpeed(){
    return this->cspeed;
  }
};
#endif
