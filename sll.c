
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
} *head = NULL;

int cnt_no_of_element()
{
    int c = 0;
    struct node *ptr = head;
    while (ptr != NULL)
    {
        ptr = ptr->link;
        c++;
    }
    return c;
}

void insert_at_begin()
{
    int n;
    do
    {
        printf("[Enter -1 to exit] Enter data : ");
        scanf("%d",&n);
        if(n==-1)
        {
            printf("Terminating!!\n");
            return;
        }

        struct node *ptr;
        ptr = (struct node *)malloc(sizeof(struct node));
        ptr->data = n;
        ptr->link = NULL;
        if (head == NULL)
        {
            head = ptr;
        }
        else
        {
            ptr->link = head;
            head = ptr;
        }
    }while(1);

}

void insert_specific_pos()
{
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    int pos,n;
    printf("Enter position you want to enter :");
    scanf("%d", &pos);
    if (pos > cnt_no_of_element(n))
    {
        printf("cannot insert");
    }
    else if (pos == 1)
    {
        insert_at_begin();
    }
    else
    {
        int i = 0;

        temp = head;
        while(i<pos-2)
        {
            temp = temp->link;
            i++;
        }
        printf("Enter data : ");
        scanf("%d", &ptr->data);
        ptr->link = temp->link;
        temp->link = ptr;

    }
}

void delete_at_begin()
{
    if(head == NULL)
    {
        printf("no element present ");
    }
    else if(head->link==NULL)
    {
        head = NULL;
    }
    else
    {
        struct node *ptr = head;
        head = ptr->link;
        ptr->link = NULL;
    }
}

void display()
{
    struct node *ptr = head;
    int i = 1, n;
    // i = cnt_no_of_element(n);
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->link;
        i++;
    }
}

int main()
{
    // printf("program started successfully");
    char choice;
    int opt;
    printf(" SINGLE LINKED LIST OPERATION\n");
    printf(" ____________________________\n");
    printf("\n");

    do
    {
        printf(" KEY......................OPERATION\n");
        printf("\n");
        printf(" 1-------------------INSERT AT BEGINING\n");
        printf(" 2-------------------INSERT AT END\n");
        printf(" 3-------------------INSERT AT A POINT\n");
        printf(" 4-------------------DELETE AT BEGINING\n");
        printf(" 5-------------------DELETE AT END\n");
        printf(" 6-------------------DELETE AT A POINT\n");
        printf(" 7-------------------DISPLAY\n");
        printf(" 8-------------------QUIT\n");
        printf("Enter choice : ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            insert_at_begin();
            break;
        case 2:

            break;
        case 3:
            insert_specific_pos();
            break;
        case 4:
            delete_at_begin();
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            display();
            break;
        case 8:
            exit(0);
            break;

        default:
            printf("INVALID CHOICE!!");
        }
        fflush(stdin);
        printf("do you want to continue [y/n]: ");
        scanf("%c", &choice);
    }
    while (choice == 'y');

    int n;
    printf("size of the node is : %d", cnt_no_of_element());
    return 0;
}
