//
//  mergesort.c
//  Algorithm_2022
//
//  Created by 정도현 on 2022/04/09.
//

#include <stdio.h>
#include <stdlib.h>

// merge (for mergesort)
void merge(int head, int mid, int tail, int* arr) {
    int sub1Head = head;    // left sub array head
    int sub1tail = mid;     // left sub array tail
    int sub2Head = mid + 1; // right sub array head
    int sub2tail = tail;    // right sub array tail
    int tempIndex = head;   // temp array index
    int* tempArr = (int*)malloc(sizeof(int)*(sub2tail+1));  // make temp index (store sorted Array)
    
    while ((sub1Head <= sub1tail) && (sub2Head <= sub2tail)){
        // The smaller of the two subarrays is stored in tempArr (If duplicate, left array first)
        if(arr[sub1Head] <= arr[sub2Head]){
            tempArr[tempIndex] = arr[sub1Head];
            sub1Head++;
        } else {
            tempArr[tempIndex] = arr[sub2Head];
            sub2Head++;
        }
        tempIndex++;
    }
    
    // remain right sub array
    if (sub1Head > sub1tail){
        // copy to tempArr
        while(sub2Head <= sub2tail){
            tempArr[tempIndex] = arr[sub2Head];
            tempIndex++;
            sub2Head++;
        }
    }
    // remain left sub array
    if(sub2Head > sub2tail){
        // compy to tempArr
        while(sub1Head <= sub1tail){
            tempArr[tempIndex] = arr[sub1Head];
            tempIndex++;
            sub1Head++;
        }
    }
    // copy to arr from tempArr
    for(int x = head; x <= tail; x++){
        arr[x] = tempArr[x];
    }
}

// mergesort
void MergeSort(int frontIndex, int rearIndex, int* arr){
    if(frontIndex < rearIndex){    // case : array size > 1
        int mid = (frontIndex+rearIndex)/2;
        MergeSort(frontIndex, mid, arr); // subarray m ~ mid (left sub array)
        MergeSort(mid+1, rearIndex, arr); // subarray mid+1 ~ n (right sub array)
        merge(frontIndex, mid, rearIndex, arr);  // merge
    }
}
