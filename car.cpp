#include "car.h"
#include <stdio.h>
#include <stdbool.h>

#define CAR_PARK_SIZE 6
#define MAX_ACCELERATION_RATE_AIXAM
#define MAX_ACCELERATION_RATE_MULTIPLA
#define MAX_ACCELERATION_RATE_AIXAM

struct TestCase {
  enum CarType car_type;
  enum Color color;
  double fill_level;
  double acceleration_rate;
  double speed;
  bool isRented;
};

 static struct TestCase aixam = {AIXAM, RED, 16, 0, 0, false};
 static struct TestCase multipla1 = {FIAT_MULTIPLA, GREEN, 65, 0, 0, false};
 static struct TestCase multipla2 = {FIAT_MULTIPLA, BLUE, 65, 0, 0, false};
 static struct TestCase multipla3 = {FIAT_MULTIPLA, ORANGE, 65, 0, 0, false};
 static struct TestCase jeep1 = {JEEP, SILVER, 80, 0, 0, false};
 static struct TestCase jeep2 = {JEEP, BLACK, 80, 0, 0, false};

 Car car_park[CAR_PARK_SIZE] = {&aixam, &multipla1, &multipla2, &multipla3, &jeep1, &jeep2};

 Car get_car(CarType type){
  for(int i = 0; i < CAR_PARK_SIZE; i++)
  {
    if((car_park[i]->car_type == type) && (!car_park[i]->isRented))
    {
      car_park[i]->isRented = true;
      return car_park[i];
    }
  }
  return 0;
 }

 enum CarType get_type(Car car1){
   return car1->car_type;
 }

 enum Color get_color(Car car1){
   return car1->color;
 }

 double get_fill_level(Car car1){
   return car1->fill_level;
 }

 double get_acceleration_rate(Car car1){
   return car1->acceleration_rate;
 }

 void set_acceleration_rate(Car car1, double acceleration){
   if(acceleration >= 0)
   {
     car1->acceleration_rate = acceleration;
   }
 }

 double get_speed(Car car1)
 {
   return car1->speed;
 }

void init(){
  for(int i = 0; i < CAR_PARK_SIZE; i++)
  {
    car_park[i]->acceleration_rate = 0;
    car_park[i]->isRented = false;
    car_park[i]->speed = 0;
    if(i == 0)
    {
      car_park[i]->fill_level = 16;
    }
    else if(i < 4)
    {
      car_park[i]->fill_level = 65;
    }
    else
    {
      car_park[i]->fill_level = 80;
    }
  }
}
