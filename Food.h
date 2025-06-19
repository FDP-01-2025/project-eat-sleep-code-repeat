#ifndef FOOD_H_
#define FOOD_H_

#include <windows.h> //This library is for cleaning the console and using for COORD (cls)
#include <time.h>    //This library is for using time() in srand()
#include <stdlib.h>  //This library is for using rand() and srand()

#define width 20
#define height 20

void initFood();
void spawnFood();
COORD getFoodPos();

#endif /* FOOD_H_ */