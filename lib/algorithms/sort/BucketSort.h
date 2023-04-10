#include <type_traits>
#include <vector>

using namespace std;

template<typename T, typename U>
class BucketSort {

    static_assert(
        !is_same<T, bool>::value &&
        is_integral<U>::value &&
        !is_same<U, bool>::value &&
        !is_same<U, char>::value,
        "Error data type."
    );

    public:
        static void sort(T*, U);
};

template<typename T, typename U>
void BucketSort<T, U>::sort(T* array, U size) {
    T minValue = array[0];
    T maxValue = array[0];
    U k = 0;
    for (U i = size - 1; i >= 1; i--) {
        if (array[i] > maxValue) {
            maxValue = array[i];
        }
        if (array[i] < minValue) {
            minValue = array[i];
        }
    }
    vector<T> bucket[maxValue - minValue + 1];
    for (U i = 0; i < size; i++) {
        bucket[array[i] - minValue].push_back(array[i]);
    }
    for (vector<T> element : bucket) {
        if (element.size() > 0) {
            for (T data : element) {
                array[k] = data;
                k++;
            }
        }
    }
}