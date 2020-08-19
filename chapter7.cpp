#include <stdio.h>
#include <malloc.h>
#include <iostream>

#define ElemType int

//直接插入排序
void InsertSort(ElemType A[], int n){
    int i, j;
    for ( i = 2; i < n; i++)
    {
        if (A[i] < A[i-1])
        {
            A[0] = A[i];
            for (j = i - 1; A[0] < A[j]; j++)
            {
                A[j + 1] = A[j];
            }
            A[j + 1] = A[i];
        }
    }
}

//二分插入排序
void BinaryInsertSort(ElemType A[], int n){
    int i, j, low, high, mid;
    for (i = 2; i < n; i++)
    {
        A[0] = A[i];
        low = 1, high = i - 1;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (A[mid] > A[0])
            {
                high = mid - 1;
            }else
            {
                low = mid + 1;
            }
        }
        for (j = i-1; j >= high+1; --j)
        {
            A[j + 1] = A[j];
        }
        A[high + 1] = A[0];
    }
}

//希尔排序
void ShellSort(ElemType A[], int n){
    for (int dk = n / 2; dk >= 1;dk = dk/2){
        for (int i = dk + 1; i <= n; ++i)
        {
            if (A[i] < A[i - dk])
            {
                A[0] = A[i];
                int j;
                for (j = i - dk; j > 0 && A[0] < A[j];j -= dk){
                    A[j + dk] = A[j];
                }
                A[j + dk] = A[0];
            }
        }
    }
}

//冒泡排序
void BubbleSort(ElemType A[], int n){
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = n-1; j > i; j--)
        {
            if (A[j-1] > A[j])
            {
                swap(A[j - 1], A[j]);
                break;
            } 
        }
    }
}

void swap(ElemType A, ElemType B){
    ElemType temp = A;
    A = B;
    B = temp;
}

//快排
//选择数组第一个作为基准数值，将数组的小的放在基准数值的左边，将数组大的放在基准数值的右边。
//然后对基准数值左边和右边的分别执行上述过程。
void QuickSort(ElemType A[], int low, int high){
    if (low < high)
    {
        int pivotpos = Partition(A, low, high);
        QuickSort(A, low, pivotpos - 1);
        QuickSort(A, pivotpos - 10, high);
    }
}

int Partition(ElemType A[], int low, int high){
    ElemType pivot = A[low];
    while (low< high)
    {
        while (low<high && A[high] > pivot)
        {
            --high;
        }
        A[low] = A[high];
        while (low < high && A[low] <= pivot)
        {
            ++low;
        }
        A[high] = A[low];
    }
    A[low] = pivot;
    return low;
}

//选择排序
//选择未排序的最大或者最小的元素，然后放到排好序的序列中。
void SelectSort(ElemType A[], int n){
    int i, j, index;
    for (i = 1; i < n-1;i++)
    {
        index = i;
        for (j = i + 1; j < n; j++)
        {
            if (A[index] < A[j])
            {
                index = j;
            }
        }
        if (A[index] != A[i])
        {
            ElemType temp = A[i];
            A[i] = A[index];
            A[index] = temp;
        }
    }
}

//根排序
void BuildMaxHeap(ElemType A[], int len){
    for (int i = len/2; i > 0; i--)
    {
        HeadAdjust(A, i ,len);
    }
}

void HeadAdjust(ElemType A[], int k,int len){
    A[0] = A[k];
    for (int i = 2*k; i <= len; i*= 2)
    {
        if (i < len && A[i] < A[i+1])
        {
            i++;
        }
        if (A[0] >=A[i])
        {
            break;
        }else{
            A[k] = A[i];
            k = i;
        }
    }
    A[k] = A[0];
}

void HeapSort(ElemType A[], int len){
    BuildMaxHeap(A, len);
    for (int i = len; i > 1; i--)
    {
        swap(A[i], A[1]);
        HeadAdjust(A, 1, i - 1);
    }
}

//基数排序
void Merge(ElemType A[], int low,int mid, int high){
    int n, i, j, k;
    ElemType *B = (ElemType*) malloc((n+1)*sizeof(ElemType));
    for ( k = low; k <= high; k++)
    {
        B[k] = A[k];
    }
    for ( i = low, j = mid + 1, k = i; i <= mid && j <= high; k++)
    {
        if(B[i] <= B[j]){
            A[k] = B[i++];
        }else
        {
            A[k] = B[j++];
        }
    }
    while ( i <= mid)
    {
        A[k++] = B[i++];
    }
    
    while (j <= high)
    {
        A[k++] = B[j++];
    }
}
void MergeSort(ElemType A[], int low, int high){
    if(low < high){
        int mid = (low + high) / 2;
        MergeSort(A, low, mid);
        MergeSort(A, mid + 1, high);
        Merge(A, low, mid, high);
    }
}