#include "LQueue.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitLQueue(LQueue * Q)
{
	Q->front = NULL;
	Q->rear = NULL;
	Q->length = 0;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue * Q)
{
	Node* p;
	while (Q->front != NULL) {
		p = Q->front->next;
		free(Q->front->data);
		Q->front->data = NULL;
		free(Q->front);
		Q->front = p;
	}
	Q->rear = NULL;
	Q->length = 0;
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue * Q)
{
	if (Q->front != NULL) {
		return FALSEE;
	}
	return TRUEE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadLQueue(LQueue * Q, void * e,int size)
{
	if (Q->length != 0) {
		memcpy(e, Q->front->data, size);
		return TRUEE;
	}
	return FALSEE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue * Q)
{
	return Q->length;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
Status EnLQueue(LQueue * Q, void * data,int size)
{
	Node *head = malloc(sizeof(Node));
	if (head != NULL) {
		head->data = malloc(size);
		memcpy(head->data, data, size);
		head->next = NULL;
		if (Q->front == NULL) {
			Q->front = head;
		}
		else {
			Q->rear->next = head;
		}
		Q->rear = head;
		Q->length++;
		return TRUEE;
	}
	return FALSEE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue * Q)
{
	Node* p;
	if (Q->length != 0) {
		p = Q->front->next;
		free(Q->front->data);
		Q->front->data = NULL;
		free(Q->front);
		Q->front = p;
		Q->length--;
		if (Q->length == 0) {
			Q->rear = NULL;
		}
		return TRUEE;
	}
	return FALSEE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearLQueue(LQueue * Q)
{
	Node* p;
	while (Q->front != NULL) {
		p = Q->front->next;
		free(Q->front->data);
		Q->front->data = NULL;
		free(Q->front);
		Q->front = p;
	}
	Q->rear = NULL;
	Q->length = 0;
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue * Q, void(*foo)(void *q))
{
	Node *p = NULL;
	if (Q->length != 0) {
		p = Q->front;
		while(p!=NULL){
			(*foo)(p->data);
			p = p->next;
		}
		return TRUEE;
	}
	return FALSEE;
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : ��������
 *    @param         q ָ��q

 *  @notice      : None
 */
void LPrint_int(void * q) {
	printf("%d ", *(int*)q);
}

void LPrint_float(void * q) {
	printf("%f ", *(float*)q);
}

void LPrint_double(void * q) {
	printf("%lf ", *(double*)q);
}

void LPrint_char(void * q) {
	printf("%c ", *(char*)q);
}

void LPrint_short(void * q) {
	printf("%d ", *(short*)q);
}

void LPrint_longint(void * q) {
	printf("%ld ", *(long*)q);
}