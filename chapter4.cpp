#include <stdio.h>
#include <malloc.h>
#include <iostream>

#define MAXLEN 255

typedef struct{
    char ch[MAXLEN];
    int length;
} SString;//定长，超出只能截断

typedef struct{
    char *ch;
    int length;
} HString;//动态分配

//暴力匹配 时间复杂度最坏O(nm)
int Index(SString S, SString T){
    int i = 1, j = 1;
    while (i < S.length && j < T.length)
    {
        if (S.ch[i] == T.ch[j])
        {
            i++;
            j++;
        }else
        {
            i = i - j + 2;
            j = 1;
        }
    }
    if (j > T.length)
    {
        return i - T.length;
    }
    return 0;
}
//KMP算法 O(n + m)
//a a a a b aaabaaaaab
//0 1 2 3 0  
void getnext_val(SString T, int nextVal[]){

}