#ifndef _CBeast
#define _CBeast
#include"../accessory/Accessory.hpp"
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
/**
 * Initer an instance of beast and his father class is Animal.
 *
 * @param _id int the id of the beast
 * @param _pos pair<float, float> the position of the beast
 * @param _dir pair<float, float> the moving direction of the beast
 * @param b shared_ptr<Behaviour> the behaviour of the beast
 */
  Beast(int _id, ii _pos, ii _dir, shared_ptr<Behaviour> b):Animal(_id, _pos, _dir) {
    b.swap(behaviour);
  }
  ~Beast(){}
  /**
  * Add accessories to the beast
  *
  * @param *a pointer of the accessory which will be equiped to the beast
  */
  void addAccessory(Accessory *a){
    this->accesories.push_back( a );
  }
  /**
  * Add sensors to the beast
  *
  * @param *a pointer of the sensor which will be equiped to the beast
  */
  void addSensor( Sensor* s){
    this->sensors.push_back( s );
  }

  /**
  * The beast will use this fonction to move
  *
  * @param neighbors a vector of animals that exists in the simulation
  */
  void move(vector<Animal*> &neighbors){
    #ifdef DEBUG
      cout << setprecision(2) << fixed << "\tMoving "<< this ;
    #endif
    this->behaviour->move( this, neighbors );
  }
  /// The beast will clone himself
  Beast* clone(){
    return new Beast( *this);
  }
  void setBehavior( int type ){
  //  this->behaviour = b;
  }
   /**
   * Print the info of the beast, ID and position actual
   *
   * @param b a pointer of beast
   */
  friend ostream& operator << (ostream &out, Beast *b) {
    out << "Animal #"<< b->getId() << " = {"<< b->getPosition().X <<", " << b->getPosition().Y << "}";
    return out;
  }

};
#endif
