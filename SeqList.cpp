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

int DeleteMinElemAndReplaceWithLastElem(SeqList l,int i, int &e)
{
    if (l.length == 0 || i < 1 || i > l.length)
    {
        return 0;//throw error.
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

    l.data[i] = l.data[l.length];
    l.length--;
    return e;
}

void reverse(SeqList l) {
    if (l.length == 0)
    {
        return;
    }

    for (int i = l.length/2; i < l.length; i++)
    {
        int temp = l.data[i];
        l.data[i] = l.data[];
    }
}

int main()
{
    SeqList l;
    l.data = new int[InitSize];
    return 0;
}
