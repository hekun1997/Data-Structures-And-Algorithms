#include <iostream>
using namespace std;

#define InitSize 100

typedef struct
{
    int *data;
    int length, maxSize;
}SeqList;

int add(int a, int b)
{
    return a + b;
}

bool ListInsert(SeqList &L, int i, int e)
{
    if (i < 1 || i > L.length+1){//如果比L.length+1还大，中间就会出现空位置。
        return false;
    }
    if (L.length > L.maxSize){
        return false;
    }
    for (int j = L.length; j >= i; j --){
        L.data[j] = L.data[j - 1];
    }
    L.data[i-1] = e;
    L.length++;
    return true;
}

int ListDelete(SeqList &l, int i, int &e)
{
    if (i < 1 || i > l.length)
    {
        return false;
    }
    e = l.data[i-1];
    for (int j = l.length; j >= i; j--)
    {
        l.data[j - 1] = l.data[j];
    }
    l.length--;
    return e;
}

int LocateElem(SeqList l, int e)
{
    for (int i = 0; i < l.length; i++)
    {
        if (l.data[i] == e)
        {
            return i + 1;
        }
    }
    
    return 0;
}

//1.
bool DeleteMinElemAndReplaceWithLastElem(SeqList l,int i, int &e)
{
    if (l.length == 0 || i < 1 || i > l.length)
    {
        return false;//throw error.
    }
    int index = 0;
    int minElem = l.data[0];
    for (int i = 1; i < l.length; i++)
    {
        if (l.data[i] < minElem)
        {
            minElem = l.data[i];
            index = i;
        }
    }

    e = l.data[i];

    l.data[i] = l.data[l.length-1];
    l.length--;
    return true;
}
//2.
void reverse(SeqList &l) {
    for (int i = l.length/2, j = 0; i < l.length && j <= i; i++, j ++)
    {
        int temp = l.data[i];
        l.data[i] = l.data[j];
        l.data[j] = l.data[i];
    }
}
//3.对长度为 的顺序表 ，编写一个时间复杂度为 O(n 、空间复杂度为 0(1 ）的算法 该算
//法删除线性表中所有值为x 的数据元素
void DeleteX(SeqList &l, int x){
    int k = 0;
    for (int i = 0; i < l.length; i ++)
    {
        if (l.data[i] != x)
        {
            l.data[k] = l.data[i];
            k++;
        }
    }
    l.length = k;
} 
//4. 删除s-t之间的元素  1 5 9 8 7- 4- 1- 2 3 // 9 4-8
bool DeleteBewteenSAndT(SeqList &l, int s, int t){
    int i, j;
    if(l.length = 0 || s >= t){
        return;
    }
    for (i = 0; i < l.length && l.data[i] < s; i ++);
    if (i >= l.length)
    {
        return false;
    }

    for (j = 0; i < l.length && l.data[i] > t; j ++);
    if (i >= l.length)
    {
        return false;
    }
    for (; j < l.length;i ++, j++)
    {
        l.data[i] = l.data[j];
    }
    l.length = i;
    return true;
}
//6.从有序顺序表中删除所有其值重复的元素，使表中所有元素的值均不同
bool DeleteRepate(SeqList &l){
    if (l.length == 0)
    {
        return false;
    }
    int i, j;
    for (int i = 0, j = 1; j < l.length; j++)
    {
        if (l.data[i] != l.data[j])
        {
            l.data[++i] = l.data[j];
        }
    }
    l.length = i + 1;
    return true;
}
//7.将两个有序顺序表合并为一个新的有序顺序表，并 函数返回结果顺序表
bool mergeList(SeqList a, SeqList b, SeqList &c){
    if (a.length + b.length > c.maxSize){
        return false;
    }
    int i = 0, j = 0, k = 0;
    while (i < a.length && j < b.length)
    {
        if (a.data[i] <= b.data[j])
        {
            c.data[k++] = a.data[i++];
        }else
        {
            c.data[k++] = b.data[j++];
        }
    }
    while (i < a.length)
    {
        c.data[k++] = a.data[i++];
    }
    while (j < b.length)
    {
        c.data[k++] = b.data[j++];
    }

    c.length = k;
    return true;
}
//8. (a1, a2 ,a3 ......am, b1, b2, .....bn) -> (b1, b2, ....bn, a1, a2, ....an)
typedef int DataType;
void Reverse(DataType list[], int left, int right,int arraySize){
    if (left >= right || right > arraySize)
    {
        return;
    }
    int mid = (left + right) / 2;
    for (int i = 0; i < mid - left; i++){
        DataType temp = list[left + i];
        list[left + i] = list[right - i];
        list[right - i] = temp;
    }
}

void Exchange(DataType list[], int m, int n, int arraySize){
    Reverse(list, 0, m + n - 1, arraySize);
    Reverse(list, 0, n - 1, arraySize);
    Reverse(list, n, m + n - 1, arraySize);
}

//9.最短的时间里找到x的位置，找到x，与后继元素交换，找不到则插入
void ExchangeXOrInsertX(DataType list[], DataType x, int n){
    int low = 0, high = n - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (list[mid] == x)
            break;
        else if (list[mid] > x)
            high = mid -1;
        else if (list[mid] < x)
            low = mid +1;
    }
    if (list[mid] == x && mid != n-1)
    {
        DataType temp = list[mid];
        list[mid] = list[mid + 1];
        list[mid + 1] = temp;
    }
    if (low > high)
    {
        mid = 0;
        for (; mid < high && list[mid] < x; mid++);
        for (int i = high; i > mid; i --){
            list[i + 1] = list[i];
        }
        list[mid] = x;
    }
}
//10. (a0, a1,...,an-1) -> 左移p个位置->(ap, .... an-1,a0,a1,...ap-1)
void Reverse(DataType list[], int from, int to){
    for (int i = 0; i < to -from + 1; i++)
    {
        DataType temp = list[from + i];
        list[from + i] = list[to - i];
        list[to - i] = temp;
    }
    
}
void offsetP(DataType list[],int n, int p){
    Reverse(list, 0, p - 1);
    Reverse(list, p, n - 1);
    Reverse(list, 0, n - 1);
}


int main()
{
}
