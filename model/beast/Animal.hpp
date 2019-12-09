#ifndef _CAnimal
#define _CAnimal
class Animal{
private:
  int id;
  ii pos;
  ii dir;
  public:
  Animal(int _id, ii _pos, ii _dir): id(_id), pos(_pos), dir(_dir){}
  virtual ~Animal(){};
  ii getPosition(){
    return this->pos;
  }
  ii getDirection(){
    return this->dir;
  }
  int getId(){
    return this->id;
  }
};
#endif
