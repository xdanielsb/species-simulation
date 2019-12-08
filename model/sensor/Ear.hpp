#include"./Sensor.hpp"

#ifndef _CEar
#define _CEar
class Ear: public: Sensor{
public:
  Ear( double _dist): Sensor( _dist, 2PI){
  }
};
#endif
