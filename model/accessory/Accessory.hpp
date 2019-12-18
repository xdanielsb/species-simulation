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
  virtual double getSpeed(){
    return 0;
  };
};
#endif
