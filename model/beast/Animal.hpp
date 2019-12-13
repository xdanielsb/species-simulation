#ifndef _CAnimal
#define _CAnimal
#include"../../include/CImg.h"
using namespace cimg_library;
typedef unsigned char        T;
typedef CImg<T>            UImg;
class Animal{
private:
  int id;
  ii pos;
  ii dir;
  int age;
  int maxAge;
  bool hasMultipleBehaviours;
   T               * color;

const double      AFF_SIZE = 8.;
const double      MAX_VITESSE = 10.;
const double      LIMITE_VUE = 30.;
public:
  Animal(){}
  Animal(int _id, ii _pos, ii _dir): id(_id), pos(_pos), dir(_dir){
    this->age = 0;
    color = new T[ 3 ];
    color[ 0 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
    color[ 1 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
    color[ 2 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
  }
  virtual ~Animal(){};
  ii getPosition() {
    return this->pos;
  }
  float getPosX() const{
    return this->pos.X;
  }
  float getPosY() const{
    return this->pos.Y;
  }
  float getDirX() const{
    return this->dir.X;
  }
  float getDirY() const{
    return this->dir.Y;
  }
  void setPosX(float posX){
    this->pos.X = posX;
  }
  void setPosY(float posY){
    this->pos.Y = posY;
  }
  void setDirX(float dirX){
    this->dir.X = dirX;
  }
  void setDirY(float dirY){
    this->dir.Y = dirY;
  }
  int getAge() const {
    return this->age;
  }
  void getOlder(){
    this->age++;
  }
  void setMaxAge( int m){
    this->maxAge = m;
  }
  int getMaxAge( ) const{
    return this->maxAge;
  }
  ii getDirection(){
    return this->dir;
  }
  int getId() {
    return this->id;
  }
  void invertDirection(){
    this->dir.X *= -1;
    this->dir.Y *= -1;
  }
  double getDistance(const ii &a2){
      return hypot( this->pos.X - a2.X , this->pos.Y - a2.Y );
  }
  virtual void move(vector<Animal*> &neighbors){
    printf("Move of parent was called\n");
  };
  void sethasMultipleBehaviours( bool flag ){
    this->hasMultipleBehaviours = flag;
  }

  bool gethasMultipleBehaviours() const {
    return this->hasMultipleBehaviours;
  }
  virtual void setBehavior( int type) = 0;

  virtual Animal* clone() = 0;

  void draw( UImg &u ){
   double orientation = this->getDirX() != 0 ? atan(-this->getDirY()/this->getDirX()): .0;
   debug( orientation );
   double         xt = this->getPosX() + cos( orientation )*AFF_SIZE/2.1;
   double         yt = this->getPosY() - sin( orientation )*AFF_SIZE/2.1;
   u.draw_ellipse( this->getPosX(), this->getPosY(), AFF_SIZE, AFF_SIZE/5., -orientation/M_PI*180., this->color );
   u.draw_circle(  this->getPosX(), this->getPosY(), 4, this->color );
  }
  friend ostream& operator << (ostream &out, Animal *b) {
   out << "Animal #"<< b->getId()
       << " = { "<< b->getPosition().X
       << ", " << b->getPosition().Y
       << "}"<< endl;
   return out;
 }
};
#endif
