#include <type_traits>
#include <algorithm>
#include <limits>

using namespace std;

template <typename T>
class TravellingSalesman {
    static_assert(
        is_integral<T>::value
        && !is_same<T, bool>::value
        && !is_same<T, char>::value,
        "Error data type."
    );
    public:
        static T getMinCost(T** cost, T size);
};

template <typename T>
T TravellingSalesman<T>::getMinCost(T** cost, T size) {
    T minimum = numeric_limits<T>::max();
    T* P =  new T[size];
    for (T i = 0; i < size; i++) {
        P[i] = i;
    }
    do {
        T current = 0;
        for (T i = 0; i < size - 1; i++) {
            current += cost[P[i]][P[i + 1]];
        }
        current += cost[P[size - 1]][P[0]];
        minimum = min(minimum, current);
    } while (next_permutation(P, P + size));
    delete[] P;
    return minimum;
}