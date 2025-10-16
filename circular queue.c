#include<stdio.h>
#define MAX 3

int front = -1, rear = -1, queue[MAX];

void insert(int a) {
    if ((rear + 1) % MAX == front) {
        printf("Queue overflow.\n");
    } else {
        if (front == -1) {
            front = rear = 0;
            queue[rear] = a;  // Insert the first element here
        } else {
            rear = (rear + 1) % MAX;
            queue[rear] = a;
        }
    }
}

void delete() {
    if (front == -1) {
        printf("Queue underflow\n");
    } else {
        printf("The deleted element: %d\n", queue[front]);
        if (front == rear) {
            front = rear = -1; // Queue becomes empty
        } else {
            front = (front + 1) % MAX;
        }
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue: ");
        int i = front;
        while (1) {
            printf("%d\t", queue[i]);
            if (i == rear)
                break;
            i = (i + 1) % MAX;
        }
        printf("\n");
    }
}

void main() {
    printf("Circular Queue\n");
    int c, ele;
    printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
    while (1) {
        printf("\nEnter the choice: ");
        scanf("%d", &c);
        switch (c) {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &ele);
                insert(ele);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Terminating...\n");;
            default:
                printf("Invalid choice\n");
        }
        if(c==4)
            break;
    }
}
