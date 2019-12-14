
#include"../model/accessory/Accessory.hpp"
#include"../model/accessory/Camouflage.hpp"
TEST_CASE("Test getter for Camouflage") {
   double ccamouflage = 0.3;
   CamouflageS *c1 = new CamouflageS(ccamouflage);
   CHECK(c1->getCamouflage() == 0.3);
   delete c1;
}
