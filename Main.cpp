#include <iostream>
#include <windows.h> //La usaremos par poder usar la funcion de limpiar la consola
#include <time.h>    //Para usar time() en srand()
#include <stdlib.h>  //Para usar rand() y srand()
#include <conio.h>   //Para usar _getch() para la entrada del teclado

using namespace std;

const int W = 20, H = 20;   // Ancho del juego y alto del juego
bool gameOver;              // Determinar el fin del juego
int headPos[2], foodPos[2]; // Posicion de X y Y de la serpiente y de la comida
int tailPosX[100], tailPosY[100], tailLength; // Posiciones de la cola de la serpiente
int score;                  // Puntuacion del jugador

enum directionEnum
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};                            // Enumeracion para las direcciones
directionEnum snakeDirection; // Variable para la direccion de la serpiente

// Inicializar todo
void init()
{
    system("cls"); // Limpiamos la consola al iniciar el juego

    headPos[0] = W / 2; // Posicion X de la serpiente
    headPos[1] = H / 2; // Posicion Y de la serpiente

    foodPos[0] = rand() % W; // Posicion X de la comida (Definimos el rango maximo (w))
    foodPos[1] = rand() % H; // Posicion Y de la comida (Definimos el rango maximo (h))

    score = 0; // Inicializamos la puntuacion a 0

    snakeDirection = STOP; // Inicializamos la direccion de la serpiente

    gameOver = false;
}
// Renderiza todo en pantalla
void render()
{
    system("cls"); // Limpiamos la consola (en Linux sería system("clear"))

    // Renderizamos la parte superior del marco
    for (int i = 0; i < W + 2; i++)
    {
        cout << "#";
    }
    cout << endl;

    // Renderizamos las partes intermedias (el área de juego)
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (j == 0) // Pared izquierda
                cout << "#";

            if (j == headPos[0] && i == headPos[1]) // Cabeza de la serpiente
                cout << "O";

            else if (j == foodPos[0] && i == foodPos[1]) // Comida
                cout << "*";

            else
            {
                bool printTail = false;

                // Dibujamos la cola de la serpiente
                for (int k = 0; k < tailLength; k++)
                {
                    if (tailPosX[k] == j && tailPosY[k] == i)
                    {
                        cout << "o";
                        printTail = true;
                    }
                }

                if (!printTail) // Espacio en blanco si no hay cola
                    cout << " ";
            }

            if (j == W - 1) // Pared derecha
                cout << "#";
        }

        cout << endl;
    }

    // Renderizamos la parte inferior del marco
    for (int i = 0; i < W + 2; i++)
    {
        cout << "#";
    }

    cout << endl
         << endl;

    // Mostramos la puntuación actual
    cout << "Score: " << score << endl;
}

// Encargado de recibir las instrucciones del teclado
void input()
{
    if (_kbhit()) // Si hay una tecla pulsada
    {
        switch (_getch()) // Obtenemos la tecla pulsada
        {
        case 'a':                  // Si se pulsa la tecla 'a'
            snakeDirection = LEFT; // La serpiente va a la izquierda
            break;
        case 'd':                   // Si se pulsa la tecla 'd'
            snakeDirection = RIGHT; // La serpiente va a la derecha
            break;
        case 'w':                // Si se pulsa la tecla 'w'
            snakeDirection = UP; // La serpiente va hacia arriba
            break;
        case 's':                  // Si se pulsa la tecla 's'
            snakeDirection = DOWN; // La serpiente va hacia abajo
            break;
        case 'q':            // Si se pulsa la tecla 'x'
            gameOver = true; // El juego termina
            break;
        }
    }
}

// Encargado de toda la logica del juego
void gameLogic()
{
    int prevTailPosX = tailPosX[0]; // Guardamos la posicion X de la cola
    int prevTailPosY = tailPosY[0]; // Guardamos la posicion Y de la cola

    int prevTailPosX2, prevTailPosY2; // Guardamos la posicion X y Y de la cola anterior
    tailPosX[0] = headPos[0]; // Actualizamos la posicion X de la cabeza de la serpiente
    tailPosY[0] = headPos[1]; // Actualizamos la posicion Y de la cabeza de la serpiente

    for(int i = 1; i < tailLength; i++) // Recorremos la cola de la serpiente
    {
        prevTailPosX2 = tailPosX[i]; // Guardamos la posicion X de la cola anterior
        prevTailPosY2 = tailPosY[i]; // Guardamos la posicion Y de la cola anterior

        tailPosX[i] = prevTailPosX; // Actualizamos la posicion X de la cola
        tailPosY[i] = prevTailPosY; // Actualizamos la posicion Y de la cola

        prevTailPosX = prevTailPosX2; // Actualizamos la posicion X de la cola anterior
        prevTailPosY = prevTailPosY2; // Actualizamos la posicion Y de la cola anterior

    }


    switch (snakeDirection)
    {
    case STOP:
        // No mover la serpiente si la dirección es STOP
        break;

    case LEFT:
        headPos[0]--; // Mover la cabeza de la serpiente una posición a la izquierda
        break;

    case RIGHT:
        headPos[0]++; // Mover la cabeza de la serpiente una posición a la derecha
        break;

    case UP:
        headPos[1]--; // Mover la cabeza de la serpiente una posición hacia arriba
        break;

    case DOWN:
        headPos[1]++; // Mover la cabeza de la serpiente una posición hacia abajo
        break;
    }

    if(headPos[0] >= W || headPos[0] < 0 || headPos [1] >= H || headPos[1] < 0)//Si la cabeza de la serpiente toca los bordes del juego
        gameOver = true; // El juego termina


    for(int i = 0; i < tailLength; i++) // Recorremos la cola de la serpiente
    {
        if(tailPosX[i] == headPos[0] && tailPosY[i] == headPos[1]) // Si la cabeza de la serpiente toca su cola
        {
            gameOver = true; // El juego termina
        }
    }
    if(headPos[0] == foodPos[0] && headPos[1] == foodPos[1]) // Si la cabeza de la serpiente toca la comida
    {
        score += 10; // Aumentamos la puntuacion
        foodPos[0] = rand() % W; // Generamos una nueva posicion X para la comida
        foodPos[1] = rand() % H; // Generamos una nueva posicion Y para la comida
        tailLength++; // Aumentamos la longitud de la cola
    }
}

int main()
{
    srand(time(0)); // Inicializamos la semilla para generar numeros aleatorios

    init();

    while (!gameOver) // Mientras gameOver sea falso el juego sigue
    {
        render();
        input();
        gameLogic();
        Sleep(50); // Pausa para que el juego no vaya demasiado rápido
    }
}