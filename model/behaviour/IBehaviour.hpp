#ifndef _CBehaviour
#define _CBehaviour
#include"../beast/Animal.hpp"

using namespace std;

class Behaviour{
public:
 virtual auto move(int index, ii posActual, ii dirActual, vector<Beast*> listBeast);
 ~Behaviour() = default;
};
#endif
