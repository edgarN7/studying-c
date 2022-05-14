#include <stdio.h>

int main(){
    int testCases, initialYear, finalYear, initialMonth, finalMonth, initialDay, finalDay, difd=0, auxa=0, auxm=0, auxd=0, caso=0;
    int t=0, i=0, j=0, oxi=0, axe=0;

    scanf("%d", &testCases);

    for (t = 0; t < testCases; t++)
    {
       scanf("%d-%d-%d %d-%d-%d", &initialYear, &initialMonth, &initialDay, &finalYear, &finalMonth, &finalDay);

       if (initialYear == finalYear) //Inicio pra ordenar as datas.
       {
           if (initialMonth == finalMonth)
            {
                if (initialDay > finalDay)
                {
                 auxd = initialDay;
                 initialDay = finalDay;
                 finalDay = auxd;
                }
            }
            else if (initialMonth > finalMonth)
            {
                auxm = initialMonth;
                initialMonth = finalMonth;
                finalMonth = auxm;

                auxd = initialDay;
                initialDay = finalDay;
                finalDay = auxd;
            }
        }
        else if (initialYear > finalYear)
        {
            auxa = initialYear;
            initialYear = finalYear;
            finalYear = auxa;

            auxm = initialMonth;
            initialMonth = finalMonth;
            finalMonth = auxm;

            auxd = initialDay;
            initialDay = finalDay;
            finalDay = auxd;
        } // Fim pra ordenar as datas.

        int ivet[13], ivetbi[13];

        ivet[0]  = 0;
        ivet[1]  = 31;
        ivet[2]  = 28;
        ivet[3]  = 31;
        ivet[4]  = 30;
        ivet[5]  = 31;
        ivet[6]  = 30;
        ivet[7]  = 31;
        ivet[8]  = 31;
        ivet[9]  = 30;
        ivet[10] = 31;
        ivet[11] = 30;
        ivet[12] = 31;

        ivetbi[0]  = 0;
        ivetbi[1]  = 31;
        ivetbi[2]  = 29;
        ivetbi[3]  = 31;
        ivetbi[4]  = 30;
        ivetbi[5]  = 31;
        ivetbi[6]  = 30;
        ivetbi[7]  = 31;
        ivetbi[8]  = 31;
        ivetbi[9]  = 30;
        ivetbi[10] = 31;
        ivetbi[11] = 30;
        ivetbi[12] = 31;

        if (initialYear == finalYear)
        {
            if (initialMonth == finalMonth)
            {
                caso = 0; //Mesmo ano e mesmo mes.
            }
            else if ((finalMonth - initialMonth) == 1)
            {
                caso = 1; //Mesmo ano, meses seguidos.
            }
            else if ( (1 < (finalMonth - initialMonth) ) && ( (finalMonth - initialMonth) <= 11) )
            {
                caso = 2; //Mesmo ano, diferenca entre meses maior que 1 e menor igual a 11.
            }
        }
        else if ( (finalYear - initialYear) == 1 ) //Um ano seguido do outro.
        {
            caso = 3;   
        }
        else //Diferenca de anos maior que 1.
        {
            caso = 4;
        }

        switch (caso)
        {
            case 0: //a1=a2, m1=m2.
        
                difd = finalDay - initialDay;

                printf("%d\n", difd); 
                break;
    
            case 1: //a1=a2, meses seguidos.

                if ( (((initialYear%400) == 0) && ((initialYear%100) == 0) ) || ( ((initialYear%4) == 0) && ((initialYear%100) != 0) ) )
                {
                    difd = (ivetbi[initialMonth] - initialDay) + finalDay;
                    printf("%d\n", difd);
                }
                else
                {
                    difd = (ivet[initialMonth] - initialDay) + finalDay;
                    printf("%d\n", difd);
                }

                break;

            case 2: // a1=a2, meses diferentes > 1.

                if ( (((initialYear%400) == 0) && ((initialYear%100) == 0) ) || ( ((initialYear%4) == 0) && ((initialYear%100) != 0) ) )
                {
                    difd = (ivetbi[initialMonth]) - initialDay;
                }
                else
                {
                    difd = (ivet[initialMonth]) - initialDay;
                }

                for  (i = (initialMonth+1); i < finalMonth; i++)
                {
                    if ( (((initialYear%400) == 0) && ((initialYear%100) == 0) ) || ( ((initialYear%4) == 0) && ((initialYear%100) != 0) ) )
                    {
                        difd += ivetbi[i];
                    }
                    else
                    {
                        difd += ivet[i];
                    }         
                }

                difd += finalDay;
                printf("%d\n", difd);             
                break;

            case 3: //Um ano seguido do outro.

                if ( (((initialYear%400) == 0) && ((initialYear%100) == 0) ) || ( ((initialYear%4) == 0) && ((initialYear%100) != 0) ) )
                {
                    difd = (ivetbi[initialMonth]) - initialDay;
                }
                else
                {
                    difd = (ivet[initialMonth]) - initialDay;
                }

                for (j = 0; j < 2; j++)
                {
                    if( (j == 0) && (initialMonth < 12) )
                    {
                        oxi = (initialMonth+1);
                        axe = 12;
                    }
                    else if (finalMonth > 1)
                    {
                        j = 1;
                        oxi = 1;
                        axe = (finalMonth-1);
                    }
                    else
                    {
                        oxi = 2;
                        axe = 1;
                    }
                    
                    int aatual=0;
                    
                    if ( j == 0 )
                    {
                        aatual = initialYear;
                    }
                    else if ( j == 1 )
                    {
                        aatual = finalYear;
                    }
                    
                    for  (i = oxi; i <= axe; i++)
                    {
                        if ( (((aatual%400) == 0) && ((aatual%100) == 0) ) || ( ((aatual%4) == 0) && ((aatual%100) != 0) ) )
                        {
                            difd += ivetbi[i];
                        }
                        else
                        {
                            difd += ivet[i];
                        }         
                    }                
                }

                difd += finalDay;
                printf("%d\n", difd);
                break;

            case 4: //Diferenca de anos maior que 1.


                if ( (((initialYear%400) == 0) && ((initialYear%100) == 0) ) || ( ((initialYear%4) == 0) && ((initialYear%100) != 0) ) )
                {
                    difd = (ivetbi[initialMonth]) - initialDay;
                }
                else
                {
                    difd = (ivet[initialMonth]) - initialDay;
                }

                for (j = 0; j <= (finalYear-initialYear); j++)
                {
                    if( (j == 0) && (initialMonth < 12) )
                    {
                        oxi = (initialMonth+1);
                        axe = 12;
                    }
                    else if ( (0 < j) && (j < (finalYear-initialYear)) )
                    {
                        difd += 365;
                    }
                    else if ( j == (finalYear-initialYear) )
                    {
                        oxi = 1;
                        axe = (finalMonth-1);
                    }
                
                    if ( ( (j == 0) && (initialMonth < 12) ) || (j == (finalYear-initialYear) ) )
                    {
                        for  (i = oxi; i <= axe; i++)
                        {
                            difd += ivet[i];         
                        }
                    }                
                }

                for (i = initialYear; i <= finalYear; i++) //Soma dos dias bissextos a mais.
                {
                    if ( (i == initialYear) && (initialMonth == 1) && ((((i%400) == 0) && ((i%100) == 0) ) || ( ((i%4) == 0) && ((i%100) != 0) )) )
                    {
                        difd += 1;
                    }
                    else if ( (i > initialYear) && (i < finalYear) && ((((i%400) == 0) && ((i%100) == 0) ) || ( ((i%4) == 0) && ((i%100) != 0) )) )
                    {
                        difd += 1;
                    }
                    else if ( (i == finalYear) && (finalMonth > 2) && ((((i%400) == 0) && ((i%100) == 0) ) || ( ((i%4) == 0) && ((i%100) != 0) )) )
                    {
                        difd += 1;
                    }
                }

                difd += finalDay;
                printf("%d\n", difd);
                break;

            default:
                printf("Really?\n");
                break;
                    
        } //Final do Switch Caso.
    } //Final do For.

    return 0;
}
