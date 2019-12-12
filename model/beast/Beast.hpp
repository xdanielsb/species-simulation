#ifndef _CBeast
#define _CBeast
#include"../accesory/Accessory.hpp"
#include"../sensor/Sensor.hpp"
#include"../behaviour/IBehaviour.hpp"
#include"../behaviour/Lazy.hpp"
#include"../behaviour/Kamikaze.hpp"
#include"../behaviour/Gregarius.hpp"
#include"../behaviour/Farsighted.hpp"

#include <iomanip>
class Beast: public Animal{
private:
  int age;
  int maxAge;
  double camouflage;
  double perceptionEar;
  double perceptionEye;
  double speed;
  double resistance;
  vector< Sensor* > sensors;
  vector< Accessory*> accesories;
  bool idBehaviour;
  Behaviour *behaviour;
public:
  Beast(int _id, ii _pos, ii _dir, int _idBehaviour):Animal(_id, _pos, _dir), idBehaviour(_idBehaviour){
   // TODO : Factory of Behaviours
    this->age = 0;
    if( _idBehaviour == 0){
      this->behaviour = new FarsightedB();
    }else if( _idBehaviour == 1){
      this->behaviour = new GregariusB();
    }else if( _idBehaviour == 2){
      this->behaviour = new KamikazeB();
    }else if( _idBehaviour == 3){
      this->behaviour = new LazyB();
    }else if( _idBehaviour == 4){ //this can change
      this->behaviour = new FarsightedB();
    }
  }
  ~Beast(){}
  void addAccessory(Accessory *a){
    this->accesories.push_back( a );
  }
  void addSensor( Sensor* s){
    this->sensors.push_back( s );
  }
  void move(vector<Animal*> &neighbors){
    cout << setprecision(2) << fixed << "\tMoving "<< this ;
    this->behaviour->move( this, neighbors );
  }
  Beast* clone(){

  }
  void getOlder(){
    this->age++;
  }
  void setBehavior( Behaviour *b ){
    this->behaviour = b;
  }
  friend ostream& operator << (ostream &out, Beast *b) {
    out << "Animal #"<< b->getId() << " = {"<< b->getPosition().X <<", " << b->getPosition().Y << "}";
    return out;
  }

};
#endif
