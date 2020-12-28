#include <stdio.h>
#include <stdlib.h>

//declaring the array globally as it'll be used in all functions
char a[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
void printBoard();
int markBoard(int choice, char mark);
int checkWinner();

int main()
{
    int player = 1, checker, marker, choice;
    char mark;
    do
    {
        system("clear");
        printBoard();

        if(player % 2 == 1)
        {
            player = 1;
            mark = 'X';
        }
        else
        {
            player = 2;
            mark = 'O';
        }

        printf("Player %d enter your choice:", player);
        scanf("%d", &choice);

        marker = markBoard(choice, mark);
        // decrement player if the input choice is invalid
        if(marker == 0)
        {
            --player;
        }

        checker = checkWinner();
        // increment player only if no one has either win or draw
        if(checker == -1)
        {
            player++;
        }
    }
    while(checker == -1);
    
    system("clear");
    printBoard();
    if(checker == 1)
    {
        printf("Player %d has won.\n\n", player);
    }
    else
    {
        printf("<----------Game Draw---------->\n\n");
    }
}

// a function to print out the board and assigning
// the array elements each to its required place
void printBoard()
{
    printf("____Player 1 (X) ---- Player 2 (O) ____\n\n");
    printf("    |    |    \n");
    printf(" %c  | %c  | %c \n", a[1], a[2], a[3]);
    printf("____|____|____\n");
    printf("    |    |    \n");
    printf(" %c  | %c  | %c \n", a[4], a[5], a[6]);
    printf("____|____|____\n");
    printf("    |    |    \n");
    printf(" %c  | %c  | %c \n", a[7], a[8], a[9]);
    printf("____|____|____\n");
    printf("    |    |    \n");
}

int markBoard(int choice, char mark)
{   
    // another simple approach to simplify the if conditions
    // by changing the input choice into a char and making 
    // a general case for all winning conditions

    // int iChoice = choice - '0';
    // if(a[iChoice] == choice && iChoice!= 0)  //bonus
    //     a[iChoice] = mark;

    if(choice == 1 && a[1] == '1')
        a[1] = mark;
    else if(choice == 2 && a[2] == '2')
        a[2] = mark;
    else if(choice == 3 && a[3] == '3')
        a[3] = mark;
    else if(choice == 4 && a[4] == '4')
        a[4] = mark;
    else if(choice == 5 && a[5] == '5')
        a[5] = mark;
    else if(choice == 6 && a[6] == '6')
        a[6] = mark;
    else if(choice == 7 && a[7] == '7')
        a[7] = mark;
    else if(choice == 8 && a[8] == '8')
        a[8] = mark;
    else if(choice == 9 && a[9] == '9')
        a[9] = mark;
    else
    {
        return 0;
    }
    return 1;
}

int checkWinner()
{   
    // Winning conditions
    if(a[1] == a[2] && a[2] == a[3])
        return 1;
    if(a[4] == a[5] && a[5] == a[6])
        return 1;
    if (a[7] == a[8] && a[8] == a[9])
        return 1;
    if (a[1] == a[4] && a[4] == a[7])
        return 1;
    if (a[2] == a[5] && a[5] == a[8])
        return 1;
    if (a[3] == a[6] && a[6] == a[9])
        return 1;
    if (a[1] == a[5] && a[5] == a[9])
        return 1;
    if (a[3] == a[5] && a[5] == a[7])
        return 1;
    if(a[1] != '1' && a[2] != '2' && a[3] != '3' && a[4] != '4' && a[5] != '5' && a[6] != '6' && a[7] != '7' &&
    a[8] != '8' && a[9] != '9')     //Draw Condition
        return 0;

    return -1;

}
