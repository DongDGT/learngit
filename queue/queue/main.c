#include"main.h"


void faqueue_int(AQueue* aqueue_int) {
	char input=0;
	int temp=0;
	while (1) {
		system("cls");
		printf("���������ǰ�����ֻ��ַ����в���\n");
		printf("1.���\n2.����\n3.�鿴�����Ƿ�����\n4.�鿴�����Ƿ�Ϊ��\n5.�鿴��ͷԪ��\n");
		printf("6.�鿴���鳤��\n7.�������ȫ��Ԫ��\n8.��ն���\ne.�˳�����\n");
		scanf_s("%c", &input);
		switch (input) {
		case'1':
			printf("����������ݣ�");
			scanf_s("%d", &temp);
			EnAQueue(aqueue_int, &temp,sizeof(int));
			break;
		case'2':DeAQueue(aqueue_int); break;
		case'3':
			if (IsFullAQueue(aqueue_int)) {
				printf("��������\n");
			}
			else {
				printf("����δ��\n");
			}
			break;
		case'4':
			if (IsEmptyAQueue(aqueue_int)) {
				printf("����Ϊ��\n");
			}
			else {
				printf("����δ��\n");
			}
			break;
		case'5':
			if (GetHeadAQueue(aqueue_int, &temp, sizeof(int))) {
				printf("��ͷԪ��Ϊ%d\n", temp);
			}
			else {
				printf("����Ϊ��\n");
			}
			break;
		case'6':
			printf("���г���Ϊ%d\n", LengthAQueue(aqueue_int));
			break;
		case'7':
			if (TraverseAQueue(aqueue_int, APrint_int)) {
			}
			else {
				printf("����Ϊ��");
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
		printf("���������ǰ�����ֻ��ַ����в���\n");
		printf("1.���\n2.����\n3.�鿴�����Ƿ�Ϊ��\n4.�鿴��ͷԪ��\n");
		printf("5.�鿴���鳤��\n6.�������ȫ��Ԫ��\n7.��ն���\ne.�˳�����\n");
		scanf_s("%c", &input);
		switch (input) {
		case'1':
			printf("����������ݣ�");
			scanf_s("%d", &temp);
			EnLQueue(lqueue_int, &temp, sizeof(int));
			break;
		case'2':DeLQueue(lqueue_int); break;
		case'3':
			if (IsEmptyLQueue(lqueue_int)) {
				printf("����Ϊ��\n");
			}
			else {
				printf("����δ��\n");
			}
			break;
		case'4':
			if (GetHeadLQueue(lqueue_int, &temp, sizeof(int))) {
				printf("��ͷԪ��Ϊ%d\n", temp);
			}
			else {
				printf("����Ϊ��\n");
			}
			break;
		case'5':
			printf("���г���Ϊ%d\n", LengthLQueue(lqueue_int));
			break;
		case'6':
			if (TraverseLQueue(lqueue_int, APrint_int)) {
			}
			else {
				printf("����Ϊ��");
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
		printf("���������ǰ�����ֻ��ַ����в���\n");
		printf("1.���\n2.����\n3.�鿴�����Ƿ�����\n4.�鿴�����Ƿ�Ϊ��\n5.�鿴��ͷԪ��\n");
		printf("6.�鿴���鳤��\n7.�������ȫ��Ԫ��\n8.��ն���\ne.�˳�����\n");
		scanf_s("%c", &input);
		switch (input) {
		case'1':
			printf("����������ݣ�");
			scanf_s("%c", &temp);
			EnAQueue(aqueue_char, &temp, sizeof(double));
			break;
		case'2':DeAQueue(aqueue_char); break;
		case'3':
			if (IsFullAQueue(aqueue_char)) {
				printf("��������\n");
			}
			else {
				printf("����δ��\n");
			}
			break;
		case'4':
			if (IsEmptyAQueue(aqueue_char)) {
				printf("����Ϊ��\n");
			}
			else {
				printf("����δ��\n");
			}
			break;
		case'5':
			if (GetHeadAQueue(aqueue_char, &temp, sizeof(char))) {
				printf("��ͷԪ��Ϊ%c\n", temp);
			}
			else {
				printf("����Ϊ��\n");
			}
			break;
		case'6':
			printf("���г���Ϊ%d\n", LengthAQueue(aqueue_char));
			break;
		case'7':
			if (TraverseAQueue(aqueue_char, APrint_char)) {
			}
			else {
				printf("����Ϊ��");
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
		printf("���������ǰ�����ֻ��ַ����в���\n");
		printf("1.���\n2.����\n3.�鿴�����Ƿ�Ϊ��\n4.�鿴��ͷԪ��\n");
		printf("5.�鿴���鳤��\n6.�������ȫ��Ԫ��\n7.��ն���\ne.�˳�����\n");
		scanf_s("%c",&input);
		switch (input) {
		case'1':
			printf("����������ݣ�");
			scanf_s("%lf", &temp);
			EnLQueue(lqueue_double, &temp, sizeof(double));
			break;
		case'2':DeLQueue(lqueue_double); break;
		case'3':
			if (IsEmptyLQueue(lqueue_double)) {
				printf("����Ϊ��\n");
			}
			else {
				printf("����δ��\n");
			}
			break;
		case'4':
			if (GetHeadLQueue(lqueue_double, &temp, sizeof(double))) {
				printf("��ͷԪ��Ϊ%lf\n", temp);
			}
			else {
				printf("����Ϊ��\n");
			}
			break;
		case'5':
			printf("���г���Ϊ%d\n", LengthLQueue(lqueue_double));
			break;
		case'6':
			if (TraverseLQueue(lqueue_double, APrint_double)) {
			}
			else {
				printf("����Ϊ��");
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
	printf("�����ɣ�a����ѭ�����С�b������ʽ���С�c�ַ���ѭ�����С�d��������ʽ����\n");
	printf("����������ǰ���ַ��Ը����ͽ�����Ӧ�Ĳ���,������e�˳�:\n");
	scanf_s("%c", &input);
	switch (input) {
	case 'a':faqueue_int(aqueue_int); break;
	case 'b':flqueue_int(lqueue_int); break;
	case 'c':faqueue_char(aqueue_char); break;
	case 'd':flqueue_double(lqueue_double); break;
	case 'e':return FALSE; break;
	default:printf("������������������\n");
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