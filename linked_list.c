#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head1 = NULL;
struct Node *head2 = NULL;
struct Node *head = NULL;


struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory overflow! Unable to allocate new node.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

struct Node* create_list(int n) {
    int value;
    struct Node *head = NULL, *temp = NULL, *newNode;

    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        newNode = createNode(value);

        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    return head;
}

void displayList(struct Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


struct Node* deleteAtBeginning(struct Node *head) {
    if (head == NULL) {
        printf("Underflow! List is empty.\n");
        return head;
    }

    struct Node *temp = head;
    head = head->next;
    printf("Deleted node: %d\n", temp->data);
    free(temp);
    return head;
}


struct Node* deleteAtEnd(struct Node *head) {
    if (head == NULL) {
        printf("Underflow! List is empty.\n");
        return head;
    }

    if (head->next == NULL) {
        printf("Deleted node: %d\n", head->data);
        free(head);
        return NULL;
    }

    struct Node *temp = head, *prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    printf("Deleted node: %d\n", temp->data);
    prev->next = NULL;
    free(temp);
    return head;
}


struct Node* deleteAtPosition(struct Node *head, int position) {
    if (head == NULL) {
        printf("Underflow! List is empty.\n");
        return head;
    }

    if (position == 1) {
        struct Node *temp = head;
        head = head->next;
        printf("Deleted node: %d\n", temp->data);
        free(temp);
        return head;
    }

    struct Node *temp = head, *prev = NULL;
    for (int i = 1; i < position && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position!\n");
        return head;
    }

    prev->next = temp->next;
    printf("Deleted node: %d\n", temp->data);
    free(temp);
    return head;
}


struct Node* sortList(struct Node *head) {
    if (head == NULL)
        return head;

    struct Node *ptr1, *ptr2;
    int temp;

    for (ptr1 = head; ptr1->next != NULL; ptr1 = ptr1->next) {
        for (ptr2 = ptr1->next; ptr2 != NULL; ptr2 = ptr2->next) {
            if (ptr1->data > ptr2->data) {
                temp = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = temp;
            }
        }
    }

    return head;
}


struct Node* concatenate(struct Node *head1, struct Node *head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    struct Node *temp = head1;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;
    return head1;
}


int main() {
    int n, choice, position;

    printf("Enter number of nodes for first list: ");
    scanf("%d", &n);
    head1 = create_list(n);

    printf("\nEnter number of nodes for second list: ");
    scanf("%d", &n);
    head2 = create_list(n);

    head = head1;

    while (1) {
        printf("\nMENU:\n");
        printf("1. Display List\n");
        printf("2. Delete from Beginning\n");
        printf("3. Delete from End\n");
        printf("4. Delete from Position\n");
        printf("5. Sort List\n");
        printf("6. Concatenate List1 + List2\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayList(head);
                break;
            case 2:
                head = deleteAtBeginning(head);
                break;
            case 3:
                head = deleteAtEnd(head);
                break;
            case 4:
                printf("Enter position: ");
                scanf("%d", &position);
                head = deleteAtPosition(head, position);
                break;
            case 5:
                head = sortList(head);
                printf("List sorted successfully!\n");
                break;
            case 6:
                head = concatenate(head1, head2);
                printf("Lists concatenated successfully!\n");
                break;
            case 7:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
