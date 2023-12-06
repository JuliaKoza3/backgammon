// Backgammon.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "conio2.h"
#include <cstdlib>
#include <stdio.h>
#include<ctime>

#define WIDHT 50
#define HIGHT 15
#define AREA_HIGHT 5
#define AREA_AMOUNT 24
#define PAWNS_AMOUNT 15
#define MAX_LETTERS 20
#define FILE_NAME "board.txt"
#define PRINT_START_MENUX 50
#define PRINT_START_MENUY 10


using namespace std;

int input()
{
    int x;
    if (scanf("%i", &x) > 0) {
        cout << x << endl;
    }
    else cout << "You did not enter any number.\n";
    return x;
}

int throwDice()
{
    return rand() % 6 + 1;    
}


void corrdiantesForAreasX(int areasX[AREA_AMOUNT])
{
    
    int k = 43;
    for (int i = 0; i < (AREA_AMOUNT / 4); i++)
    {
        areasX[i] = k;
        k -= 3;
    }
    k = 18;
    for (int i = (AREA_AMOUNT / 4); i < 2 * (AREA_AMOUNT / 4); i++)
    {
        areasX[i] = k;
        k -= 3;
    }
    k = 3;
    for (int i = 2 * (AREA_AMOUNT / 4); i < 3 * (AREA_AMOUNT / 4); i++)
    {
        areasX[i] = k;
        k += 3;
    }
    k = 28;
    for (int i = 3 * (AREA_AMOUNT / 4); i < AREA_AMOUNT; i++)
    {
        areasX[i] = k;
        k += 3;
    }
}


void corrdinatesForAreasY(int areasY[AREA_HIGHT+1][AREA_AMOUNT])
{
    
    int a = 19;
    for (int i = 0; i < (AREA_HIGHT+1); i++)
    {
        for (int j = 0; j < (AREA_AMOUNT / 2); j++)
        {
            areasY[i][j] = a;
        }
        a--;

    }
    a = 5;
    for (int i = 0; i < (AREA_HIGHT+1); i++)
    {
        for (int j = (AREA_AMOUNT / 2); j < AREA_AMOUNT; j++)
        {
            areasY[i][j] = a;
        }
        a++;

    }
}


void markPawnsOnAreas(char areas[PAWNS_AMOUNT][AREA_AMOUNT], int amountOfPawns[AREA_AMOUNT])
{
    for (int j = 0; j < AREA_AMOUNT; j++)
    {
        amountOfPawns[j] = 0;
    }
    
    for (int i = 0; i < PAWNS_AMOUNT; i++)
    {
        for (int j = 0; j < AREA_AMOUNT; j++)
        {
            if (j % 2)
            {
                areas[i][j] = ':';
            }
            else
            {
                areas[i][j] = '!';
            }
        }
    }

    for (int i = 0; i < 2; i++)
    {
        areas[i][0] = '[';
        areas[i][23] = '#';
    }
    for (int i = 0; i < 5; i++)
    {
        areas[i][5] = '#';
        areas[i][11] = '[';
        areas[i][12] = '#';
        areas[i][18] = '[';
    }
    for (int i = 0; i < 3; i++)
    {
        areas[i][7] = '#';
        areas[i][16] = '[';
    }


}


void printAreas(void)
{
    for (int i = 0; i < AREA_HIGHT; i++)
    {
        putch(':');
        for (int i = 0; i < 3; i++)
        {
            putch(' ');
            putch(':');
            putch(':');
            putch(' ');
            putch('!');
            putch('!');
            
        }
        putch(' ');
        putch('|');
        for (int i = 0; i < 4; i++)
        {
            putch(' ');
        }
        putch('|');
        for (int i = 0; i < 3; i++)
        {
            putch(' ');
            putch(':');
            putch(':');
            putch(' ');
            putch('!');
            putch('!');

        }
        putch(' ');
        putch('|');
        for (int i = 0; i < 4; i++)
        {
            putch(' ');
        }
        putch('|');
        putch(':');
        putch('\n');

        /*cout << ":";
        cout << " " << "::" << " " << "!!" << " " << "::" << " " << "!!" << " " << "::" << " " << "!!" << " ";
        cout << "|    |";
        cout << " " << "::" << " " << "!!" << " " << "::" << " " << "!!" << " " << "::" << " " << "!!" << " ";
        cout << "|    |";
        cout << ":" << endl;*/
    }
}


void printBreak(void)
{
    for (int i = 0; i < (HIGHT - 2 * AREA_HIGHT); i++)
    {
        putch(':');
        for (int i = 0; i < 19; i++)
        {
            putch(' ');
        }
        putch('|');
        for (int i = 0; i < 4; i++)
        {
            putch(' ');
        }
        putch('|');
        for (int i = 0; i < 19; i++)
        {
            putch(' ');
        }
        putch('|');
        for (int i = 0; i < 4; i++)
        {
            putch(' ');
        }
        putch('|');
        putch(':');
        putch('\n');

        /*cout << ":";
        cout << " " << "  " << " " << "  " << " " << "  " << " " << "  " << " " << "  " << " " << "  " << " ";
        cout << "|    |";
        cout << " " << "  " << " " << "  " << " " << "  " << " " << "  " << " " << "  " << " " << "  " << " ";
        cout << "|    |";
        cout << ":" << endl;*/
    }
}


void printFrame(void)
{
    putch(':');
    for (int i = 0; i < WIDHT; i++)
    {
        putch('=');
    }
    putch(':');
    putch('\n');

}


void printUpperNumbers()
{
    putch(' ');
    for (int i = 13; i < 19; i++)
    {
        putch(' ');
        printf("%i", i);
    }
    for (int i = 0; i < 7; i++)
    {
        putch(' ');
    }
    for (int i = 19; i < 25; i++)
    {
        putch(' ');
        printf("%i", i);
    }
    cout << endl;

}


void printLowerNumbers()
{
    putch(' ');
    for (int i = 12; i > 9; i--)
    {
        putch(' ');
        printf("%i", i);
        //cout << " " << i;
    }
    for (int i = 9; i > 6; i--)
    {
        putch(' ');
        putch(' ');
        printf("%i", i);
        //cout << "  " << i;
    }
    for (int i = 0; i < 7; i++)
    {
        putch(' ');
    }
    for (int i = 6; i > 0; i--)
    {
        putch(' ');
        putch(' ');
        printf("%i", i);
        //cout << "  " << i;
    }
}


void printDices(int n1, int n2)
{   
    cout << "DICE 1: " << n1 << "   ";
    cout << "DICE 2: " << n2 << "   ";
}



void printOptions()
{
    cout << "'M'- move";
    cout << "    ";
    cout << "'S' - save game";
    cout << "    ";
    cout << "'R' - show ranking";
}

void printWhitePawns(int i, int j, int k, int areasX[AREA_AMOUNT], int areasY[AREA_HIGHT][AREA_AMOUNT], int amountOfPawns[AREA_AMOUNT])
{
    if (i > 4)
    {
        textcolor(BLUE);
        //gotoxy(areasX[j], areasY[k+1][j]);
        //cout << amountOfPawns[j]+1;
    }
    gotoxy(areasX[j], areasY[k][j]);
    insline;
    putch('[');
    gotoxy(areasX[j] + 1, areasY[k][j]);
    insline;
    putch(']');
    amountOfPawns[j] += 1;
    textcolor(MAGENTA);

}

void printDarkPawns(int i, int j, int k, int areasX[AREA_AMOUNT], int areasY[AREA_HIGHT][AREA_AMOUNT], int amountOfPawns[AREA_AMOUNT])
{
    if (i > 4)
    {
        textcolor(BLUE);
        // gotoxy(areasX[j], areasY[k + 1][j]);
         //cout << amountOfPawns[j] + 1;
    }
    gotoxy(areasX[j], areasY[k][j]);
    insline;
    putch('#');
    gotoxy(areasX[j] + 1, areasY[k][j]);
    insline;
    putch('#');
    amountOfPawns[j] += 1;
    textcolor(MAGENTA);
}

void printWhiteAreas(int i, int j, int k, int areasX[AREA_AMOUNT], int areasY[AREA_HIGHT][AREA_AMOUNT], int amountOfPawns[AREA_AMOUNT])
{
    gotoxy(areasX[j], areasY[i][j]);
    insline;
    putch('!');
    gotoxy(areasX[j] + 1, areasY[i][j]);
    insline;
    putch('!');
}

void printDarkAreas(int i, int j, int k, int areasX[AREA_AMOUNT], int areasY[AREA_HIGHT][AREA_AMOUNT], int amountOfPawns[AREA_AMOUNT])
{
    gotoxy(areasX[j], areasY[i][j]);
    insline;
    putch(':');
    gotoxy(areasX[j] + 1, areasY[i][j]);
    insline;
    putch(':');
}

void printPawns(char areas[PAWNS_AMOUNT][AREA_AMOUNT], int areasX[AREA_HIGHT], int areasY[AREA_HIGHT][AREA_AMOUNT], int amountOfPawns[AREA_AMOUNT])
{
    int amount = 0;
    for (int i = 0; i < 15; i++)
    {
        int k = i;
        for (int j = 0; j < AREA_AMOUNT; j++)
        {
            if (i > 4)
            {
                k = 4;                              
            }
            if (areas[i][j] == '[')
            {
                printWhitePawns(i, j, k, areasX, areasY, amountOfPawns);                
            }
            else  if (areas[i][j] == '#')
            {
                printDarkPawns(i, j, k, areasX, areasY, amountOfPawns);              
                
            }
            if (i <= 4)
            {
                if (areas[i][j] == '!')
                {
                    printWhiteAreas(i, j, k, areasX, areasY, amountOfPawns);

                    //*amountOfPawns[j] += 1;
                    //textcolor(MAGENTA);
                }
                else if (areas[i][j] == ':')
                {
                    printDarkAreas(i, j, k, areasX, areasY, amountOfPawns);
                   
                    //*amountOfPawns[j] += 1;
                   // textcolor(MAGENTA);
                }
            }
        }
    }
    gotoxy(1, 25);

}

void player1starts()
{
    gotoxy(PRINT_START_MENUX, PRINT_START_MENUY + 8);
    cout << "first one starts";
    gotoxy(PRINT_START_MENUX, PRINT_START_MENUY + 9);
    cout << "press enter to start the game";
}

void player2starts()
{
    gotoxy(PRINT_START_MENUX, PRINT_START_MENUY + 8);
    cout << "second one starts";
    gotoxy(PRINT_START_MENUX, PRINT_START_MENUY + 9);
    cout << "press enter to start the game";
}

void newGame(char player1name[MAX_LETTERS], char player2name[MAX_LETTERS])
{
    int n1 = throwDice();
    int n2 = throwDice();
    gotoxy(PRINT_START_MENUX, PRINT_START_MENUY+5);
    cout << "first one: " << n1 << endl;
    gotoxy(PRINT_START_MENUX, PRINT_START_MENUY + 6);
    cout << "second one: " << n2 << endl;

    if ( n1> n2)
    {
        player1starts();
    }
    else if (n2 > n1)
    {
        player2starts();
    }
    else
    {
        newGame(player1name, player2name);
    }

}



void printBoard(void)
{
    //textmode(C4350);
    textcolor(MAGENTA);
    cout << "Julia Koza, 198151\n";
    gotoxy(36, 2);
    cout << "player1name";
    gotoxy(0, 3);
    putch('\n');
    printUpperNumbers();
    printFrame();
    printAreas();
    printBreak();
    printAreas();
    printFrame();
    printLowerNumbers();
    //printPawns();
    gotoxy(36, 22);
    cout << "player2name";
    putch('\n');
   // printDices();
    printOptions();

}

void printStartMenu()
{
    gotoxy(PRINT_START_MENUX, PRINT_START_MENUY);
    cout << "N - new game" << endl;
    gotoxy(PRINT_START_MENUX, PRINT_START_MENUY + 1);
    cout << "S - play from saved game" << endl;
    gotoxy(PRINT_START_MENUX, PRINT_START_MENUY + 3);

}

void startMenu(char areas[PAWNS_AMOUNT][AREA_AMOUNT], int areasX[AREA_HIGHT], int areasY[AREA_HIGHT][AREA_AMOUNT], int amountOfPawns[AREA_AMOUNT], char player1name[MAX_LETTERS], char player2name[MAX_LETTERS])
{   
    printStartMenu();

    if (getche() == 'N')
    {
        /*cout << "Enter name of first player: ";
        for (int i = 0; i < MAX_LETTERS; i++)
        {
            player1name[i] = getche();

        }
        cout << "Enter name of second player: ";
        for (int i = 0; i < MAX_LETTERS; i++)
        {
            player2name[i] = getche();

        }*/
        newGame(player1name, player2name);
        getch();        
        clrscr();                
        gotoxy(1, 1);
        printBoard();
        printPawns(areas, areasX, areasY, amountOfPawns);
        

    }
    else if (getche() == 's')
    {
        //otwieranie zapisanej gry
        FILE* file;
        file = fopen(FILE_NAME, "r");
        for (int i = 0; i < PAWNS_AMOUNT; i++)
        {
            for (int j = 0; j < AREA_AMOUNT; j++)
            {
                areas[i][j] = fread(areas, sizeof(char), 360, file);
            }
        }
        cout << "kot";
        newGame(player1name, player2name);
        getch();
        clrscr();
        gotoxy(1, 1);
        printBoard();
        printPawns(areas, areasX, areasY, amountOfPawns);


    }

}

void highlightWhitePawns(int optionMove, int areasX[AREA_AMOUNT], int areasY[AREA_HIGHT][AREA_AMOUNT], int i)
{
    textcolor(YELLOW);
    gotoxy(areasX[optionMove], areasY[i][optionMove]);
    insline;
    putch('[');
    gotoxy(areasX[optionMove] + 1, areasY[i][optionMove]);
    insline;
    putch(']');
    gotoxy(1, 27);

}

void highlightDarkPawns(int optionMove, int areasX[AREA_AMOUNT], int areasY[AREA_HIGHT][AREA_AMOUNT], int i)
{
    textcolor(YELLOW);
    gotoxy(areasX[optionMove], areasY[i][optionMove]);
    insline;
    putch('#');
    gotoxy(areasX[optionMove] + 1, areasY[i][optionMove]);
    insline;
    putch('#');
    gotoxy(1, 27);
}

void highlightWhiteAreas(int optionMove, int areasX[AREA_AMOUNT], int areasY[AREA_HIGHT][AREA_AMOUNT], int i)
{
    textcolor(YELLOW);
    gotoxy(areasX[optionMove], areasY[i][optionMove]);
    insline;
    putch('!');
    gotoxy(areasX[optionMove] + 1, areasY[i][optionMove]);
    insline;
    putch('!');
    gotoxy(1, 27);
}

void highlightDarkAreas(int optionMove, int areasX[AREA_AMOUNT], int areasY[AREA_HIGHT][AREA_AMOUNT], int i)
{
    textcolor(YELLOW);
    gotoxy(areasX[optionMove], areasY[i][optionMove]);
    insline;
    putch(':');
    gotoxy(areasX[optionMove] + 1, areasY[i][optionMove]);
    insline;
    putch(':');
    gotoxy(1, 27);

}

void highlight(int* optionMove, int areasX[AREA_AMOUNT], int areasY[AREA_HIGHT][AREA_AMOUNT], char areas[PAWNS_AMOUNT][AREA_AMOUNT])
{
    for (int i = 0; i < AREA_HIGHT; i++)
    {
        if (areas[i][*optionMove] == '[')
        {
            highlightWhitePawns(*optionMove, areasX, areasY, i);
        }
        else if (areas[i][*optionMove] == '#')
        {
            highlightDarkPawns(*optionMove, areasX, areasY, i);
        }
        else if (areas[i][*optionMove] == '!')
        {
            highlightWhiteAreas(*optionMove, areasX, areasY, i);
        }
        else if (areas[i][*optionMove] == ':')
        {
            highlightDarkAreas(*optionMove, areasX, areasY, i);
        }
    }
    textcolor(MAGENTA);
}



int checkPossibilityOfMoveForPlayer1(char areas[PAWNS_AMOUNT][AREA_AMOUNT], int optionMove, int areasX[AREA_AMOUNT], int areasY[AREA_HIGHT][AREA_AMOUNT])
{
    bool move = false;
    if (areas[0][optionMove] == '#')
    {
        if (areas[1][optionMove] == '!' || areas[1][optionMove] == ':')
        {
            highlight(&optionMove, areasX, areasY, areas);
            move = true;
            return 3;
        }
    }
    else if (areas[0][optionMove] == '[')
    {
        highlight(&optionMove, areasX, areasY, areas);
        move = true;
    }
    else if (areas[0][optionMove] == '!' || areas[0][optionMove] == ':')
    {
        highlight(&optionMove, areasX, areasY, areas);
        move = true;
    }
    if (move)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int checkPossibilityOfMoveForPlayer2(char areas[PAWNS_AMOUNT][AREA_AMOUNT], int optionMove, int areasX[AREA_AMOUNT], int areasY[AREA_HIGHT][AREA_AMOUNT])
{
    bool move = false;
    if (areas[0][optionMove] == '[')
    {
        if (areas[0][optionMove] == '!' || areas[0][optionMove] == ':')
        {
            highlight(&optionMove, areasX, areasY, areas);
            move = true;
            return 3;
        }
    }
    else if (areas[0][optionMove] == '#')
    {
        highlight(&optionMove, areasX, areasY, areas);
        move = true;
    }
    else if (areas[0][optionMove] == '!' || areas[0][optionMove] == ':')
    {
        highlight(&optionMove, areasX, areasY, areas);
        move = true;
    }
    
    if (move)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

void changeValuesInAreas(char areas[PAWNS_AMOUNT][AREA_AMOUNT], int start)
{
    for (int i = 0; i < PAWNS_AMOUNT; i++)
    {
        if (areas[i + 1][start - 1] == '!' || areas[i + 1][start - 1] == ':')
        {
            if ((start - 1) % 2)
            {
                areas[i][start - 1] = ':';
                //printPawns(areas, areasX, areasY, amountOfPawns);                    
            }
            else
            {
                areas[i][start - 1] = '!';
                //printPawns(areas, areasX, areasY, amountOfPawns);                    
            }
        }
        else
        {
            continue;
        }
    }
}

void showMovesOptionsForPlayer1DubletAll(int n1, char areas[PAWNS_AMOUNT][AREA_AMOUNT], int areasX[AREA_AMOUNT], int areasY[AREA_HIGHT][AREA_AMOUNT])
{
    int optionMove = n1 * 4;
    checkPossibilityOfMoveForPlayer1(areas, optionMove, areasX, areasY);

    showMovesOptionsForPlayer1DubletOnlyTwo(n1, areas, areasX, areasY);
    
}

void showMovesOptionsForPlayer1DubletOnlyTwo(int n1, char areas[PAWNS_AMOUNT][AREA_AMOUNT], int areasX[AREA_AMOUNT], int areasY[AREA_HIGHT][AREA_AMOUNT])
{
    int optionMove = n1 * 2;
    checkPossibilityOfMoveForPlayer1(areas, optionMove, areasX, areasY);

    showMovesOptionsForPlayer1DubletOnlyOne(n1, areas, areasX, areasY);
}

void showMovesOptionsForPlayer1DubletOnlyOne(int n1, char areas[PAWNS_AMOUNT][AREA_AMOUNT], int areasX[AREA_AMOUNT], int areasY[AREA_HIGHT][AREA_AMOUNT])
{
    int optionMove = n1;
    checkPossibilityOfMoveForPlayer1(areas, optionMove, areasX, areasY);
}

void dubletOption4(int n1, int start, char areas[PAWNS_AMOUNT][AREA_AMOUNT], int areasX[AREA_AMOUNT], int areasY[AREA_HIGHT][AREA_AMOUNT])
{
    int optionMove = start + n1 * 4;
    checkPossibilityOfMoveForPlayer1(areas, optionMove, areasX, areasY);
    int finish = input();
    if (finish == optionMove)
    {
        changeValuesInAreasForPlayer1(areas, finish);
    }

}

void option2(int con2, char areas[PAWNS_AMOUNT][AREA_AMOUNT], int areasX[AREA_AMOUNT], int areasY[AREA_HIGHT][AREA_AMOUNT])
{
    int optionMove = con2;
    checkPossibilityOfMoveForPlayer1(areas, optionMove, areasX, areasY);
    int finish = input();
    if (finish == optionMove)
    {
        changeValuesInAreasForPlayer1(areas, finish);
    }

}

void dubletOption2_2(int con2, char areas[PAWNS_AMOUNT][AREA_AMOUNT], int areasX[AREA_AMOUNT], int areasY[AREA_HIGHT][AREA_AMOUNT])
{
    option2(con2, areas, areasX, areasY);

    int start = input();

    option2(con2, areas, areasX, areasY);
    

}

void option1(int con1, char areas[PAWNS_AMOUNT][AREA_AMOUNT], int areasX[AREA_AMOUNT], int areasY[AREA_HIGHT][AREA_AMOUNT])
{
    int optionMove = con1;
    checkPossibilityOfMoveForPlayer1(areas, optionMove, areasX, areasY);
    int finish = input();
    if (finish == optionMove)
    {
        changeValuesInAreasForPlayer1(areas, finish);

    }

}

void dubletOption1_1_1_1(int con1, char areas[PAWNS_AMOUNT][AREA_AMOUNT], int areasX[AREA_AMOUNT], int areasY[AREA_HIGHT][AREA_AMOUNT])
{
    option1(con1, areas, areasX, areasY);
    for (int i = 0; i < 3; i++)
    {
        int start = input();
        option1(con1, areas, areasX, areasY);
    }
}


//zmiejszyc funkcje jeszce nie wiem jak
void showMovesOptionsForPlayer1(int n1, int n2, int start, int beat, char areas[PAWNS_AMOUNT][AREA_AMOUNT], int areasX[AREA_AMOUNT], int areasY[AREA_HIGHT][AREA_AMOUNT])
{
    int optionMove = (start - 1 + n1);

    if (areas[0][start - 1] == '[')
    {
        //rozpisaæ ta funkcje bo jest nie dokoñczona
        beat = checkPossibilityOfMoveForPlayer1(areas, optionMove, areasX, areasY);
    }
    if (beat != 3)
    {
        
        int possibleMove = checkPossibilityOfMoveForPlayer1(areas, optionMove, areasX, areasY);

        optionMove = (start - 1 + n2);

        possibleMove = checkPossibilityOfMoveForPlayer1(areas, optionMove, areasX, areasY);

        if (possibleMove == 1)
        {
            optionMove += n1;
            checkPossibilityOfMoveForPlayer1(areas, optionMove, areasX, areasY);
        }
    }
    else
    {
        cout << "u must beat";
    }
}

//zmiejszycfunkcje jeszce nie wiem jak
void showMovesOptionsForPlayer2(int n1, int n2, int start, int beat, char areas[PAWNS_AMOUNT][AREA_AMOUNT], int areasX[AREA_AMOUNT], int areasY[AREA_HIGHT][AREA_AMOUNT])
{
    int optionMove = (start - 1 - n1);

    if (areas[0][start - 1] == '#')
    {
        beat = checkPossibilityOfMoveForPlayer2(areas, optionMove, areasX, areasY);
    }
    if (beat != 3)
    {

        int possibleMove= checkPossibilityOfMoveForPlayer2(areas, optionMove, areasX, areasY);

        optionMove = (start - 1 - n2);

        possibleMove = checkPossibilityOfMoveForPlayer2(areas, optionMove, areasX, areasY);

        if (possibleMove == 1)
        {
            optionMove -= n1;
            checkPossibilityOfMoveForPlayer2(areas, optionMove, areasX, areasY);
        }
    }
    else
    {
        cout << "u must beat";
    }
}

void changeValuesInAreasForPlayer1(char areas[PAWNS_AMOUNT][AREA_AMOUNT], int finish)
{
    for (int i = 0; i < PAWNS_AMOUNT; i++)
    {
        if (areas[i][finish - 1] == '!' || areas[i][finish - 1] == ':')
        {           
            areas[i][finish - 1] = '[';
            // printPawns(areas, areasX, areasY, amountOfPawns);
            break;
            
        }
        /* else
         {
             continue;
         }*/
    }

}

void changeValuesInAreasMovePlayer1(int n1, int n2, int start, int finish, int player, char areas[PAWNS_AMOUNT][AREA_AMOUNT])
{
    if (finish == start + n1 || finish == start + n2 || finish == start + n1 + n2)
    {
        changeValuesInAreasForPlayer1(areas, finish);
    }

}

void changeValuesInAreasForPlayer2(int n1, int n2, int start, int finish, int player, char areas[PAWNS_AMOUNT][AREA_AMOUNT])
{
    if (finish == start - n1 || finish == start - n2 || finish == start - n1 - n2)
    {
        for (int i = 0; i < PAWNS_AMOUNT; i++)
        {
            if (areas[i][finish - 1] == '!' || areas[i][finish - 1] == ':')
            {
                if (player == 2)
                {
                    areas[i][finish - 1] = '#';
                    //printPawns(areas, areasX, areasY, amountOfPawns);
                    break;
                }
            }
            else
            {
                continue;
            }
        }
    }

}

void movePlayer1(char areas[PAWNS_AMOUNT][AREA_AMOUNT], int areasX[AREA_AMOUNT], int areasY[AREA_HIGHT][AREA_AMOUNT], int beat, int player, int amountOfPawns[AREA_AMOUNT])
{
    int n1 = throwDice();
    int n2 = throwDice();
    printDices(n1, n2);
    putch('\n');

    cout << "Enter start area\n";

    int start = input();


    changeValuesInAreas(areas, start);

    if (n1 == n2)
    {
        //opcja dla dubleta
        cout << "dublet";
    }
    else
    {
        showMovesOptionsForPlayer1(n1, n2, start, beat, areas, areasX, areasY);
    }

    cout << "Enter finish area\n";

    int finish = input();

    changeValuesInAreasMovePlayer1(n1, n2, start, finish, player, areas);

    printPawns(areas, areasX, areasY, amountOfPawns);
    //cout << "Next player move";

}

void movePlayer2(char areas[PAWNS_AMOUNT][AREA_AMOUNT], int areasX[AREA_AMOUNT], int areasY[AREA_HIGHT][AREA_AMOUNT], int beat, int player, int amountOfPawns[AREA_AMOUNT])
{
    int n1 = throwDice();
    int n2 = throwDice();
    printDices(n1, n2);
    putch('\n');

    cout << "Enter area from where u want to start\n";

    int start = input();


    changeValuesInAreas(areas, start);

    if (n1 == n2)
    {
        //opcja dla dubleta
        cout << "dublet";
    }
    else
    {
        showMovesOptionsForPlayer2(n1, n2, start, beat, areas, areasX, areasY);
    }

    cout << "Enter area where u want to finish\n";
    

    int finish = input();

    changeValuesInAreasForPlayer2(n1, n2, start, finish, player, areas);

    printPawns(areas, areasX, areasY, amountOfPawns);
    //cout << "Next player move";
    

}

void dubletOption2_1(int n1, int finish, int start, char areas[PAWNS_AMOUNT][AREA_AMOUNT], int areasX[AREA_AMOUNT], int areasY[AREA_HIGHT][AREA_AMOUNT])
{
    if (finish == start + n1 * 2)
    {
        //n1*2
        //change values in areas

    }
    else
    {
        //n1
        //change valus in areas
        start = input();
        showMovesOptionsForPlayer1DubletOnlyOne(n1, areas, areasX, areasY);
        finish = input();
        if (finish == start + n1)
        {
            //n1
            //change values in areas
        }
    }

}

int checkTimes(int n1, int start, int finish)
{
    
    int k = finish - start;
    int times = k / n1;
    return times;
}

int saveGame(char areas[PAWNS_AMOUNT][AREA_AMOUNT])
{
    //napisac funkcje na zapisywanie

    FILE* file;
    //file = fopen(FILE_NAME, "w");

    errno_t err = fopen_s(&file, FILE_NAME, "w");


    if (err != 0 || file == NULL) {

        printf("Error opening the file.\n");

        return 1;
    }

    fwrite(areas, sizeof(areas[0][0]), sizeof(areas) / sizeof(char), file);
    fclose(file);
    cout << "kot";

}

void menu( char areas[PAWNS_AMOUNT][AREA_AMOUNT], int areasX[AREA_AMOUNT], int areasY[AREA_HIGHT][AREA_AMOUNT],int beat, int player, int amountOfPawns[AREA_AMOUNT])
{
    if (getch() == 'M')
    {
        if (player == 1)
        {
            movePlayer1(areas, areasX, areasY, beat, player, amountOfPawns);
        }
        else
        {
            movePlayer2(areas, areasX, areasY, beat, player, amountOfPawns);
        }
    }
    else if (getch() == 'S')
    {
        saveGame(areas);

    }
}





int main()
{
    srand((unsigned)time(0));


    int areasX[AREA_AMOUNT];
    int areasY[AREA_HIGHT+1][AREA_AMOUNT];
    char areas[PAWNS_AMOUNT][AREA_AMOUNT];
    int amountOfPawns[AREA_AMOUNT];

    char player1name[MAX_LETTERS];
    char player2name[MAX_LETTERS];
    bool player1 = true;
    bool player2 = true;   
    int player = 0;
    char player1pawns = '[';
    char player2pawns = '#';

    int beat = 0;


    corrdiantesForAreasX(areasX);
    corrdinatesForAreasY(areasY);
    markPawnsOnAreas(areas, amountOfPawns);
    startMenu(areas, areasX, areasY, amountOfPawns, player1name, player2name);


    while (player1 && player2)
    {
        if (player1)
        {
            player = 1;
            cout << "Choose option from menu\n";            
            menu(areas, areasX, areasY, beat, player, amountOfPawns);
            gotoxy(1, 25);
            clreol();
            gotoxy(1, 26);
            clreol();
            gotoxy(1, 27);
            delline();
            gotoxy(1, 28);
            delline();
            gotoxy(1, 30);
            clreol();
            gotoxy(1, 25);
        }
        if (player2)
        {          
            player = 2;
            cout << "Choose option from menu\n";
            menu(areas, areasX, areasY, player2pawns, player, amountOfPawns);
            gotoxy(1, 25);
            clreol();
            gotoxy(1, 26);
            clreol();
            gotoxy(1, 27);
            delline();
            gotoxy(1, 28);
            delline();
            gotoxy(1, 30);
            clreol();
            gotoxy(1, 25);
        }
    } 

   

   



    //dublet
    //player1
    int n1;
    int k;
    int start = input();

    int con1 = start + n1;
    int con2 = start + n1 * 2;
    
    showMovesOptionsForPlayer1DubletAll(n1, areas, areasX, areasY);

    int finish = input();

    if (finish == con1 ||finish == con2 || finish == start + n1 * 4)
    {
        if (finish == start + n1 * 4)
        {
            //n1*4
           //change values in areas
        }
        else
        {           
           
            if (checkTimes(n1, start, finish) == 1)
            {
                //n1
                //change values in areas
                start = input();                
                showMovesOptionsForPlayer1DubletOnlyTwo(n1, areas, areasX, areasY);
                finish = input();

                if (finish == con1 || finish == con2)
                {
                    if (finish == con2)
                    {
                        //n1*2
                        //change values in areas
                        start = input();
                        showMovesOptionsForPlayer1DubletOnlyOne(n1, areas, areasX, areasY);              
                        finish = input();

                        if (finish == con1)
                        {
                            //n1
                            //change values in areas
                        }
                    }
                    else
                    {
                        //n1
                        //change values in areas
                        start = input();
                        showMovesOptionsForPlayer1DubletOnlyTwo(n1, areas, areasX, areasY);
                        finish = input();

                        if (finish == con1||finish==con2)
                        {
                            dubletOption2_1(n1, finish, start, areas, areasX, areasY);
                            
                        }
                    }
                }

            }
            else
            {
                //n1*2
                //change values
                start = input();
                showMovesOptionsForPlayer1DubletOnlyTwo(n1, areas, areasX, areasY);
                finish = input();
                if (finish == con1 || finish == con2)
                {
                    dubletOption2_1(n1, finish, start, areas, areasX, areasY);                    
                }
            }
        }
    }




    int n1;
    int k;
    int start = input();

    int con1 = start + n1;
    int con2 = start + n1 * 2;



    showMovesOptionsForPlayer1DubletAll(n1, areas, areasX, areasY);

    cout << "How many pawns u want to move?";
    int amount = input();

    if (amount == 1)
    {
        dubletOption4(n1, start, areas, areasX, areasY);
    }
    else if (amount == 2)
    {
        dubletOption2_2(con2, areas, areasX, areasY);        

    }
    else if (amount == 3)
    {

        //option2-1-1()
        showMovesOptionsForPlayer1DubletOnlyTwo(n1, areas, areasX, areasY);
        finish = input();
        if (finish == con1 || finish == con2)
        {
            if (finish == con2)
            {
                //n1*2
                changeValuesInAreasForPlayer1(areas, finish);
                for (int i = 0; i < 2; i++)
                {
                    start = input();
                    int optionMove = con1;
                    checkPossibilityOfMoveForPlayer1(areas, optionMove, areasX, areasY);
                    finish = input();
                    if (finish == optionMove)
                    {
                        changeValuesInAreasForPlayer1(areas, finish);
                    }
                }


            }
            else
            {
                //n1
                changeValuesInAreasForPlayer1(areas, finish);
                start = input();
                showMovesOptionsForPlayer1DubletOnlyTwo(n1, areas, areasX, areasY);
                finish = input();
                if (finish == start + n1|| finish==start+n1*2)
                {
                    if (finish == start + n1)
                    {
                        //n1
                        changeValuesInAreasForPlayer1(areas, finish);
                        start = input();
                        int optionMove = start + n1 * 2;
                        checkPossibilityOfMoveForPlayer1(areas, optionMove, areasX, areasY);
                        finish = input();
                        if (finish == optionMove)
                        {
                            //n2
                            changeValuesInAreasForPlayer1(areas, finish);
                        }


                    }
                    else
                    {

                    }
                }

            }
        }
    }
    else if (amount == 4)
    {
        dubletOption1_1_1_1(con1, areas, areasX, areasY);

    }














   

    

    

    
    




    







}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
