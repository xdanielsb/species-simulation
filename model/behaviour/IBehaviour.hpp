#ifndef _CBehaviour
#define _CBehaviour
#include"./Beast.hpp"
class Behaviour{
 public:
 virtual pair<ii, ii>
      move( int index, ii posActual, ii dirActual, vector< Beast*> listBeast)  = 0;
 ~Behaviour()= default;
};
#endif
