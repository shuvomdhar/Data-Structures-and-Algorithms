#include <stdio.h>
#include <stdlib.h>
struct Queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct Queue * q)
{
    if(q->r == q->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct Queue * q)
{
    if(q->r == q->f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Enqueue(struct Queue * q, int val)
{
    if(isFull(q))
    {
        printf("This queue is full\n");
    }
    else
    {
        q->r = q->r + 1;
        q->arr[q->r] = val;
    }
}

int Dequeue(struct Queue * q)
{
    if (isEmpty(q))
    {
        printf("The queue is empty\n");
    }
    else
    {
        q->f = q->f + 1;
        int val = q->arr[q->f];
        return val;
    }
}

int main() 
{
    struct Queue q;
    q.size = 100;
    q.f = q.r = -1;
    q.arr = (int *) malloc(q.size * sizeof(int));
    if(isEmpty(&q))
    {
        printf("The queue is empty\n");
    }
    else
    {
        printf("The queue is not empty\n");
    }

    if(isFull(&q))
    {
        printf("The queue is full\n");
    }
    else
    {
        printf("The queue is not full\n");
    }
    Enqueue(&q, 12);
    Enqueue(&q, 15);
    Enqueue(&q, 20);
    if(isEmpty(&q))
    {
        printf("The queue is empty\n");
    }
    else
    {
        printf("The queue is not empty\n");
    }

    if(isFull(&q))
    {
        printf("The queue is full\n");
    }
    else
    {
        printf("The queue is not full\n");
    }
    printf("The dequeued value is %d\n",Dequeue(&q));
    printf("The dequeued value is %d\n",Dequeue(&q));
    if(isEmpty(&q))
    {
        printf("The queue is empty\n");
    }
    else
    {
        printf("The queue is not empty\n");
    }
    
    if(isFull(&q))
    {
        printf("The queue is full\n");
    }
    else
    {
        printf("The queue is not full\n");
    }
    return 0;
}