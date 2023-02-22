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
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d", &ptr->data);
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

void display()
{
    struct node *ptr = head;
    int i = 1, n;
    // i = cnt_no_of_element(n);
    while (ptr != NULL)
    {
        printf("data[%d]->%d\n", i, ptr->data);
        ptr = ptr->link;
        i++;
    }
}

int main()
{
    // printf("program started successfully");
    char choice;
    int opt;
    printf("welcome to single linked list\n");

    do
    {
        printf("Enter choice :");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            insert_at_begin();
            break;
        case 2:
            insert_specific_pos();
            break;

        default:
            break;
        }
        fflush(stdin);
        printf("do you want to continue [y/n]: ");
        scanf("%c", &choice);
    } while (choice == 'y');
    display();
    int n;
    printf("size of the node is : %d", cnt_no_of_element(n));
    return 0;
}
