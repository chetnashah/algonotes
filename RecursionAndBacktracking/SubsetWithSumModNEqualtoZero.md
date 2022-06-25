

## We have to find a subset with sum modulo N equal to 0, where N is number of elements

## original list size can be large e.g. `nums.length ~ 10^4`, `nums[i] <= 10^9`

## We have to prove that a subarray always exists which has sum Modulo N equal to 0.

By definition, a subarray is also a subset, so subset exists if subarray exists

Proof: there would be N+1 prefix sums (considering empty array sum to be 0).
And we have only N slots for modulo,
so atleast two prefix sums will be same `p[i] == p[j] (mod n)` (by pigeonhole principle).

