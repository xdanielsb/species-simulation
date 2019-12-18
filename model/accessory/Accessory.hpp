#ifndef _CAccessory
#define _CAccessory

/**
 * Implementation of Accessory
 *
 *
 */
class Accessory{
public:
  Accessory(){}
  virtual ~Accessory(){}
  virtual double getSpeed() = 0;
};
#endif
