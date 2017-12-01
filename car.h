/*----------------------------------------------------------
*				HTBLA-Leonding / Klasse: <your class>
* ---------------------------------------------------------
* Exercise Number: 0
* Title:			car.h
* Author:			P. Bauer
* Due Date:		January 9, 2015
* ----------------------------------------------------------
* Description:
* Car abstract data type demo.
* ----------------------------------------------------------
*/
#ifndef ___CAR_H
#define ___CAR_H

enum type{AIXAM, JEEP, FIAT_MULTIPLA};
enum color{BLACK, BLUE, GREEN, SILVER, RED, ORANGE};
typedef struct CarType* Car;




Car get_car(enum type type);
void init();
enum type get_type(Car car );
enum color get_color(Car car);
double get_fill_level(Car car);
double get_acceleration_rate(Car car);
void set_acceleration_rate(Car car, double acceleration_rate);
int get_speed(Car car);
void accelerate(Car car);




#endif
