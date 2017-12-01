#include <stdio.h>
#include <stdbool.h>
#include "car.h"

#define MAX_ACCERATION_RATE_AIXAM 1.0;
#define MAX_ACCERATION_RATE_FIAT 2.26;
#define MAX_ACCERATION_RATE_JEEP 3.26;
#define MAX_ACCERATION_RATE 8;

struct CarType{
  enum type type;
  enum color color;
  double fill_level;
  double acceleration_rate;
  double speed;
  bool isRented;
  int maxSpeed;


};
/* condition */
static struct CarType AIXAM1 = {AIXAM, RED, 16,0,0,false,45};
static struct CarType FIAT_MULTIPLA1 = {FIAT_MULTIPLA, GREEN, 65,0,0,false,170};
static struct CarType FIAT_MULTIPLA2 = {FIAT_MULTIPLA, BLUE, 65,0,0,false,170};
static struct CarType FIAT_MULTIPLA3 = {FIAT_MULTIPLA, ORANGE, 65,0,0,false,170};
static struct CarType JEEP1 = {JEEP, SILVER, 80,0,0,false,196};
static struct CarType JEEP2 = {JEEP, BLACK, 80,0,0,false,196};
struct CarType car_park[6] = {AIXAM1, FIAT_MULTIPLA1, FIAT_MULTIPLA2, FIAT_MULTIPLA3, JEEP1, JEEP2};

void init()
{
  for (int i = 0; i < 6; i++) {
    car_park[i].isRented = false;
    car_park[i].acceleration_rate = 0;
    car_park[i].speed = 0;
  }
}
Car get_car(enum type type)
{
  for (int i = 0; i < 6; i++)
  {
    if (type == car_park[i].type && car_park[i].isRented == false)
    {
      car_park[i].isRented = true;
      return &car_park[i];
    }
  }
  return NULL;
}
enum type get_type(Car car)
{
  return car->type;
}
enum color get_color(Car car)
{
  return car->color;
}
double get_fill_level(Car car)
{
  return car->fill_level;
}
double get_acceleration_rate(Car car)
{
  return car->acceleration_rate;
}
void set_acceleration_rate(Car car, double acceleration_rate)
{
    switch (car->type) {
    case AIXAM:
      if (acceleration_rate > 1.0) {
        acceleration_rate = 1.0;
      }
      else if(acceleration_rate < -8)
      {
        acceleration_rate = -8;
      }
        break;
    case FIAT_MULTIPLA:
        if (acceleration_rate > 2.26) {
          acceleration_rate = 2.26;
        }
        else if(acceleration_rate < -8)
        {
          acceleration_rate = -8;
        }
        break;
    case JEEP:
      if (acceleration_rate > 3.14) {
        acceleration_rate = 3.14;


      }
      else if(acceleration_rate < -8)
      {
        acceleration_rate = -8;
      }
      break;
  }
  car->acceleration_rate = acceleration_rate;
}
int get_speed(Car car)
{
  if (car->speed > car->maxSpeed) {
    car->speed = car->maxSpeed;
    return car->speed;
  }
  return car->speed + 0.5;;
}
void accelerate(Car car) {
  double s = car->acceleration_rate * 3.6;
  car->speed += s;

}
