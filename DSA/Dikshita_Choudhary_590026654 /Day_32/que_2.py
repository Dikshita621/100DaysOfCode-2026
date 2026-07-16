def copyStack(st):
    temp = []
    copy = []

    while st:
        temp.append(st.pop())

    while temp:
        x = temp.pop()
        st.append(x)
        copy.append(x)

    return copy

n = int(input("Enter number of elements: "))
print("Enter the elements:")

st = list(map(int, input().split()))

copied = copyStack(st)

print("Copied Stack:", copied)
