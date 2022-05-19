

## Brute force approach

We track max with a single variable.

`Enqueue`: tracking max is simple, we update max with previous known max.
`Dequeue`: We must track max by checking against all the remaining elements in queue.

## Insight

In a queue, both end pointer moves on adding elements, and front pointer moves on dequeueing elements.
hence you can think of these two pointers forming a sliding window.


## Code

```java
public class QueueWithMax {
  ArrayDeque<Integer> entriesDeque = new ArrayDeque<>();
  ArrayDeque<Integer> candidateMax = new ArrayDeque<>();// monotonic decreasing queue holds max in front

  // by convention enqueueing via addLast
  public void enqueue(Integer x) {
    System.out.println("enqueue x = "+x);
    entriesDeque.addLast(x);
    // keep removing items from last till we have monotonic decreasing for same ordering as entries queue
    while(!candidateMax.isEmpty() && candidateMax.peekLast() < x){ // maintain monotonic decreasing property in maxqueue
      candidateMax.removeLast();
    }
    candidateMax.addLast(x);
    printDequeue();
  }

  // by convention dequeueing from front via removeFirst
  public Integer dequeue() {
    System.out.println("dequeue");
    Integer removed = entriesDeque.removeFirst();
    if(removed.equals(candidateMax.peekFirst())) {
      candidateMax.removeFirst();
    }
    printDequeue();
    return removed;
  }

  private void printDequeue(){
    System.out.println("entries dequeue : " + Arrays.toString(entriesDeque.toArray()));
    System.out.println("candidateMax dequeue : " + Arrays.toString(candidateMax.toArray()));
  }

  public Integer max() {
    return candidateMax.peekFirst();
  }
}
```