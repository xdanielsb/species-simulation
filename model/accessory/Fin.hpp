#ifndef _CFin
#define _CFin
#include "./Accessory.hpp"

/**
 * Implementation of Fin
 *
 * The fins allow the equipped animal to move faster by applying 
 * a multiplier coefficient ν∈ [1; νmax] at the speed of the 
 * creature. The constructeur is used to initier an instance of 
 * fin and "getSpeed" is used to get the caracter of the fin.
 *
 * 
 */
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
