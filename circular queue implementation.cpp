#include <stdio.h>
#define MAX 5

int cq[MAX];
int front = -1, rear = -1;

void enqueue(int val)
{
    if((rear + 1) % MAX == front)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        if(front == -1)
            front = 0;

        rear = (rear + 1) % MAX;
        cq[rear] = val;
    }
}

void dequeue()
{
    if(front == -1)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        printf("Deleted element = %d\n", cq[front]);

        if(front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % MAX;
        }
    }
}

void display()
{
    int i;

    if(front == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        i = front;
        while(1)
        {
            printf("%d ", cq[i]);
            if(i == rear)
                break;
            i = (i + 1) % MAX;
        }
        printf("\n");
    }
}

int main()
{
    int ch, val;

    while(1)
    {
        printf("\n1.Enqueue  2.Dequeue  3.Display  4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                enqueue(val);
                break;

            case 2:
                dequeue();
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
