
Two pointers is useful in longest subarray/substring kind of problems, where you can keep incrementing end pointer/window till a condition is valid.

## Connection between two pointers and Binary search

### Binary search is a kind of two pointer technique where we move around hi,lo till we arrive to an answer

### Binary search (the end pointer) can be applied where we have condition: find longest subarray where some condition

### Why? 

Because binary search can be applied when we have a bunch of yes followed by a bunch of no or vice versa.
So for end pointer of subarray, anything greater than longest subarray might be a bunch of no/false.

## Cpp template

```cpp
#include<bits/stdc++.h>
using namespace std;


void solve(){
	int n,d;
	cin>>n>>d;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	long long ans = 0;

	// head and tail
	int tail = 0,head = -1;
	// some ds
	int cnt1 = 0;

	// move tail one by one
	while(tail<n){
		// move head one by one if you can take the next element
		while(head+1<n && (cnt1 + arr[head+1]<=d)){
			head++;
			if(arr[head]==1){
				cnt1++;
			}
			
		}
		// update the answer with the current window
		ans += head-tail+1;

		// move your tail one step
		if(head>=tail){
			if(arr[tail]==1){
				cnt1--;
			}
			tail++;
		}else{
			// empty subarray case
			tail++;
			head=tail-1;
		}
	}


	cout<<ans<<endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t=1;
	// cin>>t;
	for(int i=0;i<t;i++){
		solve();
	}
}
```