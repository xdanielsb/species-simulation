#include<iterator>
#include<vector>
#include"./Beast.hpp"

using namespace std;
#ifndef _CBehaviour
#define _CBehaviour
class Behaviour{
 public:
 virtual pair<ii, ii>
      move( int index, ii posActual, ii dirActual, vector< Beast*> listBeast)  = 0;
 ~Behaviour()= default;
};
#endif
