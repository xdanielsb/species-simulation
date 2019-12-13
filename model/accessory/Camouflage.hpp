#ifndef _CCamouflage
#define _CCamouflage
#include "./Accessory.hpp"
class CamouflageS: public Accessory{
private:
  double ccamouflage;
public:
  CamouflageS(double camouflage){
		this->ccamouflage = camouflage;
  }
  double getCamouflage(){
    return this->ccamouflage;
  }
  ~CamouflageS(){}
};
#endif
