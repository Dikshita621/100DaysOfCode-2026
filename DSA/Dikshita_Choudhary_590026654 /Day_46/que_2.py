def maximize_prefix_difference(arr):
    if len(arr) <= 1:
        return arr

    maximum = max(arr)
    minimum = min(arr)

    arr.remove(maximum)
    arr.remove(minimum)

    return [maximum, minimum] + arr


# Example
arr = [7, 6, 5]
result = maximize_prefix_difference(arr[:])
print("Rearranged Array:", result)

# Calculate the required sum
running_max = result[0]
running_min = result[0]
total = 0

for x in result:
    running_max = max(running_max, x)
    running_min = min(running_min, x)
    total += running_max - running_min

print("Maximum Sum:", total)
