#include<stdio.h>
int q[50];
int rear =-1,front =-1;
int dequeue();
void enqueue();
void display();
int main()
{
    int choice;
    char repeat;
    do
    {
        printf("||||||||||||||MENU DRIVEN PROGRAM||||||||||||||\n");
        printf("PRESS KEY---------------------OPERATIONS\n");
        printf("1-----------------------------Insertion\n");
        printf("2-----------------------------Deletion\n");
        printf("3-----------------------------Display All Elements;\n");
        printf("4-----------------------------EXIT\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nInvalid Choice\n");
        }
        printf("Do you want to perform more operations on the stack(y/n) : ");
        fflush(stdin);
        scanf("%c",&repeat);
    }
    while((repeat=='y')||(repeat=='Y'));

    return 0;
}
void enqueue()
{
    if(rear == 49)
    {
        printf("stack overflow");
    }
    else
    {
        rear++;
        printf("enter the value\n");
        scanf("%d",&q[rear]);
        if(front==-1)
        {
            front = 0;
        }
    }
}
int dequeue()
{
    if(rear == -1)
    {
        printf("queue is empty");
    }
    else
    {
        front++;
        return q[front-1];
    }
}
void display()
{
    int i;
    if(rear==-1)
    {
        printf("queue is empty");
    }
    else{
        for(i = front ; i<=rear;i++)
        {
            printf("%d",q[i]);
        }
    }
}
