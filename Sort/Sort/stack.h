#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

//栈只能先进后出
//每个元素最后进出的相对顺序不唯一，可以边进边出

typedef int STDataType;

typedef struct Stack
{
	int* a;  //存储栈内元素的数组
	int top;		// 标识栈顶位置的,代表栈顶元素的下一个位置（也可以代表是栈顶元素，但栈为空时top==-1）
	int capacity;
}ST;

void STInit(ST* pst);//
void STDestroy(ST* pst);//

// 栈顶插入删除//
void STPush(ST* pst, STDataType x);
void STPop(ST* pst);
STDataType STTop(ST* pst);

bool STEmpty(ST* pst);
int STSize(ST* pst);