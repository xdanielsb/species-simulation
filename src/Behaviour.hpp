#include<iterator>
#include<vector>
#include"./Beast.hpp"

using namespace std;

class Behaviour{
 public:
 virtual pair<pair< int, int >, pair< int, int >>  move(int index, pair< int, int > posActual, pair< int, int > dirActual, vector< Beast*> listBeast)  =0;
 ~Behaviour()= default;
};
