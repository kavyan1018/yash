#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

struct Deque {
    int front;
    int rear;
    int capacity;
    int* array;
};

struct Deque* initializeDeque(int capacity) {
    struct Deque* deque = (struct Deque*)malloc(sizeof(struct Deque));
    deque->front = -1;
    deque->rear = -1;
    deque->capacity = capacity;
    deque->array = (int*)malloc(capacity * sizeof(int));
    return deque;
}

int isEmpty(struct Deque* deque) {
    return deque->front == -1;
}

int isFull(struct Deque* deque) {
    return (deque->rear + 1) % deque->capacity == deque->front;
}

int size(struct Deque* deque) {
    if (isEmpty(deque)) {
        return 0;
    }
    return (deque->capacity - deque->front + deque->rear + 1) % deque->capacity;
}

void insertFront(struct Deque* deque, int data) {
    if (isFull(deque)) {
        printf("Deque overflow\n");
        return;
    }

    if (isEmpty(deque)) {
        deque->front = 0;
        deque->rear = 0;
    } else {
        deque->front = (deque->front - 1 + deque->capacity) % deque->capacity;
    }

    deque->array[deque->front] = data;
}

void insertRear(struct Deque* deque, int data) {
    if (isFull(deque)) {
        printf("Deque overflow\n");
        return;
    }

    if (isEmpty(deque)) {
        deque->front = 0;
        deque->rear = 0;
    } else {
        deque->rear = (deque->rear + 1) % deque->capacity;
    }

    deque->array[deque->rear] = data;
}

int deleteFront(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque underflow\n");
        return -1;
    }

    int data = deque->array[deque->front];

    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = -1;
    } else {
        deque->front = (deque->front + 1) % deque->capacity;
    }

    return data;
}

int deleteRear(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque underflow\n");
        return -1;
    }

    int data = deque->array[deque->rear];

    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = -1;
    } else {
        deque->rear = (deque->rear - 1 + deque->capacity) % deque->capacity;
    }

    return data;
}

void display(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        return;
    }

    int i = deque->front;
    printf("Deque elements: ");
    while (1) {
        printf("%d ", deque->array[i]);

        if (i == deque->rear) {
            break;
        }

        i = (i + 1) % deque->capacity;
    }
    printf("\n");
}

int main() {
    int capacity, choice, data;
    
    printf("Enter the capacity of the deque: ");
    scanf("%d", &capacity);

    struct Deque* deque = initializeDeque(capacity);

    do {
        printf("\nChoose operation:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display Deque\n");
        printf("6. Get Deque Size\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at front: ");
                scanf("%d", &data);
                insertFront(deque, data);
                break;

            case 2:
                printf("Enter data to insert at rear: ");
                scanf("%d", &data);
                insertRear(deque, data);
                break;

            case 3:
                data = deleteFront(deque);
                if (data != -1) {
                    printf("Deleted element from front: %d\n", data);
                }
                break;

            case 4:
                data = deleteRear(deque);
                if (data != -1) {
                    printf("Deleted element from rear: %d\n", data);
                }
                break;

            case 5:
                display(deque);
                break;

            case 6:
                printf("Deque size: %d\n", size(deque));
                break;

            case 7:
                printf("Exiting program\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    } while (choice != 7);

    free(deque->array);
    free(deque);

    return 0;
}