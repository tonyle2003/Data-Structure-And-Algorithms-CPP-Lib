#include <type_traits>

using namespace std;

template<typename T, typename U>
class HeapSort {

    static_assert(
        !is_same<T, bool>::value
        && is_integral<U>::value
        && !is_same<U, bool>::value
        && !is_same<U, char>::value,
        "Error data type."
    );

    private:
        static void heapify(T*, U, U);
    public:
        static void sort(T*, U);
};

template<typename T, typename U>
void HeapSort<T, U>::sort(T* array, U size) {
    for (U i = size - 1; i >= 0; i--) {
        heapify(array, size, i);
    }
    for (U j = size - 1; j >= 0; j--) {
        T temp = array[0];
        array[0] = array[j];
        array[j] = temp;
        heapify(array, j, 0);
    }
}

template<typename T, typename U>
void HeapSort<T, U>::heapify(T* array, U size, U index) {
    U largest = index;
    U left = index + 1;
    U right = index + 2;
    if (left < size && array[left] > array[largest]) {
        largest = left;
    }
    if (right < size && array[right] > array[largest]) {
        largest = right;
    }
    if (largest != index) {
        T temp = array[index];
        array[index] = array[largest];
        array[largest] = temp;
        heapify(array, size, largest);
    }
}