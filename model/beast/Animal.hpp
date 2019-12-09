#ifndef _CAnimal
#define _CAnimal
class Animal{
private:
  int id;
  public:
  ii pos;
  ii dir;
  Animal(){}
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
