#include<stdio.h>
#include<stdlib.h>
#include<math.h>


struct Board
{
    int id;
    char Player1[5];
    char Player2[5];
    char sign[3];
    int objNumber;
};

int *generateRandom();
void printGrid(int *p,int);
int rolldice();

//void displayBoard()
//{
//    int a[100],i;
//    for(i=1; i<=100; i++)
//    {
//        a[i]=i;
//    }
//
//    for(i=100; i>=1; i--)
//    {
//        for(int j=10; j>=1; j--)
//        {
//            printf("%d",a[i]);
//        }
//        printf("\n");
//    }
//}

void printGrid(int *p,int playerPos)
{
    if(playerPos>=100)
    {
        playerPos=100;

    }

    int arr[10][10],i=100,j;
    int a=0;
    for(a=10; a>=1; a--)
    {
        if(a%2==0)
        {
            for(i=a*10; i>=a*10-9; i--)
            {
                if(i==playerPos)
                    printf(" %d(P)\t",i);
                else
                    printf(" %d   \t",i);
            }
            printf("\n");
        }
        else
        {

            for(i=a*10-9; i<=a*10; i++)
            {
                if(i>=1 && i<=19)
                {


                    if(i==playerPos)
                        printf(" %d(P)\t",i);
                    else
                        printf(" %d  \t",i);
                }
                else
                {
                    if(i==playerPos)
                        printf(" %d (P)\t",i);
                    else
                        printf(" %d   \t",i);
                }

            }
            printf("\n");
        }
        printf("\n");
    }
}

int rolldice()
{
    srand(time(0));
    printf("Rolling dice.");
    printf(".");
    int lowerRand=1,UpperRand=6;
    int num=(rand()%(UpperRand-lowerRand+1))+lowerRand;
    printf("%d\n",num);
    sleep(1);
    return num;
}

int *generateRandom()
{
    int *p;
    int random_numbers[10],i;
    int count =0;

    srand(time(0));

    while(count <10)
    {
        int lowerRand=4,UpperRand=98;
        int randNum=(rand()%(UpperRand-lowerRand+1))+lowerRand; //Generate a random number
        int found =0; //assume the random number hasnt been generated

        //make sure the random number hasnt already been generated
        for (i = 0; i < 10; i++)
        {
            if(random_numbers[i] ==randNum)
            {
                found =1;
                break; //once we have located the number we dont need to continue checking
            }
        }

        //we have a new random number
        if(!found)
        {
            //printf("%d",randNum);
            random_numbers[i] =randNum;
            count++;
        }
    }
    p=&random_numbers[0];
    return random_numbers;
}

int randomObjective(int lowerRand,int UpperRand)
{
    srand(time(0));
    int randNum=(rand()%(UpperRand-lowerRand+1))+lowerRand; //Generate a random number
    return randNum;
}

int *Grid2()
{
    struct Board B[100],*ptr,*ptr_orig;
    ptr=ptr_orig=&B[0];
    for(int i=0; i<100; i++)
    {
        ptr->id=i;
        ptr++;
    }
    return ptr_orig;
}

void PrintGrid2(int *ptr)
{
    for(int k=0;k<100;k++)
    {
       // printf("%d..",ptr->id);
        //ptr++;
    }
    printf("\n");
    for(int i=10; i>=1; i--)
    {
        if (i%2 == 1)
        {
            for (int j = 0; j < 10; j++)
            {
                printf("%d ", *ptr+j);
            }
            printf("\n");
        }
        else
        {
            for (int j = 10 - 1; j >= 0; j--)
            {
                printf("%d ", *ptr+j);
            }
            printf("\n");
        }
    }
}


