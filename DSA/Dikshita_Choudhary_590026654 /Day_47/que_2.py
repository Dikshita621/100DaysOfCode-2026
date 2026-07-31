class Solution(object):
    def kthSmallest(self, A, B, k):
        # Always binary search on the smaller array
        if len(A) > len(B):
            A, B = B, A

        n, m = len(A), len(B)

        # Number of elements taken from A
        left = max(0, k - m)
        right = min(k, n)

        while left <= right:
            i = (left + right) // 2
            j = k - i

            Aleft = float('-inf') if i == 0 else A[i - 1]
            Aright = float('inf') if i == n else A[i]

            Bleft = float('-inf') if j == 0 else B[j - 1]
            Bright = float('inf') if j == m else B[j]

            if Aleft <= Bright and Bleft <= Aright:
                return max(Aleft, Bleft)
            elif Aleft > Bright:
                right = i - 1
            else:
                left = i + 1

        return -1


# Example
A = [2, 3, 6, 7]
B = [1, 4, 5, 8]
k = 5

obj = Solution()
print(obj.kthSmallest(A, B, k))
