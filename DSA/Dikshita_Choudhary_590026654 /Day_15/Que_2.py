'''Reverse a singly linked list without creating a new list.
Example
Input:1 -> 2 -> 3 -> 4 -> 5. Output:5 -> 4 -> 3 -> 2 -> 1'''
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
def reverse(head):
    prev = None
    curr = head

    while curr:
        nxt = curr.next
        curr.next = prev
        prev = curr
        curr = nxt

    return prev

def printList(head):
    result = []
    while head:
        result.append(str(head.data))
        head = head.next
    print(" -> ".join(result))

# Driver code
head = Node(1)
head.next = Node(2)
head.next.next = Node(3)
head.next.next.next = Node(4)
head.next.next.next.next = Node(5)

printList(head)
head = reverse(head)
printList(head)
