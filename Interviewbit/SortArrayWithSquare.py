class Solution:
    # @param A : list of integers
    # @return a list of integers
    def solve(self, A):
        for i in range(len(A)):
            A[i]*=A[i]
        A.sort()
        return A

t = Solution()

print(t.solve([-6, -3, -1, 2, 4, 5]))