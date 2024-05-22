#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>

#define WIDTH 50
#define HEIGHT 10
#define JUMP_HEIGHT 5 // Ajusta la distacia para el salto
#define GAME_SPEED 50 // Ajusta este valor para cambiar la velocidad del juego

int gameOver;
int score;
int dinoX, dinoY;
int cactusX, cactusY;

void setup() {
    gameOver = 0;
    score = 0;
    dinoX = 5;
    dinoY = HEIGHT - 1;
    cactusX = WIDTH - 5;
    cactusY = HEIGHT - 1;
}

void draw() {
    system("cls");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == dinoY && j == dinoX)
                std::cout << "R";
            else if (i == cactusY && j == cactusX)
                std::cout << "+";
            else if (i == HEIGHT - 1)
                std::cout << "_";
            else
                std::cout << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "Score: " << score << std::endl;
}

void jump() {
    if (dinoY >= HEIGHT - JUMP_HEIGHT)
        dinoY -= JUMP_HEIGHT;
}

void input() {
    if (_kbhit()) {
        char key = _getch();
        if (key == ' ')
            jump();
    }
}

void update() {
    if (dinoY < HEIGHT - 1)
        dinoY++;
    cactusX--;
    if (cactusX <= 0) {
        cactusX = WIDTH - 5;
        score++;
    }
    if ((cactusX == dinoX) && (cactusY == dinoY))
        gameOver = 1;
}

int main() {
    setup();
    while (!gameOver) {
        draw();
        input();
        update();
        Sleep(GAME_SPEED); // Ajusta la velocidad del juego
    }
    std::cout << std::endl << "Game Over! Final Score: " << score << std::endl;
    return 0;
}