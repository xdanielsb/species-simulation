#ifndef _CBeast
#define _CBeast
#include"../accesory/Accessory.hpp"
#include"../sensor/Sensor.hpp"
#include"../behaviour/IBehaviour.hpp"
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
  bool hasMultipleBehaviours;
  Behaviour *behaviour;

public:

  Beast(int _id, ii _pos, ii _dir):Animal(_id, _pos, _dir){
    //Animal(_id, _pos, _dir)
  }
  ~Beast(){}
  void addAccessory(Accessory *a){

  }
  void addSensor( Sensor* s){

  }
  void removeAccesory( Accessory *a){

  }
  void removeSensor(Sensor *s){

  }
  void move(vector<Animal*> &neighbors){
    this->behaviour->move( this, neighbors );
  }
  Beast* clone(){

  }
  bool checkCollition(){

  }
  void getOlder(){

  }
  void changePosition( ){

  }
  void changeDirection(){

  }
 // setters and getters
 void setBehavior( Behaviour *b ){
   this->behaviour = b;
 }

 friend ostream& operator << (ostream &out, Beast *b) {
  out << "Animal { id = "<< b->getId() << "}"<< endl;
  return out;
}

};
#endif
