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
#include "lib/algorithms/sort/MergeSort.h"

// Greedy libs Algorithm

// Searching libs Algorithm

// Sorting libs Algorithm

// Graph libs Data Structure

// Tree libs Data Structure

using namespace std;

int main() {
    int array[] = {6,5,3,1,8,7,2,4};
    MergeSort<int, int>::sort(array, 0, 7);
    for (int e : array) {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}