# Suffix Array

> Part of the https://www.youtube.com/watch?v=RBSGKlAvoiM&t=23152s
>
> reference: https://github.com/williamfiset/Algorithms


## What is a suffix?

A substring, starting from somewhere at a string to the end of the string, is a suffix of the string. 

Example) horse -> e, se, rse, orse, horse

## What is a Suffix Array (SA)?

### Meaning

All **Sorted** suffixes of a string.

Ex) for "camel"

|index|Starting point|Suffix string|
|----|----|---|
|0| 1| amel|
|1| 0| camel|
|2| 3| el|
|3| 4| l|
|4| 2| mel|

We can store starting points only. 

### An alternative to `suffix tree`

Suffix arrays can do everything suffix trees can,
with some additional information such as
a Longest Common Prefix (LCP) array.

# The longest common prefix (LCP) array

LCP array is the longest common-prefix length between two adjacent elements of SA.

Example) "ABABBAB"
- starting point: The starting point of the suffix substring
- LCP value: length of the LCP

|Starting Point|LCP value|Suffix|
|:---:|:---:|:---|
|5|0|AB| 
|0|2|ABABBAB|
|2|2|ABBAB|
|6|0|B|
|4|1|BAB|
|1|3|BABBAB|
|3|1|BBAB|

LCP array can be constructed over O(nlog(n)) or O(n) time. 

# SA/LCP Application 1 - Find unique substrings

## Naive algorithm

O(n^2) time complexity.

## Using LCP array

Time/Space efficient.

## Example

All unique substrings of `AZAZA.`

The number of all substrings: n(n+1)/2 => 15 => O(n^2) time

- **A, AZ, AZA, AZAZ, AZAZA, Z, ZA, ZAZ, ZAZA**, A, AZ, AZA, Z, ZA, A

Number of unique substrings: 9 (bold font)

### With LCP value

LCP Array 

|LCP value|Sorted Suffixes|
|:-:|--|
|0| A|
|1| AZA|
|3|AZAZA|
|0|ZA|
|2|ZAZA|

We can find the number of repeated substrings using the LCP Array.
The value of the LCP indicates whether
there are repeated substrings or not. 
For example, LCP value 1 in the LCP array[1]
indicates that `A` and `AZA` have the same substring `A`, a length of 1.
If we follow this observation, we can create a simple equation.

Number of all unique substrings = 
n(n+1)/2 - sum(LCP[i] from i = 1 to i = n),
where n(n+1)/2 is the number of all substrings, and `sum` is the number of duplicates.

# The longest common substring

[This file.](./LCS.md)