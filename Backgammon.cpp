// Backgammon.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "conio2.h"
#include <cstdlib>
#include<ctime>

#define WIDHT 50
#define HIGHT 15
#define AREA_HIGHT 5
#define AREA_AMOUNT 24

using namespace std;

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


void corrdinatesForAreasY(int areasY[AREA_HIGHT][AREA_AMOUNT])
{
    
    int a = 19;
    for (int i = 0; i < AREA_HIGHT; i++)
    {
        for (int j = 0; j < (AREA_AMOUNT / 2); j++)
        {
            areasY[i][j] = a;
        }
        a--;

    }
    a = 5;
    for (int i = 0; i < AREA_HIGHT; i++)
    {
        for (int j = (AREA_AMOUNT / 2); j < AREA_AMOUNT; j++)
        {
            areasY[i][j] = a;
        }
        a++;

    }
}


void markPicesOnAreas(char areas[AREA_HIGHT][AREA_AMOUNT])
{
    for (int i = 0; i < AREA_HIGHT; i++)
    {
        for (int j = 0; j < AREA_AMOUNT; j++)
        {
            areas[i][j] = '0';
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
        cout << ":";
        cout << " " << "::" << " " << "!!" << " " << "::" << " " << "!!" << " " << "::" << " " << "!!" << " ";
        cout << "|    |";
        cout << " " << "::" << " " << "!!" << " " << "::" << " " << "!!" << " " << "::" << " " << "!!" << " ";
        cout << "|    |";
        cout << ":" << endl;
    }
}


void printBreak(void)
{
    for (int i = 0; i < (HIGHT - 2 * AREA_HIGHT); i++)
    {
        cout << ":";
        cout << " " << "  " << " " << "  " << " " << "  " << " " << "  " << " " << "  " << " " << "  " << " ";
        cout << "|    |";
        cout << " " << "  " << " " << "  " << " " << "  " << " " << "  " << " " << "  " << " " << "  " << " ";
        cout << "|    |";
        cout << ":" << endl;
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
        cout << " " << i;
    }
    for (int i = 0; i < 7; i++)
    {
        putch(' ');
    }
    for (int i = 19; i < 25; i++)
    {
        cout << " " << i;
    }
    cout << endl;

}


void printLowerNumbers()
{
    putch(' ');
    for (int i = 12; i > 9; i--)
    {
        cout << " " << i;
    }
    for (int i = 9; i > 6; i--)
    {
        cout << "  " << i;
    }
    for (int i = 0; i < 7; i++)
    {
        putch(' ');
    }
    for (int i = 6; i > 0; i--)
    {
        cout << "  " << i;
    }
}


void printDices()
{
    srand((unsigned)time(0));
    cout << "DICE 1: " << throwDice() << "   ";
    cout << "DICE 2: " << throwDice()<<"\n\n";
}

void printOptions()
{
    cout << "'D'- throw dices";
    cout << "    ";
    cout << "'S' - save game";
    cout << "    ";
    cout << "'N' - new game";
    cout << "    ";
    cout << "'R' - show ranking";
}

void printPices(char areas[AREA_HIGHT][AREA_AMOUNT], int areasX[AREA_HIGHT], int areasY[AREA_HIGHT][AREA_AMOUNT])
{
    for (int i = 0; i < AREA_HIGHT; i++)
    {
        for (int j = 0; j < AREA_AMOUNT; j++)
        {
            if (areas[i][j] == '[')
            {
                gotoxy(areasX[j], areasY[i][j]);
                insline;
                putch('[');
                gotoxy(areasX[j] + 1, areasY[i][j]);
                insline;
                putch(']');
            }
            else  if (areas[i][j] == '#')
            {
                gotoxy(areasX[j], areasY[i][j]);
                insline;
                putch('#');
                gotoxy(areasX[j] + 1, areasY[i][j]);
                insline;
                putch('#');
            }
            else
            {
                continue;
            }

        }
    }
    gotoxy(1, 27);

}


void printBoard(void)
{
    textmode(C4350);
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
    gotoxy(36, 22);
    cout << "player2name";
    putch('\n');
    printDices();
    printOptions();

}




int main()
{
    int areasX[AREA_AMOUNT];
    int areasY[AREA_HIGHT][AREA_AMOUNT];
    char areas[AREA_HIGHT][AREA_AMOUNT];
    printBoard();
    corrdiantesForAreasX(areasX);
    corrdinatesForAreasY(areasY);
    markPicesOnAreas(areas);
    printPices(areas, areasX, areasY);


    //oznaczenie czy pioenk jest czy nie (jesli jasny to [, jesli ciemny to #,  jesli nie ma to 0)
   
    //printPices(areas, areasX, areasY);


  


    //ustawianie pionków na planszy
   





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
