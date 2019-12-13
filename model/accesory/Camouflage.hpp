#ifndef _CCamouflage
#define _CCamouflage
#include "./Accessory.hpp"
class Camouflage: public Accessory{
private:
  double ccamouflage;
public:
  Camouflage( int cam_limit_min, int cam_limit_max){
    this->ccamouflage = rand() % (cam_limit_max - cam_limit_min) + cam_limit_min;
  }
  double get_ccamouflage(){
    return this->ccamouflage;
  }
  ~Camouflage(){}
};
#endif
