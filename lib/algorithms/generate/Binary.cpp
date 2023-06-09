#include <type_traits>

using namespace std;

template <typename T, typename U>
class Binary {

    static_assert(is_same<T, bool>::value
               && is_integral<U>:: value
               && !is_same<U, bool>::value
               && !is_same<U, char>::value,
               "Error data type.");

    public:
        static bool next(T*, U);
};

template <typename T, typename U>
bool Binary<T, U>::next(T* array, U size) {
    U index = size - 1;
    while (index >= 0 && array[index] == 1) {
        array[index] = 0;
        index--;
    }
    if (index == -1) {
        return true;
    } else {
        array[index] = 1;
        return false;
    }
}

