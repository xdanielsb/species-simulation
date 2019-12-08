#ifndef _CBehaviour
#define _CBehaviour
#include"../beast/Animal.hpp"

using namespace std;

class Behaviour{
public:
 virtual auto move(int index, pair<float, float> posActual, pair<float, float> dirActual, vector<Beast*> listBeast);
 ~Behaviour() = default;
};
#endif
