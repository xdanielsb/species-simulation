#include"./Sensor.hpp"
const double 2PI= 2*acos(-1);
class Ear: public: Sensor{
public:
  Ear( double _dist): Sensor( _dist, 2PI){
  }
};
