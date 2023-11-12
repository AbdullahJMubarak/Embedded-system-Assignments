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

void addNodeAtIndex(struct Node** head, int newData, int index) {
    if (index < 0) {
        printf("Invalid index.\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    
    if (index == 0) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* current = *head;
        int currentIndex = 0;

        while (current != NULL && currentIndex < index - 1) {
            current = current->next;
            currentIndex++;
        }

        if (current == NULL) {
            printf("Index out of bounds.\n");
            free(newNode);
            return;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    printf("Node added at index %d.\n", index);
}

int main() {
    struct Node* head = NULL;
    int choice;

    while (1) {
        printf("Press 0 to add a node, 1 to print the linked list, 2 to delete a node, 3 to add a node at a specific index, or 4 to exit: ");
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
            case 3: {
                int newData, index;
                printf("Enter data for the new node: ");
                scanf("%d", &newData);
                printf("Enter index for the new node: ");
                scanf("%d", &index);
                addNodeAtIndex(&head, newData, index);
                break;
            }
            case 4:
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
