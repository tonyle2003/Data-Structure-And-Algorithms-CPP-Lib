#include <type_traits>

using namespace std;

template <typename T, typename U>
class Permutation {

    static_assert(!is_same<T, bool>::value
               && is_integral<U>::value
               && !is_same<U, bool>::value
               && !is_same<U, char>::value,
               "Error data type.");

    public:
        static bool next(T*, U);
};


template <typename T, typename U>
bool Permutation<T, U>::next(T* array, U size) {
    U index = size - 2;
    while (index >= 0 && array[index] > array[index + 1]) {
        index--;
    }
    if (index == -1) {
        return true;
    } else {
        U selector = size - 1;
        while (array[index] > array[selector]) {
            selector--;
        }
        swap(array[index], array[selector]);
        reverse(array + index + 1, array + size);
        return false;
    }
}