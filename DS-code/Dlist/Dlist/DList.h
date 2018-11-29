#pragma once

#include<stdio.h>
#include<Windows.h>
#include<assert.h>
#include<malloc.h>
#include<stdlib.h>

// ��ͷ���ѭ��˫������
typedef int DLDataType;

typedef struct DListNode
{
	struct DListNode* _pNext;
	struct DListNode* _pPre;
	DLDataType _data;
}DListNode;

typedef struct DList
{
	struct DListNode* _pHead;
}DList;

DListNode* BuyNewDListNode(DLDataType data);
void ListInit(DList* plist);
void ListDestory(DList* plist);

void ListPushBack(DList* plist, DLDataType x);
void ListPopBack(DList* plist);
void ListPushFront(DList* plist, DLDataType x);
void ListPopFront(DList* plist);

DListNode* ListFind(DList* plist, DLDataType x);

// ��pos��ǰ����в���
void ListInsert(DListNode* pos, DLDataType x);

// ɾ��posλ�õĽڵ�
void ListErase(DListNode* pos);

void ListRemove(DList* plist, DLDataType x);

void ListPrint(DList* plist);

void ListReversePrint(DList* plist);
void TestDList1();
