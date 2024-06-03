#include <iostream>

void sort(int array[], int size) {
    int tmp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
}

int main() {
    int array[] = {1, 3, 4, 7, 9, 10, 2, 5, 6, 8};
    int size = sizeof(array) / sizeof(array[0]);

    sort(array, size);

    for (int element : array) {
        std::cout << element << std::endl;
    }

    return 0;
}
