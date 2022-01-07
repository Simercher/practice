# include "stdio.h"
# include "stdlib.h"
# include "string.h"

typedef struct stackNode 
{
    char data[20];
    struct stackNode *next;
}StackNode;
typedef StackNode *StackNodePtr;

void push(StackNodePtr *topPtr, char value[20]);
void pop(StackNodePtr *topPtr);
int isEmpty(StackNodePtr currentPtr);
void printStack(StackNodePtr currentPtr);

int main()
{
    StackNodePtr stackList = NULL;
    char item[20] = {0};
    int choice = 0;
    // printf("input your choice : ");
    // scanf("%d", &choice);
    while (scanf("%s", item))
    {
        // switch(choice)
        // {
        //     case 1:// push function
                // printf("input push item : ");
                // scanf("%s", item);
                // push(&stackList, item);
                // printStack(stackList);
                // break;
        //     case 2:// pop function
        //         pop(&stackList);
        //         printStack(stackList);
        //         break;
        //     default:
        //         break;
        // }
        // printf("input your choice : ");
        // scanf("%d", &choice);
        push(&stackList, item);
        printStack(stackList);
    }
    

    return 0;
}

int isEmpty(StackNodePtr currentPtr)
{
    return currentPtr == NULL;
}

void push(StackNodePtr *topPtr, char value[])
{
    StackNodePtr newPtr = malloc(sizeof(StackNode));

    if(newPtr != NULL)
    {
        for (int i = 0; i < strlen(value); i++)
        {
            newPtr->data[i] = value[i];
        }
        newPtr->next = *topPtr;
        *topPtr = newPtr;
    }else
    {
        printf("%s not inserted. No memory available.\n", value);
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
            printf("%s ", currentPtr->data);
            currentPtr = currentPtr->next;
        }
        puts("");
    }
}