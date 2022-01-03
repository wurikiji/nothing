# The longest common substring (LCS)

> https://www.youtube.com/watch?v=RBSGKlAvoiM&t=23338s

This problem can be solved with LCP array in O(n1 + n2 + ... + nm) time.


## Example

- problem: find the longest common prefix from these strings. 

```
S1 = "abca"
S2 = "bcad"
S3 = "daca"
```

- step 1: concatenate all strings with delimiters that are lexicographically less than
any characters of the strings

```
newString = "abca#bcad$daca%"
```

- step 2: Build LCP array

|LCP Value|Suffix String|
|:---:|----|
|0|#bcad$daca%|
|0|$daca%|
|0|%|
|0|a#bcad$daca%|
|1|a%|
|1|abca#bcad$daca%|
|1|aca%|
|1|ad$daca%|
|0|ca#bcad$daca%|
|2|ca%|
|2|cad$daca%
|0|d$daca%|
|1|daca%|

- step 3: find LCS. Please refer to the original video. 

# The longest repeated substring (LRS)

Building LCP array, and find LRS. It is the same as finding unique substrings. 