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
#include <memory>

class Beast: public Animal{
private:
  double camouflage;
  double perceptionEar;
  double perceptionEye;
  double speed;
  double resistance;
  vector< Sensor* > sensors;
  vector< Accessory*> accesories;
  shared_ptr<Behaviour> behaviour;
public:
  Beast(int _id, ii _pos, ii _dir, shared_ptr<Behaviour> b):Animal(_id, _pos, _dir) {
    b.swap(behaviour);
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
    return new Beast( *this);
  }
  void setBehavior( shared_ptr<Behaviour> b ){
    this->behaviour = b;
  }
  friend ostream& operator << (ostream &out, Beast *b) {
    out << "Animal #"<< b->getId() << " = {"<< b->getPosition().X <<", " << b->getPosition().Y << "}";
    return out;
  }

};
#endif
