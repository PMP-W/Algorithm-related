#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<time.h>
void PrintArray(int* a,int n);
void InsertSort(int* a, int n);
void BubbleSort(int* a, int n);
void ShellSort(int* a, int n);
void SelectSort(int* a, int n);
void AdjustDown(int* a, int size, int parent);
void HeapSort(int* a, int n);
void QuickSort(int* a, int begin,int end);
void MergeSort(int* a, int n);


void TestOP();