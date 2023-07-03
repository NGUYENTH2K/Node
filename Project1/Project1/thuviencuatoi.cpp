#include "thuviencuatoi.h"

//định nghĩa hàm kiểm tra  số hoàn thiện
//struct student
//{
//    char name[50];
//    int dtb;
//};
//typedef struct student STUDENT;
//
//struct node
//{
//    STUDENT data;
//    struct node* link;
//};
//typedef struct node* LinkedList;
int isEmpty(LinkedList list)
{
    return list == NULL;
}
//chÃ¨n node m?i vÃ o d?u danh sÃ¡ch
/*void addNewNode(LinkedList* head, STUDENT data)
{
    struct node* current = (struct node*)malloc(sizeof(struct node));
    current->data.dtb = data.dtb;
    strncpy_s(current->data.name, data.name, sizeof(current->data.name));
    current->link = NULL;

    if (isEmpty(*head))
    {
        *head = current;
    }

    else
    {
        current->link = *head;
        *head = current;
    }
}*/
void addHead(LinkedList* head, STUDENT data)
{
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data.dtb = data.dtb;
    strncpy_s(temp->data.name, data.name, sizeof(temp->data.name));
    temp->link = NULL;
    if (isEmpty(*head))
    {
        *head = temp;
    }
    else
    {
        temp->link = *head;
        *head = temp;
    }
}
//chen vao end
void addTail(LinkedList* head, STUDENT data)
{
    struct node* ptr, * temp;
    ptr = *head;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data.dtb = data.dtb;
    strncpy_s(temp->data.name, data.name, sizeof(temp->data.name));
    temp->link = NULL;
    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr = temp;
}

//Insert after X
void addAfterX(LinkedList* head, STUDENT data, STUDENT x)
{
    struct node* temp, * ptr;
    ptr = *head;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data.dtb = data.dtb;
    strncpy_s(temp->data.name, data.name, sizeof(temp->data.name));
    temp->link = NULL;
    while (ptr != NULL && (strcmp(ptr->data.name, x.name) != 0 || ptr->data.dtb != x.dtb))
    {
        ptr = ptr->link;
    }
    if (ptr == NULL)
    {
        addTail(head, data);
    }
    else
    {
        temp->link = ptr->link;
        ptr->link = temp;
    }
}

//Insert before X
void addBeforeX(LinkedList* head, STUDENT data, STUDENT x)
{
    struct node* temp, * ptr, *prev;
    ptr = *head;
    prev = ptr;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data.dtb = data.dtb;
    strncpy_s(temp->data.name, data.name, sizeof(temp->data.name));
    temp->link = NULL;
    while (ptr != NULL && (strcmp(ptr->data.name, x.name) != 0 || ptr->data.dtb != x.dtb))
    {
        prev = ptr;
        ptr = ptr->link;
    }
    if (ptr == NULL)
    {
        addHead(head, data);
    }
    else
    {
        temp->link = ptr;
        prev->link = temp;
    }
}

//delete last
void dele_last(LinkedList head)
{
    if (head == NULL)
    {
        printf("Linked list is empty");
    }
    else if (head->link == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        struct node* temp = head;
        struct node* temp2 = head;
        while(temp->link != NULL)
        {
            temp2 = temp;
            temp = temp->link;
        }
        temp2->link = NULL;
        free(temp);
        temp = NULL;
    }
}

//delete head
void dele_head(LinkedList *head)
{
    if (head == NULL)
    {
        printf("Linked List is empty");
    }
    else
    {
        struct node* temp = *head;
        (*head) = (*head)->link;
        free(temp);
        temp = NULL;
    }
}
//dele_X
void dele_X(LinkedList* head, const STUDENT x)
{
    if ((strcmp((*head)->data.name, x.name) == 0 || (*head)->data.dtb == x.dtb))
        dele_head(head);
    else
    {
        struct node* current = *head;
        struct node* pre = *head;
        while ((strcmp((current)->data.name, x.name) != 0 || (current)->data.dtb != x.dtb))
        {
            pre = current;
            current = current->link;
        }
        if (current == NULL)
        {
            printf("No value");
        }
        else
        {
            pre->link = current->link;
            current->link = NULL;
            free(current);
        }
    }

}
//search X
struct node* search_X(LinkedList list, STUDENT x)
{
    struct node* p = list;
    while (p != NULL)
    {
        if ((strcmp((p)->data.name, x.name) == 0))
        {
            return p;
        }
        p = p->link;
    }
    return NULL;
}
//count X
int count_X(const LinkedList list, const STUDENT x)
{
    const struct node* p = list;
    int count = 0;
    while (p != NULL)
    {
        if ((strcmp((p)->data.name, x.name) == 0))
        {
            count++;
        }
        p = p->link;
    }
    return count;
}
//couting node
void count_of_nodes(LinkedList head)
{
    int count = 0;
    if (head == NULL)
        printf("\nLinked List is empty");
    struct node* ptr = NULL;
    ptr = head;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->link;
    }
    printf("%d", count);
}

//reverse list
void reverse(LinkedList* head)
{
    struct node* temp = NULL;
    struct node* temp2 = NULL;
    while ((*head) != NULL)
    {
        temp2 = (*head)->link;
        (*head)->link = temp;
        temp = (*head);
        (*head) = temp2;
    }
    (*head) = temp;
}

//Print data
void print_data(LinkedList head)
{
    if (head == NULL)
        printf("Linked List is empty");
    struct node* ptr = NULL;
    ptr = head;
    while (ptr != NULL)
    {
        printf("\nName: %sScore: %d \n", ptr->data.name, ptr->data.dtb);
        ptr = ptr->link;
    }
    printf("\nNULL");
}
