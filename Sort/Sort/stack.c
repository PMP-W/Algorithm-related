#define _CRT_SECURE_NO_WARNINGS 1
#include"stack.h"
//初始化
void STInit(ST* pst)
{
	assert(pst);
	pst->a = NULL;
	pst->capacity = 0;
	//此时top表示指向栈顶元素的下一个位置
	pst->top = 0;
	//pst->top=-1;//表示指向栈顶元素

}
void STDestroy(ST* pst)
{
	assert(pst);

	free(pst->a);
	pst->a = NULL;
	pst->top = pst->capacity = 0;//
}
// 栈顶插入删除
void STPush(ST* pst, STDataType x)//
{
	assert(pst);
	if (pst->top == pst->capacity)
	{
		int newcapacity = pst->capacity == 0 ? 4 : pst->capacity * 2;
		STDataType* tmp = (STDataType*)realloc(pst->a, sizeof(STDataType) * newcapacity);
		if (tmp == NULL)
		{
			perror("realloc error!");
			return;
		}
		pst->a = tmp;
		pst->capacity = newcapacity;
	}
	pst->a[pst->top] = x;
	pst->top++;

}
//删除栈顶元素
void STPop(ST* pst)
{
	assert(pst);
	//不为空
	assert(pst->top > 0);
	pst->top--;
}
//返回栈顶元素
STDataType STTop(ST* pst)
{
	assert(pst);
	//不为空
	assert(pst->top > 0);
	return pst->a[pst->top - 1];
}
//检验栈是否为空
bool STEmpty(ST* pst)
{
	assert(pst);
	return pst->top == 0;
}
//栈的大小////
int STSize(ST* pst)
{
	return pst->top;
}