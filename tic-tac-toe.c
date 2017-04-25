#include <stdio.h>

int main(void)
{
    char board[3][3];

    int i,j, k = 1;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            board[i][j] = k;
            k++;
            printf("%d", board[i][j]);
        }
    }

    int location;

    printf("\n player X, where to put ur X?\n");
    scanf("%d", &location);

    if (location == 1)
    {
        board[0][0] = 'X';
    }

    printf("%c", board[0][0]);

    /*
    for (int turn = 0; turn < 9; turn++)
    {
        printf("")
    }
*/

    return 0;
}

