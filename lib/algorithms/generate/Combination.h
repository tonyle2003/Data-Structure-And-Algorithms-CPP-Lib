#include <type_traits>

using namespace std;

template <typename T, typename U>
class Combination {

    static_assert(std::is_integral<U>::value
               && !std::is_same<U, bool>::value
               && !std::is_same<U, char>:: value,
               "Error type.");

    public:
        static bool next(T*, U, U);
};

template <typename T, typename U>
bool Combination<T, U>::next(T* array, U n, U k) {
    U index = k - 1;
    while (index >= 0 && array[index] == n - k + index + 1) {
        index--;
    }
    if (index == -1) {
        return true;
    } else {
        array[index]++;
        for (U i = index + 1; i < k; i++) {
            array[i] = array[i - 1] + 1;
        }
        return false;
    }
}