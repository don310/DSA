#include<stdio.h>
#include<stdlib.h>

// Define a structure for a node in a singly linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to traverse and print the elements of a linked list
void linkedListTraversal(struct Node* ptr) {
    // Traverse the linked list until the end (ptr becomes NULL)
    while (ptr != NULL) {
        // Print the data of the current node
        printf("Element: %d\n", ptr->data);
        // Move the pointer to the next node
        ptr = ptr->next;
    }
}

// case1 : Deleting the first element from the linked list
struct Node* deleteFirst(struct Node* head) {
    struct Node* ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

// case2 : Deleting the element at a given index from the linked list
struct Node* deleteAtIndex(struct Node* head, int index) {
    struct Node* p = head;
    struct Node* q = head->next;
    for (int i = 0; i < index - 1; i++) {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

// case3 : Deleting the Last element
struct Node* deleteAtLast(struct Node* head) {
    struct Node* p = head;
    struct Node* q = head->next;
    while (q->next != NULL) {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

// case2 : Deleting the element with a given value from the linked list
struct Node* deleteAtIndex(struct Node* head, int value) {
    struct Node* p = head;
    struct Node* q = head->next;
    while(q->data!=value && q->next != NULL) {
        p = p->next;
        q = q->next;
    }
   if(q->data == value){
      p->next = q->next;
    free(q);
   }
    return head;
}


int main() {
    struct Node* head;
    struct Node* second;
    struct Node* third;
    struct Node* fourth;

    // Allocate memory for nodes in the linked list in the heap
    head = (struct Node*) malloc(sizeof(struct Node));
    second = (struct Node*) malloc(sizeof(struct Node));
    third = (struct Node*) malloc(sizeof(struct Node));
    fourth = (struct Node*) malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 4;
    head->next = second;

    // Link second and third nodes
    second->data = 3;
    second->next = third;

    // Link third and fourth nodes
    third->data = 8;
    third->next = fourth;

    // Terminate the list at the fourth node
    fourth->data = 1;
    fourth->next = NULL;

    printf("Linked list before deletion\n");
    linkedListTraversal(head);

    // Perform deletion operations
    // head = deleteFirst(head); // For deleting the first element of the linked list
    // head = deleteAtIndex(head, 2); // For deleting element at a given index
    head = deleteAtLast(head); // For deleting the last element

    printf("Linked list after deletion\n");
    linkedListTraversal(head);

    return 0;
}
