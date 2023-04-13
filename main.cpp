// Standard libs
#include <iostream>

// BruteForce libs Algorithm
#include "lib/algorithms/BruteForce/TravellingSalesman.cpp"

// Dynamic libs Algorithm
#include "lib/algorithms/dynamic/EditDistance.cpp"
#include "lib/algorithms/dynamic/FibonacciNumber.cpp"
#include "lib/algorithms/dynamic/LongestCommonSubsequence.cpp"
#include "lib/algorithms/dynamic/LongestCommonSubstring.cpp"
#include "lib/algorithms/dynamic/WeightedActivitySelection.cpp"

// generate libs Algorithm
#include "lib/algorithms/generate/Binary.cpp"
#include "lib/algorithms/generate/Combination.cpp"
#include "lib/algorithms/generate/Permutation.cpp"

// greedy libs algorithm
#include "lib/algorithms/greedy/ActivitySelection.cpp"

// sorting libs algorithm
#include "lib/algorithms/sort/BubbleSort.cpp"
#include "lib/algorithms/sort/BucketSort.cpp"
#include "lib/algorithms/sort/HeapSort.cpp"
#include "lib/algorithms/sort/InsertionSort.cpp"
#include "lib/algorithms/sort/MergeSort.cpp"
#include "lib/algorithms/sort/QuickSort.cpp"
#include "lib/algorithms/sort/SelectionSort.cpp"

// Greedy libs Algorithm

// Searching libs Algorithm

// Graph libs Data Structure

// Tree libs Data Structure

using namespace std;

int main() {
    int **graph = new int*[4];
    graph[0] = new int[4] {0, 10, 15, 20};
    graph[1] = new int[4] {10, 0, 35, 25};
    graph[2] = new int[4] {15, 35, 0, 30};
    graph[3] = new int[4] {20, 25, 30, 0};
    cout << TravellingSalesman<int>::getMinCost(graph, 4) << endl;
    return 0;
}