#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push operation
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }

    stack[++top] = value;
}

// Pop operation
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }

    return stack[top--];
}

// Swap top two elements
void swapTop() {
    if (top < 1) {
        printf("Not enough elements to swap\n");
        return;
    }

    int temp = stack[top];
    stack[top] = stack[top - 1];
    stack[top - 1] = temp;
}

// Display stack from top to bottom
void display() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack (top to bottom): ");

    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    push(40);

    printf("Popped: %d\n", pop());

    swapTop();

    display();

    return 0;
}
