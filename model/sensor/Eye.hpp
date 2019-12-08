#include"./Sensor.hpp"

#ifndef _CEye
#define _CEye
class Eye: public: Sensor{
public:
  Eye( double _dist, double _deg): Sensor( _dist, _deg){
  }
};
#endif
