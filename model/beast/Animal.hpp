#ifndef _CAnimal
#define _CAnimal
class Animal{
private:
  int id;
public:
  ii pos;
  ii dir;
  Animal(){}
  Animal(int _id, ii _pos, ii _dir): id(_id), pos(_pos), dir(_dir){
    //printf("An animal with id = %d was created.\n", _id);
  }
  virtual ~Animal(){};
  ii getPosition() {
    return this->pos;
  }
  float getPosX(){
    return this->pos.X;
  }
  float getPosY(){
    return this->pos.Y;
  }
  float getDirX(){
    return this->dir.X;
  }
  float getDirY(){
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
  virtual void move(vector<Animal*> &neighbors){
    printf("Move of parent was called\n");
  };

  friend ostream& operator << (ostream &out, Animal *b) {
   out << "Animal #"<< b->getId() << " = { "<< b->getPosition().X <<", " << b->getPosition().Y << "}"<< endl;
   return out;
 }
};
#endif
