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

// Greedy libs Algorithm

// Searching libs Algorithm

// Sorting libs Algorithm

// Graph libs Data Structure

// Tree libs Data Structure

using namespace std;

int main() {
    int array[] = {1, 2, 3, 4};
    Permutation::next(array, 4);
    for (int i = 0; i < 4; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    return 0;
}