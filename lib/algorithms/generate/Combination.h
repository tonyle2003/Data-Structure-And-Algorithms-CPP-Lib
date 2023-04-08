using namespace std;

class Combination {
    public:
        static bool next(int*, int, int);
};

bool Combination::next(int* array, int n, int k) {
    int index = k - 1;
    while (index >= 0 && array[index] == n - k + index + 1) {
        index--;
    }
    if (index == -1) {
        return true;
    } else {
        array[index]++;
        for (int i = index + 1; i < k; i++) {
            array[i] = array[i - 1] + 1;
        }
        return false;
    }
}