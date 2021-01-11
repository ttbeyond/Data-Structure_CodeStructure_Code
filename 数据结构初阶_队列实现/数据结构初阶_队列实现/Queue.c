#include"Queue.h"

void QueueInit(Queue* pq)
{
	assert(pq);

	pq->_front = NULL;
	pq->_back = NULL;
}
void QueueDestory(Queue* pq)
{
	assert(pq);

	QueueNode* cur = pq->_front;
	while (cur)
	{
		QueueNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	pq->_back = pq->_front = NULL;
}
QueueNode* BuyQueueNode(QDataType x)
{
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	newnode->_data = x;
	newnode->_next = NULL;
	return newnode;
}
void QueuePush(Queue* pq, QDataType x)//��������,�൱�������β��
{
	assert(pq);

	Queue* newnode = BuyQueueNode(x);
	if (pq->_back == NULL)
	{
		pq->_back = pq->_front = newnode;
	}
	else
	{
		pq->_back->_next = newnode;
		pq->_back = newnode;
	}

}

//ɾ����ͷ��һ��Ԫ��
void QueuePop(Queue* pq)
{
	assert(pq&&pq->_front!=NULL);
	if (pq->_front->_next == NULL)
	 {
		free(pq->_front);
		pq->_front = pq->_back = NULL;
	 }
	 else
	 {
		QueueNode* cur = pq->_front->_next;
		free(pq->_front);
		pq->_front = cur;
	 }
}
//��ȡ����ͷ��Ԫ��
QDataType QueueFront(Queue* pq)
{
	assert(pq);

	return pq->_front->_data;
}
//��ȡ����β��Ԫ��
QDataType QueueBack(Queue* pq)
{
	assert(pq);

	return pq->_back->_data;
}
//�пգ�Ϊ�շ���1�����շ���0��
int QueueEmpty(Queue* pq)
{
	return pq->_front == NULL ? 1 : 0;
}
int QueueSize(Queue* pq)
{
	int len = 0;
	QueueNode* ret = pq->_front;
	while (ret)
	{
		len++;
		ret = ret->_next;
	}
	return len;
}