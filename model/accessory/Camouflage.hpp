#ifndef _CCamouflage
#define _CCamouflage
#include "./Accessory.hpp"

/**
 * Implementation of Camouflage
 *
 * An animal with camouflage decreases the detection capacity of the
 * others beast towards the beast who has this accesory. This camouflage
 * capacity is modeled by ψ∈ [ψmin; ψmax] with 0≤ ψmin ≤ ψmax ≤1. When
 * it is equal to 0, the animal is not at all camouflaged (it is also
 * the case of any animal without the camouflage accessory) and is
 * therefore totally detectable by other animals.
 * The more the value of ψ approaches 1, the more
 * effective the camouflage, until reaching the perfect camouflage
 * (undetectable beast) for ψ = 1. The constructeur is used to
 * initier an instance of camouflage and "getCamouflage" is used
 * to get the caracter of the camouflage.
 *
 *
 */
class CamouflageS: public Accessory{
private:
  double ccamouflage;
public:
  CamouflageS(double camouflage): Accessory(){
		this->ccamouflage = camouflage;
  }
  double getCamouflage(){
    return this->ccamouflage;
  }
  ~CamouflageS(){}
};
#endif
