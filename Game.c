#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "logic.h"


int printWelcome();
void displayLevel();
void switchToGameScreen();
void switchToInstructions();




int main()
{
    struct Board B[100],*ptr,*ptr_orig;
    ptr=ptr_orig=&B[0];
    int i;
    int lower = 9, upper = 92, count = 1;

	// Use current time as
	// seed for random generator
	srand(time(0));

    for(i=100; i>=1; i--)
    {
            int a1=printRandoms(lower, upper, count);
            int a2=printRandoms(lower, upper, count);
            int a3=printRandoms(lower, upper, count);
            int a4=printRandoms(lower, upper, count);
            int a5=printRandoms(lower, upper, count);
            int a6=printRandoms(lower, upper, count);
            int a7=printRandoms(lower, upper, count);
            int a8=printRandoms(lower, upper, count);
            int a9=printRandoms(lower, upper, count);
            int a10=printRandoms(lower, upper, count);
            int b1=printRandoms(lower, upper, count);
            int b2=printRandoms(lower, upper, count);
            int b3=printRandoms(lower, upper, count);
            int b4=printRandoms(lower, upper, count);
            int b5=printRandoms(lower, upper, count);
            int b6=printRandoms(lower, upper, count);
            int b7=printRandoms(lower, upper, count);
            int b8=printRandoms(lower, upper, count);
            int b9=printRandoms(lower, upper, count);
            int b10=printRandoms(lower, upper, count);
            if(i==a1||i==a2||i==a3||i==a4||i==a5||i==a6||i==a7||i==a8||i==a9||i==a10)
            {
                B[i-1].id=i;
                strcpy(B[i-1].Player1,"  ");
                strcpy(B[i-1].Player2,"  ");
                strcpy(B[i-1].sign,"+");
                B[i-1].objNumber=printRandoms(2,6,1);
            }
            else if(i==b1||i==b2||i==b3||i==b4||i==b5||i==b6||i==b7||i==b8||i==b9||i==b10)
            {
                B[i-1].id=i;
                strcpy(B[i-1].Player1,"  ");
                strcpy(B[i-1].Player2,"  ");
                strcpy(B[i-1].sign,"-");
                B[i-1].objNumber=printRandoms(3,7,1);
            }
            //}
        //}
        else
        {
            B[i-1].id=i;
            strcpy(B[i-1].Player1,"  ");
            strcpy(B[i-1].Player2,"  ");
//            strcpy(B[i-1].sign,(rand()%2==0)?"+":"-");
//            B[i-1].objNumber=res;
                strcpy(B[i-1].sign," ");
                B[i-1].objNumber=0;
        }

    }
    int screen1Opt;
    menu:screen1Opt=printWelcome();
    switch(screen1Opt)
    {
    case 1:
        system("CLS");
        displayLevel(ptr_orig);
        break;
    case 2:
        system("CLS");
        switchToInstructions(ptr_orig);
        break;
    case 3:
    default:
        printf("%s","Invalid Option..Please Enter any of the options on the screen\n");
        //system("CLS");
        goto menu;

    }



//    int *ptr;
//    int opt;
//    ptr=generateRandom();
//    printGrid(ptr,0);
    return 0;
}


int printWelcome()
{
    int opt;
    printf("%s","\t\tWelcome to Snake&Ladders GAME");
    printf("%s","\n\nPlease choose one of the below options");
    printf("%s","\n1:Play Game\n2:Instructions\n3:Exit\n");
    scanf("%d",&opt);
    return opt;

}
void switchToGameScreen(int level,struct Board *ptr,int player1Pos,int player2Pos,int playerTurn,char playerName1[50],char playerName2[50])
{
    //system("CLS");
    int prevP1Pos,prevP2Pos;
    printf("\n\t\t %s VS %s \n",playerName1,playerName2);
    int opt,exit_opt;
    updatePlayerInitialPosition(ptr,player1Pos,player2Pos);
    prevP1Pos=player1Pos;
    prevP2Pos=player2Pos;
label1:
    displayBoard(ptr);
    //printGrid(ptr,playerPos);
    printf("\n1: Roll Dice for Player%d\n2:Exit\n",playerTurn);
    menu:scanf("%d",&opt);
    fflush(stdout);
   label2:if(playerTurn==2&&level==2)
   {
       displayBoard(ptr);
   }
       switch(opt)
    {
    case 1:
        //system("CLS");
        if(playerTurn==1)
        {
            printf("%s P1 ",playerName1);
            player1Pos += rolldice();
            //printGrid(ptr,playerPos);
            Sleep(3);
            if(player1Pos>=100)
            {
                printf("%s P1 is the Winner!!!",playerName1);
                printf("\nPress 1 to Exit\n",playerTurn);
                menu:scanf("%d",&exit_opt);
                switch(exit_opt)
                {
                case 1:
                    system("CLS");
                    main();
                    break;
                case 2:
                default:
                    printf("%s","Invalid Option..Please Enter any of the options on the screen\n");
                    //system("CLS");
                    goto menu;
                }
            }
            updatePlayerPosition(ptr,playerTurn,player1Pos,prevP1Pos,playerName1,playerName2);
            prevP1Pos=player1Pos;
            playerTurn=2;
            //switchToGameScreen(level,ptr,player1Pos,player2Pos,prevP1Pos,prevP2Pos,playerTurn);
            if(level==1)
                goto label1;
            else
                goto label2;

        }
        else
        {
            printf("%s P2 ",playerName2);
            player2Pos += rolldice();
            //printGrid(ptr,playerPos);
            Sleep(6);
            //switchToGameScreen(level,ptr,player1Pos,player2Pos,prevP1Pos,prevP2Pos,playerTurn);
            updatePlayerPosition(ptr,playerTurn,player2Pos,prevP2Pos,playerName1,playerName2);
            if(player2Pos>=100)
            {
                printf("%s P2 is the Winner!!!",playerName2);
                printf("\nPress 1 to Exit\n",playerTurn);
                menu:scanf("%d",&exit_opt);
                switch(exit_opt)
                {
                case 1:
                    system("CLS");
                    main();
                    break;
                case 2:
                default:
                    printf("%s","Invalid Option..Please Enter any of the options on the screen\n");
                    //system("CLS");
                    goto menu;
                }
            }
            prevP2Pos=player2Pos;
            playerTurn=1;
            goto label1;
        }
        break;
    case 2:
    default:
        printf("%s","Invalid Option..Please Enter any of the options on the screen\n");
        goto menu;
    }
}

void displayLevel(int *ptr)
{
    int opt;
    printf("%s","Select Difficulty");
    char playerName1[50];
    char playerName2[50];
    printf("%s","\n1: Player with Player\n2: Player with Computer\n");
    menu:scanf("%d",&opt);
    fflush(stdin);
    switch(opt)
    {
    case 1:
        printf("Enter P1 Name\n");
        gets(playerName1);
        printf("Enter P2 Name\n");
        gets(playerName2);
        system("CLS");
        switchToGameScreen(1,ptr,1,1,1,playerName1,playerName2);
        //displayBoard(ptr);
        break;
    case 2:
        printf("Enter P1 Name\n");
        gets(playerName1);
        strcpy(playerName2,"Computer");
        system("CLS");
        switchToGameScreen(2,ptr,1,1,1,playerName1,playerName2);
        break;
    default:
        printf("%s","Invalid Option..Please Enter any of the options on the screen\n");
        goto menu;
    }

}

void switchToInstructions(int *ptr)
{
    int opt;
    printf("%s","\t\tInstructions\n");
    printf("\tRules are similar to Snake & Ladder Board game. Instead of snakes and ladders, there will be negative and positive points respectively. Position of Players while landing on that cells will be updated as per the points on the respective cell. Players need to roll the dice on each turns and whoever reach the 100th cell first is the Winner. If the player chooses to play with Computer, turn will be passed to computer automatically. Have a Good Day!.\n\n");
    printf("%s","\n1: Play Game\n2:Back to Main Screen\n3:Exit\n");
    menu:scanf("%d",&opt);
    switch(opt)
    {
    case 1:
        system("CLS");
        displayLevel(ptr);
        break;
    case 2:
        system("CLS");
        main();
        break;
    case 3:
    default:
        printf("%s","Invalid Option..Please Enter any of the options on the screen\n");
        goto menu;
    }
}



void updatePlayerPosition(struct Board *ptr,int PlayerTurn,int PlayerPos,int prevPos,char playerName1[50],char playerName2[50])
{

    if(strcmp("+",ptr[PlayerPos-1].sign)==0)
    {
        printf("%s %s landed on Ladder. Adding +%d points\n",PlayerTurn==1?playerName1:playerName2,PlayerTurn==1?"P1":"P2",ptr[PlayerPos-1].objNumber);
        prevPos=PlayerPos;
        PlayerPos+=ptr[PlayerPos-1].objNumber;
        updatePlayerPosition(ptr,PlayerTurn,PlayerPos,prevPos,playerName1,playerName2);
    }
    else if(strcmp("-",ptr[PlayerPos-1].sign)==0)
        {
            printf("%s landed on Snake. -%d points\n",PlayerTurn==1?"P1":"P2",ptr[PlayerPos-1].objNumber);
            prevPos=PlayerPos;
            PlayerPos-=ptr[PlayerPos-1].objNumber;
            updatePlayerPosition(ptr,PlayerTurn,PlayerPos,prevPos,playerName1,playerName2);
        }else
    {
        if(PlayerTurn==1)
        {
            strcpy(ptr[PlayerPos-1].Player1,"P1");
            //if(PlayerPos!=0&&PlayerPos-1!=0)
            //{

            strcpy(ptr[prevPos-1].Player1,"  ");
            //}
        }
        else
        {
            strcpy(ptr[PlayerPos-1].Player2,"P2");
            //if(prevPos!=0&& PlayerPos-1!=0)
            //{
            strcpy(ptr[prevPos-1].Player2,"  ");
            //}
        }
    }


}

void updatePlayerInitialPosition(struct Board *ptr,int player1Pos,int Player2Pos)
{
    strcpy(ptr[player1Pos-1].Player1,"P1");
    strcpy(ptr[Player2Pos-1].Player2,"P2");
}


void displayBoard(struct Board *ptr)
{
    int i,k=1;
    printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    for(i=100; i>=1; i--)
    {
        printf("|");
        if((ptr+(i-1))->id<100 && (ptr+(i-1))->id>9)
        {
            printf(" ");
        }
        if((ptr+(i-1))->id<10 && (ptr+(i-1))->id>0)
        {
            printf("  ");
        }
        printf("%d ",(ptr+(i-1))->id);
        printf(" %s",(ptr+(i-1))->sign);
        if((ptr+(i-1))->objNumber == 0)
        {
            printf("    ");
        }
        else
        {
            printf("(%d) ",(ptr+(i-1))->objNumber);
        }
        printf("  %s",(ptr+(i-1))->Player1);
        printf(" %s ",(ptr+(i-1))->Player2);



        if(k==10)
        {
            printf("|");
            printf("\n");
            k=0;
        }
        k++;
    }
    printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");


}

int printRandoms(int lower, int upper,
							int count)
{
	int i,num=0;
	for (i = 0; i < count; i++) {
		num = (rand() %
		(upper - lower + 1)) + lower;
		//printf("%d ", num);
	}
	return num;
}

