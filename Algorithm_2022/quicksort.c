//
//  quicksort.c
//  Algorithm_2022
//
//  Created by 정도현 on 2022/04/09.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// quickSort
void QuickSort(int frontIndex, int rearIndex, int* arr){
    if(frontIndex >= rearIndex) return;   // 내부 원소가 1개인 경우
    
    int pivot = frontIndex; // set pivot item
    int i = frontIndex + 1; // 설정된 피봇 다음 인뎃스부터 비교 시작
    int j = rearIndex;  // 맨 끝 인덱스 설정
    int temp;
    
    while(i<=j){
        // 피봇값보다 큰 값을 찾을 때 까지 i 증가
        while(arr[i] <= arr[pivot]) i++;
        // 피봇값보다 작은 값을 찾을 때 까지 j 감소 (단, j 는 frontIndex보다 커야 한다)
        while((j > frontIndex) && arr[j] >= arr[pivot]) j--;
        if(i <= j){  // cross state
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        } else {    // cross state
            temp = arr[j];
            arr[j] = arr[pivot];
            arr[pivot] = temp;
        }
    }
    // 재귀 호출
    QuickSort(frontIndex, j-1, arr);    // sort frontIndex ~ j-1 (피봇 기준 왼쪽 배열 정렬)
    QuickSort(j+1, rearIndex, arr);     // sort j+1 ~ tailindex (피봇 기준 오른쪽 정렬)
}

// random pivot quickSort (random pivot pick)
void randQuickSort(int frontIndex, int rearIndex, int* arr){
    if(frontIndex >= rearIndex) return;   // if arr size == 1
    
    int i = frontIndex + 1; // 설정된 피봇 다음 인뎃스부터 비교 시작
    int j = rearIndex;  // 맨 끝 인덱스 설정
    srand((unsigned int)time(NULL));
    int pivot = frontIndex + rand()%(rearIndex - frontIndex + 1); // set pivot item random
    int temp;
    
    while(i<=j){
        // 피봇값보다 큰 값을 찾을 때 까지 i 증가
        while(arr[i] <= arr[pivot]) i++;
        // 피봇값보다 작은 값을 찾을 때 까지 j 감소 (단, j 는 frontIndex보다 커야 한다)
        while((j > frontIndex) && arr[j] >= arr[pivot]) j--;
        if(i <= j){  // cross state
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        } else {    // cross state
            temp = arr[j];
            arr[j] = arr[pivot];
            arr[pivot] = temp;
        }
    }
    // 재귀 호출
    randQuickSort(frontIndex, j-1, arr);    // sort frontIndex ~ j-1 (피봇 기준 왼쪽 배열 정렬)
    randQuickSort(j+1, rearIndex, arr);     // sort j+1 ~ tailindex (피봇 기준 오른쪽 정렬)
}
