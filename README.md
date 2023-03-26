# Sorting_test (C Code)
Sorting_algorithm Implementation with C code.


## Sorting Algorithm
### Exchange Sort
``` C
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
```

<br>

### Merge Sort (Divide & Conquer)

``` C
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
```

<br>

### Quick Sort (Random Pivot)
``` C
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

```

<br>

### Heap Sort
``` C
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

```

<br>

### Radix Sort (LSD - Least Significant Digit)
``` C
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

```

<br>

## Complexity 
<img width="70%" src="https://user-images.githubusercontent.com/40754281/227786930-8f55b68b-3245-4a5f-82aa-122000b017d7.png">


<br>

## Result 
<h4> Case) size 100 array (sec) </h4>
<img width="70%" src="https://user-images.githubusercontent.com/40754281/227786446-53d2690b-a039-4311-ad71-4fb95c390ee5.png">

<h4> Case) size 500 array (sec) </h4>
<img width="70%" src="https://user-images.githubusercontent.com/40754281/227786515-aec4a810-fae1-4be0-9a48-db726f960b14.png">

<h4> Case) size 1000 array (sec) </h4>
<img width="70%" src="https://user-images.githubusercontent.com/40754281/227786559-7d35b55f-ead5-4521-ab65-cb738d8db12d.png">

<h4> Case) size 5000 array (sec) </h4>
<img width="70%" src="https://user-images.githubusercontent.com/40754281/227786649-037ae8f5-b3d5-4be3-953c-96201cce767f.png">

<h4> Case) size 10000 array (sec) </h4>
<img width="70%" src="https://user-images.githubusercontent.com/40754281/227786683-aab3e6a0-c303-4211-aa21-c0173abd2615.png">

<br>

## Result - Graph
<img width="70%" src="https://user-images.githubusercontent.com/40754281/227786299-0e267d8b-0940-4aa2-8373-d68f8fa8ab7c.png">

