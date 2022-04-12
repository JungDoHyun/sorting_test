//
//  main.c
//  Algorithm_2022
//
//  Created by 정도현 on 2022/04/07.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <sys/time.h>
#include <unistd.h>

#include "sorting.h"
#include "queue.h"

int main(int argc, const char* argv[]) {
    int n;
    double timeStart, timeEnd; // for time measurement
    printf("===== 2022 DKU Algorithm. ===== \n");
    printf("Enter the size of Array : ");
    scanf("%d", &n);    // get array size input
    int* exchangeArr = makeRandomArr(n);    // for exchangesort Array
    int* mergeArr = (int*)malloc(sizeof(int)*n);    // for mergesort Array
    int* quickArr = (int*)malloc(sizeof(int)*n);    // for quicksort Array
    int* randQuickArr = (int*)malloc(sizeof(int)*n);    // for random quicksort Array
    int* heapArr = (int*)malloc(sizeof(int)*n);    // for quicksort Array
    int* radixArr = (int*)malloc(sizeof(int)*n);    // for radixsort Array
    memmove(mergeArr, exchangeArr, sizeof(int)*n);
    memmove(quickArr, exchangeArr, sizeof(int)*n);
    memmove(randQuickArr, exchangeArr, sizeof(int)*n);
    memmove(heapArr, exchangeArr, sizeof(int)*n);
    memmove(radixArr, exchangeArr, sizeof(int)*n);
    
    // exchangesort
    timeStart = (double)clock() / CLOCKS_PER_SEC;
    ExchangeSort(n, exchangeArr);
    timeEnd = ((double)clock()) / CLOCKS_PER_SEC;
    printf("\nExchangeSort time : %lf sec", (timeEnd - timeStart));
    
    // mergesort
    timeStart = (double)clock() / CLOCKS_PER_SEC;
    MergeSort(0, n-1, mergeArr);
    timeEnd = ((double)clock()) / CLOCKS_PER_SEC;
    printf("\nMergeSort time : %lf sec", (timeEnd - timeStart));
    
    // quicksort (pivot = 1st item)
    timeStart = (double)clock() / CLOCKS_PER_SEC;
    QuickSort(0, n-1, quickArr);
    timeEnd = (double)clock() / CLOCKS_PER_SEC;
    printf("\nQuickSort time : %lf sec", (timeEnd - timeStart));
    
    // random pivot Quicksort (pivot = random pick)
    timeStart = (double)clock() / CLOCKS_PER_SEC;
    QuickSort(0, n-1, randQuickArr);
    timeEnd = (double)clock() / CLOCKS_PER_SEC;
    printf("\nRandom Pivot QuickSort time : %lf sec", (timeEnd - timeStart));
        
    // heapsort
    timeStart = (double)clock() / CLOCKS_PER_SEC;
    HeapSort(n, heapArr);
    timeEnd = (double)clock() / CLOCKS_PER_SEC;
    printf("\nHeap sort time : %lf sec", (timeEnd - timeStart));
    
    // radixsort
    timeStart = (double)clock() / CLOCKS_PER_SEC;
    RadixSort(n, radixArr);
    timeEnd = (double)clock() / CLOCKS_PER_SEC;
    printf("\nRadix sort time : %lf sec \n", (timeEnd - timeStart));
    return 0;
}
