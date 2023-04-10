#include <type_traits>

using namespace std;

template<typename T, typename U>
class SelectionSort {

    static_assert(
        !is_same<T, bool>::value
        && is_integral<U>::value
        && !is_same<U, bool>::value
        && !is_same<U, char>::value,
        "Error data type."
    );

    public:
        static void sort(T*, U);
};

template<typename T, typename U>
void SelectionSort<T, U>::sort(T* array, U size) {
    for (U i = 0; i < size - 1; i++) {
        U minId = i;
        U j;
        for (j = i + 1; j < size; j++) {
            if (array[j] < array[minId]) {
                minId = j;
            }
        }
        T temp = array[minId];
        array[minId] = array[i];
        array[i] = temp;
    }
}