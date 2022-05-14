#include <stdio.h>

int ledsEach(char algarism);

int ledsAmount(char* number);

void printResult(int result);

int main(){
    int nTests=0, resultantAmount=0;
    char number[1000];
    

    scanf("%d", &nTests);
    
    while(gets(number))
    {
        resultantAmount = ledsAmount(number);

        printResult(resultantAmount);
    }

    return 0;
}

int ledsEach(char algarism){
    int leds=0;

    if(algarism == '0')
    {
        leds = 6;
    }
    else if (algarism == '1')
    {
        leds = 2;
    }
    else if (algarism == '2')
    {
        leds = 5;
    }
    else if (algarism == '3')
    {
        leds = 5;
    }
    else if (algarism == '4')
    {
        leds = 4;
    }
    else if (algarism == '5')
    {
        leds = 5;
    }
    else if (algarism == '6')
    {
        leds = 6;
    }
    else if (algarism == '7')
    {
        leds = 3;
    }
    else if (algarism == '8')
    {
        leds = 7;
    }
    else if (algarism == '9')
    {
        leds = 6;
    }

    return leds;
}

int ledsAmount(char* number){
    int amount=0, j=0;

    for ( j = 0; number[j] != '\0'; j++)
        { 
            amount += ledsEach(number[j]);
        }

    return amount;
}

void printResult(int result){
    if (result != 0)
    {
        printf("%d leds\n", result);
    }
}

