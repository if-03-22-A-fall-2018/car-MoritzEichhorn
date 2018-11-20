#include "car.h"
#include <stdio.h>
#include <stdbool.h>

struct TestCase {
  enum CarType car_type;
  enum Color color;
  double fill_level;
  double acceleration_rate;
  double speed;
  bool isRented;
};

 static struct TestCase multipla1 = {FIAT_MULTIPLA, GREEN, 65, 0, 0, false};
 static struct TestCase multipla2 = {FIAT_MULTIPLA, BLUE, 65, 0, 0, false};
 static struct TestCase multipla3 = {FIAT_MULTIPLA, ORANGE, 65, 0, 0, false};
 static struct TestCase aixam = {FIAT_MULTIPLA, RED, 16, 0, 0, false};
 static struct TestCase jeep1 = {FIAT_MULTIPLA, SILVER, 80, 0, 0, false};
 static struct TestCase jeep2 = {FIAT_MULTIPLA, BLACK, 80, 0, 0, false};

 Car car_park[6] = {&multipla1, &multipla2, &multipla3, &aixam, &jeep1, &jeep2};


Car get_car(CarType type){
  int();
  return car_park[0];
}

enum CarType get_type(Car car1){
  return car1->car_type;
}

enum Color get_color(Car car1){
  return car1->color;
}

double get_fill_level(Car car1){
  return 0;
}

double get_acceleration_rate(Car car1){
  return 0;
}

double get_speed(Car car1)
{
  return 0;
}

void init(){

}

void set_acceleration_rate(Car car1, double acceleration){

}
