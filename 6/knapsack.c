#include <stdio.h>

typedef struct {
    int item_id;
    float item_profit;
    float item_weight;
    float profit_weight_ratio;
} ITEM;
void heapify(ITEM arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].profit_weight_ratio > arr[largest].profit_weight_ratio)
        largest = left;

    if (right < n && arr[right].profit_weight_ratio > arr[largest].profit_weight_ratio)
        largest = right;

    if (largest != i) {
        ITEM temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heap_sort(ITEM arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        ITEM temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

float fractional_knapsack(ITEM items[], int n, float capacity) {
    heap_sort(items, n);

    float total_profit = 0.0;

    printf("\nItem No\t\tProfit\t\tWeight\t\tAmount to be taken\n");
    for (int i = 0; i < n; i++) {
        if (capacity == 0)
            break;

        if (items[i].item_weight <= capacity) {
            capacity -= items[i].item_weight;
            total_profit += items[i].item_profit;
            printf("%d\t\t%.6f\t%.6f\t1.000000\n", items[i].item_id, items[i].item_profit, items[i].item_weight);
        } else {
            float fraction = capacity / items[i].item_weight;
            total_profit += items[i].item_profit * fraction;
            printf("%d\t\t%.6f\t%.6f\t%.6f\n", items[i].item_id, items[i].item_profit, items[i].item_weight, fraction);
            capacity = 0;
        }
    }

    return total_profit;
}

int main() {
    int num_items;
    printf("Enter the number of items: ");
    scanf("%d", &num_items);

    ITEM items[num_items];

    for (int i = 0; i < num_items; i++) {
        printf("Enter the profit and weight of item no %d: ", i + 1);
        scanf("%f %f", &items[i].item_profit, &items[i].item_weight);
        items[i].item_id = i + 1;
        items[i].profit_weight_ratio = items[i].item_profit / items[i].item_weight;
    }

    float knapsack_capacity;
    printf("Enter the capacity of knapsack: ");
    scanf("%f", &knapsack_capacity);

    float max_profit = fractional_knapsack(items, num_items, knapsack_capacity);

    printf("Maximum profit: %.6f\n", max_profit);

    return 0;
}
