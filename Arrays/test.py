
def calculatePrefixSum(arr):
    prefixSum = [0] * len(arr)
    prefixSum[0] = arr[0]
    for i in range(1, len(arr)):
        prefixSum[i] = arr[i] + prefixSum[i-1]
    return prefixSum


lst = [1,1,1,1,1,1,1,1]
prefixSum = calculatePrefixSum(lst)
assert prefixSum == [1,2,3,4,5,6,7,8]