class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def rearrangeEvenOdd(head):
    if head is None:
        return None

    evenStart = evenEnd = None
    oddStart = oddEnd = None
    curr = head

    while curr:
        nextNode = curr.next
        curr.next = None

        if curr.data % 2 == 0:
            if evenStart is None:
                evenStart = evenEnd = curr
            else:
                evenEnd.next = curr
                evenEnd = curr
        else:
            if oddStart is None:
                oddStart = oddEnd = curr
            else:
                oddEnd.next = curr
                oddEnd = curr

        curr = nextNode

    if evenStart is None:
        return oddStart
    if oddStart is None:
        return evenStart

    evenEnd.next = oddStart
    return evenStart

def printList(head):
    s = ""
    while head:
        s += str(head.data)
        if head.next:
            s += " -> "
        head = head.next
    print(s)

# Driver code
values = [17, 15, 8, 9, 2, 4, 6]

head = None
tail = None

for x in values:
    node = Node(x)
    if head is None:
        head = node
        tail = node
    else:
        tail.next = node
        tail = node

head = rearrangeEvenOdd(head)
printList(head)
