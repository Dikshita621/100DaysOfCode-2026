def arrayPairSum(nums):
    # Sort the array
    nums.sort()

    total = 0

    # Add every first element of each pair
    for i in range(0, len(nums), 2):
        total += nums[i]

    return total


# Example
nums = [1, 4, 3, 2]
print(arrayPairSum(nums))
