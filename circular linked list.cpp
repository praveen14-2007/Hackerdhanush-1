#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

// insert at end
void insertEnd(int val)
{
    struct node *newnode, *temp;

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;

    if(head == NULL)
    {
        head = newnode;
        newnode->next = head;
    }
    else
    {
        temp = head;
        while(temp->next != head)
            temp = temp->next;

        temp->next = newnode;
        newnode->next = head;
    }
}

// delete from beginning
void deleteBeg()
{
    struct node *temp, *last;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if(head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        temp = head;
        last = head;

        while(last->next != head)
            last = last->next;

        head = head->next;
        last->next = head;
        free(temp);
    }
}

// display list
void display()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while(temp != head);

    printf("(back to head)\n");
}

int main()
{
    int ch, val;

    while(1)
    {
        printf("\n1.Insert End  2.Delete Begin  3.Display  4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insertEnd(val);
                break;

            case 2:
                deleteBeg();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
