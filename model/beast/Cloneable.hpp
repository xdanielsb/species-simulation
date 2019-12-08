#ifndef _CCloneable
#define _CCloneable
#include"./Beast.hpp"
class Cloneable{
  virtual Beast* clone()=  0;
};
#endif
