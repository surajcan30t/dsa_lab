#include <stdio.h>
#include <string.h>

char arr1[50], arr2[50];
int top = -1, top2 = -1;

void push(char c)
{
    if (top == 49)
    {
        printf("memory full");
    }
    else
    {
        top++;
        arr1[top] = c;
    }
}

char pop()
{
    if (top == -1)
        return -1;
    else
    {
        top--;
        return arr1[top + 1];
    }
}

void push2(char c)
{
    if (top2 == 49)
    {
        printf("memory full!!");
    }
    else
    {
        top2++;
        arr2[top2] = c;
    }
}

void display()
{
    for (int i = top2; i >= 0; i--)
    {
        printf("%c", arr2[i]);
    }
}

int opt(char c)
{
    if ((c == '+') ||( c == '-') || (c == '*') || (c == '/') || (c == '(') || (c == ')') || (c == '^') || (c == '%'))
        return 1;
    else
        return 0;
}

int prec(char c)
{
    if (c == '^')
        return 3;
    else if ((c == '*') ||( c == '/') || (c == '%'))
        return 2;
    else if ((c == '+') || (c == '-'))
        return 1;
    else
        return 0;
}

int main()
{
    char infix[50];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    char *e;
    strrev(infix);
    e = infix;
    while (*e != '\0')
    {
        if (opt(*e) == 0)
        {
            push2(*e);
        }
        else if (*e == ')')
        {
            push(*e);
        }
        else if (*e == '(')
        {
            while (pop() != ')')
            {
                char b = pop();
                push2(b);
            }
        }
        else
        {
            while (prec(arr1[top]) > prec(*e))
            {
                char b = pop();
                push2(b);
            }
            push(*e);
        }

        e++;
    }
    display();

    return 0;
}