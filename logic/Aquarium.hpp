/*
 * New Types
 */

typedef pair< int, int > ii;

/*
 * Constants
 */

const double 2PI = acos(-1) * 2.;
/*
 * Dependencies
 */
using namespace std;
#include"./factory/FactoryBeast.hpp"
#include"../../model/beast//Beast.hpp"
#include"../../model/environment/Environment.hpp"


#ifndef _CAquarium
#define _CAquarium
class Aquarium{
private:
  Environment *env;
  FactoryBeast *fac;
public:
  Aquarium(){
    fac = new FactoryBeast();
    vector< Beast*> list_beast;
    env = new Environment( list_beast );
  }
  void run(){
    bool ok = true;
    while( ok ){
      ok &= env->step();
    }
  }
};
#endif
