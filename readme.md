# Beast Collider

This is a simulation of a game in c++, in which each beast can have Possible  Behaviours,
accessories and sensors.

#### Types
```c++
enum BEHAVIOURS{
  FARSIGTHED         = 0,
  GREGARIU           = 1,
  KAMIKAZE           = 2,
  LAZY               = 3,
  MULTIPLEBEHAVIOUR  = 4
};
enum ACCESSORY{
  CAMOUFLAGE  = 0,
  FIN         = 1,
  SHELL       = 2,
};
enum SENSOR{
  EAR = 0,
  EYE = 1,
};
```

#### How to run?
```sh
  $ make
```
#### How to run the tests?
```sh
  $ make test-code
```
#### How to debug?
```sh
  $ make debug
```
