#ifndef _CAnimal
#define _CAnimal
class Animal{
private:
  int id;
  ii pos;
  ii dir;
public:
  Animal(){}
  Animal(int _id, ii _pos, ii _dir): id(_id), pos(_pos), dir(_dir){
    //printf("An animal with id = %d was created.\n", _id);
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

  ii getDirection(){
    return this->dir;
  }
  int getId() {
    return this->id;
  }
  double getDistance(const ii &a2){
      return hypot( this->pos.X - a2.X , this->pos.Y - a2.Y );
  }
  virtual void move(vector<Animal*> &neighbors){
    printf("Move of parent was called\n");
  };

  friend ostream& operator << (ostream &out, Animal *b) {
   out << "Animal #"<< b->getId() << " = { "<< b->getPosition().X <<", " << b->getPosition().Y << "}"<< endl;
   return out;
 }
};
#endif
