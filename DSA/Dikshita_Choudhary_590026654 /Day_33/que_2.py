class Solution:
    def postToPre(self, post_exp):
        stack = []

        for ch in post_exp:
            if ch.isalpha():
                stack.append(ch)
            else:
                op2 = stack.pop()
                op1 = stack.pop()
                stack.append(ch + op1 + op2)

        return stack.pop()


# Driver code
s = "ABC/-AK/L-*"

obj = Solution()
print(obj.postToPre(s))
