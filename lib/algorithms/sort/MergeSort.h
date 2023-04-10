#include <type_traits>

using namespace std;

template<typename T, typename U>
class MergeSort {

    static_assert(!is_same<T, bool>::value
               && is_integral<U>::value
               && !is_same<U, bool>::value
               && !is_same<U, char>::value,
               "Error data type.");

    private:
        static void merge(T*, U, U, U);

    public:
        static void sort(T*, U, U);
};

template<typename T, typename U>
void MergeSort<T, U>::merge(T* array, U left, U mid, U right) {
    U sizeLeft = mid - left + 1;
    U sizeRight = right - mid;
    T* leftArray = new T[sizeLeft];
    T* rightArray = new T[sizeRight];

    for (U i = 0; i < sizeLeft; i++) {
        leftArray[i] = array[left + i];
    }
    for (U i = 0; i < sizeRight; i++) {
        rightArray[i] = array[mid + 1 + i];
    }

    U indexLeft = 0, indexRight = 0;
    U indexMerge = left;
    while (indexLeft < sizeLeft && indexRight < sizeRight) {
        if (leftArray[indexLeft] <= rightArray[indexRight]) {
            array[indexMerge] = leftArray[indexLeft];
            indexLeft++;
        } else {
            array[indexMerge] = rightArray[indexRight];
            indexRight++;
        }
        indexMerge++;
    }

    while (indexLeft < sizeLeft) {
        array[indexMerge] = leftArray[indexLeft];
        indexLeft++;
        indexMerge++;
    }
    while (indexRight < sizeRight) {
        array[indexMerge] = rightArray[indexRight];
        indexRight++;
        indexMerge++;
    }

    delete[] leftArray;
    delete[] rightArray;
}

template<typename T, typename U>
void MergeSort<T, U>::sort(T* array, U begin, U end) {
    if (begin >= end) {
        return;
    }
    U mid = begin + (end - begin) / 2;
    sort(array, begin, mid);
    sort(array, mid + 1, end);
    merge(array, begin, mid, end);
}