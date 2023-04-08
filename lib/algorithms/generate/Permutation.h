using namespace std;

class Permutation {
    public:
        static bool next(int*, int); 
};

bool Permutation::next(int* array, int size) {
    int index = size - 2;
    while (index >= 0 && array[index] > array[index + 1]) {
        index--;
    }
    if (index == -1) {
        return true;
    } else {
        int selector = size - 1;
        while (array[index] > array[selector]) {
            selector--;
        }
        swap(array[index], array[selector]);
        reverse(array + index + 1, array + size);
        return false;
    }
}