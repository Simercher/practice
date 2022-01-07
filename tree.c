#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct treeNode
{
    struct treeNode *left;
    int datanumber;
    char name[20];
    int score[3];
    struct treeNode *right;

} TreeNode;

typedef TreeNode *TreeNodePtr;

void insertNode(TreeNodePtr *Treeptr, int datanum, char[], int[]);
int searchNode(TreeNodePtr *Treeptr, int datanum);
void print(TreeNodePtr treeptr);

int main()
{
    TreeNodePtr tree = NULL;
    //struct treeNode *tree = NULL;
    int choice = 0;
    struct treeNode student;
    // int item = 0;
    printf("0 is add student\n1 is search student\n2 is print all students\n3 is Exit\n");
    printf("input your choice : ");
    scanf("%d", &choice);
    while (choice != 3)
    {
        switch (choice)
        {
        case 0:
            printf("insert a new student in tree: ");
            scanf("%d %s %d %d %d", &student.datanumber, student.name, &student.score[0], &student.score[1], &student.score[2]);
            insertNode(&tree, student.datanumber, student.name, student.score);
            break;
        case 1:
            printf("search student in tree: ");
            scanf("%d", &student.datanumber);
            if (searchNode(&tree, student.datanumber) == 0)
            {
                printf("No Data Found!\n");
            }
            break;
        case 2:
            printf("print all number(Low to High)\n");
            print(tree);
            puts("");
            break;
        default:
            break;
        }
        printf("0 is add student\n1 is search student\n2 is print all students\n3 is Exit\n");
        printf("input your choice : ");
        scanf("%d", &choice);
    }

    return 0;
}

void insertNode(TreeNodePtr *Treeptr, int datanum, char stdname[20], int stdscore[])
{
    if (*Treeptr == NULL)
    {
        *Treeptr = malloc(sizeof(TreeNode));

        if (*Treeptr != NULL)
        {
            (*Treeptr)->datanumber = datanum;
            for (int i = 0; i < strlen(stdname); i++)
            {
                (*Treeptr)->name[i] = stdname[i];
            }
            for (int j = 0; j < 3; j++)
            {
                (*Treeptr)->score[j] = stdscore[j];
            }

            (*Treeptr)->left = NULL;
            (*Treeptr)->right = NULL;
        }
        else
        {
            printf("student not inserted. No memory available.\n");
        }
    }
    else
    {
        if (datanum < (*Treeptr)->datanumber)
        {
            insertNode(&((*Treeptr)->left), datanum, stdname, stdscore);
        }
        else if (datanum > (*Treeptr)->datanumber)
        {
            insertNode(&((*Treeptr)->right), datanum, stdname, stdscore);
        }
        else
        {
            printf("This data is duplication\n");
        }
    }
}

void print(TreeNodePtr treeptr)
{
    if (treeptr != NULL)
    {
        print(treeptr->left);
        printf("%d %s %d %d %d\n", treeptr->datanumber, treeptr->name, treeptr->score[0], treeptr->score[1], treeptr->score[2]);
        print(treeptr->right);
    }
}

int searchNode(TreeNodePtr *Treeptr, int data)
{
    if ((*Treeptr)->datanumber == data)
    {
        printf("%d %s %d %d %d\n", (*Treeptr)->datanumber, (*Treeptr)->name, (*Treeptr)->score[0], (*Treeptr)->score[1], (*Treeptr)->score[2]);
        return 1;
    }
    else if ((*Treeptr)->left != NULL || (*Treeptr)->right != NULL)
    {
        if (data > (*Treeptr)->datanumber)
        {
            searchNode(&((*Treeptr)->right), data);
        }
        else
        {
            searchNode(&((*Treeptr)->left), data);
        }
    }
    else
    {
        return 0;
    }
}