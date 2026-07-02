class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def removeNthFromEnd(head, n):
    dummy = Node(0)
    dummy.next = head
    fast = dummy
    slow = dummy

    for i in range(n + 1):
        fast = fast.next

    while fast:
        fast = fast.next
        slow = slow.next

    slow.next = slow.next.next
    return dummy.next

def printList(head):
    while head:
        print(head.data)
        head = head.next

# Create linked list: 1 -> 2 -> 3 -> 4 -> 5
head = Node(1)
head.next = Node(2)
head.next.next = Node(3)
head.next.next.next = Node(4)
head.next.next.next.next = Node(5)

n = 2

head = removeNthFromEnd(head, n)

printList(head)
