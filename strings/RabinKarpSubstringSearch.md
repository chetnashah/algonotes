
For exact matching of a pattern P within a Text T.

### Hashing used

Given `Text T` and `Pattern P`

1. generate hash of pattern `P`, i.e `hash(P) = X`


### Number of substrings (of text T) to compare against Pattern P

`No of substrings = len(T) - len(P) + 1` which is like O(T)

### Hash function

`a-z` is mappped to `1-26`.

### Since hash is a sum polynomial of individual chars, sliding window technique can be used

hash value is the running aggregate that we care about and can be stored in a separate aux structure if needed as a preprocessing step.

Rolling hash is updated by sliding window considering different substrings.
1. subtract the leaving charachter.
2. Divide by prime(remaining polynomial is guaranteed to be divisible)
3. Add result from previos step + p ^ k - 1, to get hash of current window.

### Core iteration loop to update aggregate/running hash on window slide

1. X = old_hash - val(old_char)
2. X = X/prime
3. X = X + val(new_char) * prime ^ (k - 1) 

