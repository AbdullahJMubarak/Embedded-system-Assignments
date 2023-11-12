#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void addNode(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
    printf("Node added successfully.\n");
}

void printList(struct Node* head) {
    printf("Linked List: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}


void deleteNode(struct Node** head, int value) {
    struct Node* current = *head;
    struct Node* prev = NULL;

    while (current != NULL) {
        if (current->data == value) {
            if (prev == NULL) {
                *head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Node with value %d deleted.\n", value);
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("Node with value %d not found.\n", value);
}

int main() {
    struct Node* head = NULL;
    int choice;

    while (1) {
        printf("Press 0 to add a node, 1 to print the linked list, 2 to delete a node, or 3 to exit: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0: {
                int newData;
                printf("Enter data for the new node: ");
                scanf("%d", &newData);
                addNode(&head, newData);
                break;
            }
            case 1:
                printList(head);
                break;
            case 2: {
                int deleteValue;
                printf("Enter the value to delete: ");
                scanf("%d", &deleteValue);
                deleteNode(&head, deleteValue);
                break;
            }
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Incorrect entry.\n");
        }
    }

    
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
