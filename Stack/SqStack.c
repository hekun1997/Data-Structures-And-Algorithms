#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ElemType int

#define MaxSize 50

//栈顶指针需要注意，其位置可能指向栈顶位置（init = -1）,可能指向栈顶前一个元素。
typedef struct{
    ElemType data[MaxSize];
    int top;
} SqStack;

SqStack createStack(){
    SqStack stack;
    stack.top = 0;
    return stack;
}

bool StackEmpty(SqStack s){
    return s.top == 0 ? true : false;
}

bool Push(SqStack s, ElemType data){
    if(s.top == MaxSize){
        return false;
    }
    s.data[s.top] = data;
    s.top++;
    return true;
}

ElemType Pop(SqStack s){
    if(s.top == 0){
        return -1;
    }
    ElemType data = s.data[s.top--];
    return data;
}

ElemType GetTop(SqStack s){
    if(s.top == 0){
        return -1;
    }
    ElemType data = s.data[s.top - 1];
    return data;
}



int main(){
    SqStack s = createStack();
    Push(s, 987);
    printf("%d\n", s.top);
    printf("%d", Pop(s));
    return 0;
}