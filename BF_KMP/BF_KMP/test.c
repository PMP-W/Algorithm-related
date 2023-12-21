#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<string.h>
//字符串匹配算法  BF  KMP



//BF
/*
* str:主串
* sub:子串
* 返回值：返回子串在主串中的下标，不存在，则返回-1
*/
int BF(char* str, char* sub)
{
	assert(str && sub);
	if (str == NULL || sub == NULL)
		return -1;
	int strLen = strlen(str);
	int subLen = strlen(sub);
	
	int i = 0;//str
	int j = 0;//sub

	while (i < strLen && j < subLen)
	{
		if (str[i] == sub[j])
		{
			i++;
			j++;
		}
		else
		{
			j = 0;
			i = i - j + 1;
		}
	}
	if (j >= subLen)
	{
		return i-j;
	}
	return -1;
}
int main()
{
	printf("%d\n", BF("abcabdabcdef", "abcd"));//6
	printf("%d\n", BF("abcabdabcdef", "abc"));//0
	printf("%d\n", BF("abcabdabcdef", "abecd"));//-1

	return 0;
}