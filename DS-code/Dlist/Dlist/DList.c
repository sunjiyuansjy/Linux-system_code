#include"DList.h"




DListNode* BuyNewDListNode(DLDataType data)
{
	DListNode* pNewNode = (DListNode*)malloc(sizeof(DListNode));
	if (NULL == pNewNode)
		exit(1);
	pNewNode->_pNext = NULL;
	pNewNode->_pPre = NULL;
	pNewNode->_data = data;
	return pNewNode;
}

void ListInit(DList* plist)
{
	//������ҲҪ�нڵ�
	assert(plist);
	plist->_pHead = BuyNewDListNode(0);//�ȶ����ͷ�ڵ�
	plist->_pHead->_pNext = plist->_pHead;
	plist->_pHead->_pPre = plist->_pHead;//˫������ʼ��Ҫѭ���������ʳ�ʼ��ͷ�ڵ�����ָ�����Լ�
}

void ListDestory(DList* plist)
{
	//���������е���Ч�ڵ�
	DListNode* pDel = plist->_pHead->_pNext;//����Ч�ڵ���ͷ�ֿ�
	while (pDel != plist->_pHead)
	{
		plist->_pHead->_pNext = pDel->_pNext;
		free(pDel);
		pDel = plist->_pHead->_pNext;
	}
	free(plist->_pHead);//��������ͷ
	plist->_pHead = NULL;
}

void ListPushBack(DList* plist, DLDataType x)
//˫��������Ҫ�ı��ĸ�ָ����
{	//ԭ������ò�Ҫ�ƻ�ԭ��������������̫���ң����Ƚ��½ڵ��pPreָ��ǰһ���ڵ㣬������nextָ��ͷ���ٽ�β��nextָ���¶�ԭ��β��ͷ��ָ��
	//���ԭ�����β��nextָ����
	//�½ڵ��nextָ��head
	assert(plist);
	DListNode* pNewNode=BuyNewDListNode(x);
	pNewNode->_pPre = plist->_pHead->_pNext;
	pNewNode->_pNext = plist->_pHead;
	
	plist->_pHead->_pPre = pNewNode;
	pNewNode->_pPre->_pNext = pNewNode;
}
void ListPopBack(DList* plist)
{
	//βɾ��ֻ��Ҫ�ı�����ָ���򣬽���ɾ��ͷһ����nextָ��head����ͷ��pPreָ��ǰһ������β�����£��ͷŽڵ㼴��
	//���ұ�ɾ
	DListNode* pDel = plist->_pHead->_pPre;//β��ͷ��pPre
	if (pDel != plist->_pHead)
	{
		pDel->_pPre->_pNext = plist->_pHead;
		plist->_pHead->_pPre = pDel->_pPre;
	}

}
void ListPushFront(DList* plist, DLDataType x)
{
	DListNode* pNewNode = BuyNewDListNode(x);
	
	pNewNode->_pNext = plist->_pHead->_pNext;
	pNewNode->_pPre = plist->_pHead;
	
	plist->_pHead->_pNext = pNewNode;
	pNewNode->_pNext->_pPre = pNewNode;
}
void ListPopFront(DList* plist)
{
	assert(plist);
	DListNode* pDel = plist->_pHead->_pNext;
	while (pDel != plist->_pHead)
	{
		plist->_pHead->_pNext = pDel->_pNext;
		pDel->_pNext->_pPre = plist->_pHead;
		free(pDel);
	}
}

DListNode* ListFind(DList* plist, DLDataType x)
{
	assert(plist);
	DListNode* pCur = plist->_pHead->_pNext;
	while (pCur != plist->_pHead)
	{
		if (pCur->_data = x)
			return pCur;
		pCur = pCur->_pNext;

	}
	return NULL;
}

// ��pos��ǰ����в���
void ListInsert(DListNode* pos, DLDataType x)
{
	assert(pos);
	DListNode* pNewNode = BuyNewDListNode(x);
	while(pos!=plist)


}

// ɾ��posλ�õĽڵ�
void ListErase(DListNode* pos);

void ListRemove(DList* plist, DLDataType x);

void ListPrint(DList* plist)
{
	DListNode* pCur = plist->_pHead->_pNext;
	while (pCur!=plist->_pHead)//ת��ͷ˵��һȦ����
	{
		printf("%d ", pCur->_data);
		pCur = pCur->_pNext;
	}
	printf("\n");
}


void TestDList1()
{
	DList dl;
	ListInit(&dl);
	ListPushBack(&dl, 1);
	ListPushBack(&dl, 2);
	ListPushBack(&dl, 3);
	ListPushBack(&dl, 4);
	ListPushBack(&dl, 5);
	ListPrint(&dl);
}

