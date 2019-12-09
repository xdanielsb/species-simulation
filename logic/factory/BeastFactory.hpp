#ifndef _CBeastFactory
#define _CBeastFactory
#include"../../model/beast/Beast.hpp"
class BeastFactory{

  // TODO: put this in the parameters of the main program
  /* DISTRIBUTION_OF_BEAST is an array which contains the probability
  *  of spawning each types of Beast.
  *  Its sum should be equal to 1.0.
  *  The indexes of the behaviours are referenced as follows:
  *  0:FarSighted
  *  1:Gregariu
  *  2:Kamikaze
  *  3:Lazy
  *  4:MultipleBehaviour
  */
  const array<double, 5> DISTRIBUTION_OF_BEASTS = {0.2, 0.2, 0.2, 0.2, 0.2};

  static BeastFactory *factory;

  ~BeastFactory() {}

  public:

    static BeastFactory *buildFactory() {
      if (!factory)
      factory = new BeastFactory();
      return factory;
    }


    Beast* newBeast(){

    }

    vector<Beast*> newPopulation(){

    }

};
#endif
