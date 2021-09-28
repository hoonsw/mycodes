#ifndef __C_QUEUE_H__
#define __C_QUEUe_H__

#define TRUE 1
#define FALSE 0

#define Q_LEN 100
typedef int Data;

typedef struct
{
    int front;
    int rear;
    Data queArr[Q_LEN];
} Queue;

void QueueInit(Queue* pq);
int QIsEmpty(Queue* pq);

void Enqueue(Queue* pq, Data data);
Data Dequeue(Queue* pq);
Data PeekQueue(Queue* pq);

#endif