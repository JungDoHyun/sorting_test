//
//  radixsort.c
//  Algorithm_2022
//
//  Created by 정도현 on 2022/04/10.
//

#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

// queue initialize
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
    Node *newItem = (Node *)malloc(sizeof(Node));     // create node
    newItem -> val = num;
    newItem -> next = NULL;
    if(EmptyCheck(q)){
        q->front = q->rear = newItem;   // front = rear = newItem
    } else {
        q->rear->next = newItem;
    }
    q->rear = newItem;
    q->itemCount++;
}

// Dequeue
int Dequeue(dynamicQueue *q){
    int result = 0;
    Node *extract;
    // if empty Queue
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

// LSD (Least-Significant-Digit)
void RadixSort(int n, int* arr){
    dynamicQueue bucket[10]; // 0~9
    for(int i = 0; i<10; i++){
        // init queue
        InitializeQ(&bucket[i]);
    }
    
    // get max value from arr
    int maxValue = 0;
    for(int i = 0; i < n; i++){
        if(maxValue < arr[i])
            maxValue = arr[i];
    }
    
    int maxValueDigit = 1;
    
    // get max number of digits
    while(maxValue >= 10){
        maxValueDigit *= 10;
        maxValue /= 10;
    }
    
    // sorting and copy
    for(int i = 1; i<=maxValueDigit; i*=10){
        int arrIndex = 0;
        for (int j = 0; j<n; j++) {
            int queueIndex;
            // If the digit you are looking for is 0
            if(arr[j] < i){
                queueIndex = 0;
            }
            else {
                queueIndex = (arr[j] / i) % 10;
            }
            // insert into the appropriate queue for the number
            Enqueue(&bucket[queueIndex], arr[j]);
        }
        // copy to arr
        for(int k = 0; k<10; k++){
            while(!EmptyCheck(&bucket[k])){
                arr[arrIndex] = Dequeue(&bucket[k]);
                arrIndex++;
            }
        }
    }
}
