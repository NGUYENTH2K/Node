#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    char name[50];
    int dtb;
};
typedef struct student STUDENT;

struct node
{
    STUDENT data;
    struct node* link;
};
typedef struct node* LinkedList;
int isEmpty(LinkedList list);
void addHead(LinkedList* head, STUDENT data);
void addTail(LinkedList* head, STUDENT data);
void addAfterX(LinkedList* head, STUDENT data, STUDENT x);
void addBeforeX(LinkedList* head, STUDENT data, STUDENT x);
void dele_last(LinkedList head);
void dele_head(LinkedList *head);
void dele_X(LinkedList* head, STUDENT x);
struct node *search_X(LinkedList list, const STUDENT x);
int count_X(const LinkedList list, const STUDENT x);
void reverse(LinkedList* head);
void count_of_nodes(LinkedList head);
void print_data(LinkedList head);

