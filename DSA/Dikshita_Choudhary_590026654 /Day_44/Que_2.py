def favorite_removed(nums, favoriteIndex, k):
    favorite = nums[favoriteIndex - 1]

    greater = 0
    equal = 0

    for num in nums:
        if num > favorite:
            greater += 1
        elif num == favorite:
            equal += 1

    if greater >= k:
        return "NO"
    elif greater + equal <= k:
        return "YES"
    else:
        return "MAYBE"


# Example
nums = [4, 2, 1, 3, 5]
favoriteIndex = 5
k = 3

print(favorite_removed(nums, favoriteIndex, k))
