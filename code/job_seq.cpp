#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char id;
    int deadline;
    int profit;
} Job;

int compareJobs(const void* a, const void* b) {
    return ((Job*)b)->profit - ((Job*)a)->profit;
}

typedef struct {
    char* jobSequence;
    int totalProfit;
} Result;

Result jobSequencing(Job jobs[], int n, int maxDeadline) {
    qsort(jobs, n, sizeof(Job), compareJobs);

    char* result = (char*)malloc(maxDeadline * sizeof(char));
    int* slot = (int*)malloc(maxDeadline * sizeof(int));

    for (int i = 0; i < maxDeadline; ++i) {
        result[i] = '\0';
        slot[i] = 0;
    }

    int totalProfit = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = (jobs[i].deadline < maxDeadline ? jobs[i].deadline : maxDeadline) - 1; j >= 0; --j) {
            if (slot[j] == 0) {
                result[j] = jobs[i].id;
                slot[j] = 1;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    Result jobResult;
    jobResult.jobSequence = result;
    jobResult.totalProfit = totalProfit;

    free(slot);
    return jobResult;
}

int main() {
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    Job* jobs = (Job*)malloc(n * sizeof(Job));

    for (int i = 0; i < n; ++i) {
        printf("Enter job ID, deadline, and profit for job %d: ", i + 1);
        scanf(" %c %d %d", &jobs[i].id, &jobs[i].deadline, &jobs[i].profit);
    }

    int maxDeadline = 0;
    for (int i = 0; i < n; ++i) {
        maxDeadline = (maxDeadline > jobs[i].deadline) ? maxDeadline : jobs[i].deadline;
    }

    Result result = jobSequencing(jobs, n, maxDeadline);

    printf("Job Sequence: ");
    for (int i = 0; i < maxDeadline; ++i) {
        if (result.jobSequence[i] != '\0') {
            printf("%c ", result.jobSequence[i]);
        }
    }
    printf("\nTotal Profit: %d\n", result.totalProfit);

    free(jobs);
    free(result.jobSequence);

    return 0;
}