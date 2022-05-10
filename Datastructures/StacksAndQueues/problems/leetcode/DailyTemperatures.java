import java.util.Stack;

class PairInt {
    public Integer value;
    public Integer pos;
    
    PairInt(int value, int pos) {
        this.value = value;
        this.pos = pos;
    }
}

class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        Stack<PairInt> st = new Stack<PairInt>(); // monotonically decreasing stack needed to get next greater el
        int[] ans = new int[temperatures.length];
        
        for(int i=temperatures.length -1; i >= 0; i--) {
            if(st.size() == 0) {
                st.push(new PairInt(temperatures[i], i));
                ans[i] = 0;
            } else {
                int valtobepushed = temperatures[i];
                int postobepushed = i;
                
                while(st.isEmpty() == false && st.peek().value <= valtobepushed) {
                    PairInt poppedItem = st.pop();
                }
                if(st.isEmpty() == false) {
                    PairInt peekedItem = st.peek();
                    int posdiff = peekedItem.pos - i;
                    ans[i] = posdiff;
                } else {
                    ans[i] = 0;
                }
                st.push(new PairInt(valtobepushed, postobepushed));
            }
        }
        return ans;
    }
}