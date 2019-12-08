#ifndef _CFin
#define _CFin
#include "./Accesory.hpp"
class Fin: public Accesory{
private:
  double cspeed;
public:
  Fin( double _c): cspeed(_c){}
};
#endif
