//哈希表的建立于应用
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
typedef struct {
	char firstChar[15];
	int id;
	int value=0;//根据姓名（拼音）产生的对应的数值 
}Name;
typedef struct {
	Name people[30];//人的个数 
	int number;//查找上限为2 
	char* key[37];
}HashTable;
HashTable *initHashTable() {
	//初始化人的姓名； 
	HashTable *start = (HashTable *)malloc(sizeof(HashTable));
	char *middle=nullptr;
	//首先将所有指针初始化
	for(int j=0;j<37;j++)
		start->key[j] = NULL;
	int m = 0;
	for (int i = 0; i < 30; i++) {
		printf("请输入第%d名同学的姓名：\n", i + 1);
		cin >> start->people[i].firstChar;
		printf("请输入第%d名同学的id：\n", i + 1);
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
	//计算该名称所对应的键值 
	char *middle = a;
	int keyvalue = 0;
	while (*middle != '\0')
		keyvalue += *middle++;
	keyvalue = keyvalue % 36;
	//对键值进行查找，找到对应位置进行对比，如果满足输出，不满足进行循环，直到查找到。 
	if (start->key[keyvalue] == NULL) {
		cout << "查找失败" << endl;
		return;
	}
	while (strcmp(start->key[keyvalue], a)!=0) {
		keyvalue++;
	}
	printf("查找到了,位置是：%d  \n", keyvalue);
}
int main() {
	HashTable *start = initHashTable();
	char a[10] ;
	for (;;) {
		printf("请输入查找的人的姓名\n");
		cin >> a;
		search(start, a);
	}
	return 0;
}