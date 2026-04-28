#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push(int val)
{
    if(top == MAX - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        stack[top] = val;
    }
}

void pop()
{
    if(top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("Deleted element = %d\n", stack[top]);
        top--;
    }
}

void display()
{
    int i;
    if(top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        for(i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
    }
}

int main()
{
    int ch, val;

    while(1)
    {
        printf("\n1.Push  2.Pop  3.Display  4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                push(val);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
