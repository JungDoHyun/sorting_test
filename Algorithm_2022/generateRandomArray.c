//
//  generateRandomArray.c
//  Algorithm_2022
//
//  Created by 정도현 on 2022/04/10.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// make random array
int* makeRandomArr(int n){
    int i;
    int* arr = (int*)malloc(sizeof(int)*n);
    srand((unsigned int)time(NULL));
    for(i=0; i<n; i++){
        arr[i] = rand()%10000;  // generate Random Number 0 ~ 9999
    }
    return arr;
}
