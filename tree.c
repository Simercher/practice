# include <stdio.h>
# include <string.h>
# include <stdlib.h>

typedef struct treeNode 
{
    struct treeNode *left;
    int data;
    struct treeNode *right;
}TreeNode;
typedef TreeNode *TreeNodePtr;

void insertNode(TreeNodePtr *Treeptr, int data);
void searchNode(TreeNodePtr *Treeptr, int data);
void print(TreeNodePtr treeptr);

int main()
{
    TreeNodePtr tree = NULL;
    int choice = 0;
    int item = 0;
    printf("input your choice : ");
    scanf("%d", &choice);
    while (choice != 3)
    {
        switch (choice)
        {
            case 0:
                printf("insert a new node item in tree: ");
                scanf("%d", &item);
                insertNode(&tree, item);
                break;
            case 1:
                // printf("search item in tree: ");
                // scanf("%d", &item);
                // searchNode(&tree, item);
                break;
            case 2:
                printf("print all number(Low to High)");
                print(tree);
                puts("");
                break;
            default:
                break;
        }
        printf("input your choice : ");
        scanf("%d", &choice);
    }

    return 0;
}

void insertNode(TreeNodePtr *Treeptr, int data)
{
    if (*Treeptr == NULL)
    {
        *Treeptr = malloc(sizeof(TreeNode));

        if (*Treeptr != NULL)
        {
            (*Treeptr)->data = data;
            (*Treeptr)->left = NULL;
            (*Treeptr)->right = NULL;
        }else
        {
            printf("%d not inserted. No memory available.\n", data);
        }
    }else
    {
        if(data < (*Treeptr)->data)
        {
            insertNode(&((*Treeptr)->left), data);
        }else if(data > (*Treeptr)->data)
        {
            insertNode(&((*Treeptr)->right), data);
        }else
        {
            printf("This data is duplication\n");
        }
    }
}

void print(TreeNodePtr treeptr)
{
    if(treeptr != NULL)
    {
        print(treeptr->left);
        printf("%d --> ", treeptr->data);
        print(treeptr->right);
    }
}