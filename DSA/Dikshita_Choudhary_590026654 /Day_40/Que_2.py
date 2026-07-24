from collections import deque

def max_sliding_window(temperatures, k):
    # Return empty list if input is invalid
    if not temperatures or k == 0:
        return []

    # Deque will store indices of useful elements
    dq = deque()

    # List to store the maximum of each window
    result = []

    # Traverse through the temperature array
    for i in range(len(temperatures)):

        # Remove indices that are outside the current window
        while dq and dq[0] <= i - k:
            dq.popleft()

        # Remove indices whose corresponding values are
        # smaller than the current element because they
        # can never be the maximum while the current element exists
        while dq and temperatures[dq[-1]] < temperatures[i]:
            dq.pop()

        # Add the current index to the deque
        dq.append(i)

        # Once the first window is complete,
        # record the maximum element of the current window
        if i >= k - 1:
            result.append(temperatures[dq[0]])

    # Return the list of window maximums
    return result


# ---------------- Main Program ----------------

# Read temperatures from the user
temperatures = list(map(int, input("Enter temperatures separated by spaces: ").split()))

# Read the window size
k = int(input("Enter window size (k): "))

# Find maximum temperature in every window
answer = max_sliding_window(temperatures, k)

# Display the result
print("\nMaximum temperature in each window:")
print(answer)
