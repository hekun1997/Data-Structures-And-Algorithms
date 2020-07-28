#include <iostream>
#include <stdio.h>
#include <string.h>
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

//11. 【2011】一个长度为L (L >= 1)的升序序列s,处在第[L / 2]个位置的数称为S的中位数。例如,若序列S1= (11, 13, 15, 17, 19),则S,的中位数是15,两个序列的中位数是含它们所有元素的升序序列的中位数。
//例如,若S2= (2, 4, 6, 8, 20),则S,和S2的中位数是11,现在有两个等长升序序列A和B,试设计一个在时间和空间两方面都尽可能高效的算法,找出两个序列A和B的中位数。
//要求:1)给出算法的基本设计思想。2)根据设计思想,采用C或C++或Java语言描述算法,关键之处给出注释。3)说明你所设计算法的时间复杂度和空间复杂度。

int findMiddleNum(int A[], int B[], int L){
    int s1 = 0, d1 = L - 1, m1, s2 = 0, d2 = L - 2, m2;
    while (s1!=d1 || s2!=d2)
    {
        m1 = (s1 + d1) / 2;
        m2 = (s2 + d2) / 2;
        if (A[m1] == B[m2])
        {
            return m1;
        }
        
        if (A[m1] < B[m2])
        {
            if ((s1+d1) % 2==0)
            {
                s1 = m1;
                d2 = m2;
            }else{
                s1 = m1 + 1;
                d2 = m2;
            }
        }else
        {
            if ((s1+d1) % 2==0)
            {
                d1 = m1;
                s2 = m2;
            }else{
                d1 = m1;
                s2 = m2 + 1;
            }
        }
    }
    return A[s1] > B[s2] ? A[s1] : B[s2];
}

//12, 【2013】已知一个整数序列A = (a0, a1,.., an-1), 其中0 <= ai < n (0 <= i < n),若存在apl = ap2 = ... = apm = x且m > n/2 (0 < pk <n ,1 1 <= k <= m),则称x为A的主元素。
//例如A= (0,5, 5, 3,5, 7, 5, 5),则5为主元素;又如A=(0, 5, 5, 3, 5, 1,5,7),则A中没有主元素。假设A中的n个元素保存在一个一维数组中,请设计一个尽可能高效的算法,找出A的主元素。
//若存在主元素,则输出该元素;否则输出-1,要求:1)给出算法的基本设计思想。2)根据设计思想,采用C或C++或Java语言描述算法,关键之处给出注释。3)说明你所设计算法的时间复杂度和空间复杂度。
int Majority(int A[], int n){
    int i, c = A[0], count = 1;
    for ( i = 1; i < n; i++)
    {
        if (A[i] == c)
        {
            count++;
        }else
        {
            count--;
        }
        if (count == 0)
        {
            c = A[i];
            count = 1;
        }
    }
    count = 0;
    for ( i = 0; i < n; i++)
    {
        if (A[i] == c)
        {
            count++;
        }
    }
    return c > 2 / n ? c : -1;
}

//13, 【2018】给定一个含n (n>=1)个整数的数组,请设计一个在时间上尽可能高效的算法,找出数组中未出现的最小正整数。
//例如,数组{-5, 3, 2, 3}中未出现的最小正整数是1; 数组{1, 2, 3}中未出现的最小正整数是4,
//要求:1)给出算法的基本设计思想。2)根据设计思想,采用C或C++语言描述算法,关键之处给出注释。3)说明你所设计算法的时间复杂度和空间复杂度。
int findMinNum(int a[], int n){
    int *b, i;
    b = (int *)malloc(sizeof(int) * n);
    memset(b, 0, sizeof(int)*n);
    for ( i = 0; i < n; i++)
    {
        int temp = a[i];
        if (temp > 0)
        {
            b[temp - 1] = temp;
        }
    }
    for ( i = 0; i < n; i++)
    {
        if (b[i] == 0)
            break;
    }
    return i;
}   

int main()
{

}
