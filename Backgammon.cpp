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
#define PAWNS_AMOUNT 15
#define MAX_LETTERS 20
#define FILE_NAME "board.txt"
#define PRINT_START_MENUX 50
#define PRINT_START_MENUY 10


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


void markPawnsOnAreas(char areas[AREA_HIGHT][AREA_AMOUNT], int amountOfPawns[AREA_AMOUNT])
{
    for (int j = 0; j < AREA_AMOUNT; j++)
    {
        amountOfPawns[j] = 0;
    }
    
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
        putch(':');
        for (int j = 0; j < 3; j++)
        {
            putch(' ');
            putch(':');
            putch(':');
            putch(' ');
            putch('\\');
            putch('/');

        }
        putch('|');
        for (int j = 0; j < 4; j++)
        {
            putch(' ');
        }
        putch('|');
        for (int j = 0; j < 3; j++)
        {
            putch(' ');
            putch(':');
            putch(':');
            putch('\\');
            putch('/');

        }
        putch('|');
        for (int j = 0; j < 4; j++)
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


void printDices(int n1, int n2)
{   
    cout << "DICE 1: " << n1 << "   ";
    cout << "DICE 2: " << n2 << "   ";

}



void printOptions()
{
    cout << "'M'- move";
    cout << "    ";
    cout << "'D'- throw dices";
    cout << "    ";
    cout << "'S' - save game";
    cout << "    ";
    cout << "'N' - new game";
    cout << "    ";
    cout << "'R' - show ranking";
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
                if (i>4)
                {
                    textcolor(BLUE);
                    gotoxy(areasX[j], areasY[k+1][j]);
                    cout << amountOfPawns[j]+1;
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
            else  if (areas[i][j] == '#')
            {
                
                if (i > 4)
                {
                    textcolor(BLUE);
                    gotoxy(areasX[j], areasY[k + 1][j]);
                    cout << amountOfPawns[j] + 1;
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
            else
            {
                continue;
            }

        }
    }
    gotoxy(1, 27);

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
        gotoxy(PRINT_START_MENUX, PRINT_START_MENUY + 8);
        cout <<"first one starts"; 
        gotoxy(PRINT_START_MENUX, PRINT_START_MENUY + 9);
        cout<< "press enter to start the game";
    }
    else if (n2 > n1)
    {
        gotoxy(PRINT_START_MENUX, PRINT_START_MENUY + 8);
        cout <<"second one starts"; 
        gotoxy(PRINT_START_MENUX, PRINT_START_MENUY + 9);
        cout << "press enter to start the game";
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
    gotoxy(36, 22);
    cout << "player2name";
    putch('\n');
   // printDices();
    printOptions();

}

void startMenu(char areas[PAWNS_AMOUNT][AREA_AMOUNT], int areasX[AREA_HIGHT], int areasY[AREA_HIGHT][AREA_AMOUNT], int amountOfPawns[AREA_AMOUNT], char player1name[MAX_LETTERS], char player2name[MAX_LETTERS])
{   gotoxy(PRINT_START_MENUX, PRINT_START_MENUY);
    cout << "N - new game" << endl;
    gotoxy(PRINT_START_MENUX, PRINT_START_MENUY + 1);
    cout << "S - play from saved game" << endl;
    gotoxy(PRINT_START_MENUX, PRINT_START_MENUY + 3);
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
        if (kbhit)
        {
            clrscr();
            gotoxy(1, 1);
            printBoard();
            printPawns(areas, areasX, areasY, amountOfPawns);
        }

    }
    if (getche() == 'S')
    {
        //otwieranie zapisanej gry
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


    corrdiantesForAreasX(areasX);
    corrdinatesForAreasY(areasY);
    markPawnsOnAreas(areas, amountOfPawns);
    startMenu(areas, areasX, areasY, amountOfPawns, player1name, player2name);

    

    


    //Menu
    int startArea;
    int finishArea;
    if (getch() == 'M')
    {
        if (kbhit)
        {
            int n1 = throwDice();
            int n2 = throwDice();
            printDices(n1, n2);
            putch('\n');

            cout << "Enter number of area from where you want to move your pawn: \n";
            startArea=getche();
            putch('\n');
            //opcja dla bia³ych pionków
            if (*areas[(startArea + 1)] == '[')
            {
                //highlight();
            }
            else if (*areas[(startArea + 1)] == '0')
            {
                //highlight();
                
            }

            //opcja dla czarnych pionków

            if (*areas[(startArea + 1)] == '#')
            {
                //highlight();
            }
            else if (*areas[(startArea + 1)] == '0')
            {
                //highlight();

            }

            //sprawdzanie ruchów i podswietlanie pól


            cout << "Enter number of area you where you want to move your pawn: \n";
            finishArea = getche();

        }
               

    }

   

    

    //zapisywanie pliku
    FILE* file;
    //file = fopen(FILE_NAME, "w");

    errno_t err = fopen_s(&file, FILE_NAME, "w");



    
     //Check if the file was opened successfully

    if (err != 0 || file == NULL) {

        printf("Error opening the file.\n");

        return 1; // Exit the program with an error code

    }

    fwrite(areas, sizeof(areas[0][0]), sizeof(areas) / sizeof(areas[0][0]), file);
    fclose(file);


    
    




    







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
