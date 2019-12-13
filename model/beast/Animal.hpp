#ifndef _CAnimal
#define _CAnimal

class Animal{
private:
  int id;
  ii pos;
  ii dir;
  int age;
  int maxAge;
  bool hasMultipleBehaviours;
public:
  Animal(){}
  Animal(int _id, ii _pos, ii _dir): id(_id), pos(_pos), dir(_dir){
    //printf("An animal with id = %d was created.\n", _id);
    this->age = 0;
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

  friend ostream& operator << (ostream &out, Animal *b) {
   out << "Animal #"<< b->getId()
       << " = { "<< b->getPosition().X
       << ", " << b->getPosition().Y
       << "}"<< endl;
   return out;
 }
};
#endif
