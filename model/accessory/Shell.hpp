#ifndef _CShell
#define _CShell
#include "./Accessory.hpp"
class Shell: public Accessory{
private:
  double cdied;
  double cspeed;
public:
  ShellS( double died, double speed){
    this->cdied = died;
    this->cspeed = speed;
  }
  double getDied(){
    return this->cdied;
  }
  double getSpeed(){
    return this->cspeed;
  }
  ~ShellS(){}
};
#endif
