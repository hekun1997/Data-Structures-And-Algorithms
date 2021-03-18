#include <stdio.h>
#include <stdbool.h>

#define MaxSize 50
#define ElemType int

void InsertSort(ElemType A[], int n){
    int i, j, temp;
    for (i = 1; i <= n; i++){
        if(A[i] < A[i-1]){
            temp = A[i];
            for (j = i - 1; temp < A[j]; --j){
                A[j + 1] = A[j];
            }
            A[j + 1] = temp;
        }
    }
}

void BinaryInsertSort(ElemType A[], int n){
    int i, j, low, high, mid, temp;
    for (i = 1; i <= n; i++){
        temp = A[i];
        low = 0, high = i - 1;
        while(low <= high){
            mid = (low + high) / 2;
            if(A[mid] > temp)
                high = mid - 1;
            else
                low = mid + 1;
        }
        for (j = i - 1; j >= high + 1; --j){
            A[j + 1] = A[j];
        }
        A[high + 1] = temp;
    }
}

//A[0] 排不到序
void ShellSort(ElemType A[], int n){
    int dk, i, j;
    for (dk = n / 2; dk >= 1; dk = dk / 2){
        for (i = dk + 1; i <= n; ++i){
            if(A[i] < A[i-dk]){
                A[0] = A[i];
                for (j = i - dk; j > 0 && A[0] < A[j]; j -= dk){
                    A[j + dk] = A[j];
                }
                A[j + dk] = A[0];
            }
        }
    }
}

void BubbleSort(ElemType A[], int n){
    int i = 0, j, temp;
    for (; i < n - 1;i++){
        for (j = n - 1; j > i; j--){
            if (A[j - 1] > A[j]){
                temp = A[j - 1];
                A[j - 1] = A[j];
                A[j] = temp;
            }
        }
    }
}

void QuickSort(ElemType A[], int low, int high){
    if(low < high){
        int povit = Partition(A, low, high);
        QuickSort(A, low, povit - 1);
        QuickSort(A, povit + 1, high);
    }
}

int Partition(ElemType A[], int low, int high){
    ElemType pivot = A[low];
    while(low < high){
        while(low < high && A[high] >= pivot)
            --high;
        A[low] = A[high];
        while(low < high && A[low] <= pivot)
            ++low;
        A[high] = A[low];
    }
    A[low] = pivot;
    return low;
}


void SelectSort(ElemType A[], int n){
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++){
        min = i;
        for (j = i + 1; j < n; j++){
            if (A[j] < A[min])
                min = j;
            if (min != i){
                temp = A[min];
                A[min] = A[i];
                A[i] = temp;
            }
        }
    }
}

void BuildMaxHeap(ElemType A[], int len){
    int i;
    for (i = len / 2; i > 0; i--){
        HeapAdjust(A, i, len);
    }
}

void HeapAdjust(ElemType A[], int len, int k){
    A[0] = A[k];
    int i;
    for (i = 2 * k; i <= len; i += 2){
        if (i < len && A[i] < A[i + 1]){
            i++;
        }
        if (A[0] >= A[i]) break;
        else {
            A[k] = A[i];
            k = i;
        }
    }
    A[k] = A[0];
}

void HeapSort(ElemType A[], int len){
    BuildMaxHeap(A, len);
    int i, temp;
    for (i = len; i > 1; i--){
        temp = A[i];
        A[i] = A[i - 1];
        A[i - 1] = temp;
        HeapAdjust(A, 1, i - 1);
    }
}

int main(){
    ElemType A[] = { 50, 38, 13, 97, 123, 10};
    int n = 6;

    int i, j, min, temp;
    for (i = 0; i < n - 1; i++){
        min = i;
        for (j = i + 1; j < n; j++){
            if (A[j] < A[min])
                min = j;
            if (min != i){
                temp = A[min];
                A[min] = A[i];
                A[i] = temp;
            }
        }
    }

    for (i = 0; i < 6;i++){
        printf("%d ", A[i]);
    }
    return 0;
}