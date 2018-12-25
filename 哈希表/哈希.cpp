//��ϣ��Ľ�����Ӧ��
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
typedef struct {
	char firstChar[15];
	int id;
	int value=0;//����������ƴ���������Ķ�Ӧ����ֵ 
}Name;
typedef struct {
	Name people[30];//�˵ĸ��� 
	int number;//��������Ϊ2 
	char* key[37];
}HashTable;
HashTable *initHashTable() {
	//��ʼ���˵������� 
	HashTable *start = (HashTable *)malloc(sizeof(HashTable));
	char *middle=nullptr;
	//���Ƚ�����ָ���ʼ��
	for(int j=0;j<37;j++)
		start->key[j] = NULL;
	int m = 0;
	for (int i = 0; i < 30; i++) {
		printf("�������%d��ͬѧ��������\n", i + 1);
		cin >> start->people[i].firstChar;
		printf("�������%d��ͬѧ��id��\n", i + 1);
		cin >> start->people[i].id;
		middle = start->people[i].firstChar;
		start->people[i].value = 0;
		while (*middle != '\0')
			start->people[i].value += *middle++;
		m = (start->people[i].value) % 36;
		while (start->key[m] != NULL)
			m = (m + 1) % 36;
		start->key[m] = start->people[i].firstChar;
	}
	return start;
}
void search(HashTable *start, char a[]) {
	//�������������Ӧ�ļ�ֵ 
	char *middle = a;
	int keyvalue = 0;
	while (*middle != '\0')
		keyvalue += *middle++;
	keyvalue = keyvalue % 36;
	//�Լ�ֵ���в��ң��ҵ���Ӧλ�ý��жԱȣ����������������������ѭ����ֱ�����ҵ��� 
	if (start->key[keyvalue] == NULL) {
		cout << "����ʧ��" << endl;
		return;
	}
	while (strcmp(start->key[keyvalue], a)!=0) {
		keyvalue++;
	}
	printf("���ҵ���,λ���ǣ�%d  \n", keyvalue);
}
int main() {
	HashTable *start = initHashTable();
	char a[10] ;
	for (;;) {
		printf("��������ҵ��˵�����\n");
		cin >> a;
		search(start, a);
	}
	return 0;
}