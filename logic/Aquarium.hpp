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
 * Constants and defines
 */
const double PI = acos(-1);
#define first X
#define second Y

/*
 * Enum types
 */
 enum BEHAVIOURS{
   FarSighted         = 0,
   Gregariu           = 1,
   Kamikaze           = 2,
   Lazy               = 3,
   MultipleBehaviour  = 4
 };

/*
 * Depenedencies
 */
#include"../model/environment/Environment.hpp"
#include"../model/beast//Beast.hpp"



#include"./factory/BeastFactory.hpp"
class Aquarium{
private:
  BeastFactory *fac;
  Environment *env;
public:
  Aquarium(){
    this->fac = new BeastFactory();
    //Animal *a = new Animal(1, {1,1}, {1,1});
    Beast *a = new Beast(1, {1,1}, {1,1});
    //vector< Beast*> list_beast = this->fac->newPopulation();
    //env = new Environment( list_beast );
  }
  void* run(){
    //bool ok = true;
    //while( ok ){
      //ok &= env->step();
    //}
  }
};
#endif
