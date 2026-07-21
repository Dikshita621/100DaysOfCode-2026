from collections import deque

# User input
priorities = list(map(int, input("Enter priorities separated by space: ").split()))
location = int(input("Enter document location: "))

# Create queue (priority, original_index)
queue = deque()

for i in range(len(priorities)):
    queue.append((priorities[i], i))

time = 0

while queue:
    current = queue.popleft()

    # Check if any document has higher priority
    if any(current[0] < doc[0] for doc in queue):
        queue.append(current)
    else:
        time += 1
        if current[1] == location:
            print("Output:", time)
            break
