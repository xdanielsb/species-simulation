#ifndef _CFin
#define _CFin
#include "./Accesory.hpp"
class Fin: public Accesory{
private:
  double cspeed;
public:
  Fin( double fin_limit){
    this->cspeed = rand() % (fin_limit-1) + 1;
  }
  ~Fin(){}
  double get_cspeed(){
    return this->cspeed;
  }
};
#endif
