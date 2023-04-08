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
#include "lib/algorithms/sort/BubbleSort.h"
#include "lib/algorithms/sort/BucketSort.h"
#include "lib/algorithms/sort/CountingSort.h"
#include "lib/algorithms/sort/CycleSort.h"
#include "lib/algorithms/sort/HeapSort.h"
#include "lib/algorithms/sort/InsertionSort.h"
#include "lib/algorithms/sort/MergeSort.h"
#include "lib/algorithms/sort/OddEvenSort.h"
#include "lib/algorithms/sort/QuickSort.h"
#include "lib/algorithms/sort/SelectionSort.h"

// Graph libs Data Structure
#include "lib/data_structure/graph/Graph.h"
#include "lib/data_structure/graph/UndirectedGraph.h"

// Tree libs Data Structure
#include "lib/data_structure/tree/BinarySearchTree.h"
#include "lib/data_structure/tree/Tree.h"

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