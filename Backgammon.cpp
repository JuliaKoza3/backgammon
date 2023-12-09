// Backgammon.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS
#include "conio2.h"
#include <cstdlib>
#include <stdio.h>
#include<ctime>

#define WIDHT 50
#define HIGHT 15

#define AREA_HIGHT 5
#define AREA_AMOUNT 24

#define PAWNS_AMOUNT 15

#define MAX_LETTERS 5

#define FILE_NAME "board.txt"

#define PRINT_START_MENUX 50
#define PRINT_START_MENUY 10

#define COMMENTS_X 60
#define COMMENTS_Y 10

#define MENU_X 1
#define MENU_Y 25




using namespace std;

typedef struct board {

    int X[AREA_AMOUNT];
    int Y[AREA_HIGHT + 1][AREA_AMOUNT];
    char inside[PAWNS_AMOUNT][AREA_AMOUNT];
};

int inputInt()                                           //input function//////////////////////
{
    int x;
    if (scanf("%d", &x) > 0) {
        printf("%d  ", x);
    }
    else printf("You did not enter any number.\n");
    return x;
}    

char inputChar()
{
    char x;
    if (scanf("%c", &x) > 0) {
        printf("%c", x);
    }
    else printf("You did not enter any number.\n");
    return x;
}                                                   //////////////////////////////////////////////////



int throwDice()
{
    return rand() % 6 + 1;    
}



void looseTrun()                                                //comment functions////////////////////////////
{                                                               
    gotoxy(COMMENTS_X, COMMENTS_Y);                             
    printf("move not possible u lose ur turn");
}                                                                  

void startComent()
{
    gotoxy(1, 27);
    printf("Enter where u want to start");
}

void finishComent()
{
    gotoxy(65, 27);
    printf("Enter where u want to finish");
}

void pawnsQuestion()
{
    gotoxy(30, 27);
    printf("How many pawns u want to move?  ");
}                                                     ////////////////////////////////////////////////




void corrdiantesForAreasX(struct board *areas)                          //zapis inforamcji o polac i poczatkowe ustwaienie pionków
{
    
    int k = 43;
    for (int i = 0; i < (AREA_AMOUNT / 4); i++)
    {
        areas->X[i] = k;
        k -= 3;
    }
    k = 18;
    for (int i = (AREA_AMOUNT / 4); i < 2 * (AREA_AMOUNT / 4); i++)
    {
        areas->X[i] = k;
        k -= 3;
    }
    k = 3;
    for (int i = 2 * (AREA_AMOUNT / 4); i < 3 * (AREA_AMOUNT / 4); i++)
    {
        areas->X[i] = k;
        k += 3;
    }
    k = 28;
    for (int i = 3 * (AREA_AMOUNT / 4); i < AREA_AMOUNT; i++)
    {
        areas->X[i] = k;
        k += 3;
    }
}


void corrdinatesForAreasY(struct board *areas)
{
    
    int a = 19;
    for (int i = 0; i < (AREA_HIGHT+1); i++)
    {
        for (int j = 0; j < (AREA_AMOUNT / 2); j++)
        {
            areas->Y[i][j] = a;
        }
        a--;

    }
    a = 5;
    for (int i = 0; i < (AREA_HIGHT+1); i++)
    {
        for (int j = (AREA_AMOUNT / 2); j < AREA_AMOUNT; j++)
        {
            areas->Y[i][j] = a;
        }
        a++;

    }
}


void markPawnsOnAreas(struct board *areas)
{
    
    for (int i = 0; i < PAWNS_AMOUNT; i++)
    {
        for (int j = 0; j < AREA_AMOUNT; j++)
        {
            if (j % 2)
            {
                areas->inside[i][j] = ':';
            }
            else
            {
                areas->inside[i][j] = '!';
            }
        }
    }

    for (int i = 0; i < 2; i++)
    {
        areas->inside[i][0] = '[';
        areas->inside[i][23] = '#';
    }
    for (int i = 0; i < 5; i++)
    {
        areas->inside[i][5] = '#';
        areas->inside[i][11] = '[';
        areas->inside[i][12] = '#';
        areas->inside[i][18] = '[';
    }
    for (int i = 0; i < 3; i++)
    {
        areas->inside[i][7] = '#';
        areas->inside[i][16] = '[';
    }
}
                                             //////////////////////////////////////////////////////////////




void printAreas(void)                          //wyswietalnie wszystkich elementów planszy na podstawie wspo³rzednych ekarnu
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
    putch('\n');

}

void printLowerNumbers()
{
    putch(' ');
    for (int i = 12; i > 9; i--)
    {
        putch(' ');
        printf("%i", i);
    }
    for (int i = 9; i > 6; i--)
    {
        putch(' ');
        putch(' ');
        printf("%i", i);
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
    }
}      
void printOptions()
{
    printf("'M'- move");
    printf("    ");
    printf("'S' - save game");
}       
void printBoard(char name1[MAX_LETTERS], char name2[MAX_LETTERS])
{

    textcolor(MAGENTA);
    printf("Julia Koza, 198151\n");
    gotoxy(36, 2);
    for (int i = 0; i < MAX_LETTERS; i++)
    {
        printf("%c", name1[i]);
    }
    printf("    PAWNS: []");
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
    for (int i = 0; i < MAX_LETTERS; i++)
    {
        printf("%c", name2[i]);
    }
    printf("   PAWNS: ##");
    putch('\n');
    printOptions();

}                                                                 ////////////////////////////////////////////////



void printDices(int n1, int n2)
{   
    printf("DICE 1: %d    ", n1);
    printf("DICE 2: %d    ", n2);
    
}


void printWhitePawns(int i, int j, int k, struct board *areas)                 //drukowanie pionków na polach i pól
{
    if (i > 4)
    {
        textcolor(BLUE);
    }
    gotoxy(areas->X[j], areas->Y[k][j]);
    insline;
    putch('[');
    gotoxy(areas->X[j] + 1, areas->Y[k][j]);
    insline;
    putch(']');
    textcolor(MAGENTA);

}            

void printDarkPawns(int i, int j, int k, struct board *areas)
{
    if (i > 4)
    {
        textcolor(BLUE);
    }
    gotoxy(areas->X[j], areas->Y[k][j]);
    insline;
    putch('#');
    gotoxy(areas->X[j] + 1, areas->Y[k][j]);
    insline;
    putch('#');
    textcolor(MAGENTA);
}

void printWhiteAreas(int i, int j, int k, struct board *areas)
{
    gotoxy(areas->X[j], areas->Y[i][j]);
    insline;
    putch('!');
    gotoxy(areas->X[j] + 1, areas->Y[i][j]);
    insline;
    putch('!');
}

void printDarkAreas(int i, int j, int k, struct board* areas)
{
    gotoxy(areas->X[j], areas->Y[i][j]);
    insline;
    putch(':');
    gotoxy(areas->X[j] + 1, areas->Y[i][j]);
    insline;
    putch(':');
}

void printPawns(struct board* areas)
{
    for (int i = 0; i < 15; i++)
    {
        int k = i;
        for (int j = 0; j < AREA_AMOUNT; j++)
        {
            if (i > 4)
            {
                k = 4;                              
            }
            if (areas->inside[i][j] == '[')
            {
                printWhitePawns(i, j, k, areas);                
            }
            else  if (areas->inside[i][j] == '#')
            {
                printDarkPawns(i, j, k, areas);              
                
            }
            if (i <= 4)
            {
                if (areas->inside[i][j] == '!')
                {
                    printWhiteAreas(i, j, k, areas);

                }
                else if (areas->inside[i][j] == ':')
                {
                    printDarkAreas(i, j, k, areas);
                   
                }
            }
        }
    }
    gotoxy(MENU_X, MENU_Y);

}                                                                       //////////////////////////////////////////////





void player1starts()                                                //funkcje do wyswietlania menu startowego
{
    gotoxy(PRINT_START_MENUX, PRINT_START_MENUY + 11);
    printf("first one starts");
    gotoxy(PRINT_START_MENUX, PRINT_START_MENUY + 12);
    printf("press enter to start the game");
}

void player2starts()
{
    gotoxy(PRINT_START_MENUX, PRINT_START_MENUY + 11);
    printf("second one starts");
    gotoxy(PRINT_START_MENUX, PRINT_START_MENUY + 12);
    printf("press enter to start the game");
}

void adjustingNamesN1(char player1name[MAX_LETTERS], char player2name[MAX_LETTERS], char name1[MAX_LETTERS], char name2[MAX_LETTERS])
{
    for (int i = 0; i < MAX_LETTERS; i++)
    {
        name1[i] = player1name[i];
        name2[i] = player2name[i];
    }
}

void adjustingNamesN2(char player1name[MAX_LETTERS], char player2name[MAX_LETTERS], char name1[MAX_LETTERS], char name2[MAX_LETTERS])
{
    for (int i = 0; i < MAX_LETTERS; i++)
    {
        name1[i] = player2name[i];
        name2[i] = player1name[i];
    }

}

void newGame(char player1name[MAX_LETTERS], char player2name[MAX_LETTERS], char name1[MAX_LETTERS], char name2[MAX_LETTERS])
{
    int n1 = throwDice();
    int n2 = throwDice();
    gotoxy(PRINT_START_MENUX, PRINT_START_MENUY+8);
    printf("first one: %d", n1);
    gotoxy(PRINT_START_MENUX, PRINT_START_MENUY + 9);
    printf("second one: %d", n2);

    if ( n1> n2)
    {
        adjustingNamesN1(player1name, player2name, name1, name2);
        player1starts();
        
    }
    else if (n2 > n1)
    {
        adjustingNamesN2(player1name, player2name, name1, name2);
        player2starts();

    }
    else
    {
        newGame(player1name, player2name, name1, name2);
    }

}

void printStartMenu()
{
    gotoxy(PRINT_START_MENUX, PRINT_START_MENUY);
    printf("N - new game\n");
    gotoxy(PRINT_START_MENUX, PRINT_START_MENUY + 1);
    printf("S - play from saved game\n");
    gotoxy(PRINT_START_MENUX, PRINT_START_MENUY + 3);

}

void printBeginingOfGame(struct board* areas, char player1name[MAX_LETTERS], char player2name[MAX_LETTERS], char name1[MAX_LETTERS], char name2[MAX_LETTERS])
{
    newGame(player1name, player2name, name1, name2);
    getch();
    clrscr();
    gotoxy(1, 1);
    printBoard(name1, name2);
    printPawns(areas);

}

void readSavedGame(struct board*areas)
{
    FILE* file;
    file = fopen(FILE_NAME, "r");
    if (!file)
    {
        printf("Error, cant open a file");
    }
    else
    {

        size_t err = fread(areas->inside, sizeof(char), PAWNS_AMOUNT * AREA_AMOUNT, file);
        if (err != PAWNS_AMOUNT * AREA_AMOUNT)
        {
            printf("Error, problem with reading from file");
        }
        fclose(file);
    }

}

void enterPlayerName(char player1name[MAX_LETTERS], char player2name[MAX_LETTERS])
{
    char l;
    gotoxy(PRINT_START_MENUX, PRINT_START_MENUY + 5);
    printf("Enter name of first player: ");
    for (int i = 0; i < MAX_LETTERS; i++)
    {
        player1name[i] = inputChar();
    }

    gotoxy(PRINT_START_MENUX, PRINT_START_MENUY + 6);
    printf("Enter name of second player: ");
    for (int i = 0; i < MAX_LETTERS; i++)
    {
        player2name[i] = inputChar();
    }

}

void startMenu(struct board* areas, char player1name[MAX_LETTERS], char player2name[MAX_LETTERS], char name1[MAX_LETTERS], char name2[MAX_LETTERS])
{
    printStartMenu();

    char option = inputChar();

    if (option == 'N')
    {
        enterPlayerName(player1name, player2name);
        printBeginingOfGame(areas, player1name, player2name, name1, name2);


    }
    else if (option == 'S')
    {
        readSavedGame(areas);
        printBeginingOfGame(areas, player1name, player2name, name1, name2);

    }                                                                                      

}                                                                                                  ///////////////////////////////////////////////




void highlightWhitePawns(int optionMove, struct board* areas, int i)                             // funkcje do podswietlania po³ na które moze pojsc gracz
{
    textcolor(YELLOW);
    gotoxy(areas->X[optionMove], areas->Y[i][optionMove]);
    insline;
    putch('[');
    gotoxy(areas->X[optionMove] + 1, areas->Y[i][optionMove]);
    insline;
    putch(']');
    gotoxy(1, 27);

}

void highlightDarkPawns(int optionMove, struct board* areas, int i)
{
    textcolor(YELLOW);
    gotoxy(areas->X[optionMove], areas->Y[i][optionMove]);
    insline;
    putch('#');
    gotoxy(areas->X[optionMove] + 1, areas->Y[i][optionMove]);
    insline;
    putch('#');
    gotoxy(1, 27);
}

void highlightWhiteAreas(int optionMove, struct board* areas, int i)
{
    textcolor(YELLOW);
    gotoxy(areas->X[optionMove], areas->Y[i][optionMove]);
    insline;
    putch('!');
    gotoxy(areas->X[optionMove] + 1, areas->Y[i][optionMove]);
    insline;
    putch('!');
    gotoxy(1, 27);
}

void highlightDarkAreas(int optionMove, struct board* areas, int i)
{
    textcolor(YELLOW);
    gotoxy(areas->X[optionMove], areas->Y[i][optionMove]);
    insline;
    putch(':');
    gotoxy(areas->X[optionMove] + 1, areas->Y[i][optionMove]);
    insline;
    putch(':');
    gotoxy(1, 27);

}

void highlight(int* optionMove, struct board* areas)
{
    for (int i = 0; i < AREA_HIGHT; i++)
    {
        if (areas->inside[i][*optionMove] == '[')
        {
            highlightWhitePawns(*optionMove, areas, i);
        }
        else if (areas->inside[i][*optionMove] == '#')
        {
            highlightDarkPawns(*optionMove,areas, i);
        }
        else if (areas->inside[i][*optionMove] == '!')
        {
            highlightWhiteAreas(*optionMove, areas, i);
        }
        else if (areas->inside[i][*optionMove] == ':')
        {
            highlightDarkAreas(*optionMove, areas, i);
        }
    }
    textcolor(MAGENTA);
}                                                                                               //////////////////////////////////////////////////




int checkPossibilityOfMoveForPlayer1(int optionMove, struct board* areas)                     //sprawdzanie mo¿liwoœci ruchu dla player1 i player2
{
    bool move = false;
    if (areas->inside[0][optionMove] == '[')
    {
        highlight(&optionMove, areas);
        move = true;
    }
    else if (areas->inside[0][optionMove] == '!' || areas->inside[0][optionMove] == ':')
    {
        highlight(&optionMove, areas);
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

int checkPossibilityOfMoveForPlayer2(int optionMove, struct board* areas)
{
    bool move = false;
    if (areas->inside[0][optionMove] == '#')
    {
        highlight(&optionMove, areas);
        move = true;
    }
    else if (areas->inside[0][optionMove] == '!' || areas->inside[0][optionMove] == ':')
    {
        highlight(&optionMove,areas);
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

}                                                                     ///////////////////////////////////////////



void changeValuesInAreas(struct board* areas, int start)                                 //zmaina warosci w tablicy inside, na podsatie której drukuja sie pionki
{
    for (int i = 0; i < PAWNS_AMOUNT; i++)
    {
        if (areas->inside[i + 1][start - 1] == '!' || areas->inside[i + 1][start - 1] == ':')
        {
            if ((start - 1) % 2)
            {
                areas->inside[i][start - 1] = ':';                                   
            }
            else
            {
                areas->inside[i][start - 1] = '!';                
            }
        }
    }
}

void changeValuesInAreasForPlayer1(struct board* areas, int finish)
{
    for (int i = 0; i < PAWNS_AMOUNT; i++)
    {
        if (areas->inside[i][finish - 1] == '!' || areas->inside[i][finish - 1] == ':')
        {
            areas->inside[i][finish - 1] = '[';
            break;

        }
    }
}

void changeValuesInAreasForPlayer2(struct board* areas, int finish)
{
    for (int i = 0; i < PAWNS_AMOUNT; i++)
    {
        if (areas->inside[i][finish - 1] == '!' || areas->inside[i][finish - 1] == ':')
        {
            areas->inside[i][finish - 1] = '#';
            break;

        }
       
    }

}                                                                                                       ///////////////////////////



void changeValues_PawnsPlayer1(struct board* areas, int finish)                                    //zmiana w areas i drukowanie pionków
{                                                                                                  //powstaly zeby zmniejszyc funkcje
    changeValuesInAreasForPlayer1(areas, finish);
    printPawns(areas);
}

void changeValues_PawnsPlayer2(struct board* areas, int finish)
{
    changeValuesInAreasForPlayer2(areas, finish);
    printPawns(areas);
}                                                                                           /////////////////////////////////////////////




bool showMovesOptionsForPlayer1DubletOnlyOne(int n1, int start, struct board* areas)                    //sparwdzanie mo¿liwosci ruchów dla róznych opcji dubleta
{                                                                                                      // only one-n1
    int optionMove = start+n1-1;                                                                        // only two - n1 i n1*2
    if (!checkPossibilityOfMoveForPlayer1(optionMove, areas))
    {
        looseTrun();
        return false;
    }
    else
    {
        return true;
    }
}


void showMovesOptionsForPlayer1DubletOnlyTwo(int n1, int start, struct board* areas)
{
    bool possibleMove = false;
    int optionMove = start+n1 * 2-1;
    if (!checkPossibilityOfMoveForPlayer1(optionMove, areas))
    {
        possibleMove=false;
    }

    possibleMove = (showMovesOptionsForPlayer1DubletOnlyOne(n1, start, areas));
    if (!possibleMove)
    {
        looseTrun();
        return;
    }

}

bool showMovesOptionsForPlayer2DubletOnlyOne(int n1, int start, struct board* areas)
{
    int optionMove = start-n1-1;
    if (!checkPossibilityOfMoveForPlayer2(optionMove, areas))
    {
        looseTrun();
        return false;
    }
    else
    {
        return true;
    }
}


void showMovesOptionsForPlayer2DubletOnlyTwo(int n1, int start, struct board* areas)
{
    bool possibleMove = false;
    int optionMove = start-n1 * 2-1;
    if (!checkPossibilityOfMoveForPlayer2(optionMove, areas))
    {
        possibleMove = false;
    }

    possibleMove = (showMovesOptionsForPlayer2DubletOnlyOne(n1, start, areas));
    if (!possibleMove)
    {
        looseTrun();
        return;
    }
                                                                                                        ////////////////////////////////
}



void option1Player1(int n1, int start, struct board* areas)                          // opcja dla n1 i warunek sprawdzajacy czy mo¿na wykonac ruch player1 i player2
{
    int optionMove = start + n1 - 1;
    if (!checkPossibilityOfMoveForPlayer1(optionMove, areas))
    {
        looseTrun();
        return;
    }
    changeValuesInAreas(areas, start);
    finishComent();
    int finish = inputInt();
    if (finish == optionMove + 1)
    {
        changeValuesInAreasForPlayer1(areas, finish);

    }
    printPawns(areas);

}

void option1Player2(int n1, int start, struct board* areas)
{
    int optionMove = start - n1 - 1;
    if (!checkPossibilityOfMoveForPlayer2(optionMove, areas))
    {
        looseTrun();
        return;
    }
    changeValuesInAreas(areas, start);
    finishComent();
    int finish = inputInt();
    if (finish == optionMove + 1)
    {
        changeValuesInAreasForPlayer2(areas, finish);

    }
    printPawns(areas);

}

void conditionForOption1Player1(int n1, int start,  struct board* areas)
{
    if (start + n1 > AREA_AMOUNT)
    {
        looseTrun();
        return;
    }
    else
    {

        option1Player1(n1, start, areas);
    }

}

void conditionForOption1Player2(int n1 ,int start, struct board* areas)
{
    if (start-n1 <1)
    {
        looseTrun();
        return;
    }
    else
    {
        option1Player2(n1, start,  areas);
    }

}                                                                             ///////////////////////////////////////




void option2Player1(int n1, int start, struct board* areas)                       // opcja dla n1*2 i warunke sprawdzajacy czy da sie wykonac ruch player1 player2
{
    int optionMove = start + n1 * 2 - 1;
    if (!checkPossibilityOfMoveForPlayer1(optionMove, areas))
    {
        looseTrun();
        return;
    }
    changeValuesInAreas(areas, start);
    finishComent();
    int finish = inputInt();
    if (finish == optionMove + 1)
    {
        changeValuesInAreasForPlayer1(areas, finish);
    }

}

void option2Player2(int n1, int start, struct board* areas)
{
    int optionMove = start - n1 * 2 - 1;
    if (!checkPossibilityOfMoveForPlayer2(optionMove, areas))
    {
        looseTrun();
        return;
    }
    changeValuesInAreas(areas, start);
    finishComent();
    int finish = inputInt();
    if (finish == optionMove + 1)
    {
        changeValuesInAreasForPlayer2(areas, finish);
    }




}

void conditionForOption2Player1(int n1, int start, struct board* areas)
{
    if (start + n1 * 2 > AREA_AMOUNT)
    {
        looseTrun();
        return;
    }
    else
    {
        option2Player1(n1, start, areas);
    }

}

void conditionForOption2Player2(int n1, int start, struct board* areas)
{
    if (start - n1 * 2 > AREA_AMOUNT)
    {
        looseTrun();
        return;
    }
    else
    {
        option2Player2(n1, start, areas);
    }
    
}                                                                                      ///////////////////////////////////////////////////////////////////




void dubletOption4Player1(int n1, int start, struct board* areas)                       // opcja n1 * 4 dla player1 i player2 i warunke czy mozna zrobic ruch
{
    int optionMove = (start + (n1 * 4)) - 1;
    if (!checkPossibilityOfMoveForPlayer1(optionMove, areas))
    {
        looseTrun();
        return;
    }
    changeValuesInAreas(areas, start);

    finishComent();
    int finish = inputInt();
    if (finish == optionMove + 1)
    {
        changeValuesInAreasForPlayer1(areas, finish);
    }

}

void dubletOption4Player2(int n1, int start, struct board* areas)
{
    int optionMove = (start - (n1 * 4)) - 1;
    if (!checkPossibilityOfMoveForPlayer2(optionMove, areas))
    {
        looseTrun();
        return;
    }
    changeValuesInAreas(areas, start);

    finishComent();
    int finish = inputInt();
    if (finish == optionMove + 1)
    {
        changeValuesInAreasForPlayer2(areas, finish);
    }

}

void conditionDublet4Player1(int start, int n1, struct board* areas)                                
{
    if (start + n1 * 4 > AREA_AMOUNT)
    {
        looseTrun();
        return;
    }
    else
    {
        dubletOption4Player1(n1, start, areas);

    }
}

void conditionDublet4Player2(int start, int n1, struct board* areas)
{
    if ((start - n1 * 4) < 1)
    {
        looseTrun();
        return;
    }
    else
    {
        dubletOption4Player2(n1, start, areas);

    }
}                                                                            ///////////////////////////////////////////////////////////



                                                                        




void dubletOption2_2Player1(int n1, int start, struct board* areas)                //opcja n1*2 i n1*2 dla player1 i player2 i warunek czy mozna zrobic ruch             
{
    

    option2Player1(n1, start, areas);
    
    printPawns(areas);

    startComent();
    start = inputInt();

    conditionForOption2Player1(n1, start, areas);    
}


void dubletOption2_2Player2(int n1, int start, struct board* areas)
{
    option2Player2(n1, start, areas);

    printPawns(areas);

    startComent();
    start = inputInt();
    
    conditionForOption2Player2(n1, start, areas);
}   

void conditionDublet2Player2(int con2, int n1, int start, struct board* areas)
{
    if (con2 < 1)
    {
        looseTrun();
        return;
    }
    else
    {
        dubletOption2_2Player2(n1, start, areas);
    }
}

void conditionDublet2Player1(int con2, int n1, int start, struct board* areas)        
{
    if (con2 > AREA_AMOUNT)
    {
        looseTrun();
        return;
    }
    else
    {
        dubletOption2_2Player1(n1, start, areas);
    }
}                                                                                                          ///////////////////////////////////////////////





void dubletOption1_1_1_1Player1(int n1, int start, struct board* areas)               // opcja dla n1 n1 n1 n1 dla player1 i player2 i warunke wykonania ruchu
{
    option1Player1(n1,start, areas);

    
    
    for (int i = 0; i < 3; i++)
    {
        startComent();
        start = inputInt();

        conditionForOption1Player1(n1, start, areas);
        
    }
}

void dubletOption1_1_1_1Player2(int n1, int start, struct board* areas)
{
    option1Player2(n1, start, areas);   

    
    for (int i = 0; i < 3; i++) 
    {
        startComent();
        start = inputInt();
        

        conditionForOption1Player2(n1, start, areas);

    }
} 

void conditionDublet1Player1(int con1, int n1, int start, struct board* areas)
{
    if (con1 > AREA_AMOUNT)
    {
        looseTrun();
        return;

    }
    else
    {
        dubletOption1_1_1_1Player1(n1, start, areas);
    }

}

void conditionDublet1Player2(int con1, int n1, int start, struct board* areas)
{
    if (con1 < 1)
    {
        looseTrun();
        return;

    }
    else
    {
        dubletOption1_1_1_1Player2(n1, start, areas);
    }

}                                                                                                  //////////////////////////////////



void option211Player1(int n1, int start, int finish, struct board* areas)                     // opcja n1*2 n1 n1 dla player1 i player2
{
    changeValuesInAreasForPlayer1(areas, finish);
    printPawns(areas);
    for (int i = 0; i < 2; i++)
    {
        startComent();
        start = inputInt();

        conditionForOption1Player1(n1, start, areas);
    }
    

}


void option211Player2(int n1, int start, int finish, struct board* areas)
{
    changeValues_PawnsPlayer2(areas, finish);
    
    for (int i = 0; i < 2; i++)
    {
        startComent();
        start = inputInt();
        

        conditionForOption1Player2(n1, start, areas);       

    }

}                                                                              //////////////////////////////////////////////////////



void option_12Player1(int n1, int start, int finish, struct board*areas)           //opcja _ n1 n1*2 oraz opcja _ n1*2 n1 dla player1 
{
    changeValues_PawnsPlayer1(areas, finish);
    start = inputInt();
    
    conditionForOption2Player1(n1, start, areas);
}

void option_21Player1(int n1, int start, int finish, struct board* areas)
{
    changeValues_PawnsPlayer1(areas, finish);

    startComent();
    start = inputInt();

    conditionForOption1Player1(n1, start, areas);
}                                                                       ///////////////////////////////////////////////////////////////



void opt112_121Player1(int n1, int finish, struct board* areas)                      //opcja n1 n1 n1*2
{                                                                                    // opcja n1 n1*2 n1 dla player1 
    changeValues_PawnsPlayer1(areas, finish);

    startComent();
    int start = inputInt();
    
    if ((start + n1) > AREA_AMOUNT)
    {
        if ((start + n1 * 2) > AREA_AMOUNT)
        {
            looseTrun();
            return;
        }
    }
    showMovesOptionsForPlayer1DubletOnlyTwo(n1, start, areas);
    changeValuesInAreas(areas, start);

    finishComent();
    finish = inputInt();

    if (finish == start + n1 || finish == start + n1 * 2)
    {
        if (finish == start + n1)
        {
            //n1
            option_12Player1(n1, start, finish, areas);          

        }
        else
        {
            //n1*2
            option_21Player1(n1, start, finish, areas);
        }
    }
}                                                                                       /////////////////////////////////////



void option_12Player2(int n1, int start, int finish, struct board*areas)                           //opcja _ n1 n1*2 oraz opcja _ n1*2 n1 dla player2
{
    changeValues_PawnsPlayer2(areas, finish);
    startComent();
    start = inputInt();
    conditionForOption2Player2(n1, start, areas);

}

void option_21Player2(int n1, int start, int finish, struct board*areas)
{
    changeValues_PawnsPlayer2(areas, finish);

    startComent();
    start = inputInt();
   

    conditionForOption1Player2(n1, start, areas);
}                                                                                       ///////////////////////////////////////////////




void option112_121Player2(int n1, int finish, struct board* areas)                            //opcja n1 n1 n1*2
{                                                                                             // opcja n1 n1*2 n1 dla player2
    changeValues_PawnsPlayer2(areas, finish);

    startComent();
    int start = inputInt();
   
    
    if ((start - n1) <1)
    {
        if ((start - n1 * 2) <1)
        {
            looseTrun();
            return;
        }
    }
    showMovesOptionsForPlayer2DubletOnlyTwo(n1, start, areas);
    changeValuesInAreas(areas, start);
    finishComent();
    finish = inputInt();
    if (finish == start - n1 || finish == start-n1*2)
    {
        if (finish == start - n1)
        {
            //n1
            option_12Player2(n1, start, finish, areas);          
        }
        else
        {
            //n1*2
            option_21Player2(n1, start, finish, areas);          
        }
    }
}                                                                                      //////////////////////////////////////



void dubletOption2_1_1Player1(int n1, int start, struct board* areas)                //opcja kiedy ruszamy trzema pionkami po wyrzuceniu dubletu 
{                                                                                    // trzy wrianty dla player1 i player2 
    showMovesOptionsForPlayer1DubletOnlyTwo(n1, start, areas);
    changeValuesInAreas(areas, start);
    finishComent();
    int finish = inputInt();
    if (finish == start+n1 || finish == start+n1*2)
    {
        if (finish == start + n1 * 2)
        {
            if (start + n1 * 2 > AREA_AMOUNT)
            {
                looseTrun();
                return;
            }
            else
            {
                option211Player1(n1, start, finish, areas);
            }
            //n1*2
            
        }
        else
        {
            if (start+n1 > AREA_AMOUNT)
            {
                looseTrun();
                return;
            }
            else
            {
                opt112_121Player1(n1, finish, areas);
            }
            //n1
                        
        }
    }

}

void dubletOption2_1_1Player2(int n1, int start, struct board* areas)                        
{                                                                                           
    showMovesOptionsForPlayer2DubletOnlyTwo(n1, start, areas);
    changeValuesInAreas(areas, start);
    finishComent();
    int finish = inputInt();
    if (finish == start-n1 || finish == start-n1*2)
    {
        if (finish == start-n1*2)
        {
            //n1*2
            option211Player2(n1, start, finish, areas);
        }
        else
        {
            //n1
            option112_121Player2(n1, finish, areas);

        }
    }

}                                                                                             ///////////////////////////////////////////////////





void dubletPlayer1(int start, int n1, struct board* areas)                                  //dublet player1 i player2
{
    int con1 = start + n1;
    int con2 = start + (n1 * 2);


    pawnsQuestion();
    int amount = inputInt();

    

    if (amount == 1)
    {
        conditionDublet4Player1(start, n1, areas);
    }
    else if (amount == 2)
    {
        conditionDublet2Player1(con2, n1, start, areas);      

    }
    else if (amount == 3)
    {


        dubletOption2_1_1Player1(n1, start, areas);


    }
    else if (amount == 4)
    {
        conditionDublet1Player1(con1, n1, start, areas);
    }

}

void dubletPlayer2(int start, int n1, struct board* areas)
{
    int con1 = start - n1;
    int con2 = start - n1 * 2;

    pawnsQuestion();
    int amount = inputInt();

    if (amount == 1)
    {
        conditionDublet4Player2(start, n1, areas);
        
    }
    else if (amount == 2)
    {
        conditionDublet2Player2(con2, n1, start, areas);

    }
    else if (amount == 3)
    {


        dubletOption2_1_1Player2(n1, start, areas);


    }
    else if (amount == 4)
    {
        conditionDublet1Player2(con1, n1, start, areas);
       

    }

}                                                                                         ///////////////////////////////////////////////////////




void changeValuesInAreasMovePlayer1(int n1, int n2, int start, int finish, int player, struct board* areas)          //funkcje do wykoniania ruchu player1
{
    if (finish == start + n1 || finish == start + n2 || finish == start + n1 + n2)
    {
        changeValuesInAreasForPlayer1(areas, finish);
    }

}

void insideOfShowMovesPlayer1(int n1, int n2, int start, int optionMove, struct board*areas)   //podfunkcja showMovesOptionsForPlayer1
{
    int possibleMove = checkPossibilityOfMoveForPlayer1(optionMove, areas);

    optionMove = (start - 1 + n2);
    if (optionMove + 1 < AREA_AMOUNT)
    {
        possibleMove = checkPossibilityOfMoveForPlayer1(optionMove, areas);


    }
    possibleMove = checkPossibilityOfMoveForPlayer1(optionMove, areas);

    if (possibleMove)
    {
        optionMove += n1;
        if (optionMove + 1 < AREA_AMOUNT)
        {
            checkPossibilityOfMoveForPlayer1(optionMove, areas);
        }
    }
    else
    {
        looseTrun();
    }

}


void showMovesOptionsForPlayer1(int n1, int n2, int start, int beat,int player, struct board* areas)       //pokazanie na planszy mozliwych ruchów
{
    int optionMove = (start - 1 + n1);
    if (areas->inside[0][start - 1] == '[')
    {
        if (optionMove+1>AREA_AMOUNT)
        {
            looseTrun();
            return;           
            
        }
        else
        {
            insideOfShowMovesPlayer1(n1, n2, start, optionMove, areas);
            
        }
    }
    else
    {
        looseTrun();
    }
    
}

int correctPawnPlayer1(int start, struct board*areas)                          // sprawdzenie czy gracz wybral dobry pionek, jesi nie to utrata kolejki
{
    if (areas->inside[0][start - 1] != '[')
    {
        gotoxy(COMMENTS_X, COMMENTS_Y);
        printf("Not ur pawn");
        return 0;
    }
}

void normalPlayer1(int n1, int n2, int start, int beat, int player, struct board*areas)               //podfunkcja movePlayer1
{
    showMovesOptionsForPlayer1(n1, n2, start, beat, player, areas);


    finishComent();
    int finish = inputInt();

    changeValuesInAreasMovePlayer1(n1, n2, start, finish, player, areas);
    changeValuesInAreas(areas, start);
    printPawns(areas);
    return;
}

void movePlayer1(struct board* areas, int beat, int player)
{
    int n1 = throwDice();
    int n2 = throwDice();
    printDices(n1, n2);
    putch('\n');

    startComent();

    int start = inputInt();
    if (!correctPawnPlayer1(start, areas))
    {
        return;
    }


    if (n1 == n2)
    {
        dubletPlayer1(start, n1, areas);
        printPawns(areas);
        return;
    }
    else
    {
        normalPlayer1(n1, n2, start, beat, player, areas);
        return;       
    }
}                                                                  /////////////////////////////////////////////////





void changeValuesInAreasMovePlayer2(int n1, int n2, int start, int finish, int player, struct board* areas)           //funkcje do wykoniania ruchu player1
{
    if (finish == start - n1 || finish == start - n2 || finish == start - n1 - n2)
    {
        changeValuesInAreasForPlayer2(areas, finish);
    }
}

void insideOfShowMovesPlayer2(int n1, int n2, int start, int optionMove, struct board* areas)                  //podfunkcja showMovesOptionsForPlayer2
{
    int possibleMove = checkPossibilityOfMoveForPlayer2(optionMove, areas);

    optionMove = (start - 1 - n2);
    if (start - n2 > 1)
    {
        possibleMove = checkPossibilityOfMoveForPlayer2(optionMove, areas);
    }

    if (possibleMove)
    {
        optionMove -= n1;
        if (start - n1 - n2 > 1)
        {
            checkPossibilityOfMoveForPlayer2(optionMove, areas);
        }
    }
    else
    {
        looseTrun();
    }
}

void showMovesOptionsForPlayer2(int n1, int n2, int start, int beat, int player, struct board* areas)             //pokazanie na planszy mozliwych ruchów
{
    int optionMove = start - 1 - n1;
    if (areas->inside[0][start - 1] == '#')
    {
        if (optionMove + 1 < 1)
        {
            looseTrun();
            return;
        }
        else
        {
            insideOfShowMovesPlayer2(n1, n2, start, optionMove, areas);
        }


    }
    else
    {
        looseTrun();
    }


}

int correctPawnPlayer2(int start, struct board*areas)                                                       // sprawdzenie czy gracz wybral dobry pionek, jesi nie to utrata kolejki
{
    if (areas->inside[0][start - 1] != '#')
    {
        gotoxy(COMMENTS_X, COMMENTS_Y);
        printf("Not ur pawn");
        return 0;
    }

}

void normalPlayer2(int n1, int n2, int start, int beat, int player, struct board*areas)             //podfunkcja movePlayer2
{
    showMovesOptionsForPlayer2(n1, n2, start, beat, player, areas);
    changeValuesInAreas(areas, start);
    finishComent();


    int finish = inputInt();

    changeValuesInAreasMovePlayer2(n1, n2, start, finish, player, areas);

    printPawns(areas);
}


void movePlayer2(struct board* areas, int beat, int player)
{
    int n1 = throwDice();
    int n2 = throwDice();
    printDices(n1, n2);
    putch('\n');

    startComent();

    int start = inputInt();

    if (!correctPawnPlayer2(start, areas))
    {
        return;
    }   

    if (n1 == n2)
    {
        dubletPlayer2(start, n1, areas);
        printPawns(areas);        
    }
    else
    {
        normalPlayer2(n1, n2, start, beat, player, areas);  
        return;
    }
}                                                                      //////////////////////////////////////




void saveGame(struct board* areas)                                //zapis gry do pliku
{
    FILE* file;
    file = fopen(FILE_NAME, "w");

    file = fopen(FILE_NAME, "w");
    if (!file)
    {
        printf("Error opening the file.\n");
        return;

    }  
    else
    {
        fwrite(areas->inside, sizeof(areas->inside[0][0]), PAWNS_AMOUNT * AREA_AMOUNT, file);
        fclose(file);
    }
  

} 



void clearMistakeComment()                           //funkcje do czyszczenia komentarzy
{
    gotoxy(COMMENTS_X, COMMENTS_Y);
    clreol();
    gotoxy(MENU_X, MENU_Y);

}

void cleanComments()
{
    gotoxy(MENU_X, MENU_Y);
    delline();
    gotoxy(MENU_X, MENU_Y + 1);
    delline();
    gotoxy(MENU_X, MENU_Y + 2);
    delline();
    gotoxy(MENU_X, MENU_Y);
}                                        //////////////////////////////////////////////////////




bool menu(struct board* areas,int beat, int player)               //Menu 
{
    char menu = inputChar();
    if (menu == 'M')
    {
        clearMistakeComment();
        if (player == 1)
        {
            movePlayer1(areas, beat, player);
            return false;
        }
        else
        {
            movePlayer2(areas, beat, player);
            return false;
        }
    }
    else if (menu == 'S')
    {
        clearMistakeComment();

    }
}                                   ///////////////////////////////////////////////////////////

void Important(struct board*areas, char player1name[MAX_LETTERS], char player2name[MAX_LETTERS], char name1[MAX_LETTERS], char name2[MAX_LETTERS])           //wazne do zrobienia przed rozpoczeciem gry
{
    corrdiantesForAreasX(areas);
    corrdinatesForAreasY(areas);
    markPawnsOnAreas(areas);
    startMenu(areas, player1name, player2name, name1, name2);
}






int main()
{
    srand((unsigned)time(0));

    struct board areas;   

    char player1name[MAX_LETTERS];
    char player2name[MAX_LETTERS];

    char name1[MAX_LETTERS];
    char name2[MAX_LETTERS];

    bool player1 = true;
    bool player2 = true;   
    int player = 0;
   

    int beat = 0; 

    Important(&areas, player1name, player2name, name1, name2);


    while (player1 && player2)
    {
        if (player1)
        {
            player = 1;
            printf("Choose option from menu\n");            
            player1=menu(&areas, beat, player);
            cleanComments();
        }
        if (player2)
        {          
            player = 2;
            printf("Choose option from menu\n");
            player2=menu(&areas, beat, player);
            cleanComments();
        }
        player1 = true;
        player2 = true;
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
