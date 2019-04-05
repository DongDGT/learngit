#include "LQueue.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
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
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
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
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
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
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
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
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue * Q)
{
	return Q->length;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
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
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
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
 *    @description : 清空队列
 *    @param         Q 队列指针Q
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
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
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
 *    @description : 操作函数
 *    @param         q 指针q

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