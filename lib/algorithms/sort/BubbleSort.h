#include <type_traits>

using namespace std;

template <typename T, typename U>
class BubbleSort {

    static_assert(!std::is_same<T, bool>::value 
                && std::is_integral<U>::value
                && !std::is_same<U, bool>::value
                && !std::is_same<U, char>::value,
                "Error type.");

    public:
        static void sort(T*, U);
};

template <typename T, typename U>
void BubbleSort<T, U>::sort(T* array, U size) {
    for (U i = size - 1; i >= 0; i--) {
        for (U j = 1; j <= i; j++) {
            if (array[j - 1] > array[j]) {
                T temp = array[j - 1];
                array[j - 1] = array[j];
                array[j] = temp;
            }
        }
    }
}