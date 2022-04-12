//
//  queue.h
//  Algorithm_2022
//
//  Created by 정도현 on 2022/04/11.
//

#ifndef queue_h
#define queue_h

typedef struct Node{
    struct Node *next;
    int val;
} Node;

typedef struct {
    int itemCount;  // queue size
    Node *front;    // front
    Node *rear;     // rear
} dynamicQueue;

void InitializeQ(dynamicQueue *q);
int EmptyCheck(dynamicQueue *q);
void Enqueue(dynamicQueue *q, int num);
int Dequeue(dynamicQueue *q);

#endif /* queue_h */
