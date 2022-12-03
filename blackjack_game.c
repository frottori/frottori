#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int player_draw(int,int);
int dealer_draw(int);
void print_cards(int,int,int);
void print_result(int,int,int);

int main (void)
{
    srand(time(NULL));
    int player1;            //First card of Player
    int player2;            //Second card of Player
    int sum_player1=0;      //Sum of First hand of Player
    int sum_player2=0;      //Sum of Second hand of Player
    int dealer;             //First card of Dealer
    int sum_dealer=0;       //Sum of Dealer
    int split=0;            //Option for Player to split Hand

    dealer= (rand()%(13))+1;
    player1= (rand()%(13))+1;
    player2= (rand()%(13))+1;
    print_cards(player1,player2,dealer);

    if (player1==player2)   //The option of split is enabled
        split=1; 
    if (player1>10)
        player1=10;
    if (player2>10)
        player2=10;
    if (dealer>10)
        dealer=10;

    if (player1==1 && player2==10 | player1==1 && player2==10 ) 
    {
        printf("Players gets 21! Player Wins!\n");
        return 0;
    }
    if(split)
    {
        printf("Split the cards (1:for yes)?");
        scanf("%d",&split);   
        if (split)
        {
            sum_player1+=player1;
            sum_player2+=player2;
            sum_player1=player_draw(1,sum_player1);
            sum_player2=player_draw(2,sum_player2);
            sum_dealer+=dealer;
            sum_dealer= dealer_draw (sum_dealer);
            print_result(sum_player1,sum_dealer,1);
            print_result(sum_player2,sum_dealer,2);
            return 0;
        }  
    }
    sum_player1+=player1+player2;
    sum_player1=player_draw(1,sum_player1);
    sum_dealer+=dealer;
    sum_dealer=dealer_draw(sum_dealer);
    print_result(sum_player1,sum_dealer,1);
    return 0;
}

int player_draw(int hand,int sum_player)
{
    int draw,card;
    do
    {
        printf("Hand_%d do you want to draw another card (1:for yes)?",hand);
        scanf("%d",&card);
        if (card)
        {
            draw=(rand()%(13))+1;
            switch(draw)
            {
                case 11: printf("Player draw 'J'\n"); break;
                case 12: printf("Player draw 'Q'\n"); break;
                case 13: printf("Player draw 'K'\n"); break;
                default: printf("Player draw %d\n",draw);
            }
            if (draw>10)
                draw=10;
            sum_player+= draw;
            if (sum_player==21)
                return sum_player;
            printf("Player has total %d\n",sum_player);
        }
        if (sum_player>21)
        {
            printf("Player Lost!\n"); 
            exit(1);
        }   
    }
    while(card); 
    return sum_player;
}

int dealer_draw(int sum_dealer)
{
    int draw;
    do
    {
        draw=(rand()%(13))+1;
        switch(draw)
        {
            case 11: printf("Dealer draw 'J'\n"); break;
            case 12: printf("Dealer draw 'Q'\n"); break;
            case 13: printf("Dealer draw 'K'\n"); break;
            default: printf("Dealer draw %d\n",draw); 
        }
        if (draw>10)
            draw=10;
        sum_dealer+= draw;
        printf("Dealer has total %d\n",sum_dealer);
        if(sum_dealer>21)
        {
            printf("Player wins!\n");
            exit(1);
        }
    }
    while(sum_dealer<=16);
    return sum_dealer;
}

void print_cards(int p1,int p2,int d)
{
    switch(d)
    {
        case 11:printf("First card of dealer is 'J'\n"); break;
        case 12:printf("First card of dealer is 'Q'\n"); break;
        case 13: printf("First card of dealer is 'K'\n"); break;
        default: printf("First card of dealer is %d\n",d);
    }
    switch(p1)
    {
        case 11:printf("First card of player is 'J'\n"); break;
        case 12:printf("First card of player is 'Q'\n"); break;
        case 13: printf("First card of player is 'K'\n"); break;
        default: printf("First card of player is %d\n",p1);
    }    
    switch(p2)
    {
        case 11:printf("Second card of player is 'J'\n"); break;
        case 12:printf("Second card of player is 'Q'\n"); break;
        case 13: printf("Second card of player is 'K'\n"); break;
        default: printf("Second card of player is %d\n",p2);
    }
}

void print_result(int sum_player,int sum_dealer,int hand)
{

    if (sum_player>sum_dealer)            
        printf("Hand_%d: Player Wins!",hand);
    else if (sum_player<sum_dealer)    
        printf("Hand_%d: Dealer Wins!",hand); 
    else 
        printf("Hand_%d Nobody Wins!",hand);
}
