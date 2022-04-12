//
//  heapsort.c
//  Algorithm_2022
//
//  Created by 정도현 on 2022/04/09.
//

#include <stdio.h>

// create max heap
void makeMaxHeap(int n, int* arr){
    for (int i = 1; i<n; i++){
        int indexCount = i;
        while (indexCount > 0){
            int parentNode = (indexCount - 1) / 2;    // idexCount에 대한 부모 노드
            int temp;
            if(arr[parentNode] < arr[indexCount]) {     // 부모노드가 자식 노드보다 작다면 자식, 부모 swap
                temp = arr[parentNode];
                arr[parentNode] = arr[indexCount];
                arr[indexCount] = temp;
            }
            indexCount = parentNode;    // 상위 노드로 올라가며 전체 체크
        }
    }
}

// 루트 노드로 올라온 수를 다시 최대 히프로 만들어 주는 과정
void downHeap(int start, int endNode, int* arr){
    int root = start;
    int compareChild;
    
    while(root * 2 + 1 <= endNode){
        int leftChild = root * 2 + 1;   // leftchild
        int rightChild = root * 2 + 2;  // rightchild
        if((leftChild < endNode) && (arr[leftChild] < arr[rightChild])){
            compareChild = rightChild;
        } else {
            compareChild = leftChild;
        }
        if(arr[compareChild] > arr[root]) { // 상위 노드 값이 비교하는 자식값보다 작으면 swap
            int temp = arr[compareChild];
            arr[compareChild] = arr[root];
            arr[root] = temp;
        } else {    // 상위 노드 값이 비교 자식 값보다 크다면 자기 자리를 찾은 것
            break;
        }
        root = compareChild;    // swap자리부터 자기 자리를 찾을 때 까지 down sift
    }
}

// heap sort
void HeapSort(int n, int* arr){
    makeMaxHeap(n, arr);    // make max heap
    int rootNode = 0;   //
    int lastNode = n - 1;   // last arr item
    while(lastNode > 0){
        // root값을 맨 뒤 값과 swap
        int temp = arr[rootNode];
        arr[rootNode] = arr[lastNode];
        arr[lastNode] = temp;
        // 맨 뒤로 보낸 값을 제외하고 maxHeap구성
        lastNode--; //
        downHeap(0, lastNode, arr);
    }
}
