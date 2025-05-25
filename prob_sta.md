# Problem Statement: **COUNTING DISTINCT NUMBER OF COLLINEAR LINES IN THE GIVEN MATRIX**

## Introduction
In geometry, identifying a collinear line is no big deal we can easily tell by looking at the matrix but implying that in a code is not that easy. This problem involves detecting all distinct collinear lines that can be formed by connecting 1s in a 2D matrix.

## Objective
To determine the total number of ***distinct*** collinear lines that can be formed by connecting two or more `1`s that lie on the same straight line in a binary matrix of size [m*n].

## Problem Description
You are given a matrix of size [m*n] consisting only of `0`s and `1`s. Your task is to:
- Identify all sets of three or more `1`s that lie on the same straight line...in terms of geometry which have the same slope(i.e., are **collinear**).
- Count the total number of *distinct* collinear lines formed.
- Overlapping lines will be counted as one collinear line only

### Example

Input 1:  
0 1 0 1  
0 0 0 0    
0 1 0 1    
1 1 0 0  
Output -> 2  

Explanation:  
-The diagonal from top right corner to bottom left contains 3 ones that lie on the same diagonal.    
-The second column has 3 ones that lie on the same line so it is also a collinear line.

Input 2:  
0 0 1 1 1  
1 0 0 0 0  
0 0 0 1 1  
1 0 1 0 1  

Output -> 3



