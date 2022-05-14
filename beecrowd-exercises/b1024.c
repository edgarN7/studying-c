/*  You have been asked to build a simple encryption program. This program should be able to send coded messages without someone been able to read them.
    The process is very simple. It is divided into two parts.

    - First, each uppercase or lowercase letter must be shifted three positions to the right, according to the ASCII table: letter 'a' should become letter 'd',
    letter 'y' must become the character '|' and so on.
    - Second, each line must be reversed. After being reversed, all characters from the half on (truncated)
    must be moved one position to the left in ASCII. In this case, 'b' becomes 'a' and 'a' becomes '`'.

    For example, if the resulting word of the first part is "tesla", the letters "sla" should be moved one position to the left.
    However, if the resulting word of the first part is "t#$A", the letters "$A" are to be displaced.

    Input
    The input contains a number of cases of test. The first line of each case of test contains an integer N (1 ≤ N ≤ 1 * 10⁴), indicating the number of
    lines the problem should encrypt. The following N lines contain M characters each M (1 ≤ M ≤ 1 * 10³).
    
    Output
    For each input, you must present the encrypted message. */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool isUppercaseOrLowecase(char character);

char * reversedString(char toReverse[1000]);

char * firstStep(char toFirstStep[1000]);

char * secondStep(char toSecondStep[1000]);

int main(){
    char input[1000];
    int count=0, numberOfTests=0;

    scanf("%d", &numberOfTests);
    getchar();

    for (; count < numberOfTests; ++count)
    {        
        gets(input);
        printf("%s\n", input);

        printf("%d - %s\n\n", count, secondStep(reversedString(firstStep(input))));
    }

    return 0;
}

bool isUppercaseOrLowecase(char character){
    return ((character >= 'A') && (character <= 'Z') ) || ( (character >= 'a') && (character <= 'z') );
}

char * reversedString(char toReverse[1000]){
    char reversed[1000];
    int countRvs=0, downCount = (strlen(toReverse) - 1), fCount=0;

    for ( countRvs = 0; countRvs < strlen(toReverse); countRvs++)
    {
        reversed[downCount] = toReverse[countRvs];

        --downCount;
    }

    for (fCount = 0; reversed[fCount] != '\0'; fCount++)
    {
        toReverse[fCount] = reversed[fCount];

    }
    
    memset(reversed, 0, sizeof(reversed));   //Limpar todo conteudo da String criada na Função.

    return toReverse;
}

char * firstStep(char toFirstStep[1000]){
    char firstStepped[1000];
    int countFst=0;

    for ( countFst = 0; countFst < strlen(toFirstStep); countFst++)
    {
        if (isUppercaseOrLowecase(toFirstStep[countFst]))
        {
            firstStepped[countFst] = toFirstStep[countFst] + 3;
        }
        else
        {
            firstStepped[countFst] = toFirstStep[countFst];
        }
        
    }
    
    for ( countFst = 0; firstStepped[countFst] != '\0'; countFst++)
    {
        toFirstStep[countFst] = firstStepped[countFst];
    }

    memset(firstStepped, 0, sizeof(firstStepped));    //Limpar todo conteudo da String criada na Função.

    return toFirstStep;
}

char * secondStep(char toSecondStep[1000]){
    char secondStepped[1000];
    int countScnd=0, middle=0;

    middle = (strlen(toSecondStep)) / 2;

    for ( countScnd = 0; countScnd < strlen(toSecondStep); countScnd++)
    {
        if (countScnd >= middle)
        {
            secondStepped[countScnd] = toSecondStep[countScnd] - 1;
        }
        else
        {
            secondStepped[countScnd] = toSecondStep[countScnd];
        }
    }
    
    for ( countScnd = 0; countScnd < strlen(toSecondStep); countScnd++)
    {
        toSecondStep[countScnd] = secondStepped[countScnd];
    }

    memset(secondStepped, 0, sizeof(secondStepped));   //Limpar todo conteudo da String criada na Função.
    
    return toSecondStep;
}
