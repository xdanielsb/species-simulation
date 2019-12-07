#include"./Cloneable.hpp"
class Beast: public Cloneable{
private:
  pair< int, int > pos;
  pair< int, int > dir;
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

};
