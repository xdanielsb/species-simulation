#include <memory>
#include"../model/behaviour/IBehaviour.hpp"
#include"../model/behaviour/Lazy.hpp"
#include"../model/behaviour/Gregarius.hpp"
#include"../model/behaviour/Farsighted.hpp"

TEST_CASE("Test getter for Lazy") {
   double mindis = 5;
   LazyB *lazy = new LazyB();
   CHECK(lazy->getMINDIS() == mindis);
   delete lazy;
}

