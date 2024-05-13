#include <stdio.h>
// Structure to represent a job
struct Job
{
    int jobNumber;
    int profit;
    int deadline;
};

// Function to perform job sequencing with deadlines
void jobSequencing(struct Job jobs[], int n)
{
    // Sort jobs based on profit in non-increasing order (using Bubble Sort)
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (jobs[j].profit < jobs[j + 1].profit)
            {
                // Swap jobs[j] and jobs[j+1]
                struct Job temp = jobs[j];
                jobs[j] = jobs[j + 1];
                jobs[j + 1] = temp;
            }
        }
    }
    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
    {
        if (jobs[i].deadline > maxDeadline)
        {
            maxDeadline = jobs[i].deadline;
        }
    }
    // Initialize an array to track job allocation
    int jobAlloc[maxDeadline];
    for (int i = 0; i < maxDeadline; i++)
    {
        jobAlloc[i] = -1; // -1 indicates slot is empty
    }
    int totalProfit = 0;
    // Perform job sequencing
    for (int i = 0; i < n; i++)
    {
        for (int j = jobs[i].deadline - 1; j >= 0; j--)
        {
            if (jobAlloc[j] == -1)
            {
                jobAlloc[j] = jobs[i].jobNumber;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }
    // Display the job sequence and total profit
    printf("Job Sequence: ");
    for (int i = 0; i < maxDeadline; i++)
    {
        if (jobAlloc[i] != -1)
        {
            printf("Job%d ", jobAlloc[i]);
        }
    }
    printf("\nTotal Profit: %d\n", totalProfit);
}

int main()
{
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);
    struct Job jobs[n];
    // Input job details from the user
    for (int i = 0; i < n; i++)
    {
        printf("Enter profit for job[%d]: ", i + 1);
        scanf("%d", &jobs[i].profit);
        printf("Enter deadline for job[%d]: ", i + 1);
        scanf("%d", &jobs[i].deadline);
        jobs[i].jobNumber = i + 1;
    }
    // Call the job sequencing function
    jobSequencing(jobs, n);
    return 0;
}