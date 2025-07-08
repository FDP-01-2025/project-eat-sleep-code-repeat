# 🐍 SnakyThings 🐍 

## 🎮 Tema y Configuración::

**SnakyThings** es un juego clásico basado en consola inspirado en la serpiente tradicional. Controlas una serpiente que se mueve por el mapa, come objetos para crecer y gana puntos.

A medida que avanzas, el juego se vuelve más desafiante con nuevos niveles y obstáculos que debes evitar para mantenerte con vida. Todo ocurre en un entorno minimalista basado en texto, lo que brinda una experiencia de juego sencilla pero divertida.
##

## ⚙️ Mecánica Principal:
La mecánica principal de SnakyThings es simple: guía a la serpiente usando las teclas AWSD para recolectar comida que aparece en la pantalla. Cada vez que la serpiente come, crece más larga y la puntuación aumenta.

El desafío consiste en evitar colisiones, ya sea con las paredes, con los obstáculos que aparecen en niveles más altos o con el propio cuerpo de la serpiente. El juego termina si la serpiente choca contra algo.

Cuando el jugador alcanza ciertas puntuaciones, se desbloquean nuevos niveles con mayor dificultad y diferentes disposiciones de obstáculos.
##

## 🧩 Idea General del Juego:
SnakyThings ofrece una experiencia de juego sencilla pero atractiva. Comienzas con una serpiente pequeña en un mapa vacío, y tu objetivo es comer tanta comida como puedas para crecer y ganar puntos.

A medida que la serpiente crece, el juego se vuelve más difícil: el espacio se reduce debido a los obstáculos y tus movimientos deben ser más precisos. Cuando alcanzas una puntuación alta, se desbloquean nuevos niveles con obstáculos colocados en el mapa, lo que añade un nivel extra de dificultad.

El juego se centra en los reflejos, la planificación de tus movimientos y la adaptación al desafío creciente a medida que avanzas.
##

## 🔧 Consideraciones Técnicas:
SnakyThings está desarrollado en C++ y se ejecuta únicamente en la consola, utilizando solo bibliotecas estándar del sistema y renderizado basado en texto.

**Detalles técnicos clave:**
- Language: C++.

- Entorno: Solo consola. (sin interfaz gráfica)
  
**Bibliotecas utilizadas:**

- **`<iostream>`** para entrada y salida de datos

- **`<windows.h>`** para control del cursor y limpieza de pantalla.

- **`<conio.h>`** para detección de teclas en tiempo real.

- **`<stdlib.h>`** and **`<time.h>`** para funciones del sistema y generación de números aleatorios.

- **`<fstream>`** para guardar nombres de jugadores y puntuaciones en un archivo `.txt`.

**Detalles y restricciones de implementación**:

 - ✅ La lógica del juego se implementa utilizando variables y tipos de datos básicos, arreglos, estructuras condicionales (if, else, switch), bucles (for, while, do while), manejo de archivos para guardar nombres de jugadores y puntajes en un archivo .txt, y funciones.
   
## 💻 Conceptos de Programación Implementados

### 📝 Salida por Consola (`cout`)
<img width="600" height="300" style="object-fit:contain;background:#1E1E1E" src="https://github.com/user-attachments/assets/c6d1a61e-3845-4ccf-9d74-20c4dd1992c8" alt="cout">  


### 🔁 Bucles Do-While
<img width="600" height="300" style="object-fit:contain;background:#1E1E1E" src="https://github.com/user-attachments/assets/3191714a-5001-456e-bc8f-150674a3d2d8" alt="do-while">  


### 📂 Manejo de Archivos
<img width="600" height="300" style="object-fit:contain;background:#1E1E1E" src="https://github.com/user-attachments/assets/04606f41-b234-4fa5-bdbb-53cdeeade0b2" alt="file-handling">  


### 🔄 Bucles For
<img width="600" height="300" style="object-fit:contain;background:#1E1E1E" src="https://github.com/user-attachments/assets/15b63cae-7ae9-4686-87c3-09e7b666d19d" alt="for-loops">  


### ❓ Condicionales If-Else
<img width="600" height="300" style="object-fit:contain;background:#1E1E1E" src="https://github.com/user-attachments/assets/3a17df08-d1f9-43cb-bf84-e38e7e93a006" alt="if-else">  


### 🎚️ Switch-Case
<img width="600" height="300" style="object-fit:contain;background:#1E1E1E" src="https://github.com/user-attachments/assets/ef7fcea6-dcfc-468d-b7f8-76898fad111b" alt="switch-case">  


### ⏳ Bucles While
<img width="600" height="300" style="object-fit:contain;background:#1E1E1E" src="https://github.com/user-attachments/assets/08f10a14-ae14-4f11-a8ce-31d8b1e6913a" alt="while-loops">  

##

## 🖼️ Bocetos y Diseños Conceptuales:
**Main menu.**
<img width="1919" height="1079" alt="Image" src="https://github.com/user-attachments/assets/eeef6c59-a427-4e70-b896-b1cf196cd050" />
**Player name entered. (To display in the game)**
<img width="1919" height="1079" alt="Image" src="https://github.com/user-attachments/assets/0de35f76-7c39-4f4a-a840-08d8a19498c1" />
**How to play menu. (If the player press SPACE)**
<img width="1915" height="1009" alt="Image" src="https://github.com/user-attachments/assets/34fbd706-d4bc-4539-a85e-9ccba3d111c3" />
**Level 1 design. (With no obstacles)**
<img width="1919" height="1076" alt="Image" src="https://github.com/user-attachments/assets/63cb6b64-a7e1-4578-a674-340a3b9e8340" />
**Design of level surpassed.**
<img width="1919" height="1079" alt="Image" src="https://github.com/user-attachments/assets/93fab2de-7e98-46ea-be68-32a2af60132e" />
**Level 2 design. (With obstacles)**
<img width="1919" height="1079" alt="Image" src="https://github.com/user-attachments/assets/3e4969e8-b9dc-4893-a667-16c23f464017" />
**Level 3 design. (With obstacles)**
<img width="1919" height="1079" alt="Image" src="https://github.com/user-attachments/assets/a9355a2a-8d7a-4830-add1-84f6a951442b" />
**Game Over.**
<img width="1919" height="1061" alt="Image" src="https://github.com/user-attachments/assets/7c85fe42-6b50-4ac5-89fe-0d3514374424" />
##
## 💼 Nombre del equipo:
**Eat, Sleep, Code, Repeat.**
##
## 👥 Miembros del equipo

1. **Anthony Odir López Guzmán.**  
   📘 **Student ID:** 00077325.

2. **Oscar Fernando Herrera Rivera.**  
   📘 **Student ID:** 00085525.

3. **William Eduardo Peraza Navas.**  
   📘 **Student ID:** 00087925

4. **Rene Fernando Serrano Cardona.**  
   📘 **Student ID:** 00098725.
##

## 📊 Flujograma del videojuego

Aquí puedes ver el flujograma completo del videojuego en Lucidchart: https://lucid.app/lucidchart/f8dfc519-39a7-4633-8a3f-c8981d498dda/edit?view_items=rjWvSFYpgDX0&invitationId=inv_55df7abf-20e1-4a6f-a504-3a42f899ad7f)

## 🚀 Cómo ejecutar el proyecto localmente

1. **Clona el repositorio en tu computadora**:
   ```bash
   git clone https://github.com/FDP-01-2025/project-eat-sleep-code-repeat.git
   ```
2. **Navega al directorio del proyecto**
   ```bash
   cd project-eat-sleep-code-repeat
   ```
3. **Compila el juego en el terminal. (Si el archivo ejecutable del juego no existe).**
   ```bash
   g++ -o snake src/source/Main.cpp src/source/Snake.cpp src/source/Food.cpp src/source/ConfigurationLevel2.cpp src/source/ConfigurationLevel3.cpp src/source/Player.cpp src/source/PowerUps.cpp src/source/MenuManager.cpp src/source/GameManager.cpp src/source/ConfigurationLevel1.cpp
   ```
4. **Ejecuta el juego y maximiza la ventana:**
   ```bash
   .\snake
   ``` 









