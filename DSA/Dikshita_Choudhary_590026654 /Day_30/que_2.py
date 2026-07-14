def insertAtBottom(stack, x):
    if not stack:
        stack.append(x)
        return

    temp = stack.pop()
    insertAtBottom(stack, x)
    stack.append(temp)

stack = [1, 2, 3, 4]
x = 5

insertAtBottom(stack, x)
print(stack)
