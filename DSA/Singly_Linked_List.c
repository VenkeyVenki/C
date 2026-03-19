/*Develop a menu driven Program in C for the following operations on Singly Linked List (SLL) of Student Data with the fields: USN, Name, Programme, Sem,PhNo
a).Create a SLL of N Students Data by using front insertion.
b).Display the status of SLL and count the number of nodes in it
c).Perform Insertion / Deletion at End of SLL
d).Perform Insertion / Deletion at Front of SLL(Demonstration of stack)
e).Exit*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student {
    char usn[20];
    char name[20];
    char program[20];
    int sem;
    long int phno;
    struct student *link;
};
typedef struct student *STUDENT;

STUDENT start = NULL;
STUDENT create() {
    STUDENT getnode;
    getnode = (STUDENT)malloc(sizeof(struct student));
    if (getnode == NULL) {
        printf("\nMemory could not be allocated!!!");
        return NULL;
    }
    printf("\nEnter the details of Student");
    printf("\nEnter the usn: ");
    scanf("%s", getnode->usn);
    printf("Enter the name: ");
    scanf("%s", getnode->name);
    printf("Enter the program: ");
    scanf("%s", getnode->program);
    printf("Enter the sem: ");
    scanf("%d", &getnode->sem);
    printf("Enter the phone number: ");
    scanf("%ld", &getnode->phno);
    getnode->link = NULL;
    return getnode;
}
void insert_front() {
    STUDENT node = create();
    if (node == NULL)
        return;
    if (start == NULL) {
        start = node;
    } else {
        node->link = start;
        start = node;
    }
}
void delete_front() {
    if (start == NULL) {
        printf("\nList is empty");
        return;
    }
    STUDENT temp = start;
    start = start->link;
    printf("\nThe deleted student's USN is %s", temp->usn);
    free(temp);
}
void create_list() {
    int n, i;
    printf("\nEnter the number of students: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        insert_front();
    }
}
void status() {
    if (start == NULL) {
        printf("\nList is empty");
        return;
    }
    STUDENT temp = start;
    int count = 0;
    printf("\nThe student details are:");
    while (temp != NULL) {
        printf("\nUSN: %s\nName: %s\nProgram: %s\nSem: %d\nPhone: %ld\n",
               temp->usn, temp->name, temp->program, temp->sem, temp->phno);
        temp = temp->link;
        count++;
    }
    printf("\nThe number of nodes are: %d", count);
}
void insert_end() {
    STUDENT node = create();
    if (node == NULL)
        return;
    if (start == NULL) {
        start = node;
    } else {
        STUDENT temp = start;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = node;
    }
}
void delete_end() {
    if (start == NULL) {
        printf("\nList is empty");
        return;
    }
    if (start->link == NULL) {
        printf("\nThe deleted student's USN is %s", start->usn);
        free(start);
        start = NULL;
        return;
    }
    STUDENT temp = start, prev = NULL;
    while (temp->link != NULL) {
        prev = temp;
        temp = temp->link;
    }
    printf("\nThe deleted student's USN is %s", temp->usn);
    free(temp);
    prev->link = NULL;
}
void stack_demo() {
    int ch;
    for (;;) {
        printf("\nSTACK OPERATIONS");
        printf("\n1: Insert End \n2: Delete End \n3: Status of Stack \n4: Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                insert_end();
                break;
            case 2:
                delete_end();
                break;
            case 3:
                status();
                break;
            case 4:
                return;
            default:
                printf("\nInvalid Choice!!!");
        }
    }
}
int main() {
    int ch;
    for (;;) {
        printf("\nSINGLY LINKED LIST OPERATIONS");
        printf("\n1: Create List \n2: Status of List \n3: Insert End \n4: Delete End \n5: Insert Front \n6: Delete Front \n7: Stack Demo \n8: Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                create_list();
                break;
            case 2:
                status();
                break;
            case 3:
                insert_end();
                break;
            case 4:
                delete_end();
                break;
            case 5:
                insert_front();
                break;
            case 6:
                delete_front();
                break;
            case 7:
                stack_demo();
                break;
            case 8:
                return 0;
            default:
                printf("\nInvalid Choice!!!");
        }
    }
    return 0;
}
