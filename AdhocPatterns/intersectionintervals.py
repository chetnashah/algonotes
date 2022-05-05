def merge(intervals_a, intervals_b):
    result = []
    # TODO: Write your code here
    i = 0
    j = 0

    while(i < len(intervals_a) and j < len(intervals_b)):
        # cases where no overlap
        if (intervals_a[i][0] >= intervals_b[j][1]): # i starts after j ends
            j = j + 1
      
        elif (intervals_b[j][0] >= intervals_a[i][1]): # j starts after i ends
            i = i + 1

        # Complete overlap cases
        # i completely in j
        elif (intervals_a[i][0] >= intervals_b[j][0] and intervals_a[i][1] <= intervals_b[j][1]):
            result.append([intervals_a[i][0], intervals_a[i][1]])
            i = i + 1
        elif (intervals_b[j][0] >= intervals_a[i][0] and intervals_b[j][1] <= intervals_a[j][1]):
            result.append([intervals_b[j][0], intervals_b[j][1]])
            j = j + 1

        # partial overlap cases remaining
        # i's ending is overlas with j, start does not
        elif (intervals_a[i][1] > intervals_b[j][0] and intervals_a[i][1] < intervals_b[j][1]): # i -> j
            result.append([intervals_b[j][0], intervals_a[i][1]])
            i = i + 1
        # i's starting overlaps with j, end does not
        elif (intervals_a[i][0] > intervals_b[j][0] and intervals_a[i][0] < intervals_b[j][1]): # j -> i
            result.append([intervals_a[i][0], intervals_b[j][1]])
            j = j + 1

    # print("i = ", i, " j = ", j)
        # intervals remaining in i or j can be safely ignored since they would not intersect with anything

    return result


def main():
  print("Intervals Intersection: " + str(merge([[1, 3], [5, 6], [7, 9]], [[2, 3], [5, 7]])))
  print("Intervals Intersection: " + str(merge([[1, 3], [5, 7], [9, 12]], [[5, 10]])))


main()