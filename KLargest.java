import java.util.*;

class KLargestNumbers {
  public static List<Integer> findKLargestNumbers(int[] nums, int k) {
    PriorityQueue<Integer> pq = new PriorityQueue<>();
    for(int i = 0; i< k; i++) {
      pq.add(nums[i]);
    }
    List<Integer> ans = new ArrayList<Integer>();
    for(int i = k; i< nums.length; i++) {
      Integer minItem = pq.peek();
      if(nums[i] < minItem) { // num under consiideration is even lower than elements in min-heap 
        // ignore it
      } else {
        // num under consideration is greater than or equal to min heap top, so it deserves a place
        pq.poll();
        pq.add(nums[i]);
      }
    }
    for(int i=0;i<k;i++) {
      ans.add(pq.poll());
    }
    return ans;
  }

  public static void main(String[] args) {
    List<Integer> result = KLargestNumbers.findKLargestNumbers(new int[] { 3, 1, 5, 12, 2, 11 }, 3);
    System.out.println("Here are the top K numbers: " + result);

    result = KLargestNumbers.findKLargestNumbers(new int[] { 5, 12, 11, -1, 12 }, 3);
    System.out.println("Here are the top K numbers: " + result);
  }
}
