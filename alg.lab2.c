#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Функция для создания динамического массива с заполнением случайными числами в заданном диапазоне
int *createRandomArray(int size, int min, int max) {
    int *arr = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (max - min + 1) + min;
    }
    return arr;
}

// Функция для проверки массива на упорядоченность
int isOrdered(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return 0; // Не упорядочен
        }
    }
    return 1; // Упорядочен
}

// Функция для сортировки Шелла
void shellSort(int *arr, int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main() {
    int n;
    printf("Input count of elements: ");
    scanf("%d", &n);

    // Создаем динамический массив с случайными числами от 1 до 100
    int *arr = createRandomArray(n, 1, 100);

    // Замеряем время выполнения сортировки Шелла
    clock_t start_time = clock();
    shellSort(arr, n);
    clock_t end_time = clock();

    // Выводим результаты
    printf("Shell sort: %.3f s\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);

    // Проверяем упорядоченность массива
    if (isOrdered(arr, n)) {
        printf("Array is ordered\n");
    } else {
        printf("Array is not ordered\n");
    }

    // Освобождаем выделенную память
    free(arr);

    return 0;
}
