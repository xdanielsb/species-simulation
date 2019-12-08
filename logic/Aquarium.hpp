#ifndef _CAquarium
#define _CAquarium
/*
 * Namespace and Dependencies
 */

using namespace std;

/*
 * New Types
 */

typedef pair< int, int > ii;

/*
 * Constants
 */
const double PI = acos(-1);

//#include"../model/beast//Beast.hpp"
//#include"../model/environment/Environment.hpp"



#include"./factory/FactoryBeast.hpp"
class Aquarium{
private:
  Environment *env;
  FactoryBeast *fac;
public:
  Aquarium(){
    this->fac = new FactoryBeast();
    //vector< Beast*> list_beast;
    //env = new Environment( list_beast );
  }
  void run(){
    bool ok = true;
    while( ok ){
      //ok &= env->step();
    }
  }
};
#endif
