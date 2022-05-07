# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param A : root node of tree
    # @return an integer
    def isSymmetric(self, A):
        if (A.left == None and A.right == None):
            return 1
        ans = self.isMirror(A.left, A.right)
        if ans == True:
            return 1
        else:
            return 0

    def isMirror(self,A, B):
        if(A == None and B == None):
            return True
        if ((A == None and B != None) or (A != None and B == None)):
            return False
        if(A.val == B.val):
            return self.isMirror(A.right, B.left) and self.isMirror(A.left, B.right)
        else:
            return False