/*

Fibonacci Number

Printing the nth Fibonacci number using Dynamic Programming.

*/
#include <type_traits>
#include <string>

using namespace std;

template<typename T>
class FibonacciNumber {

    static_assert(
        !is_same<T, bool>::value
        && !is_same<T, char>::value
        && !is_same<T, string>::value,
        "Error data type."
    );

    public:
        static T getFibonacciNumber(T);
};

template<typename T>
T FibonacciNumber<T>::getFibonacciNumber(T position) {
    T list[position + 1];
    list[0] = 0;
    list[1] = 1;
    for (T i = 2; i <= position; i++) {
        list[i] = list[i - 1] + list[i - 2];
    }
    return list[position];
}