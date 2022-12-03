#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int func1(int,int);
int func2(int);
void print(int[],int);

int main (void)
{
    srand(time(NULL));
    int player[2]; 
    int sum_player1;
    int sum_player2;
    int dealer;
    int sum_dealer=0;
    int split;     
    sum_player1=0;
    sum_player2=0;

        dealer= (rand()%(13))+1;
        player[0]=(rand()%(13))+1;
        player[1]=(rand()%(13))+1;
      
        print(player,dealer);

        if (player[0]==1 && player[1]>=10 | player[1]==1 && player[0]>=10 )
        {
            printf("Players gets 21! Player Wins!\n");
            exit(1);
        }
        if(player[0]==player[1])
            {
                printf("Split the cards (1:for yes)?");
                scanf("%d",&split);
                if (player[0]>10)
                    player[0]=10;
                if (player[1]>10)
                    player[1]=10;
                if (dealer>10)
                    dealer=10;
                if (split)
                {
                    sum_player1+=player[0];
                    sum_player2+=player[1];
                    sum_player1=func1(1,sum_player1);
                    sum_player2=func1(2,sum_player2);
                    sum_dealer+=dealer;
                    sum_dealer= func2 (sum_dealer);
                    if (sum_player1>sum_dealer | sum_player2>sum_dealer)
                        printf("Player Wins!");
                    else if (sum_player1<sum_dealer | sum_player2<sum_dealer)
                        printf("Dealer Wins!");
                    else if (sum_player1==sum_dealer | sum_player2==sum_dealer)
                        printf("Nobody Wins!");
                        exit(1);
               }  
            }
            if (player[0]>10)
                player[0]=10;
            if (player[1]>10)
                player[1]=10;
            if (dealer>10)
                dealer=10;
            sum_player1+=player[0]+player[1];
            sum_player1=func1(1,sum_player1);
            sum_dealer+=dealer;
            sum_dealer=func2(sum_dealer);
            if (sum_player1>sum_dealer)
                printf("Player Wins!");
            else if (sum_player1<sum_dealer)
                printf("Dealer Wins!");
            else 
                printf("Nobody Wins!");
            exit(1);

    return 0;
}

int func1(int hand,int sum_player)
{
    int draw,card;
     do
        {
            printf("Hand_%d do you want to draw another card (1:for yes)?",hand);
            scanf("%d",&card);
            if (card)
            {
                draw=(rand()%(13))+1;
                sum_player+= draw;
                printf("Player draw %d\n",draw);
                printf("Player has total %d\n",sum_player);
                }
                if (sum_player>21)
                {
                    printf("Dealer Wins!\n"); 
                    exit(1);
                }   
        }
        while(card); 

    return sum_player;
}

int func2(int sum_dealer)
{
    int draw;
     do
        {
            draw=(rand()%(13))+1;
            sum_dealer+= draw;
            printf("Dealer draw %d\n",draw);
            printf("Dealer has total %d\n",sum_dealer);
            if(sum_dealer>21)
            {
                printf("Player wins!\n");
                exit(1);
            }
        }
        while(sum_dealer<16);

    return sum_dealer;
}

void print(int p[],int d)
{
        switch(d)
        {
            case 11:printf("First card of dealer is 'J'\n"); break;
            case 12:printf("First card of dealer is 'Q'\n"); break;
            case 13: printf("First card is of dealer is 'K'\n"); break;
            default: printf("First card of dealer is %d\n",d);
        }
        switch(p[0])
        {
            case 11:printf("First card of player is 'J'\n"); break;
            case 12:printf("First card of player is 'Q'\n"); break;
            case 13: printf("First card of player is 'K'\n"); break;
            default: printf("First card of player is %d\n",p[0]);
        }    
        switch(p[1])
        {
            case 11:printf("Second card of player is 'J'\n"); break;
            case 12:printf("Second card of player is 'Q'\n"); break;
            case 13: printf("Second card of player is 'K'\n"); break;
            default: printf("Second card of player is %d\n",p[1]);
        }
}