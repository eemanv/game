#include <iostream>
#include <windows.h>
using namespace std;

// Global Arrays and Variables

int score = 0;
int timer;
string enemyDirection = "Up";
int health = 100;
int health1 = 100;

// Player Bullets

int bulletX[2000];
int bulletY[2000];
bool isBulletActive[2000];
int bulletCount = 0;

// Enemy Bullets

// TOM
int bulletEX[2000];
int bulletEY[2000];
bool isBulletEnemyActive[2000];
int bulletECount = 0;

// BEN
int bulletBenX[2000];
int bulletBenY[2000];
bool isBulletBenActive[2000];
int bulletBenCount = 0;

// SUPPORTING FUNCTIONS

void gotoxy(int x, int y);
char getCharAtxy(short int x, short int y);
int menu();
void login();
void header();
void printMaze();

// CHARACTER FUNCTIONS

void printJerry();
void moveJerryDown();
void moveJerryLeft();
void moveJerryUp();
void eraseJerry();
void generateBullet();
void printBullet(int x, int y);
void eraseBullet(int x, int y);
void makeBulletInactive(int index);
void moveBullet();
void moveJerryRight();
void addScore();
void printScore();

// ENEMY FUNCTIONS

// BEN
void printBen();
void moveBen();
void eraseBen();
void generateBulletBen();
void bulletCollisionWithBen();
void printBulletBen(int x, int y);
void eraseBulletBen(int x, int y);
void makeBulletInactiveBen(int index);
void moveBenBullet();
void healthCheck1();
void decreaseHealth1();
void printHealth1();

// ENEMY-2 FUNCTIONS
// TOM
void printEnemy();
void moveEnemy();
void eraseEnemy();
void generateBulletEnemy();
void bulletCollisionWithEnemy();
void printBulletEnemy(int x, int y);
void eraseBulletEnemy(int x, int y);
void makeBUlletInactiveEnemy(int index);
void moveEnemyBullet();
void healthCheck2();
void decreaseHealth2();
void printHealth2();

main()
{
    system("cls");
    header();
    menu();
    printMaze();
    printJerry();
    printEnemy();
    printBen();
    while (true)
    {
        if (health == 0)
        {
            break;
        }
        printScore();
        if (GetAsyncKeyState(VK_LEFT))
        {
            moveJerryLeft();
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {
            moveJerryRight();
        }
        if (GetAsyncKeyState(VK_UP))
        {
            moveJerryUp();
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            moveJerryDown();
        }
        if (GetAsyncKeyState(VK_SPACE))
        {
            generateBullet();
        }
        if (timer == 3)
        {
            moveEnemy();
            moveBen();
            timer = 0;
        }

        moveBullet();
        moveEnemyBullet();
        moveBenBullet();
        bulletCollisionWithEnemy();
        bulletCollisionWithBen();
        healthCheck2();
        printHealth2();
        healthCheck2();
        printHealth2();

        timer++;
        Sleep(90);
    }
}

void header()
{

    cout << "                                              @****(@                                                                                                                                                           " << endl;
    cout << "                                             (******/ @                                                                                                                                                         " << endl;
    cout << "                                            #*****# (%  @@                                                                                                                                                      " << endl;
    cout << "                                           @*/( @@ %##% %%@%            @@@@                                                                                                                                    " << endl;
    cout << "                                        @#**#*****************   @#****//////@                                                                                                                                  " << endl;
    cout << "                                      @* #*********(#%#****/*******#,,,,,,,,,,@                                                                                                                                 " << endl;
    cout << "                                     @**,  ********(@**(********(*,,,,,,,,,,,,@                                                                                                                                 " << endl;
    cout << "                                     @**  /****/(    *(********%,,,,,,,,,,,,,,@                  _ ______ _____   _____ __     __                                                                               " << endl;
    cout << "                                   @  /  ****/.    #************,,,,,*,,,,,,,@                  | |  ____|  __  \\|  __  \\ \\   / /                                                                            " << endl;
    cout << "                                    @ #@%#***(   %***************/#*,,,,,,,,@                   | | |__  | |__)  | |__)  \\ \\_/ /                                                                              " << endl;
    cout << "                                   @%*@ #(  (/%@ #/***************(,,,,,,,,@                _   | |  __| |  _  / |  _   / \\   /                                                                                " << endl;
    cout << "     @               @            @/   (@,  /*@% #//**********#,,,,,,,,,@                  | |__| | |____| |  \\ \\| |  \\ \\  | |                                                                              " << endl;
    cout << "     @.%.........#*...%             @@  *.    ,#/%(/*******/ *,,,,,,/@@                     \\____/|______| |   \\_\\_|   \\_\\ |_|                                                                             " << endl;
    cout << "     @.........../.....*           @@** (.#*    ./*///(((@@@@@@@@                                                                                                                                               " << endl;
    cout << "    @................#./../    @@/***%/ ****/(( %*****                                                 _    _ _    _ _   _ _______     ______ _____  _____                                                      " << endl;
    cout << "    /.............#...,....//******* ..*(,..%/********@                                               | |  | | |  | | \\ | |__   __|   |  ____/ ___ \\|  __ \\                                                  " << endl;
    cout << "   /.....,.........(........,%/((*#....., ***********@                                                | |__| | |  | |  \\| |  | |      | |__ | |   | | |__) |                                                   " << endl;
    cout << "  (...... (#........,../...%..%**//..#/************/@                                                 |  __  | |  | | .   |  | |      |  __|| |   | |  _  /                                                     " << endl;
    cout << "    /.........//.............(/***************/ /*#                                                   | |  | | |__| | |\\  |  | |      | |   | |___| | | \\ \\                                                  " << endl;
    cout << "  @,.....................#/************//# (.*****%                                                   |_|  |_|\\____/|_| \\_|  |_|      |_|    \\_____/|_|  \\_\\                                               " << endl;
    cout << "         @@@@ %%%  @@@@  @@ @%#*/(*.......... *****              @//@                                                                                                                                           " << endl;
    cout << "                               @..............(******          @*/@                                                                             _____ _     _ ______ ______  _____ ______                       " << endl;
    cout << "                @ ..@        @@ ...............*******/@  %**/@  @                                                                             / ____| |   | |  ____| _____|/ ____|  ____|                      " << endl;
    cout << "               (.*..(@ @#******* ............../****/(/%( @   (.(*@                                                                           | |    | |___| | |__    |__  | (___ | |__                         " << endl;
    cout << "               #....**#***********&..........//**********%@   .....@                                                                          | |    |  ___  |  __|    __|  \\____\\|  __|                      " << endl;
    cout << "               @,...%****************(#***#(***************//*.....@                                                                          | |____| |   | | |____  |____ ____) | |____                       " << endl;
    cout << "                 (.../***///((#%%%%%###(((///****************%....(                                                                            \\_____|_|   |_|______|______|_____/|______|                     " << endl;
    cout << "                   @@@                             @@ #(/****....*                                                                                                                                              " << endl;
}

int menu()
{
    int option;
    cout << "MENU" << endl;
    cout << "____________________" << endl;
    cout << "       " << endl;
    cout << "1. START " << endl;
    cout << "____________________" << endl;
    cout << "Select an Option: " << endl;
    cin >> option;
    if (option == 1)
    {
        login();
    }
}

void login()
{
    int option;
    system("cls");
    header();
    cout << "KEYS and INSTRUCTIONS" << endl;
    cout << "                     " << endl;
    cout << "________________________________" << endl;
    cout << "                                " << endl;
    cout << "1. UP              for going UP" << endl;
    cout << "2. DOWN            for going DOWN" << endl;
    cout << "3. LEFT            for going LEFT" << endl;
    cout << "4. RIGHT           for going RIGHT" << endl;
    cout << "5. SPACE           for FIRING"    << endl;
    cout << "6. EXIT "                         << endl;
    cout << "________________________________" << endl;
    cout << "PreSs any key to continue : ";
    cin >> option;
    if (option == 6)
    {
        header();
    }
}

void printMaze()
{
    system("cls");
    cout << "###############################################################################################   " << endl;
    cout << "##                                                                                           ##   " << endl;
    cout << "##                                                                                           ##   " << endl;
    cout << "##                                                                                           ##   " << endl;
    cout << "## ########################                    #######################                       ##   " << endl;
    cout << "##                                            #                                              ##   " << endl;
    cout << "##                                            #                                       #########   " << endl;
    cout << "##                                            #                                              ##   " << endl;
    cout << "##                                            #                                              ##   " << endl;
    cout << "##          ########                          ##################                             ##   " << endl;
    cout << "##                                                                                    #########   " << endl;
    cout << "##                                                                                           ##   " << endl;
    cout << "##                                                                                           ##   " << endl;
    cout << "##                                                                                           ##   " << endl;
    cout << "##          ############                    ################                                 ##   " << endl;
    cout << "##                                         #                                                 ##   " << endl;
    cout << "##                                        #                                                  ##   " << endl;
    cout << "##                                       #                                                   ##   " << endl;
    cout << "##                                      #                                             #########   " << endl;
    cout << "##                                     #                                                #    ##   " << endl;
    cout << "##                                        ############                                  #    ##   " << endl;
    cout << "##                                                       #                              #    ##   " << endl;
    cout << "##                                                      #                               #######   " << endl;
    cout << "################                                       #              ########               ##   " << endl;
    cout << "##                                                    #                                      ##   " << endl;
    cout << "##                                   #################                                       ##   " << endl;
    cout << "###########                                                                                  ##   " << endl;
    cout << "##                                                                                           ##   " << endl;
    cout << "##                                                                                           ##   " << endl;
    cout << "###############################################################################################   " << endl;
}
// Player Character

char jerry1[6] = {' ', ' ', '^', '^', ' ', ' '};
char jerry2[6] = {' ', '(', '-', '-', ')', ' '};
char jerry3[6] = {' ', '(', '|', '|', ')', ' '};
char jerry4[6] = {' ', ' ', 'o', 'o', ' ', ' '};

// Enemy Character

// BEN
char ben1[6] = {' ', ' ', ' ', '-', '-', '-'};
char ben2[6] = {'<', '=', '=', '(', '-', ')'};
char ben3[6] = {' ', ' ', ' ', '\\', '@', '/'};
char ben4[6] = {' ', ' ', ' ', '*', '*', '*'};

// TOM
char enemy1[6] = {' ', ' ', ' ', '-', '-', '-'};
char enemy2[6] = {'<', '=', '=', '(', '-', ')'};
char enemy3[6] = {' ', ' ', ' ', '\\', '@', '/'};
char enemy4[6] = {' ', ' ', ' ', '*', '*', '*'};

// LILY
char lily1[6] = {' ', ' ', ' ', '-', '-', '-'};
char lily2[6] = {'<', '=', '=', '(', '-', ')'};
char lily3[6] = {' ', ' ', ' ', '\\', '@', '/'};
char lily4[6] = {' ', ' ', ' ', '*', '*', '*'};

// Player Coordinates
int jerryX = 5;
int jerryY = 5;

// Enemy Coordinates
int enemyX = 30;
int enemyY = 10;

int benX = 10;
int benY = 10;

int lilyX = 10;
int lilyY = 20;

void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

char getCharAtxy(short int x, short int y)
{
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufSize;
    coordBufSize.X = 1;
    coordBufSize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}

void printJerry()
{
    gotoxy(jerryX, jerryY);
    for (int index = 0; index < 6; index++)
    {
        cout << jerry1[index];
    }
    gotoxy(jerryX, jerryY + 1);
    for (int index = 0; index < 6; index++)
    {
        cout << jerry2[index];
    }
    gotoxy(jerryX, jerryY + 2);
    for (int index = 0; index < 6; index++)
    {
        cout << jerry3[index];
    }
    gotoxy(jerryX, jerryY + 3);
    for (int index = 0; index < 6; index++)
    {
        cout << jerry4[index];
    }
}

void printEnemy()
{
    gotoxy(enemyX, enemyY);
    for (int index = 0; index < 6; index++)
    {
        cout << enemy1[index];
    }
    gotoxy(enemyX, enemyY + 1);
    for (int index = 0; index < 6; index++)
    {
        cout << enemy2[index];
    }
    gotoxy(enemyX, enemyY + 2);
    for (int index = 0; index < 6; index++)
    {
        cout << enemy3[index];
    }
    gotoxy(enemyX, enemyY + 3);
    for (int index = 0; index < 6; index++)
    {
        cout << enemy4[index];
    }
}

void printBen()
{
    gotoxy(benX, benY);
    for (int index = 0; index < 6; index++)
    {
        cout << ben1[index];
    }
    gotoxy(benX, benY + 1);
    for (int index = 0; index < 6; index++)
    {
        cout << ben2[index];
    }
    gotoxy(benX, benY + 2);
    for (int index = 0; index < 6; index++)
    {
        cout << ben3[index];
    }
    gotoxy(benX, benY + 3);
    for (int index = 0; index < 6; index++)
    {
        cout << ben4[index];
    }
}

// PLAYER MOVEMENT

void moveJerryLeft()
{
    char next1 = getCharAtxy(jerryX - 1, jerryY);
    char next2 = getCharAtxy(jerryX - 1, jerryY + 1);
    char next3 = getCharAtxy(jerryX - 1, jerryY + 2);
    char next4 = getCharAtxy(jerryX - 1, jerryY + 3);

    if (next1 == ' ' && next2 == ' ' && next3 == ' ' && next4 == ' ')
    {
        eraseJerry();
        jerryX = jerryX - 1;
        printJerry();
    }
}

void moveJerryRight()
{
    char next1 = getCharAtxy(jerryX + 6, jerryY);
    char next2 = getCharAtxy(jerryX + 6, jerryY + 1);
    char next3 = getCharAtxy(jerryX + 6, jerryY + 2);
    char next4 = getCharAtxy(jerryX + 6, jerryY + 3);

    if (next1 == ' ' && next2 == ' ' && next3 == ' ' && next4 == ' ')
    {
        eraseJerry();
        jerryX = jerryX + 1;
        printJerry();
    }
}

void moveJerryUp()
{
    char next1 = getCharAtxy(jerryX, jerryY - 1);
    char next2 = getCharAtxy(jerryX + 1, jerryY - 1);
    char next3 = getCharAtxy(jerryX + 2, jerryY - 1);
    char next4 = getCharAtxy(jerryX + 3, jerryY - 1);
    char next5 = getCharAtxy(jerryX + 4, jerryY - 1);
    char next6 = getCharAtxy(jerryX + 5, jerryY - 1);

    if (next1 == ' ' && next2 == ' ' && next3 == ' ' && next4 == ' ' && next5 == ' ' && next6 == ' ')
    {
        eraseJerry();
        jerryY = jerryY - 1;
        printJerry();
    }
}

void moveJerryDown()
{
    char next1 = getCharAtxy(jerryX, jerryY + 4);
    char next2 = getCharAtxy(jerryX + 1, jerryY + 4);
    char next3 = getCharAtxy(jerryX + 2, jerryY + 4);
    char next4 = getCharAtxy(jerryX + 3, jerryY + 4);
    char next5 = getCharAtxy(jerryX + 4, jerryY + 4);
    char next6 = getCharAtxy(jerryX + 5, jerryY + 4);

    if (next1 == ' ' && next2 == ' ' && next3 == ' ' && next4 == ' ' && next5 == ' ' && next6 == ' ')
    {
        eraseJerry();
        jerryY = jerryY + 1;
        printJerry();
    }
}

void eraseJerry()
{
    gotoxy(jerryX, jerryY);
    for (int index = 0; index < 6; index++)
    {
        cout << " ";
    }
    gotoxy(jerryX, jerryY + 1);
    for (int index = 0; index < 6; index++)
    {
        cout << " ";
    }
    gotoxy(jerryX, jerryY + 2);
    for (int index = 0; index < 6; index++)
    {
        cout << " ";
    }
    gotoxy(jerryX, jerryY + 3);
    for (int index = 0; index < 6; index++)
    {
        cout << " ";
    }
}

// ENEMY MOVEMENT

void eraseEnemy()
{
    gotoxy(enemyX, enemyY);
    for (int index = 0; index < 6; index++)
    {
        cout << " ";
    }
    gotoxy(enemyX, enemyY + 1);
    for (int index = 0; index < 6; index++)
    {
        cout << " ";
    }
    gotoxy(enemyX, enemyY + 2);
    for (int index = 0; index < 6; index++)
    {
        cout << " ";
    }
    gotoxy(enemyX, enemyY + 3);
    for (int index = 0; index < 6; index++)
    {
        cout << " ";
    }
}

void eraseBen()
{
    gotoxy(benX, benY);
    for (int index = 0; index < 6; index++)
    {
        cout << " ";
    }
    gotoxy(benX, benY + 1);
    for (int index = 0; index < 6; index++)
    {
        cout << " ";
    }
    gotoxy(benX, benY + 2);
    for (int index = 0; index < 6; index++)
    {
        cout << " ";
    }
    gotoxy(benX, benY + 3);
    for (int index = 0; index < 6; index++)
    {
        cout << " ";
    }
}

void moveEnemy()
{
    generateBulletEnemy();
    if (enemyDirection == "Up")
    {
        char next1 = getCharAtxy(enemyX, enemyY - 1);
        char next2 = getCharAtxy(enemyX + 1, enemyY - 1);
        char next3 = getCharAtxy(enemyX + 2, enemyY - 1);
        char next4 = getCharAtxy(enemyX + 3, enemyY - 1);

        if (next1 == ' ' && next2 == ' ' && next3 == ' ' && next4 == ' ')
        {
            eraseEnemy();
            enemyY--;
            printEnemy();
        }
        else
        {
            enemyDirection = "Down";
        }
    }
    if (enemyDirection == "Down")
    {
        char next1 = getCharAtxy(enemyX, enemyY + 4);
        char next2 = getCharAtxy(enemyX + 1, enemyY + 4);
        char next3 = getCharAtxy(enemyX + 2, enemyY + 4);
        char next4 = getCharAtxy(enemyX + 3, enemyY + 4);

        if (next1 == ' ' && next2 == ' ' && next3 == ' ' && next4 == ' ')
        {
            eraseEnemy();
            enemyY++;
            printEnemy();
        }
        else
        {
            enemyDirection = "Up";
        }
    }
}

// BEN

void moveBen()
{
    int buffX;
    int buffY;

    eraseBen();
    buffX = benX - jerryX;
    buffY = benY - jerryY;
    if (buffX < 0)
    {
        buffX++;
    }
    else if (buffX > 0)
    {
        buffX--;
    }

    if (buffY < 0)
    {
        buffY++;
    }
    else if (buffY > 0)
    {
        buffY--;
    }

    char nextX = getCharAtxy(jerryX + buffX, benY);
    char nextY = getCharAtxy(benX, jerryY + buffY);
    if (nextX == ' ')
    {
        benX = jerryX + buffX;
    }
    if (nextY == ' ')
    {
        benY = jerryY + buffY;
    }
    printBen();
}

// Firing

// GENERATE BULLET

void generateBullet()
{
    bulletX[bulletCount] = jerryX + 7;
    bulletY[bulletCount] = jerryY;
    isBulletActive[bulletCount] = true;
    gotoxy(jerryX + 7, jerryY);
    cout << ".";
    bulletCount++;
}

void generateBulletEnemy()
{
    bulletEX[bulletECount] = enemyX - 1;
    bulletEY[bulletECount] = enemyY;
    isBulletEnemyActive[bulletECount] = true;
    gotoxy(enemyX - 1, enemyY);
    cout << "*";
    bulletECount++;
}

void generateBulletBen()
{
    bulletBenX[bulletBenCount] = benX - 1;
    bulletBenY[bulletBenCount] = benY;
    isBulletBenActive[bulletBenCount] = true;
    gotoxy(benX - 1, benY);
    cout << "*";
    bulletBenCount++;
}

// BULLET RELATED FUNCTIONS

// PRINT BULLET

void printBullet(int x, int y)
{
    gotoxy(x, y);
    cout << ".";
}

void printBulletEnemy(int x, int y)
{
    gotoxy(x, y);
    cout << "*";
}

void printBulletBen(int x, int y)
{
    gotoxy(x, y);
    cout << "*";
}

// ERASE BULLET

void eraseBullet(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}

void eraseBulletEnemy(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}

void eraseBulletBen(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}

// BULLET DISAPPEAR

void makeBulletInactive(int index)
{
    isBulletActive[index] = false;
}

void makeBUlletInactiveEnemy(int index)
{
    isBulletEnemyActive[index] = false;
}

void makeBulletInactiveBen(int index)
{
    isBulletBenActive[index] = false;
}

// MOVE BULLET

void moveBullet()
{
    for (int x = 0; x < bulletCount; x++)
    {
        if (isBulletActive[x] == true)
        {
            char next = getCharAtxy(bulletX[x] + 1, bulletY[x]);
            if (next != ' ')
            {
                eraseBullet(bulletX[x], bulletY[x]);
                makeBulletInactive(x);
            }
            else
            {
                eraseBullet(bulletX[x], bulletY[x]);
                bulletX[x] = bulletX[x] + 1;
                printBullet(bulletX[x], bulletY[x]);
            }
        }
    }
}

void moveEnemyBullet()
{
    for (int x = 0; x < bulletECount; x++)
    {
        if (isBulletEnemyActive[x] == true)
        {
            char next = getCharAtxy(bulletEX[x] - 1, bulletEY[x]);
            if (next != ' ')
            {
                eraseBulletEnemy(bulletEX[x], bulletEY[x]);
                makeBUlletInactiveEnemy(x);
            }
            else
            {
                eraseBulletEnemy(bulletEX[x], bulletEY[x]);
                bulletEX[x] = bulletEX[x] - 1;
                printBulletEnemy(bulletEX[x], bulletEY[x]);
            }
        }
    }
}

void moveBenBullet()
{
    for (int x = 0; x < bulletBenCount; x++)
    {
        if (isBulletBenActive[x] == true)
        {
            char next = getCharAtxy(bulletBenX[x] - 1, bulletBenY[x]);
            if (next != ' ')
            {
                eraseBulletBen(bulletBenX[x], bulletBenY[x]);
                makeBulletInactiveBen(x);
            }
            else
            {
                eraseBulletBen(bulletBenX[x], bulletBenY[x]);
                bulletBenX[x] = bulletBenX[x] - 1;
                printBulletBen(bulletBenX[x], bulletBenY[x]);
            }
        }
    }
}

// COLLISION DETECTION

// BULLET COLLISION WITH ENEMY

void bulletCollisionWithEnemy()
{
    for (int x = 0; x < bulletBenCount; x++)
    {
        if (isBulletBenActive[x] == true)
        {
            if (bulletX[x] + 1 == enemyX && (bulletY[x] == enemyY || bulletY[x] == enemyY + 2 || bulletY[x] == enemyY + 3))
            {
                addScore();
            }
            else if (enemyX - 1 == bulletX[x] && enemyY + 1 == bulletY[x])
            {
                addScore();
            }
        }
    }
}

void bulletCollisionWithBen()
{
    for (int x = 0; x < bulletBenCount; x++)
    {
        if (isBulletActive[x] == true)
        {
            if (bulletBenX[x] + 1 == benX && (bulletBenY[x] == benY || bulletBenY[x] == benY + 2 || bulletBenY[x] == benY + 3))
            {
                addScore();
            }
            else if (benX - 1 == bulletBenX[x] && benY + 1 == bulletBenY[x])
            {
                addScore();
            }
        }
    }
}

void healthCheck2()
{
    for (int x = 0; x < bulletECount; x++)
    {
        if (isBulletEnemyActive[x] == true)
        {
            if (bulletEX[x] - 1 == jerryX && (bulletEY[x] == jerryY || bulletEY[x] == jerryY + 2 || bulletEY[x] == jerryY + 3 || bulletEY[x] == jerryY + 4))
            {
                decreaseHealth2();
            }
            else if (jerryX + 1 == bulletEX[x] && jerryY - 1 == bulletEY[x])
            {
                decreaseHealth2();
            }
        }
    }
}

void healthCheck1()
{
    for (int x = 0; x < bulletBenCount; x++)
    {
        if (isBulletBenActive[x] == true)
        {
            if (bulletBenX[x] - 1 == jerryX && (bulletBenY[x] == jerryY || bulletBenY[x] == jerryY + 2 || bulletBenY[x] == jerryY + 3 || bulletBenY[x] == jerryY + 4))
            {
                decreaseHealth1();
            }
            else if (jerryX + 1 == bulletBenX[x] && jerryY - 1 == bulletBenY[x])
            {
                decreaseHealth1();
            }
        }
    }
}

// HEALTH

void decreaseHealth1()
{
    health1--;
}
void decreaseHealth2()
{
    health--;
}

void printHealth1()
{
    gotoxy(54, 38);
    cout << "Health: " << health1;
}
void printHealth2()
{
    gotoxy(55, 39);
    cout << "Health: " << health;
}

// SCORE

void addScore()
{
    score++;
}
void printScore()
{
    gotoxy(55, 35);
    cout << "Score: " << score;
}