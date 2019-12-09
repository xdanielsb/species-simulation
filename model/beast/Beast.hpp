#ifndef _CBeast
#define _CBeast
#include"./IMove.hpp"
#include"../accesory/Accessory.hpp"
#include"../sensor/Sensor.hpp"
#include"../behaviour/IBehaviour.hpp"
class Beast: public IMove, public Animal{
private:

  int current_age;
  int max_age;
  double camouflage;
  double perception_ear;
  double perception_eye;
  double speed;
  double resistance;
  vector< Sensor* > sensors;
  vector< Accessory*> accesories;
  bool hasMultipleBehaviours;
  Behaviour *behaviour;

public:

  Beast(){}
  ~Beast(){}
  void addAccessory(Accessory *a){

  }
  void addSensor( Sensor* s){

  }
  void removeAccesory( Accessory *a){

  }
  void removeSensor(Sensor *s){

  }
  void move(){
    vector< Animal*> neighbors;
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

};
#endif
