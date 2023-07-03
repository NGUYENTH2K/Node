#include "thuviencuatoi.h"



//ki?m tra dslk có r?ng không



int main()
{
    LinkedList head = NULL;
    int n;
    puts("Enter the number of element  : ");
    scanf_s("%d", &n);
    getchar(); // Consume the newline character from the previous input
    int i;
    for (i = 0; i < n; i++)
    {
        STUDENT data;
        printf("\nEnter name of student %d: ", i + 1);
        fgets(data.name, sizeof(data.name), stdin);
        printf("\nEnter average score of student %d: ", i + 1);
        scanf_s("%d", &data.dtb);
        getchar(); // Consume the newline character from the previous input
        addHead(&head, data);
        //addTail(&singlyLikedList, data);
    }
    //printf("Linked list");
    //print_data(head);
    //STUDENT data, data1;
    //printf("\nEnter name of student need add: ");
    //fgets(data1.name, sizeof(data1.name), stdin);
    //printf("\nEnter score of student need add: ");
    //scanf_s("%d", &data1.dtb);
    //getchar();
    //printf("\nEnter name of student X: ");
    //fgets(data.name, sizeof(data.name), stdin);
    //printf("\nEnter score of student X: ");
    //scanf_s("%d", &data.dtb);
    //getchar();
    ////addAfterX(&head, data1, data);
    //addBeforeX(&head, data1, data);
    //printf("\nLinked list: ");
    //dele_last(head);
    //dele_head(&head);
    printf("\nLinked list: ");
    print_data(head);
    //SEARCH
    /*
        STUDENT data1;
        printf("\nEnter name of student need dele X: ");
        fgets(data1.name, sizeof(data1.name), stdin);
        //getchar();
        struct node *SearchResult = search_X(head, data1);
        int countResult = count_X(head, data1);
        SearchResult == NULL ? printf("No look") : printf("look");
        printf("/nThe number : %d ", countResult);
    */
    //getchar();
    //dele_X(&head, data1);
    printf("\nLinked list: ");
    reverse(&head);
    print_data(head);
    free(head);

}