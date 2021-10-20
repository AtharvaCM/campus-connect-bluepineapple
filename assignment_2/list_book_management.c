// Program that implements linked list for book management system.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct intnode *head = NULL;

struct intnode
{
    int data;
    struct node *next;
};

struct intnode *getintnode(int value)
{
    // allocate memory and initialize the node
    struct intnode *temp = NULL;

    temp = (struct intnode *)malloc(sizeof(struct intnode));
    temp->data = value;
    temp->next = NULL;

    // return the address of the node
    return temp;
}

void init()
{
    // init the header node
    head = getintnode(0);
}

// -----------------------------------------------------------------------------

struct node
{
    char *name;
    struct node *next;
};

struct node *getnode(char *value)
{
    // allocate memory and initialize the node
    struct node *temp = NULL;

    temp = (struct node *)malloc(sizeof(struct node));
    printf("\t\tb4 cpy %s", value);
    // allocate mem for temp->name
    temp->name = malloc(strlen(value) + 1);
    strcpy(temp->name, value);
    printf("\t\tafter cpy %s", temp->name);
    temp->next = NULL;

    // return the address of the node
    return temp;
}

void append(char *value)
{
    struct node *temp = head->next;

    // if list is empty
    if (temp == NULL)
        head->next = getnode(value);
    else
    {
        // traverse to the end
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = getnode(value);
    }

    // increment the header count
    head->data++;
}

void insert(int pos, char *value)
{
    // if the list is empty just use append()
    if (head->data == 0)
    {
        append(value);
        return;
    }

    // declare temp pointers
    struct node *p = head;
    struct node *q = p->next;
    struct node *temp = NULL;

    // check position
    if (pos > head->data || pos <= 0)
    {
        printf("\n[+] Invalid position passed to Insert function!");
        return;
    }

    // traverse to the required pos
    for (int i = 0; i < pos - 1; i++)
    {
        p = p->next;
        q = q->next;
    }

    // insert node
    temp = getnode(value);
    temp->next = q;
    p->next = temp;

    head->data++;
}

void delete (char *value)
{
    // draw this login on paper 1st
    struct node *p = head;
    struct node *q = p->next;
    struct node *temp = NULL;

    // traverse to the required pos
    while (strcmp(p->name, value) != 0)
    {
        p = p->next;
        q = q->next;
    }

    // rearrange the list
    temp = q;
    p->next = q->next;

    // free the memory
    freeNode(temp);

    // decrement the header count
    head->data--;
}

void display_list()
{
    struct node *temp = head->next;

    // if list is empty
    if (temp == NULL)
    {
        printf("\n[+] The list is empty");
        return;
    }

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
    printf("\n[+] 1. Append\n[+] 2. Insert A Book\n[+] 3. Delete A Book\n[+] 4. Display Books\n[+] 5. Search By Name\n[+] 6. Exit\n");
    printf("\n[+] Select an option: ");
}

void freenode(struct node *p)
{
    // free memory
    free(p);
}

int main()
{
    int op, pos;
    char value[100] = {'\0'};

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
            printf("\nEnter the book name: ");
            scanf("%s", value);
            printf("\nEnter the position to insert: ");
            scanf("%d", &pos);
            printf("\t\tb4 insert");
            insert(pos, value);
            break;

        case 3:
            printf("\nEnter a bookname to delete: ");
            scanf("%s", value);
            delete (value);
            break;

        case 4:
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