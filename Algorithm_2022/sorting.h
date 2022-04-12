//
//  sorting.h
//  Algorithm_2022
//
//  Created by 정도현 on 2022/04/09.
//

#ifndef sorting_h
#define sorting_h

int* makeRandomArr(int n);
void ExchangeSort(int n, int* arr);
void merge(int head, int mid, int tail, int* arr);
void MergeSort(int frontIndex, int rearIndex, int* arr);
void QuickSort(int frontIndex, int rearIndex, int* arr);
void randQuickSort(int frontIndex, int rearIndex, int* arr);
void downHeap(int start, int n, int* arr);
void makeMaxHeap(int n, int* arr);
void HeapSort(int n, int* arr);
void RadixSort(int n, int* arr);


#endif /* sorting_h */
