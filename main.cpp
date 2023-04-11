// Standard libs
#include <iostream>

// Dynamic libs Algorithm
#include "lib/algorithms/dynamic/EditDistance.h"
#include "lib/algorithms/dynamic/FibonacciNumber.h"
#include "lib/algorithms/dynamic/LongestCommonSubsequence.h"
#include "lib/algorithms/dynamic/LongestCommonSubstring.h"
#include "lib/algorithms/dynamic/WeightedActivitySelection.h"

//generate libs Algorithm
#include "lib/algorithms/generate/Binary.h"
#include "lib/algorithms/generate/Combination.h"
#include "lib/algorithms/generate/Permutation.h"

// sorting libs algorithm
#include "lib/algorithms/sort/BubbleSort.h"
#include "lib/algorithms/sort/BucketSort.h"
#include "lib/algorithms/sort/HeapSort.h"
#include "lib/algorithms/sort/InsertionSort.h"
#include "lib/algorithms/sort/MergeSort.h"
#include "lib/algorithms/sort/QuickSort.h"
#include "lib/algorithms/sort/SelectionSort.h"

// Greedy libs Algorithm

// Searching libs Algorithm

// Graph libs Data Structure

// Tree libs Data Structure

using namespace std;

int main() {
    
    cout << LongestCommonSubstring<int>::getLongestCommonSubstring("zxabcdezy", "yzabcdezx") << endl;
    
    return 0;
}