#include"./Cloneable.hpp"
#ifndef _CBeast
#define _CBeast
class Beast: public Cloneable{
private:
  ii pos;
  ii dir;
  int current_age;
  int max_age;
  double camouflage;
  double perception_ear;
  double perception_eye;
  double speed;
  double resistance;
  vector< Sensor* > sensors;
  vector< Accesory*> accesories;
  bool isMP;
  Behaviour behaviour;

  int index;  // @author lei

public:
  void addAccessory(Accesory *a){

  }
  void addSensor( Sensor* s){

  }
  void removeAccesory( Accesory *a){

  }
  void removeSensor(Sensor *s){

  }
  void move(){

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

  // @author lei
  pair<int ,int> getPosition(){
    return this->pos;
  }
  // @author lei
  pair<int, int> getDirection(){
    return this->dir;
  }
  // @author lei
  int getIndex(){
    return this->index;
  }

};
#endif
