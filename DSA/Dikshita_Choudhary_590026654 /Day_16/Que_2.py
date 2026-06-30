'''Delete the last node from a doubly linked list, print the updated list, or return NULL if the list becomes empty.

Example
Input:1 <-> 2 <-> 3 <-> 4. Output:1 <-> 2 <-> 3'''
class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None


def deleteLast(head):
    if head is None:
        return None

    if head.next is None:
        return None

    temp = head

    while temp.next is not None:
        temp = temp.next

    temp.prev.next = None

    return head


def printList(head):
    result = []

    while head is not None:
        result.append(str(head.data))
        head = head.next

    print(" <-> ".join(result))


# Driver Code
head = Node(1)
head.next = Node(2)
head.next.prev = head

head.next.next = Node(3)
head.next.next.prev = head.next

head.next.next.next = Node(4)
head.next.next.next.prev = head.next.next

head = deleteLast(head)

if head is None:
    print("NULL")
else:
    printList(head)
