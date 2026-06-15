int missingNumber(int* nums, int numsSize) {
    int n = numsSize;
    int expected = n * (n + 1) / 2;
    for (int i = 0; i < numsSize; i++) {
        expected -= nums[i];
    }
    return expected;
}
