#ifndef _CAnimal
#define _CAnimal
class Animal{
private:
  int id;
  pair<float, float> pos;
  pair<float, float> dir;
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
