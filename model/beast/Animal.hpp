#ifndef _CAnimal
#define _CAnimal
class Animal{
private:
  int id;
  ii pos;
  ii dir;
  public:
  Animal(){}
  virtual ~Animal(){};
  ii getPosition(){
    return this->pos;
  }
  ii getDirection(){
    return this->dir;
  }
  int getIndex(){
    return this->id;
  }
};
#endif
