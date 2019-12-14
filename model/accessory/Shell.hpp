#ifndef _CShell
#define _CShell
#include "./Accessory.hpp"

/**
 * Implementation of Shell
 *
 * An animal with a shell is more resistant in a collision with another animal. 
 * Thus the probability that he dies is reduced by a coefficient ω∈ [1; ωmax].
 * However, the presence of this shell reduces its displacement speed by a 
 * factor η∈ [1; ηmax]. The constructeur is used to initier an instance of 
 * shell and "getSpeed"&"getDied" are used to get the caracter of the shell.
 *
 * 
 */
class Shell: public Accessory{
private:
  double cdied;
  double cspeed;
public:
  ShellS( double died, double speed){
    this->cdied = died;
    this->cspeed = speed;
  }
  double getDied(){
    return this->cdied;
  }
  double getSpeed(){
    return this->cspeed;
  }
  ~ShellS(){}
};
#endif
