from collections import deque

def reconstruct_deck(n):
    positions = deque(range(n))
    deck = [0] * n

    for card in range(1, n + 1):
        # Place the current card at the front position
        deck[positions.popleft()] = card

        # Move the next position to the back
        if positions:
            positions.append(positions.popleft())

    return deck


# User Input
n = int(input("Enter n: "))

result = reconstruct_deck(n)
print("Initial deck arrangement:", result)
