/*----------------------------------------------------------
 *				HTBLA-Leonding / Class: 2AHIF
 * ---------------------------------------------------------
 * Exercise Number: 8
 * Title:			car.cpp
 * Author:			Eichhorn Moritz
 * ----------------------------------------------------------
 * Description:
 * Implementation of a car.
 * ----------------------------------------------------------
 */

#include "car.h"
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define CAR_PARK_SIZE 6
#define MAX_ACCELERATION_RATE_AIXAM 1
#define MAX_ACCELERATION_RATE_MULTIPLA 2.26
#define MAX_ACCELERATION_RATE_JEEP 3.14

#define MAX_SPEED_AIXAM 45
#define MAX_SPEED_MULTIPLA 170
#define MAX_SPEED_JEEP 196

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
   if(acceleration >= -8)
   {
     switch (car1->car_type) {
      case AIXAM:
        if(acceleration <= MAX_ACCELERATION_RATE_AIXAM)
        {
          car1->acceleration_rate = acceleration;
        }
        else
        {
          car1->acceleration_rate = MAX_ACCELERATION_RATE_AIXAM;
        }
      break;
      case FIAT_MULTIPLA:
        if(acceleration <= MAX_ACCELERATION_RATE_MULTIPLA)
        {
         car1->acceleration_rate = acceleration;
        }
        else
        {
         car1->acceleration_rate = MAX_ACCELERATION_RATE_MULTIPLA;
        }
      break;
      case JEEP:
        if(acceleration <= MAX_ACCELERATION_RATE_JEEP)
        {
         car1->acceleration_rate = acceleration;
        }
        else
        {
         car1->acceleration_rate = MAX_ACCELERATION_RATE_JEEP;
        }
      break;
     }
   }
   else
   {
     car1->acceleration_rate = -8;
   }
 }

 double get_speed(Car car1)
 {
   return round(car1->speed);
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

void accelerate(Car car1){
  car1->speed += car1->acceleration_rate*3.6;

  if((car1->car_type == AIXAM) && (car1->speed > MAX_SPEED_AIXAM))
  {
    car1->speed = MAX_SPEED_AIXAM;
  }
  else if((car1->car_type == FIAT_MULTIPLA) && (car1->speed > MAX_SPEED_MULTIPLA))
  {
    car1->speed = MAX_SPEED_MULTIPLA;
  }
  else if((car1->car_type ==JEEP) && (car1->speed > MAX_SPEED_JEEP))
  {
    car1->speed = MAX_SPEED_JEEP;
  }
}
