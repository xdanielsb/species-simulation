#include"./Beast.hpp"
#include"./Environment.hpp"
#include"./FactoryBeast.hpp"
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
