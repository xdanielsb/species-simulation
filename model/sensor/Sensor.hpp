#ifndef _CSensor
#define _CSensor
class Sensor{
private:
  double distance;
  double degree;
public:
  virtual Sensor() = 0;
};
#endif
