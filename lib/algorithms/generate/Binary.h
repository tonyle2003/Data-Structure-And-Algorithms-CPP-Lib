using namespace std;

class Binary {
    public:
        static bool next(int*, int);
};

bool Binary::next(int* array, int size) {
    int index = size - 1;
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