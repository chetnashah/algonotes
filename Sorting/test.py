

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
        while(arr[i] <= arr[l]):
            i = i+1
            if i >= r: # without this it will run past right bound
                break
        while(arr[j] >= arr[l]):
            j = j-1
            if j <= l: # without this, it will run past left bound
                break
        
        if(i >= j): # termination condition
            swapAtIdx(l, j, arr) # final swap pivot with j
            return j # return position where we placed the pivot
        
        swapAtIdx(i,j,arr) # unstuck pointers
    

def hoareQuickSort(arr, l, r):
    print("Quicksort called with indexes: [", l, ", ", r, "]")
    if (r <= l):
        return
    j = hoarePartition(l, r, arr)
    print("pivot placed in position: ", j)
    hoareQuickSort(arr, 0, j-1)
    hoareQuickSort(arr, j+1, r)

arr = [7,6,5,4,3,2,1,0]
hoareQuickSort(arr, 0 , len(arr) - 1)

print(arr)