/*----------------------------------------------------------
*				HTBLA-Leonding / Klasse: 2AHIF
* ---------------------------------------------------------
* Exercise Number: 8
* Title:			car.h
* Author:			M. Eichhorn
* Due Date:		November 20, 2018
* ----------------------------------------------------------
* Description:
* Car abstract data type demo.
* ----------------------------------------------------------
*/
#ifndef ___CAR_H
#define ___CAR_H

enum CarType { AIXAM, FIAT_MULTIPLA, JEEP };
enum Color { RED, GREEN, BLUE, ORANGE, SILVER, BLACK};

typedef struct TestCase* Car;

Car get_car(CarType);
enum CarType get_type(Car car1);
enum Color get_color(Car car1);

double get_fill_level(Car car1);
void accelerate(Car car1);
double get_acceleration_rate(Car car1);
double get_speed(Car car1);
void init();
void set_acceleration_rate(Car car1, double acceleration);


#endif
