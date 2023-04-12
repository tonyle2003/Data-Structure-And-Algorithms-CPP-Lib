#include <type_traits>

using namespace std;

template<typename T, typename U>
class InsertionSort {

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
void InsertionSort<T, U>::sort(T* array, U size) {
    U i, j, key;
    for (i = 1; i < size; i++) {
        key = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}