#include"main.h"


void faqueue_int(AQueue* aqueue_int) {
	char input=0;
	int temp=0;
	while (1) {
		system("cls");
		printf("请输入操作前的数字或字符进行操作\n");
		printf("1.入队\n2.出队\n3.查看队列是否已满\n4.查看队列是否为空\n5.查看队头元素\n");
		printf("6.查看队伍长度\n7.输出队列全部元素\n8.清空队列\ne.退出操作\n");
		scanf_s("%c", &input);
		switch (input) {
		case'1':
			printf("输入入队数据：");
			scanf_s("%d", &temp);
			EnAQueue(aqueue_int, &temp,sizeof(int));
			break;
		case'2':DeAQueue(aqueue_int); break;
		case'3':
			if (IsFullAQueue(aqueue_int)) {
				printf("队列已满\n");
			}
			else {
				printf("队列未满\n");
			}
			break;
		case'4':
			if (IsEmptyAQueue(aqueue_int)) {
				printf("队列为空\n");
			}
			else {
				printf("队列未空\n");
			}
			break;
		case'5':
			if (GetHeadAQueue(aqueue_int, &temp, sizeof(int))) {
				printf("队头元素为%d\n", temp);
			}
			else {
				printf("队列为空\n");
			}
			break;
		case'6':
			printf("队列长度为%d\n", LengthAQueue(aqueue_int));
			break;
		case'7':
			if (TraverseAQueue(aqueue_int, APrint_int)) {
			}
			else {
				printf("队列为空");
			}
			break;
		case'8':ClearAQueue(aqueue_int);
		}
		if (input == 'e') {
			break;
		}
		system("pause");
	}
}

void flqueue_int(LQueue* lqueue_int) {
	char input = 0;
	int temp = 0;
	while (1) {
		system("cls");
		printf("请输入操作前的数字或字符进行操作\n");
		printf("1.入队\n2.出队\n3.查看队列是否为空\n4.查看队头元素\n");
		printf("5.查看队伍长度\n6.输出队列全部元素\n7.清空队列\ne.退出操作\n");
		scanf_s("%c", &input);
		switch (input) {
		case'1':
			printf("输入入队数据：");
			scanf_s("%d", &temp);
			EnLQueue(lqueue_int, &temp, sizeof(int));
			break;
		case'2':DeLQueue(lqueue_int); break;
		case'3':
			if (IsEmptyLQueue(lqueue_int)) {
				printf("队列为空\n");
			}
			else {
				printf("队列未空\n");
			}
			break;
		case'4':
			if (GetHeadLQueue(lqueue_int, &temp, sizeof(int))) {
				printf("队头元素为%d\n", temp);
			}
			else {
				printf("队列为空\n");
			}
			break;
		case'5':
			printf("队列长度为%d\n", LengthLQueue(lqueue_int));
			break;
		case'6':
			if (TraverseLQueue(lqueue_int, APrint_int)) {
			}
			else {
				printf("队列为空");
			}
			break;
		case'7':ClearLQueue(lqueue_int);
		}
		if (input == 'e') {
			break;
		}
		system("pause");
	}
}

void faqueue_char(AQueue* aqueue_char) {
	char input = 0;
	char temp = 0;
	while (1) {
		system("cls");
		printf("请输入操作前的数字或字符进行操作\n");
		printf("1.入队\n2.出队\n3.查看队列是否已满\n4.查看队列是否为空\n5.查看队头元素\n");
		printf("6.查看队伍长度\n7.输出队列全部元素\n8.清空队列\ne.退出操作\n");
		scanf_s("%c", &input);
		switch (input) {
		case'1':
			printf("输入入队数据：");
			scanf_s("%c", &temp);
			EnAQueue(aqueue_char, &temp, sizeof(double));
			break;
		case'2':DeAQueue(aqueue_char); break;
		case'3':
			if (IsFullAQueue(aqueue_char)) {
				printf("队列已满\n");
			}
			else {
				printf("队列未满\n");
			}
			break;
		case'4':
			if (IsEmptyAQueue(aqueue_char)) {
				printf("队列为空\n");
			}
			else {
				printf("队列未空\n");
			}
			break;
		case'5':
			if (GetHeadAQueue(aqueue_char, &temp, sizeof(char))) {
				printf("队头元素为%c\n", temp);
			}
			else {
				printf("队列为空\n");
			}
			break;
		case'6':
			printf("队列长度为%d\n", LengthAQueue(aqueue_char));
			break;
		case'7':
			if (TraverseAQueue(aqueue_char, APrint_char)) {
			}
			else {
				printf("队列为空");
			}
			break;
		case'8':ClearAQueue(aqueue_char);
		}
		if (input == 'e') {
			break;
		}
		system("pause");
	}
}

void flqueue_double(LQueue* lqueue_double){
	char input = 0;
	double temp = 0;
	while (1) {
		system("cls");
		printf("请输入操作前的数字或字符进行操作\n");
		printf("1.入队\n2.出队\n3.查看队列是否为空\n4.查看队头元素\n");
		printf("5.查看队伍长度\n6.输出队列全部元素\n7.清空队列\ne.退出操作\n");
		scanf_s("%c",&input);
		switch (input) {
		case'1':
			printf("输入入队数据：");
			scanf_s("%lf", &temp);
			EnLQueue(lqueue_double, &temp, sizeof(double));
			break;
		case'2':DeLQueue(lqueue_double); break;
		case'3':
			if (IsEmptyLQueue(lqueue_double)) {
				printf("队列为空\n");
			}
			else {
				printf("队列未空\n");
			}
			break;
		case'4':
			if (GetHeadLQueue(lqueue_double, &temp, sizeof(double))) {
				printf("队头元素为%lf\n", temp);
			}
			else {
				printf("队列为空\n");
			}
			break;
		case'5':
			printf("队列长度为%d\n", LengthLQueue(lqueue_double));
			break;
		case'6':
			if (TraverseLQueue(lqueue_double, APrint_double)) {
			}
			else {
				printf("队列为空");
			}
			break;
		case'7':ClearLQueue(lqueue_double);
		}
		if (input == 'e') {
			break;
		}
		system("pause");
	}
	
}

Status menu(AQueue* aqueue_int, LQueue* lqueue_int, AQueue* aqueue_char, LQueue* lqueue_double) {
	char input = 0;
	system("cls");
	printf("已生成：a整型循环队列、b整型链式队列、c字符型循环队列、d浮点型链式队列\n");
	printf("请输入类型前的字符对该类型进行相应的操作,或输入e退出:\n");
	scanf_s("%c", &input);
	switch (input) {
	case 'a':faqueue_int(aqueue_int); break;
	case 'b':flqueue_int(lqueue_int); break;
	case 'c':faqueue_char(aqueue_char); break;
	case 'd':flqueue_double(lqueue_double); break;
	case 'e':return FALSE; break;
	default:printf("输入有误，请重新输入\n");
		system("cls");
	}
	return TRUE;
	
}

int main() {
	AQueue aqueue_int;
	LQueue lqueue_int;
	AQueue aqueue_char;
	LQueue lqueue_double;
	InitAQueue(&aqueue_int);
	InitAQueue(&aqueue_char);
	InitLQueue(&lqueue_int);
	InitLQueue(&lqueue_double);
	while (1) {
		if (!menu(&aqueue_int, &lqueue_int, &aqueue_char, &lqueue_double)) {
			break;
		}
	}
	DestoryAQueue(&aqueue_char);
	DestoryLQueue(&lqueue_double);
	DestoryLQueue(&lqueue_int);
	DestoryAQueue(&aqueue_int);
	return 0;
}