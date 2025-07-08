# 🐍 SnakyThings 🐍 

## 🎮 Theme and Settings:

**SnakyThings** is a classic console-based game inspired by the traditional Snake. You control a snake that moves around the map, eats objects to grow, and earns points.

As you progress, the game becomes more challenging with new levels and obstacles that you must avoid to stay alive. Everything happens in a simple, retro-style text-based environment, giving it a minimalist yet fun gameplay experience.
##

## ⚙️ Main Mechanic:
The main mechanic of SnakyThings is simple: guide the snake using the AWSD keys to collect food that appears on the screen. Each time the snake eats, it grows longer and the score increases.

The challenge comes from avoiding collisions—either with the walls, with obstacles that appear in higher levels, or with the snake’s own body. The game ends if the snake crashes into anything.

As the player reaches certain scores, new levels are unlocked with increasing difficulty and different obstacle layouts.
##

## 🧩 General Gameplay Idea:
SnakyThings offers a simple yet engaging gameplay experience. You start with a small snake on an empty map, and your goal is to eat as much food as you can to grow and earn points.

As the snake grows, the game becomes more difficult: space is reduced by obstacles and your movements must be more precise. When you reach a high score, new levels are unlocked with obstacles placed on the map, which add an extra level of difficulty.

The game focuses on reflexes, planning your moves and adapting to the increasing challenge as you progress.
##

## 🔧 Technical Considerations:
SnakyThings is developed in C++ and runs purely in the console, using only standard system libraries and text-based rendering.

**Key technical details:**
- Language: C++.

- Environment: Console-only. (no graphical interface)
  
**Libraries used:**

- **`<iostream>`** for input and output.

- **`<windows.h>`** for cursor control and screen clearing.

- **`<conio.h>`** for real-time key detection.

- **`<stdlib.h>`** and **`<time.h>`** for system functions and randomness.

- **`<fstream>`** For saving player names and scores to a `.txt` file

**Implementation details and restrictions**:

 - ✅ The game logic is implemented using variables and basic data types, arrays, Conditional structures: (if, else, switch), loops: (for, while, do while), file handling to save player names and scores to a .txt file and functions.
 - 
##

## 🖼️ Mockups and Conceptual Designs:
Initial concepts planned for implementation in the video game.

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
**Level 4 design. (With obstacles)**
<img width="1919" height="1079" alt="Image" src="https://github.com/user-attachments/assets/1e3a13eb-3867-4776-9ae3-712a6e153454" />
**Level 5 design. (With obstacles)**
<img width="1919" height="1079" alt="Image" src="https://github.com/user-attachments/assets/2db97ee1-670d-4473-8f0f-ac957baa677e" />
**Congratulations! You Win!**
<img width="1903" height="1068" alt="Image" src="https://github.com/user-attachments/assets/76a0c253-ad5d-41a0-af07-ff612d756508" />
**Game Over.**
<img width="1919" height="1061" alt="Image" src="https://github.com/user-attachments/assets/7c85fe42-6b50-4ac5-89fe-0d3514374424" />
##

## 📃Video game flowchart

##

## 💼 Team name:
**Eat, Sleep, Code, Repeat.**
##
## 👥 Team Members

1. **Anthony Odir López Guzmán.**  
   📘 **Student ID:** 00077325.

2. **Oscar Fernando Herrera Rivera.**  
   📘 **Student ID:** 00085525.

3. **William Eduardo Peraza Navas.**  
   📘 **Student ID:** 00087925

4. **Rene Fernando Serrano Cardona.**  
   📘 **Student ID:** 00098725.
##
## 🚀 How to Run the Project Locally

## Clone and Run
1. **Clone the repository in your Desktop**:
   ```bash
   git clone https://github.com/FDP-01-2025/project-eat-sleep-code-repeat.git
   ```
2. **Navigate to project directory:**
   ```bash
   cd project-eat-sleep-code-repeat
   ```
3. **Compile the game in the terminal. (If the executable file of the game does not exist.)**
   ```bash
   g++ -o snake src/source/Main.cpp src/source/Snake.cpp src/source/Food.cpp src/source/ConfigurationLevel2.cpp src/source/ConfigurationLevel3.cpp src/source/Player.cpp src/source/PowerUps.cpp src/source/MenuManager.cpp src/source/GameManager.cpp src/source/ConfigurationLevel1.cpp
   ```
4. **Run the game and maximizes the window:**
   ```bash
   .\snake
   ``` 










