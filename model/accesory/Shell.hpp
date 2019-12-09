#ifndef _CShell
#define _CShell
#include "./Accesory.hpp"
class Shell: public Accesory{
private:
  double cdied;
  double cspeed;
public:
  Shell( double resistance_limit, double speed_limit){
    this->cdied = rand() % (resistance_limit-1) + 1;
    this->cspeed = rand() % (speed_limit-1) + 1;
  }

  double get_cdied(){
    return this->cdied;
  }

  double get_cspeed(){
    return this->cspeed;
  }

  ~Shell(){}
};
#endif
