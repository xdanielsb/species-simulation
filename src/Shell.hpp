#include "./Accesory.hpp"
class Shell: public Accesory{
private:
  double cdied;
  double cspeed;
public:
  Shell( double _c, double _d): cspeed(_c), cdied(_d){}
};
