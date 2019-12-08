#include "./Accesory.hpp"
#ifndef _CShell
#define _CShell
class Shell: public Accesory{
private:
  double cdied;
  double cspeed;
public:
  Shell( double _c, double _d): cspeed(_c), cdied(_d){}
};
#endif
