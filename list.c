# include <stdio.h>
# include <string.h>
# include <stdlib.h>
// 先寫struct再寫function最後再寫main
typedef struct listnode
{
    int data;
    struct listnode *next;
}ListNode;
typedef ListNode *ListNodePtr;

void insert(ListNodePtr *sPtr, int value);
void printlist(ListNodePtr currentPtr);
void delete(ListNodePtr *sPtr, int value);
int isempty(ListNodePtr sPtr);

int main ()
{
    int item = 0;
    int number = 0;
    printf("input case number : ");
    scanf("%d", &number);
    ListNodePtr list = NULL;
    while(number != 3)
    {
        switch(number)
        {
            case 1: //執行insert function
                printf("input a new number : ");
                scanf("%d", &item);
                insert(&list, item);
                printlist(list);
                break;

            case 2:// 執行delete function
                printf("input delete number : ");
                scanf("%d", &item);
                delete(&list, item);
                printlist(list);
                break;

            default:
                break;
        }
        scanf("%d", &number);
    }

    return 0;
}

void insert(ListNodePtr *sPtr, int value)
{
    ListNodePtr newPtr = malloc(sizeof(ListNode));// 要求記憶體位置

    if (newPtr != NULL) // 有要到記憶體位置
    {
        newPtr->data = value;//將value的值賦值給newPtr的data
        newPtr->next = NULL;//將newPtr的next指向下一個NULL節點

        ListNodePtr prevPtr = NULL;
        ListNodePtr currentPtr = *sPtr;

        while (currentPtr != NULL)//判斷當前的結構指標是否為空，通常第一個沒內容的話就是NULL，一直拜訪直到List尾端
        {
            prevPtr = currentPtr;
            currentPtr = currentPtr->next;
        }

        if(prevPtr == NULL)// 假設List為空，newPtr指向sPtr的第一個
        {
            newPtr->next = *sPtr;
            *sPtr = newPtr;
        }else//當List有內容物時，將prevPtr指向newPtr，將newPtr指向currentPtr
        {
            prevPtr->next = newPtr;
            newPtr->next = currentPtr;
        }
        
    }else
    {
        printf("%d not inserted. No memory available.\n", value);
    }
}

int isempty(ListNodePtr sPtr)
{
    return sPtr == NULL;
}

void printlist(ListNodePtr currentPtr)
{
    if (isempty(currentPtr))
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

void delete(ListNodePtr *sPtr, int value)
{
    if ((*sPtr)->data == value)
    {
        ListNodePtr tempPtr = *sPtr;
        *sPtr = (*sPtr)->next;
        free(tempPtr);
    }
    else
    {
        ListNodePtr prevPtr = *sPtr;
        ListNodePtr currentPtr = (*sPtr)->next;

        while (currentPtr != NULL && currentPtr->data != value)
        {
            prevPtr = currentPtr;
            currentPtr = currentPtr->next;
        }

        if(currentPtr != NULL)
        {
            ListNodePtr tempPtr = currentPtr;
            prevPtr->next = currentPtr->next;
            free(tempPtr);
        }
        
    }
}