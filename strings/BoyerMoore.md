

## Preprocess pattern P to generate a lookup table for bad charachter and good suffix rule

Even if text T changes,
Preprocessed lookup table for pattern P can be re-used across many texts.


### COMPARISION IDEA

Charachter comparision from right to left of pattern, but starting part of text

### bad charachter rule

shift P to right till mismatch becomes a match

### good suffix rule

let `t` be substring matched by inner loop
