#include"AQueue.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


/**
 *  @name        : void InitAQueue(AQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitAQueue(AQueue * Q)
{
	Q->front = 0;
	Q->rear = 0;
	Q->length = MAXQUEUE;
	for (int i = 0; i < MAXQUEUE; i++) {
		Q->data[i] = NULL;
	}
}


/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryAQueue(AQueue * Q)
{
	if (Q->data[Q->front] != NULL) {
		while (Q->front != Q->rear) {
			free(Q->data[Q->front]);
			Q->data[Q->front] = NULL;
			Q->front++;
			if (Q->front == MAXQUEUE) {
				Q->front = 0;
			}
		}
		free(Q->data[Q->front]);
		Q->data[Q->front] = NULL;
	}
}


/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *    @description : 检查队列是否已满
 *    @param         Q 队列指针Q
 *    @return         : 满-TRUE; 未满-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue * Q)
{
	int temp;
	temp = Q->rear + 1;
	if (temp == MAXQUEUE) {
		temp = 0;
	}
	if (temp == Q->front) {
		return TRUE;
	}
	return FALSE;
}


/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyAQueue(const AQueue * Q)
{
	if (Q->data[Q->front] !=NULL) {
		return FALSE;
	}
	return TRUE;
}

/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q 队列指针Q，存放元素e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadAQueue(AQueue * Q, void *e,int size)
{
	if (IsEmptyAQueue(Q) == FALSE) {
		memcpy(e, Q->data[Q->front], size);
		return TRUE;
	}
	return FALSE;
}


/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 队列长度count
 *  @notice      : None
 */
int LengthAQueue(AQueue * Q)
{
	if (IsEmptyAQueue(Q)) {
		return 0;
	}
	else if (Q->rear - Q->front < 0) {
		return (Q->rear - Q->front + MAXQUEUE + 1);
	}
	return Q->rear - Q->front + 1;
}


/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否满了或为空
 */
Status EnAQueue(AQueue * Q, void * data,int size)
{
	void* p = NULL;
	if (!IsFullAQueue(Q)) {
		p = malloc(size);
		memcpy(p, data, size);
		if (IsEmptyAQueue(Q)) {
			Q->data[Q->rear] = p;
		}
		else {
			Q->rear++;
			if (Q->rear == MAXQUEUE) {
				Q->rear = 0;
			}
			Q->data[Q->rear] = p;
		}
		return TRUE;
	}
	return FALSE;
}

/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeAQueue(AQueue * Q)
{
	if (!IsEmptyAQueue(Q)) {
		free(Q->data[Q->rear]);
		Q->data[Q->rear] = NULL;
		Q->rear--;
		if (Q->rear <0) {
			Q->rear = MAXQUEUE-1;
		}
		return TRUE;
	}
	return FALSE;
}

/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearAQueue(AQueue * Q)
{
	if (Q->data[Q->front] != NULL) {
		while (Q->front != Q->rear) {
			free(Q->data[Q->front]);
			Q->data[Q->front] = NULL;
			Q->front++;
			if (Q->front == MAXQUEUE) {
				Q->front = 0;
			}
		}
		free(Q->data[Q->front]);
		Q->data[Q->front] = NULL;
	}
}

/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseAQueue(const AQueue * Q, void(*foo)(void *q))
{
	int count = Q->front;
	if(!IsEmptyAQueue(Q)) {
		for (int i = 0; i < LengthAQueue(Q); i++) {
			(*foo)(Q->data[count]);
			count++;
			if (count == MAXQUEUE) {
				count = 0;
			}
		}
		return TRUE;
	}
	return FALSE;
}

/**
 *  @name        : void APrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 *  @notice      : None
 */
void APrint_int(void * q)
{
	printf("%d ", *(int*)q);
}
void APrint_float(void * q)
{
	printf("%f ", *(float*)q);
}
void APrint_double(void * q)
{
	printf("%lf ", *(double*)q);
}
void APrint_char(void * q)
{
	printf("%c ", *(char*)q);
}
void APrint_short(void * q)
{
	printf("%d ", *(short*)q);
}
void APrint_longint(void * q)
{
	printf("%ld ", *(long*)q);
}