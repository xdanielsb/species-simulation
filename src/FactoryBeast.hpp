#include <array>
#include <vector>
#include "Beast.hpp"

#ifndef FACTORYBEAST
#define FACTORYBEAST
 
class BeastFactory{

// TODO: put this in the parameters of the main program
/* DISTRIBUTION_OF_BEAST is an array which contains the probability 
*  of spawning each types of Beast.
*  Its sum should be equal to 1.0.
*  The indexes are referenced as follows: 
*  0:FarSightedBeast
*  1:GregariusBeast
*  2:KamikazeBeast
*  3:LazyBeast
*  4:MultiplePerson
*/ 
const std::array<double, 5> DISTRIBUTION_OF_BEASTS = {0.2, 0.2, 0.2, 0.2, 0.2};

static BeastFactory *factory;

/* Set the constructor to private 
*  because this class implements the Singleton design pattern
*/
BeastFactory() {
  

}

public:

  static BeastFactory *buildFactory() {
    if (!factory)
    factory = new BeastFactory();
    return factory;
  }

  /*
  Beast* newBeast(){

  }

  std::vector<Beast*> newPopulation(){
    
  }
  */

};

#endif
