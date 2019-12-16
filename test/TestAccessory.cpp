
#include"../model/accessory/Accessory.hpp"
#include"../model/accessory/Camouflage.hpp"
#include"../model/accessory/Shell.hpp"
#include"../model/accessory/Fin.hpp"

TEST_CASE("Test getter for Camouflage") {
   double ccamouflage = 0.3;
   CamouflageS *c1 = new CamouflageS(ccamouflage);
   CHECK(c1->getCamouflage() == ccamouflage);
   delete c1;
}

TEST_CASE("Test getter for Shell") {
   double cdied = 0.1;
   double cspeed = 0.2;
   ShellS *s1 = new ShellS(cdied, cspeed);
   CHECK(s1->getDied() == cdied);
   CHECK(s1->getSpeed() == cspeed);
   delete s1;
}

TEST_CASE("Test getter for Fin") {
   double cspeed = 0.85;
   FinS *f1 = new FinS(cspeed);
   CHECK(f1->getSpeed() == cspeed);
   delete f1;
}

