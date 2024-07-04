#include <stdio.h>

float calculate_mean(int numbers[], int size, int *loop_count, int *addition_count) {
    int total_sum = 0;
    *loop_count = 0;
    *addition_count = 0;

    for (int i = 0; i < size; i++) {
        total_sum += numbers[i];
        (*loop_count)++;
        (*addition_count)++;
    }

    return (float) total_sum / size;
}

int main() {
    int numbers[] = {10, 20, 30, 40, 50, 60};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int loop_count = 0;
    int addition_count = 0;

    if (size != 6) {
        printf("The array must contain exactly six integers.\n");
        return 1;
    }

    float mean = calculate_mean(numbers, size, &loop_count, &addition_count);

    printf("Mean value: %.2f\n", mean);
    printf("Number of loop executions: %d\n", loop_count);
    printf("Number of addition operations: %d\n", addition_count);

    return 0;
}