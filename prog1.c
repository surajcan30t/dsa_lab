#include<stdio.h>
int fact();


int temp;
int main()
{
    printf("Enter integers:\n");
    int arr[100];
    int i;

    for(i=0 ; i < 5;)
    {

        scanf("%d",&temp);
        if(temp>=1&&temp<=20)
        {
            arr[i]= temp;
            i++;
        }
    }

    for(i = 0;i < 5; )
    {

            printf("%d\n",arr[i]);
            printf("factorial of %d is %d\n",arr[i],fact(arr[i]));
            i++;

    }


    return 0;
}

int fact(int n)
{
    if(n>1)
    {
        return n*fact(n-1);
    }
    else
        return 1;
}

