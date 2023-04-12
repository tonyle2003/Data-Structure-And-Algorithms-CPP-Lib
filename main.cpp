// Standard libs
#include <iostream>

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
    Activity<int> activities[6];
    activities[0] = Activity<int>(0, 1, 2);
    activities[1] = Activity<int>(1, 3, 4);
    activities[2] = Activity<int>(2, 0, 6);
    activities[3] = Activity<int>(3, 5, 7);
    activities[4] = Activity<int>(4, 8, 9);
    activities[5] = Activity<int>(5, 5, 9);
    ActivitySelection<int>::selectedActivities(activities, 6);
    cout << ActivitySelection<int>::getMaxActivities(activities, 6) << endl;
    return 0;
}