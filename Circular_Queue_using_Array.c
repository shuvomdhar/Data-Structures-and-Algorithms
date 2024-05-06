#include <stdio.h>
#include <stdlib.h>
struct Queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct Queue *q)
{
    if (((q->r + 1) % q->size) == q->f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct Queue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Enqueue(struct Queue *q, int val)
{
    if (isFull(q))
    {
        printf("This queue is overflow\n");
    }
    else
    {
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = val;
    }
}

int Dequeue(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("The queue is underflow\n");
    }
    else
    {
        q->f = (q->f + 1) % q->size;
        int val = q->arr[q->f];
        return val;
    }
}

int main()
{
    struct Queue q;
    int s;
    printf("Enter the size of the queue: ");
    scanf("%d", &s);
    q.size = s;
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));
    
    if (isEmpty(&q))
    {
        printf("The queue is empty\n");
    }
    else
    {
        printf("The queue is not empty\n");
    }

    int val;
    for (int i = 0; i < q.size; i++)
    {
        printf("Enter %d value: ", i + 1);
        scanf("%d", &val);
        Enqueue(&q, val);
    }

    if (isFull(&q))
    {
        printf("The queue is full\n");
    }
    else
    {
        printf("The queue is not full\n");
    }

    printf("If you want to dequeue elements from the queue the press '1' otherwise press '0'\n");
    int ch;
    int num;
    printf("Enter your choice: ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        printf("Enter how many elements do you want to dequeue: ");
        scanf("%d", &num);
        for (int i = 0; i < num; i++)
        {
            printf("The dequeued value is %d\n", Dequeue(&q));
        }
        break;
    default:
        break;
    }

    if (isFull(&q))
    {
        printf("The queue is full\n");
    }
    else
    {
        printf("The queue is not full\n");
    }

    printf("If you want to enqueue elements from the queue the press '1' otherwise press '0'\n");
    int c;
    int n, value;
    printf("Enter your choice: ");
    scanf("%d", &c);
    switch (c)
    {
    case 1:
        printf("Enter how many elements do you want to dequeue: ");
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            printf("Enter value: ");
            scanf("%d", &value);
            Enqueue(&q, value);
        }
        break;
    default:
        break;
    }

    if (isFull(&q))
    {
        printf("The queue is full\n");
    }
    else
    {
        printf("The queue is not full\n");
    }
    return 0;
}