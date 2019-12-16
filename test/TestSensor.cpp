#include"../logic/include.hpp"

#include"../model/sensor/Sensor.hpp"
#include"../model/sensor/Ear.hpp"
#include"../model/sensor/Eye.hpp"

TEST_CASE("Test getter for Ear") {
   double distance = 4;
   double detection = 0.7;
   EarS *ear = new EarS(distance, detection);
   CHECK(ear->getDistance() == distance);
   CHECK(ear->getDetection() == detection);
   delete ear;
}

TEST_CASE("Test getter for Eye") {
   double distance = 3;
   double detection = 0.9;
   double degree = 15;
   EyeS *eye = new EyeS(distance, detection, degree);
   CHECK(eye->getDistance() == distance);
   CHECK(eye->getDetection() == detection);
   CHECK(eye->getDegree() == degree);
   delete eye;
}
