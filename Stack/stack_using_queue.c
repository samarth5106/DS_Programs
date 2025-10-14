#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int main()
{
    int Q1[MAX],Q2[MAX],r1,f1,r2,f2,i;
    int ch, val;
    r1=-1,r2=-1,f1=0,f2=0;
    do
    {
        printf("\n1. push\n2.pop\n3.display\n");
        printf("\n\tEnter choice: ");
        if (scanf("%d", &ch) != 1) {
            printf("\n\tInvalid input. Exiting.\n");
            break;
        }
        switch(ch)
        {
            case 1:
            if(r1==MAX-1)
            {
                printf("\n\t\t\t stack is full");
            }
            else
            {
                printf("\n\t\tEnter the value: ");
                scanf("%d", &val);
                r1++;
                Q1[r1]=val;
                printf("\n\t\t%d is pushed", val);
            }
            break;
            case 2:
            f1=0;
            r2=-1;
            f2=0;
            if(r1==-1)
                printf("Stack is empty");
            else
            {
                while(f1<r1)
                {
                    r2++;
                    Q2[r2] = Q1[f1];
                    f1++;
                }
                printf("\n\t%d is poped ", Q1[f1]);
                r1=-1;
                while(f2<=r2)
                {
                    r1++;
                    Q1[r1] = Q2[f2];
                    f2++;
                }
            }
            printf("\n\t\t r1 in pop = %d",r1);
            break;
            case 3:
            i=r1;
            printf("\n\t\t r1 in display = %d",r1);
            while(i>=0)
            {
                    printf("\n%d",Q1[i]);
                    i--;
            }

            break;
        }
    } while (ch<=3);
    return 0;
}

