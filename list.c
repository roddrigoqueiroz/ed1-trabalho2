/*
Alunos:
Rodrigo Queiroz Neves,           12111BSI220
Emanuel Henrique Vieira Dias,    12111BSI218
Daniel de Souza Cordeiro,        12111BSI244
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int number;
    struct node *next;
};
typedef struct node Node;

// FUNCTIONS THAT DEAL WITH LIST
Node *newNode(int number);
short insertNode(Node **list, Node *newNode);
void printList(Node *list);
void freeList(Node *list);

// FUNCTIONS THAT DEAL WITH THE PROBLEM CASES
short member(Node *list, int element);
int lastElement(Node *list);
int sumElements(Node *list);
int sumOddNumbers(Node *list);
int nthElement(Node *list, int n);
int listSize(Node *list);

int main(void)
{
    int belong, n;
    scanf("%d %d", &belong, &n);

    if(nthElement < 0)
    {
        printf("Type in a positive number\n");
        return 1;
    }

    int numberOfElements;
    printf("Type the number of elements in the list: ");
    scanf("%d", &numberOfElements);

    Node *list = NULL;
    Node *nodeToInsert = NULL;

    int element;
    while(scanf("%d", &element) != EOF)
    {
        nodeToInsert = newNode(element);
        // I'm passing the adress of the list, so I can change what it's pointing to
        insertNode(&list, nodeToInsert);
    }

    printf("Is %d member of List? %hd\n", belong, member(list, belong));
    printf("Last element: %d\n", lastElement(list));
    printf("Sum of all list's elements: %d\n", sumElements(list));
    printf("Sum of all list's odd numbers: %d\n", sumOddNumbers(list));
    printf("The %dth element is: %d\n", n, nthElement(list, n));
    printf("List's size: %d\n", listSize(list));

    printList(list);

    freeList(list);

    return 0;
}

// FUNCTIONS THAT DEAL WITH THE PROBLEM CASES

// Gets the list's size
int listSize(Node *list)
{
    // The list is empty
    if(list == NULL)
    {
        return 0;
    }
    // Count this element and the subsequent ones
    else
    {
        return 1 + listSize(list->next);
    }
}

// Finds the list's nth element
int nthElement(Node *list, int n)
{
    // If the user inputs a invalid number or the list is NULL
    if(n <= 0 || list == NULL || n > listSize(list))
    {
        return 0;
    }
    else if(n == 1)
    {
        return list->number;
    }
    else
    {
        return nthElement(list->next, n - 1);
    }
}

// Sum all list's odd numbers
int sumOddNumbers(Node *list)
{
    // if the list is empty
    if(list == NULL)
    {
        return 0;
    }
    // Sum all odd numbers
    else if(list->number % 2 != 0)
    {
        return list->number + sumOddNumbers(list->next);
    }
    // Don't sum the even numbers
    else
    {
        return sumOddNumbers(list->next);
    }
}

// Sum all list's elements
int sumElements(Node *list)
{
    if(list == NULL)
    {
        return 0;
    }
    else
    {
        return list->number + sumElements(list->next);
    }
}

// Finds the list's last element
int lastElement(Node *list)
{
    // If the list is empty
    if(list == NULL)
    {
        return -8796514;
    }
    // If I'm at the last position
    else if(list->next == NULL)
    {
        return list->number;
    }
    // Recursive call
    else
    {
        return lastElement(list->next);
    }
}

// Finds if element is member of list
short member(Node *list, int element)
{
    // If the list is empty
    if(list == NULL)
    {
        return 0; // False
    }
    // If element is the first number of the list
    else if(list->number == element)
    {
        return 1; // True
    }
    // Recursive call
    else
    {
        return member(list->next, element);
    }
}

// FUNCTIONS THAT DEAL WITH LIST
// This function is used to create a new list and to create a new node
Node *newNode(int number)
{
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL)
    {
        return NULL;
    }

    newNode -> number = number;
    newNode -> next = NULL;

    return newNode;
}

// This function takes a pointer to a pointer as argument, so I can dereference the
// list pointer and set it to newNode
short insertNode(Node **list, Node *newNode)
{
    if(newNode == NULL)
    {
        return 0; // false
    }

    // If the list is empty I insert the element
    // It works to insert in the end of the list as well
    if(*list == NULL)
    {
        *list = newNode;
        return 1; // true
    }
    else
    {
        // Get the adress of the next field from the Node **list
        return insertNode(&((*list)->next), newNode);
    }
}

void printList(Node *list)
{
    if(list == NULL)
    {
        printf("\n");
        return;
    }
    else
    {
        printf("%d ", list->number);
        printList(list->next);
    }
    return;
}

// Frees the entire list
void freeList(Node *list)
{
    // List is empty, nothing to free
    if(list == NULL)
    {
        return;
    }
    // Frees the next nodes and than the actual node
    else
    {
        freeList(list->next);
        free(list);
        return;
    }
}
