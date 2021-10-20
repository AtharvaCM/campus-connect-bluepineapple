// Program that implements linked list for book management system.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node *HEAD = NULL;

// -----------------------------------------------------------------------------

struct node
{
    char *name;
    struct node *next;
};

struct node *getnode(char value[])
{
    // allocate memory and initialize the node
    struct node *temp = NULL;

    temp = (struct node *)malloc(sizeof(struct node));
    printf("\t\tb4 cpy");
    // allocate mem for temp->name
    temp->name = malloc(100 * sizeof(char));
    strcpy(temp->name, value);
    printf("\t\tafter cpy");
    temp->next = NULL;

    // return the address of the node
    return temp;
}

void init()
{
    printf("\nIn init");
    HEAD = getnode("");
}

void append(char *value)
{
    printf("\t\tin append");
    // segmentation fault check code
    struct node *temp = HEAD;

    // if list is empty
    if (temp == NULL)
        HEAD->next = getnode(value);
    else
    {
        // traverse to the end
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = getnode(value);
    }
}

void insert()
{
}

void display_list()
{
    struct node *temp = HEAD;

    // if list is empty
    if (temp->next == NULL)
    {
        printf("\n[+] The list is empty");
        return;
    }

    // to skip header count
    temp = temp->next;

    printf("\n------------------------------------------------\n");
    while (temp != NULL)
    {
        printf("%s|", temp->name);
        temp = temp->next;
    }
    printf("\n------------------------------------------------\n");
}

void display_menu()
{
    printf("\n------------------------------------------------");
    printf("\n[+] 1. Append\n[+] 2. Insert A Book\n[+] 3. Delete A Book\n[+] 4. Display Books\n[+] 5.Search By Name\n[+] 6. Exit\n");
    printf("\n[+] Select an option: ");
}

void freenode(struct node *p)
{
    // free memory
    free(p);
}

int main()
{
    int op;
    char value[100];

    // init the header node
    init();

    // menu
    do
    {
        display_menu();
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("\nEnter the book name: ");
            scanf("%s", value);
            printf("\t\tb4 append");
            append(value);
            break;

        case 2:
            display_list();
            break;

        case 6:
            exit(0);
            break;
        default:
            printf("\nInvalid input!");
        }
    } while (1);

    return 0;
}