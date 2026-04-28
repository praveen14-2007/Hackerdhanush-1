#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

// insert at beginning
void insertBeg(int val)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = val;
    newnode->prev = NULL;
    newnode->next = head;

    if(head != NULL)
        head->prev = newnode;

    head = newnode;
}

// insert at end
void insertEnd(int val)
{
    struct node *newnode, *temp;
    newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = val;
    newnode->next = NULL;

    if(head == NULL)
    {
        newnode->prev = NULL;
        head = newnode;
    }
    else
    {
        temp = head;
        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
        newnode->prev = temp;
    }
}

// delete from beginning
void deleteBeg()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;
    head = head->next;

    if(head != NULL)
        head->prev = NULL;

    free(temp);
}

// display forward
void display()
{
    struct node *temp = head;

    if(temp == NULL)
    {
        printf("List is empty\n");
        return;
    }

    while(temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    int ch, val;

    while(1)
    {
        printf("\n1.Insert Begin  2.Insert End  3.Delete Begin  4.Display  5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insertBeg(val);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                insertEnd(val);
                break;

            case 3:
                deleteBeg();
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
