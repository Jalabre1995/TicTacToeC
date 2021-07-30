#include <stdio.h>

void win(int player, int winner, int pos[]);
int main()
{
    //Declare a winner//

    int winner = 0, count = 0;
    int pos[9], index, sign, player, flag, i, k, j;

    for (i = 0; i < 9; i++)
    {
        pos[i] = ' ';
    }
    while (count < 9 && winner != 1)
    {
        flag = 0;
        //Print the board///
        printf("\n");
        printf("%c|%c|%c\n", pos[0], pos[1], pos[2]);
        printf("-+-+-\n");
        printf("%c|%c|%c\n", pos[3], pos[4], pos[5]);
        printf("-+-+-\n");
        printf("%c|%c|%c\n", pos[6], pos[7], pos[8]);

        //when the palyer moves it is a count///
        if (count % 2 == 0)
        {
            sign = 'X';
            player = 1;
        }
        else
        {
            sign = 'O';
            player = 2;
        }

        printf("Move for player %d(1-9): ", player);
        //Grab the input of the data///
        scanf("%d", &index);
        if (index < 1 || index > 9)
        {
            printf("Allowed index is 1 to 9\n");
            continue;

        } //Check if that positon has already been used//
        if (pos[index - 1] == 'X' || pos[index - 1] == 'O')
        {
            printf("Postiionis occupied\n");
            continue;
        }
        pos[index - 1] = sign;
        count++;

        //Check if the current player has won///
        for (i = 0; i < 9; i++)
        {
            //If the flag gets tyo 3 we need to indicate if the player has won//
            if (i % 3 == 0)
                flag = 0;
            if (pos[i] == sign)
                flag++;
            if (flag == 3)
            {
                winner = 1;
                win(player, winner, pos);
            }
        }
        flag = 0;
        for (i = 0; i < 3; i++)
        {
            for (k = i; k <= i + 6; k += 3)
            {
                if (pos[k] == sign)
                    flag++;
            }

            if (flag == 3)
            {
                winner == 1;
                win(player, winner, pos);
            }
                   flag = 0;
        }
 
        if((pos[0] == sign && pos[4] == sign && pos[8] == sign) || (pos[2] == sign && pos[4] == sign && pos[6] == sign)){
        winner = 1;
        win(player, winner, pos);
        }
     
    }
}

void win(int player, int winner, int pos[])
{
     //Print the board///
        printf("\n");
        printf("%c|%c|%c\n", pos[0], pos[1], pos[2]);
        printf("-+-+-\n");
        printf("%c|%c|%c\n", pos[3], pos[4], pos[5]);
        printf("-+-+-\n");
        printf("%c|%c|%c\n", pos[6], pos[7], pos[8]);
        if(winner) {
            printf("Player %d is the winner\n", player);

        }else {
            printf("Match draw\n");
        }
}
