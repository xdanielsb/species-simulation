
#include <unordered_set>
#include "../logic/controller/Environment.hpp"
TEST_CASE("Kamikaze beast impacting other beast - 1D")
{
    shared_ptr<KamikazeB> lazy_behaviour = make_shared<KamikazeB>();
    int n_neighs = 3;

    Beast* me = new Beast(666, { 0, 0 }, { 0, 0 }, lazy_behaviour);
    Beast* enemy = new Beast(999, { 0, 4 }, { 0, 0 }, lazy_behaviour);

    vector<Animal*> list;

    for (int j = 0; j < n_neighs; j++)
    {
        Beast* b = new Beast(j, { 0, 30 }, { 0, 0 }, lazy_behaviour);
        list.push_back(b);
    }

    list.push_back(me);
    list.push_back(enemy);

    Environment* e = new Environment(300, 300);

    e->setListBeast(list);
    e->step(1);

    CHECK(get<0>(me->getPosition()) == 0);
    CHECK(get<1>(me->getPosition()) == 1);

    CHECK(get<0>(enemy->getPosition()) == 0);
    CHECK(get<1>(enemy->getPosition()) == 3);

    e->step(2);

    CHECK(get<0>(me->getPosition()) == 0);
    CHECK(get<1>(me->getPosition()) == 2);

    CHECK(get<0>(enemy->getPosition()) == 0);
    CHECK(get<1>(enemy->getPosition()) == 2);

    /*
      me->move(list);
      enemy->move(list);

      CHECK(get<0>(me->getPosition()) == 0);
      CHECK(get<1>(me->getPosition()) == 1);

      CHECK(get<0>(enemy->getPosition()) == 0);
      CHECK(get<1>(enemy->getPosition()) == 3);

      me->move(list);
      enemy->move(list);

      CHECK(get<0>(me->getPosition()) == 0);
      CHECK(get<1>(me->getPosition()) == 2);

      CHECK(get<0>(enemy->getPosition()) == 0);
      CHECK(get<1>(enemy->getPosition()) == 2);

      Environment *e = new Environment(list);

      e->removeCollidedBeast();

      me->move(list);
      enemy->move(list);

      for(Animal*  b:list){
                      delete(b);
      }*/
}
/*
TEST_CASE("Lazy beast doesn't return. There are not too many beasts - 1D") {

        shared_ptr<KamikazeB> lazy_behaviour = make_shared<KamikazeB>();
        int n_neighs = lazy_behaviour->getMINDIS()-1;

        ii my_pos = {0,1};
        ii my_speed = {0,1};
        ii others_pos = {0,1};
        ii others_speed = {0,1};

        Beast *me = new Beast(1, my_pos, my_speed, lazy_behaviour);

        vector <Animal*> list;

        for(int j=0;j<n_neighs;j++){

                Beast *b = new Beast(j, others_pos, others_speed,
lazy_behaviour);
                list.push_back(b);
        }

        list.push_back(me);

        CHECK(get<0>(me->getPosition()) == get<0>(my_pos));
        CHECK(get<1>(me->getPosition()) == get<1>(my_pos));

        int nmoves = 5;
        for(int j=0;j<nmoves;j++){

                me->move(list);
        }

        CHECK(get<0>(me->getPosition()) == get<0>(my_pos));
        CHECK(get<1>(me->getPosition()) == get<1>(my_pos)+nmoves);

        me->move(list);

        // The beast should't go back!

        CHECK(get<0>(me->getPosition()) == 0);
        CHECK(get<1>(me->getPosition()) == 7);

}*/
