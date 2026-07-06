#include <stdio.h>
#include <stdlib.h>

struct Node {
    int heroID;
    struct Node* next;
};

struct Node* head = NULL;

// Insert at end
void insert(int id) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->heroID = id;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Detect and remove loop
void detectAndRemoveLoop() {
    struct Node *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }

    if (fast == NULL || fast->next == NULL)
        return;

    slow = head;

    if (slow == fast) {
        while (fast->next != slow)
            fast = fast->next;
    } else {
        while (slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    fast->next = NULL;
}

// Display list
void display() {
    struct Node* temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->heroID);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Delete a hero
void deleteHero(int id) {
    struct Node* temp = head;
    struct Node* prev = NULL;

    while (temp != NULL && temp->heroID != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    if (prev == NULL)
        head = head->next;
    else
        prev->next = temp->next;

    free(temp);
}

// Find middle node
struct Node* findMiddle() {
    struct Node* slow = head;
    struct Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main() {

    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);

    // Uncomment to test loop detection
    /*
    struct Node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = head->next;   // Creates a loop
    */

    detectAndRemoveLoop();

    display();

    deleteHero(3);

    display();

    struct Node* mid = findMiddle();

    if (mid != NULL)
        printf("Backup Leader: %d\n", mid->heroID);

    return 0;
}
