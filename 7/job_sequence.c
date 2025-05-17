#include <stdio.h>

struct jobs {
    int jobno;
    float profit;
    int deadline;
};

int find_max(int n, struct jobs job[]) {
    int max_deadline = -1;
    
    for (int i = 0; i < n; i++) {
        if (job[i].deadline > max_deadline) {
            max_deadline = job[i].deadline;
        }
    }
    return max_deadline;
}

int partition(struct jobs job[], int low, int high) {
    float pivot = job[high].profit;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (job[j].profit > pivot) {
            i++;
            swap(&job[i], &job[j]);
        }
    }
    swap(&job[i + 1], &job[high]);
    return (i + 1);
}

void quicksort(struct jobs job[], int low, int high) {
    if (low < high) {
        int pi = partition(job, low, high);
        quicksort(job, low, pi - 1);
        quicksort(job, pi + 1, high);
    }
}

void swap(struct jobs *job1, struct jobs *job2) {
    struct jobs temp = *job1;
    *job1 = *job2;
    *job2 = temp;
}

void findseq(int n, struct jobs job[], int deadmax, struct jobs sequence[]) {
    for (int i = 0; i < n; i++) {
        int count = job[i].deadline;
    
        while (count > 0 && sequence[count - 1].jobno != -1) {
            count--;
        }
    
        if (count > 0) {
            sequence[count - 1] = job[i];
        }
    }
}

void main() {
    printf("Enter number of jobs: ");
    int n;
    scanf("%d", &n);

    struct jobs job[n];

    for (int i = 0; i < n; i++) {
        printf("Enter profit and deadline for job %d: ", i + 1);
        job[i].jobno = i + 1;
        scanf("%f %d", &job[i].profit, &job[i].deadline);
    }

    int deadmax = find_max(n, job);
    
    quicksort(job, 0, n - 1); 
    struct jobs sequence[deadmax];

    for (int i = 0; i < deadmax; i++) {
        sequence[i].jobno = -1;
    }

    findseq(n, job, deadmax, sequence);

    printf("Job sequence:\n");
    for (int i = 0; i < deadmax; i++) {
        if (sequence[i].jobno != -1) {
            printf("Slot %d: Job %d (Profit: %.2f, Deadline: %d)\n", i + 1, sequence[i].jobno, sequence[i].profit, sequence[i].deadline);
        }
    }
    int maxprofit=0;


    for(int i = 0; i < deadmax; i++) {
        maxprofit+=sequence[i].profit;
    }
    printf("Max profit: %d",maxprofit);
}
