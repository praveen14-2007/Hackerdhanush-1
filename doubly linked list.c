#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* prev;
    struct node* next;
};
struct node* create_node()
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));  
    if(new_node == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    printf("Enter data: ");
    scanf("%d", &new_node->data);
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}
void display(struct node* head)
{
    struct node* temp = head;   
    if(head == NULL)
    {
        printf("List is empty!\n");
        return;
    }F
    printf("Doubly Linked List: ");
    while(temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main()
{
    struct node* head = NULL;
    struct node* temp = NULL;
    int n, i;   
    printf("How many nodes do you want to create? ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        struct node* new_node = create_node();
        if(head == NULL)
        {
            head = new_node;        
        }
        else
        {
            temp->next = new_node;  
            new_node->prev = temp;  
        }
        temp = new_node;           
    }
    display(head);
    temp = head;
    while(temp != NULL)
    {
        struct node* next = temp->next;
        free(temp);
        temp = next;
    }
    return 0;
}