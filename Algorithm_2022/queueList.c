//
//  queueList.c
//  Algorithm_2022
//
//  Created by 정도현 on 2022/04/11.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    struct Node *next;
    int val;
} Node;

typedef struct {
    int itemCount;  // queue size
    Node *front;    // front
    Node *rear;     // rear
} dynamicQueue;

void InitializeQ(dynamicQueue *q){
    q->front = q->rear = NULL;
    q->itemCount = 0;
}

// check queue empty
int EmptyCheck(dynamicQueue *q) {
    return q->itemCount == 0;
}

// Insert Queue
void Enqueue(dynamicQueue *q, int num){
    Node *enter = (Node *)malloc(sizeof(Node));     // create node
    enter -> val = num;
    enter -> next = NULL;
    if(EmptyCheck(q)){
        q->front = q->rear = enter;
    } else {
        q->rear->next = enter;
    }
    q->rear = enter;
    q->itemCount++;
}

// Dequeue
int Dequeue(dynamicQueue *q){
    int result = 0;
    Node *extract;
    if(EmptyCheck(q)){
        printf("Queue is EMPTY!\n");
        return result;
    }
    else {
        extract = q -> front;
        result = extract -> val;
        q->front = q->front->next;
        q->itemCount--;
        free(extract);
        return result;
    }
}
