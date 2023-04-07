/*

Fibonacci Number

Printing the nth Fibonacci number using Dynamic Programming.

*/

using namespace std;

class FibonacciNumber {
    public:
        static int getFibonacciNumber(int);
};

int FibonacciNumber::getFibonacciNumber(int position) {
    int list[position + 1];
    list[0] = 0;
    list[1] = 1;
    for (int i = 2; i <= position; i++) {
        list[i] = list[i - 1] + list[i - 2];
    }
    return list[position];
}