#include <type_traits>

using namespace std;

template<typename T, typename U>
class QuickSort {

    static_assert(
        !is_same<T, bool>::value
        && is_integral<U>::value
        && !is_same<U, bool>::value
        && !is_same<U, char>::value,
        "Error data type."
    );

    private:
        static U partition(T*, U, U);

    public:
        static void sort(T*, U, U);
};

template<typename T, typename U>
U QuickSort<T, U>::partition(T* array, U left, U right) {
    T pivot = array[right];
    U i = left;
    for (U j = left; j < right; j++) {
        if (array[j] <= pivot) {
            T temp = array[j];
            array[j] = array[i];
            array[i] = temp;
            i++;
        }
    }
    T temp = array[i];
    array[i] = array[right];
    array[right] = temp;
    return i;
}

template<typename T, typename U>
void QuickSort<T, U>::sort(T* array, U low, U high) {
    if (low < high) {
        U p = partition(array, low, high);
        sort(array, 0, p - 1);
        sort(array, p + 1, high);
    }
}