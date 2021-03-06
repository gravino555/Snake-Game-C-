#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

// global values
bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;
// tail arrays
int tailX [100], tailY [100];
int nTail; // specifies length of tail
// functions for game making

void Setup() {
    gameOver = false; // beginning of the game
    dir = STOP;
    x = width/2; // this centers the head of the snake at the beginning of the game
    y = height/2; // ^^
    fruitX = rand() % width; // these two next lines distributes the fruits at random locations inside the map
    fruitY = rand() % height; // ^^
    score = 0; // score initialized at 0
}

void Draw() {
    system("cls"); // clears the screen
    cout << "Welcome to Snake!!!!" << endl;
// following code draws the map as well as the fruit, snake and its tail.
    for (int i = 0; i < width + 2; i++)
        cout << "#";
        cout << endl;

    for (int i = 0; i < height; i++) {
     for (int j = 0; j < width; j++){
        if (j == 0)
            cout << "#";
            if ( i == y && j == x)
                cout << "O";
            else if (i == fruitY && j == fruitX)
                cout << "F";
            else {
                bool print = false;
                    for (int k = 0; k < nTail; k++) {
                        if (tailX[k] == j && tailY[k] == i) {
                            cout << "x";
                    print = true;
                        }
                    }
            if (!print)
                cout << " ";
            }
        if (j == width - 1)
            cout << "#";
    }
    cout << endl;
}


for (int i = 0; i < width + 2; i++)
    cout << "#";
    cout << endl;
    cout << "Score: " << score << endl; // displays the score
}

void Input() {
    // input when playing.
    if (_kbhit()){
        switch (_getch()) {
    case 'a':
        dir = LEFT;
        break;
    case 'd':
        dir = RIGHT;
        break;
    case 'w':
        dir = UP;
        break;
    case 's':
        dir = DOWN;
        break;
    case 'x':
        gameOver = true;
        break;
        }
    }
}

void Logic() {
    // this is all logic in game, I.E : what happens when head of snake hits wall (game over).
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x; // makes them follow first element of the snake
    tailY[0] = y;
    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
        }
    switch (dir) {
    // describes what left, right, up , down means to the program.
    case LEFT:
      x--;
     break;
    case RIGHT:
       x++;
      break;
    case UP:
      y--;
      break;
    case DOWN:
       y++;
      break;
    default:
      break;
    }
    if (x > width || x < 0 || y > height || y < 0)
        gameOver = true; // if snake hits edge of map, terminates the app
    for (int i = 0; i < nTail; i++)
     if (tailX[i] == x && tailY[i] == y)
         gameOver = true; // if head hits tail, game over
    if ( x == fruitX && y == fruitY) {
     score += 10 ; // Everytime the snake eats the fruit, the score will go up 10 points
     fruitX = rand() % width;
     fruitY = rand() % height; // enables us to eat the fruit
     nTail++; // if we eat fruit, tail grows by 1
}

}

int main()
{
    Setup();
    while(!gameOver){
        Draw();
        Input();
        Logic();
        Sleep(60); // slows game down
    }
    return 0;
}
