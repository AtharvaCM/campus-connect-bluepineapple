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
    // allocate mem for temp->name
    temp->name = malloc(strlen(value) + 1);
    strcpy(temp->name, value);
    temp->next = NULL;

    // return the address of the node
    return temp;
}

void freenode(struct node *p)
{
    // free memory
    free(p);
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
    struct node *p = (struct node *)head;
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
    struct node *p = (struct node *)head;
    struct node *q = p->next;
    struct node *temp = NULL;
    int name_not_found = 1;

    if (temp->next == NULL)
    {
        printf("\b[+] The list is empty!");
        return;
    }

    // traverse to the required pos
    while (p->next != NULL)
    {
        if (name_not_found = strcmp(p->next->name, value) == 0)
            break;
        p = p->next;
        q = q->next;
    }
    if (name_not_found < 0 || name_not_found > 0)
    {
        printf("\n[+] Book does not exist!");
        return;
    }

    // rearrange the list
    temp = q;
    p->next = q->next;

    // free the memory
    freenode(temp);

    // decrement the header count
    head->data--;
}

void search_by_name(char *value)
{
    struct node *temp = (struct node *)head;
    int name_not_found = 1;

    if (temp->next == NULL)
    {
        printf("\b[+] The list is empty!");
        return;
    }

    // traverse the list
    while (temp->next != NULL)
    {
        // break when the name matches
        if (name_not_found = strcmp(temp->next->name, value) == 0)
            break;
        temp = temp->next;
    }
    if (name_not_found < 0 || name_not_found > 0)
        printf("\n[+] Book Does Not Exist!");
    else
        printf("\n[+] Book With '%s' Exists!", value);
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
            printf("\n[+] Enter the book name: ");
            scanf("%s", value);
            append(value);
            break;

        case 2:
            printf("\n[+] Enter the book name: ");
            scanf("%s", value);
            printf("\n[+] Enter the position to insert: ");
            scanf("%d", &pos);
            insert(pos, value);
            break;

        case 3:
            printf("\n[+] Enter a bookname to delete: ");
            scanf("%s", value);
            delete (value);
            break;

        case 4:
            display_list();
            break;

        case 5:
            printf("\n[+] Enter a bookname to search: ");
            // scanf("%s", value);
            fgets(value, 100, stdin);
            search_by_name(value);
            break;

        case 6:
            exit(0);
            break;
        default:
            printf("\n[+] Invalid input!");
        }
    } while (1);

    return 0;
}