# include "stdio.h"
# include "stdlib.h"
# include "string.h"

typedef struct stackNode 
{
    int data;
    struct stackNode *next;
}StackNode;
typedef StackNode *StackNodePtr;

void push(StackNodePtr *topPtr, int value);
void pop(StackNodePtr *topPtr);
int isEmpty(StackNodePtr currentPtr);
void printStack(StackNodePtr currentPtr);

int main()
{
    StackNodePtr stackList = NULL;
    int item = 0;
    int choice = 0;
    printf("input your choice : ");
    scanf("%d", &choice);
    while (choice != 3)
    {
        switch(choice)
        {
            case 1:// push function
                printf("input push item : ");
                scanf("%d", &item);
                push(&stackList, item);
                printStack(stackList);
                break;
            case 2:// pop function
                pop(&stackList);
                printStack(stackList);
                break;
            default:
                break;
        }
        printf("input your choice : ");
        scanf("%d", &choice);
    }
    

    return 0;
}

int isEmpty(StackNodePtr currentPtr)
{
    return currentPtr == NULL;
}

void push(StackNodePtr *topPtr, int value)
{
    StackNodePtr newPtr = malloc(sizeof(StackNode));

    if(newPtr != NULL)
    {
        newPtr->data = value;
        newPtr->next = *topPtr;
        *topPtr = newPtr;
    }else
    {
        printf("%d not inserted. No memory available.\n", value);
    }

}

void pop(StackNodePtr *topPtr)
{
    StackNodePtr tempPtr = *topPtr;
    *topPtr = (*topPtr)->next;
    free(tempPtr);
}

void printStack(StackNodePtr currentPtr)
{
    if (isEmpty(currentPtr))
    {
        puts("List is empty.\n");
    }else
    {
        puts("The List is: ");

        while (currentPtr != NULL)
        {
            printf("%d --> ", currentPtr->data);
            currentPtr = currentPtr->next;
        }
        puts("NULL");
    }
}