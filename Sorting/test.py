

def swapAtIdx(m, n, arr):
    print("swapping at: m = ", m, " n = ", n)
    temp = arr[m]
    arr[m] = arr[n]
    arr[n] = temp

def lomutoPartition(l, r, arr):
    if (l >= r):
        return
    # start with m = l, the pivot
    m = l
    for i in range(l+1, r+1): # start iterating starting after the pivot
        if arr[i] < arr[l]: # middle pointer should increase in case -> item is less than pivot
            m = m + 1 
            # at this point, m may point to an element greater than arr[l]
            if(m != i): # simple optimization, no need to swap if same idx
                swapAtIdx(m, i, arr) # 
            # at this point, m points to arr element less than l (which came from idx i)
    swapAtIdx(l,m, arr) # bring pivot element i.e l into its final place in sorted arr

def hoarePartition(l, r, arr):
    i = l+1
    j = r
    while True: # termination till crossed over
        while(arr[i] < arr[l]):
            i = i+1
        while(arr[j] > arr[l]):
            j = j-1
        
        if(i >= j): # termination condition
            swapAtIdx(l, j, arr) # final swap pivot with j
            return
        
        swapAtIdx(i,j,arr) # unstuck pointers
    


arr = [6,2,9,3,1,4,7,5]
lomutoPartition(0, len(arr)-1, arr)
print(arr)
assert arr[-3] == 6 # 6 is third last element before 7 and 9

arr2 = [6,2,9,3,1,4,7,5]
hoarePartition(0, len(arr2) - 1, arr2)
print(arr2)
assert arr[-3] == 6 # 6 is third last element before 7 and 9
