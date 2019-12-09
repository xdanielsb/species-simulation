#ifndef _CAquarium
#define _CAquarium
/*
 * Namespace
 */

using namespace std;

/*
 * New Types
 */

typedef pair< float, float > ii;

/*
 * Constants
 */
const double PI = acos(-1);

/*
 * Depenedencies
 */

#include"../model/environment/Environment.hpp"
//#include"../model/beast//Beast.hpp"



#include"./factory/BeastFactory.hpp"
class Aquarium{
private:
  BeastFactory *fac;
  Environment *env;
public:
  Aquarium(){
    //this->fac = new FactoryBeast();
    //vector< Beast*> list_beast;
    //env = new Environment( list_beast );
  }
  void run(){
    //bool ok = true;
    //while( ok ){
      //ok &= env->step();
    //}
  }
};
#endif
