
#ifndef _CEar
#define _CEar
#include"./Sensor.hpp"
class Ear: public: Sensor{
public:
  Ear( double _dist): Sensor( _dist, PI * 2){
  }
};
#endif
