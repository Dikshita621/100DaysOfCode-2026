from collections import deque

def servedMinute(n, k):
    q = deque(range(1, n + 1))
    minute = 0

    while q:
        person = q.popleft()
        minute += 1

        if person == k:
            return minute

        if q and q[0] % 2 == 1:
            q.append(q.popleft())

print(servedMinute(4, 3))
