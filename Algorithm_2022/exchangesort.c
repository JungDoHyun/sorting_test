//
//  exchange.c
//  Algorithm_2022
//
//  Created by 정도현 on 2022/04/09.
//

#include <stdio.h>

// exchangeSort
void ExchangeSort(int n, int* arr){
    int front, back;
    for(front=0; front<n-1; front++){
        for(back=front+1; back<n; back++){
            if(arr[front] > arr[back]){    // if front > back -> swap
                int temp = arr[front];
                arr[front] = arr[back];
                arr[back] = temp;
            }
        }
    }
}
