#include "./Accesory.hpp"
#ifndef _CFin
#define _CFin
class Fin: public Accesory{
private:
  double cspeed;
public:
  Fin( double _c): cspeed(_c){}
};
#endif
