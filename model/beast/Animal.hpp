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
    printf("An animal with id = %d was created.\n", _id);
  }

  virtual ~Animal(){};
  ii getPosition() {
    return this->pos;
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
};
#endif
