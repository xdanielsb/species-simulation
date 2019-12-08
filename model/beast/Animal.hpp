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
  // @author lei
  ii getPosition(){
    return this->pos;
  }
  // @author lei
  ii getDirection(){
    return this->dir;
  }
  // @author lei
  int getIndex(){
    return this->id;
  }
};
#endif
