#ifndef FOOD_H_
#define FOOD_H_

#include <windows.h> //This library is for cleaning the console (cls)
#include <time.h>    //This library is for using time() in srand()
#include <stdlib.h>  //This library is for using rand() and srand()

#define W 20
#define H 20

class Food
{
private:
    COORD foodPos;

public:
    // Constructor:
    Food();

    // Methods:
    void spawnFood();

    // Getter:
    COORD getFoodPos();
};

#endif /* FOOD_H_ */