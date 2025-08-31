#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h>
#include <time.h>

typedef struct GOOD {
	char ID[100]; //���
	char NAME[100]; //��Ʒ��
	char sccj[200];//��������
	int kcl;//�����
	char scrq[200];//��������
	char bzq[100];//������
	char spfl[100];//��Ʒ����
	float cp;//�ɱ�
	float price;//�ۼ�
	float hyzk;//��Ա�ۿ�
	float hyzkfk;//��Ա����

} GOOD;

typedef struct person {
	char num[100]; //���
	char xm[100]; //����
	char sex[200];//�Ա�
	char birthday[200];//����
	char phone[100];//��ϵ��ʽ
	GOOD goods[100];
	GOOD goods2[100];
	int sum;
	int sum2;

} person;
GOOD goods[100];  //��Ʒ����100
person per[100];  //�ͻ�����100
void InputProduct();
int n=0;
int m=0;




int ShowMenu() {     //�˵���ʾʵ�ֽ���
	char c;
	do {
		system("cls");

		printf("\n");
		printf("\t\t-------------------���˵�-------------------\n");
		printf("\t\t      ���й���ϵͳ         \n");
		printf("\n");
		printf("\t\t    1. ��Ʒ��Ϣ����       2. �ͻ���Ϣ����        \n");
		printf("\t\t                               \n");
		printf("\t\t    3. ������Ʒ�Ǽ�       4. ��Ա�����ŻݵǼ�       \n");
		printf("\t\t                               \n");
		printf("\t\t    0. �˳�����                \n");
		printf("\t\t--------------------------------------------\n");
		printf("\t\t����ѡ��(0-4):");


		c = getchar();
	} while (c<'0' || c>='5');
	return (c - '0');
}

//*********************************************************************//
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//


void InputCustomer() {    //��ӻ�Ա��Ϣ

	char sign = 'y';
	char s[20];
	while (sign != 'n'&&sign != 'N') {
		int i=0;
		if(m==15) {
			printf("�洢�ռ��������޷�����������ݣ�\n");
			system("pause");
			return;
		}

		printf("��ţ�\n");
		scanf("%s",s);


		for( i=0; i<m; i++) {
			if(strcmp(per[i].num,s)==0) {
				printf("��������ظ���ȡ�����!\n");
				system("pause");  //ʵ����Ļ��ͣ
				return;
			}
		}
		strcpy(per[m].num,s);


		printf("������\n");
		scanf("%s",per[m].xm);

		printf("�Ա�\n");
		scanf("%s",per[m].sex);

		printf("���գ������ʽ��������1999.2.26��:\n");
		scanf("%s",per[m].birthday);

		printf("��ϵ��ʽ:\n");
		scanf("%s",per[m].phone);


		printf("�Ƿ�������?(y/n)");
		scanf("\t%c", &sign);
		m++;

	}
	system("pause");
}



void InputProduct() {    //�����Ʒ��Ϣ

	char sign = 'y';
	char s[20];
	while (sign != 'n'&&sign != 'N') {
		int i=0;
		if(n==15) {
			printf("�洢�ռ��������޷�����������ݣ�\n");
			system("pause");
			return;
		}

		printf("��ţ�\n");
		scanf("%s",s);


		for( i=0; i<n; i++) {
			if(strcmp(goods[i].ID,s)==0) {
				printf("��������ظ���ȡ�����!\n");
				system("pause");  //ʵ����Ļ��ͣ
				return;
			}
		}
		strcpy(goods[n].ID,s);


		printf("��Ʒ����\n");
		scanf("%s",goods[n].NAME);

		printf("�������ң�\n");
		scanf("%s",goods[n].sccj);

		printf("�����:\n");
		scanf("%d",&goods[n].kcl);

		printf("��������:\n");
		scanf("%s",goods[n].scrq);

		printf("������:\n");
		scanf("%s",goods[n].bzq);


		printf("��Ʒ����\n");
		scanf("%s",goods[n].spfl);

		printf("�ɱ�\n");
		scanf("%f",&goods[n].cp);

		printf("�ۼ�\n");
		scanf("%f",&goods[n].price);

		printf("�Ƿ�������?(y/n)");
		scanf("\t%c", &sign);
		n++;

	}
	system("pause");
}



void ShowCustomer() { //��ʾ��Ա��Ϣ
	printf("���\t����\t�Ա�\t����\t��ϵ��ʽ\n");
	for(int i=0; i<m; i++) {

		printf("%s\t%s\t%s\t%s\t%s\n",per[i].num,per[i].xm,per[i].sex,per[i].birthday,per[i].phone);

	}
	system("pause");

}

void ShowProduct() { //��ʾ��Ʒ��Ϣ
	printf("���\t��Ʒ��\t��������\t�����\t��������\t������\t��Ʒ����\t�ɱ�\t�ۼ�\n");
	for(int i=0; i<n; i++) {

		printf("%s\t%s\t%s\t%d\t%s\t%s\t%s\t%.2f\t%.2f\n",goods[i].ID,goods[i].NAME,goods[i].sccj,goods[i].kcl,goods[i].scrq,goods[i].bzq,goods[i].spfl,goods[i].cp,goods[i].price);
		if(goods[i].kcl==0) {
			printf("��Ҫ����������\n");
		}
	}
	system("pause");

}

void DeleteCustomer() { //ɾ������

	int i = 0;
	char sign='y';
	char ID[50];

	while (sign != 'n'&&sign != 'N')                    {
		printf(" ---------����ɾ��-----------\n");
		printf("��������\n");
		scanf("%s",ID);

		while (strcmp(per[i].num, ID)!= 0 && i<m) i++;


		if (i == m) {
			printf("\t��ѯʧ��!\n");
			system("pause");
			return;
		}

		if (i != m) {

			for(int j=i; j<n; j++) {
				per[j]=per[j+1];

			}
			m--;


		}
		printf("�Ƿ���Ҫ����?(y/n)");
		scanf("\t%c", &sign);
	}
	system("pause");

}

void DeleteProduct() { //ɾ������

	int i = 0;
	char sign='y';
	char ID[50];

	while (sign != 'n'&&sign != 'N')                    {
		printf(" ---------����ɾ��-----------\n");
		printf("��������\n");
		scanf("%s",ID);

		while (strcmp(goods[i].ID, ID)!= 0 && i<n) i++;


		if (i == n) {
			printf("\t��ѯʧ��!\n");
			system("pause");
			return;
		}

		if (i != n) {

			for(int j=i; j<n; j++) {
				goods[j]=goods[j+1];

			}
			n--;


		}
		printf("�Ƿ���Ҫ����?(y/n)");
		scanf("\t%c", &sign);
	}
	system("pause");

}


void ModifyProduct() { //�޸���Ʒ����

	char s[20];
	int i = 0;
	printf("\t���������ѯ�ı��:");
	scanf("\t%s", s);
	while (strcmp(per[i].num, s) != 0 && i<m) i++;            //�Ƚ�per[i].NAME����������Ʒ���Ƿ���ͬ//
	if (i == m) {
		printf("\t��ѯʧ��!\n");
		system("pause");
		return;
	}
	printf("����������Ҫ�޸ĵ���Ϣ:\n");
	printf("��Ʒ����\n");
	scanf("%s",goods[i].NAME);

	printf("�������ң�\n");
	scanf("%s",goods[i].sccj);

	printf("�����:\n");
	scanf("%d",&goods[i].kcl);

	printf("��������:\n");
	scanf("%s",goods[i].scrq);

	printf("������:\n");
	scanf("%s",goods[i].bzq);


	printf("��Ʒ����\n");
	scanf("%s",goods[i].spfl);

	printf("�ɱ�\n");
	scanf("%f",&goods[i].cp);

	printf("�ۼ�\n");
	scanf("%f",&goods[i].price);

	printf("\t�޸ĳɹ�����������!\n");
	system("pause");
}


void ModifyCustomer() { //�޸���Ա����


	char s[20];
	int i = 0;
	printf("\t���������ѯ�ı��:");
	scanf("\t%s", s);
	while (strcmp(goods[i].ID, s) != 0 && i<n) i++;            //�Ƚ�goods[i].NAME����������Ʒ���Ƿ���ͬ//
	if (i == n) {
		printf("\t��ѯʧ��!\n");
		system("pause");
		return;
	}
	printf("����������Ҫ�޸ĵ���Ϣ:\n");
	int mm;

	printf("\t\n��ѡ���޸ķ�ʽ:\n");
	printf("\t  1.�޸ı��    \n");
	printf("\t               \n");
	printf("\t  2.�޸�����	\n");
	printf("\t               \n");
	printf("\t  3.�޸��Ա�	\n");
	printf("\t              \n");
	printf("\t  4.�޸�����	\n");
	printf("\t               \n");
	printf("\t  5.�޸���ϵ��ʽ	\n");
	printf("\t               \n");
	printf("��������Ҫ��ѯ�ķ�ʽ\n");
	scanf("%d", &mm);
	while (mm != 1&& mm!=2&& mm!=3&& mm!=4&& mm!=5 ) {

		printf("������������²�ѯ\n");
		scanf("%d", &mm);
	}

	if (mm == 1) {
		printf("��ţ�\n");
		scanf("%s",per[i].num);
		printf("\t�޸ĳɹ�����������!\n");
	}
	if (mm == 2) {
		printf("������\n");
		scanf("%s",per[i].xm);
		printf("\t�޸ĳɹ�����������!\n");
	}
	if (mm == 3) {
		printf("�Ա�\n");
		scanf("%s",per[i].sex);
		printf("\t�޸ĳɹ�����������!\n");

	}
	if (mm == 4) {
		printf("����:\n");
		scanf("%s",per[i].birthday);
		printf("\t�޸ĳɹ�����������!\n");
	}
	if (mm == 5) {
		printf("��ϵ��ʽ:\n");
		scanf("%s",per[i].phone);
		printf("\t�޸ĳɹ�����������!\n");
	}


	system("pause");
}
void SearchCustomer() {

	char s[20];
	int i = 0;
	printf("\t���������ѯ�Ŀͻ����:");
	scanf("\t%s", s);
	int index=-1;
	printf("���\t����\t�Ա�\t����\t��ϵ��ʽ\n");

	for(i=0; i<m; i++) {
		if(strstr(per[i].num, s) != 0 ) {
			printf("%s\t%s\t%s\t%s\t%s\n",per[i].num,per[i].xm,per[i].sex,per[i].birthday,per[i].phone);
			index=1;
		}
	}
	if(index==-1) {
		printf("\t��ѯʧ��!\n");
		system("pause");
		return;
	}

	system("pause");



}
void SearchProduct() {
	int i;
	int mm;

	printf("\t\n��ѡ���ѯ��ʽ:\n");

	printf("\t  1.���ձ��    \n");
	printf("\t               \n");
	printf("\t  2.������������	\n");
	printf("\t               \n");

	printf("��������Ҫ��ѯ�ķ�ʽ\n");
	scanf("%d", &mm);
	while (mm != 1&& mm!=2 ) {

		printf("������������²�ѯ\n");
		scanf("%d", &mm);
	}


	if (mm == 1) {
		char s[20];
		int i = 0;
		printf("\t���������ѯ�ı��:");
		scanf("\t%s", s);
		int index=-1;
		printf("���\t��Ʒ��\t��������\t�����\t��������\t������\t��Ʒ����\t�ɱ�\t�ۼ�\n");

		for(i=0; i<n; i++) {
			if(strstr(goods[i].ID, s) != 0 ) {
				printf("%s\t%s\t%s\t%d\t%s\t%s\t%s\t%.2f\t%.2f\n",goods[i].ID,goods[i].NAME,goods[i].sccj,goods[i].kcl,goods[i].scrq,goods[i].bzq,goods[i].spfl,goods[i].cp,goods[i].price);
				index=1;
			}
		}
		if(index==-1) {
			printf("\t��ѯʧ��!\n");
			system("pause");
			return;
		}
		system("pause");



	}
	if (mm == 2) {
		char s[20];
		int i = 0;
		printf("\t���������ѯ����������:");
		scanf("\t%s", s);
		int index=-1;
		printf("���\t��Ʒ��\t��������\t�����\t��������\t������\t��Ʒ����\t�ɱ�\t�ۼ�\n");

		for(i=0; i<n; i++) {
			if(strstr(goods[i].sccj, s) != 0 ) {
				printf("%s\t%s\t%s\t%d\t%s\t%s\t%s\t%.2f\t%.2f\n",goods[i].ID,goods[i].NAME,goods[i].sccj,goods[i].kcl,goods[i].scrq,goods[i].bzq,goods[i].spfl,goods[i].cp,goods[i].price);
				index=1;
			}
		}
		if(index==-1) {
			printf("\t��ѯʧ��!\n");
			system("pause");
			return;
		}
		system("pause");
	}
}

void print1() { //��������

	printf("--------�ĵ�����ɹ�,д���ļ����-------\n");
	FILE *fpWrite=fopen("data.txt","w");
	if(fpWrite==NULL) {
		printf("Can't open the file!\n");
	}

	for( int i=0; i<n; i++) { //�����������������Ϣ
		fprintf(fpWrite,"%s\t%s\t%s\t%d\t%s\t%s\t%s\t%f\t%f\n",goods[i].ID,goods[i].NAME,goods[i].sccj,goods[i].kcl,goods[i].scrq,goods[i].bzq,goods[i].spfl,goods[i].cp,goods[i].price);

	}
	printf("���\t��Ʒ��\t��������\t�����\t��������\t������\t��Ʒ����\t�ɱ�\t�ۼ�\n");
	for(int i=0; i<n; i++) {

		printf("%s\t%s\t%s\t%d\t%s\t%s\t%s\t%.2f\t%.2f\n",goods[i].ID,goods[i].NAME,goods[i].sccj,goods[i].kcl,goods[i].scrq,goods[i].bzq,goods[i].spfl,goods[i].cp,goods[i].price);

	}

	fclose(fpWrite);
	system("pause");
}
void print2() { //��������

	printf("--------�ĵ�����ɹ�,д���ļ����-------\n");
	FILE *fpWrite=fopen("data2.txt","w");
	if(fpWrite==NULL) {
		printf("Can't open the file!\n");
	}

	for( int i=0; i<m; i++) { //�����������������Ϣ
		fprintf(fpWrite,"%s\t%s\t%s\t%s\t%s\n",per[i].num,per[i].xm,per[i].sex,per[i].birthday,per[i].phone);

	}
	printf("���\t����\t�Ա�\t����\t��ϵ��ʽ\n");
	for(int i=0; i<m; i++) {

		printf("%s\t%s\t%s\t%s\t%s\n",per[i].num,per[i].xm,per[i].sex,per[i].birthday,per[i].phone);

	}

	fclose(fpWrite);
	system("pause");
}
void read1() {

	int i;
	int j;
	int num1=0;
	FILE *fpRead=fopen("data.txt","a+");  //��ȡF1.txt�ļ�
	if(fpRead==NULL) {
		printf("�ļ���ʧ��!");
	}

	while((j=fgetc(fpRead))!=EOF) { //fgetc��ȡһ���ַ�����������β�᷵��EOF
		if(j=='\n') { //��ȡ���س���
			num1++;
		}
	}
	n=num1;
	FILE *fpRead2=fopen("data.txt","r");  //��ȡF1.txt�ļ�

	for( int i=0; i<n; i++) { //�����������������Ϣ
		fscanf(fpRead2,"%s\t%s\t%s\t%d\t%s\t%s\t%s\t%f\t%f\n",goods[i].ID,goods[i].NAME,goods[i].sccj,&goods[i].kcl,goods[i].scrq,goods[i].bzq,goods[i].spfl,&goods[i].cp,&goods[i].price);


	}


	printf("���\t��Ʒ��\t��������\t�����\t��������\t������\t��Ʒ����\t�ɱ�\t�ۼ�\n");
	for(int i=0; i<n; i++) {
		printf("%s\t%s\t%s\t%d\t%s\t%s\t%s\t%.2f\t%.2f\n",goods[i].ID,goods[i].NAME,goods[i].sccj,goods[i].kcl,goods[i].scrq,goods[i].bzq,goods[i].spfl,goods[i].cp,goods[i].price);

	}
	system("pause");  //ʵ����Ļ��ͣ
}

void read2() {

	int i;
	int j;
	int num1=0;
	FILE *fpRead3=fopen("data2.txt","a+");  //��ȡF1.txt�ļ�
	if(fpRead3==NULL) {
		printf("�ļ���ʧ��!");
	}

	while((j=fgetc(fpRead3))!=EOF) { //fgetc��ȡһ���ַ�����������β�᷵��EOF
		if(j=='\n') { //��ȡ���س���
			num1++;
		}
	}
	m=num1;
	FILE *fpRead4=fopen("data2.txt","r");  //��ȡF1.txt�ļ�

	for( int i=0; i<m; i++) { //�����������������Ϣ
		fscanf(fpRead4,"%s\t%s\t%s\t%s\t%s\n",per[i].num,per[i].xm,per[i].sex,per[i].birthday,per[i].phone);


	}


	printf("���\t����\t�Ա�\t����\t��ϵ��ʽ\n");
	for(int i=0; i<m ; i++) {
		printf("%s\t%s\t%s\t%s\t%s\n",per[i].num,per[i].xm,per[i].sex,per[i].birthday,per[i].phone);

	}
	system("pause");  //ʵ����Ļ��ͣ

}

void menu2() {
	while(1) {
		int index;
		printf("\t\t     �ͻ���Ϣ����         \n");
		printf("\n");
		printf("\t\t    1. ���ӿͻ�����       2. ɾ���ͻ�����        \n");
		printf("\t\t                               \n");
		printf("\t\t    3. �޸Ŀͻ�����       4. ���ҿͻ�����       \n");
		printf("\t\t                               \n");
		printf("\t\t    5. ����ͻ�����       6. ����������     \n");
		printf("\t\t                               \n");
		printf("\t\t                               \n");
		printf("\t\t    0. �˳�����                \n");
		scanf("%d",&index);
		if(index==1) {
			InputCustomer();
			print2();

		}
		if(index==2) {
			DeleteCustomer();
		}
		if(index==3) {
			ModifyCustomer();

		}
		if(index==4) {
			SearchCustomer();
		}
		if(index==5) {
			ShowCustomer();
		}
		if(index==6) {
			return;
		}
		if(index==0) {
			exit(0);
		}
	}

}
void menu1() {
	while(1) {
		int index;
		printf("\t\t     ��Ʒ��Ϣ����         \n");
		printf("\n");
		printf("\t\t    1. ������Ʒ����       2. ɾ����Ʒ����        \n");
		printf("\t\t                               \n");
		printf("\t\t    3. �޸���Ʒ����       4. ������Ʒ����       \n");
		printf("\t\t                               \n");
		printf("\t\t    5. �����Ʒ����       6. ����������     \n");
		printf("\t\t                               \n");
		printf("\t\t                               \n");
		printf("\t\t    0. �˳�����                \n");
		scanf("%d",&index);
		if(index==1) {
			InputProduct();
			print1();

		}
		if(index==2) {
			DeleteProduct();
		}
		if(index==3) {
			ModifyProduct();

		}
		if(index==4) {
			SearchProduct();
		}
		if(index==5) {
			ShowProduct();
		}
		if(index==6) {
			return;
		}
		if(index==0) {
			exit(0);
		}
	}

}


void HYbuy() {

	int mm;
	int flag;
	printf("\t\n��ѡ����ʽ:\n");

	printf("\t  1.��Ա����Ǽ�    \n");
	printf("\t               \n");
	printf("\t  2.������Ȩ����	\n");
	printf("\t               \n");

	printf("��������Ҫ��ѯ�ķ�ʽ\n");
	scanf("%d", &mm);
	while (mm != 1&& mm!=2 ) {

		printf("������������²�ѯ\n");
		scanf("%d", &mm);
	}


	if (mm == 1) {
		int flagg;
		int i;
		printf("���\t��Ʒ��\t��������\t�����\t��������\t������\t��Ʒ����\t�ɱ�\t�ۼ�\n");
		for( i=0; i<n; i++) {
			printf("%s\t%s\t%s\t%d\t%s\t%s\t%s\t%.2f\t%.2f\n",goods[i].ID,goods[i].NAME,goods[i].sccj,goods[i].kcl,goods[i].scrq,goods[i].bzq,goods[i].spfl,goods[i].cp,goods[i].price);
		}
		char s[20];
		i=0;
		printf("\t�������빺��ı��:");
		scanf("\t%s", s);
		int index=-1;
		printf("���\t��Ʒ��\t��������\t�����\t��������\t������\t��Ʒ����\t�ɱ�\t�ۼ�\n");

		for(i=0; i<n; i++) {
			if(strcmp(goods[i].ID, s) == 0 ) {
				printf("%s\t%s\t%s\t%d\t%s\t%s\t%s\t%.2f\t%.2f\n",goods[i].ID,goods[i].NAME,goods[i].sccj,goods[i].kcl,goods[i].scrq,goods[i].bzq,goods[i].spfl,goods[i].cp,goods[i].price);
				index=1;
				flagg=i;
			}
		}
		if(index==-1) {
			printf("\t��ѯʧ��!\n");
			system("pause");
			return;
		}

		char ID[20];
		printf("������ͻ����\n");
		scanf("%s",ID);
		int j=0;
		while (strcmp(per[j].num, ID)!= 0 && j<m) j++;


		if (j == m) {
			printf("\t��ѯʧ��!\n");
			system("pause");
			return;
		}
		goods[flagg].kcl--;

		printf("�������ۿ���Ϣ������8��������0.8��\n");
		scanf("%f",&goods[flagg].hyzk);


		per[j].goods2[per[j].sum]=goods[flagg];
		per[j].sum2++;

		printf("\t����ɹ�������Ա����Ǽ����£�!\n");
		printf("���\t��Ʒ��\t��������\t�����\t��������\t������\t��Ʒ����\t�ɱ�\t�ۼ�\t�ۿ�\n");
		printf("%s\t%s\t%s\t%d\t%s\t%s\t%s\t%.2f\t%.2f\t%.2f\n",goods[flagg].ID,goods[flagg].NAME,goods[flagg].sccj,goods[flagg].kcl,goods[flagg].scrq,goods[flagg].bzq,goods[flagg].spfl,goods[flagg].cp,goods[flagg].price*goods[flagg].hyzk,goods[flagg].hyzk);
		system("pause");
	}
	if (mm == 2) {
		int i;
		int flagg;
		printf("���\t��Ʒ��\t��������\t�����\t��������\t������\t��Ʒ����\t�ɱ�\t�ۼ�\n");
		for( i=0; i<n; i++) {
			printf("%s\t%s\t%s\t%d\t%s\t%s\t%s\t%.2f\t%.2f\n",goods[i].ID,goods[i].NAME,goods[i].sccj,goods[i].kcl,goods[i].scrq,goods[i].bzq,goods[i].spfl,goods[i].cp,goods[i].price);
		}
		char s[20];
		i=0;
		printf("\t�������빺��ı��:");
		scanf("\t%s", s);
		int index=-1;
		printf("���\t��Ʒ��\t��������\t�����\t��������\t������\t��Ʒ����\t�ɱ�\t�ۼ�\n");

		for(i=0; i<n; i++) {
			if(strcmp(goods[i].ID, s) == 0 ) {
				printf("%s\t%s\t%s\t%d\t%s\t%s\t%s\t%.2f\t%.2f\n",goods[i].ID,goods[i].NAME,goods[i].sccj,goods[i].kcl,goods[i].scrq,goods[i].bzq,goods[i].spfl,goods[i].cp,goods[i].price);
				index=1;
				flagg=i;
			}
		}
		if(index==-1) {
			printf("\t��ѯʧ��!\n");
			system("pause");
			return;
		}

		char ID[20];
		printf("������ͻ����\n");
		scanf("%s",ID);
		int j=0;
		while (strcmp(per[j].num, ID)!= 0 && j<m) j++;


		if (j == m) {
			printf("\t��ѯʧ��!\n");
			system("pause");
			return;
		}

		time_t timep;

		struct tm *p;

		char time1[28];

		time (&timep);

		p=gmtime(&timep);

		sprintf(time1,"%d.%d.%d",1900+p->tm_year,1+p->tm_mon,p->tm_mday);
//		printf("%s",time1);
		if(strcmp(per[j].birthday,time1)==0) {
			printf("�Ƿ�ʹ��������Ȩ�ۿۣ�4�ۣ�������1/0:\n");
			scanf("%d",&flag) ;
			if(flag==0) {
				printf("�������ۿ���Ϣ������8��������0.8������8�ۣ�\n");
				scanf("%f",&goods[flagg].hyzk);
			} else {
				goods[flagg].hyzk=0.4;
			}
		}
		goods[flagg].kcl--;



		per[j].goods2[per[j].sum2]=goods[flagg];
		per[j].sum2++;

		printf("\t����ɹ���������Ǽ����£�!\n");
		printf("���\t��Ʒ��\t��������\t�����\t��������\t������\t��Ʒ����\t�ɱ�\t�ۼ�\t�ۿ�\n");

		printf("%s\t%s\t%s\t%d\t%s\t%s\t%s\t%.2f\t%.2f\t%.2f\n",goods[flagg].ID,goods[flagg].NAME,goods[flagg].sccj,goods[flagg].kcl,goods[flagg].scrq,goods[flagg].bzq,goods[flagg].spfl,goods[flagg].cp,goods[flagg].price*goods[flagg].hyzk,goods[flagg].hyzk);
		system("pause");
	}

}

void buy() {
	int i;
	printf("���\t��Ʒ��\t��������\t�����\t��������\t������\t��Ʒ����\t�ɱ�\t�ۼ�\n");
	for( i=0; i<n; i++) {
		printf("%s\t%s\t%s\t%d\t%s\t%s\t%s\t%.2f\t%.2f\n",goods[i].ID,goods[i].NAME,goods[i].sccj,goods[i].kcl,goods[i].scrq,goods[i].bzq,goods[i].spfl,goods[i].cp,goods[i].price);
	}
	char s[20];
	i=0;
	printf("\t�������빺��ı��:");
	scanf("\t%s", s);
	int index=-1;
	printf("���\t��Ʒ��\t��������\t�����\t��������\t������\t��Ʒ����\t�ɱ�\t�ۼ�\n");
	int flag;
	for(i=0; i<n; i++) {
		if(strstr(goods[i].ID, s) != 0 ) {
			printf("%s\t%s\t%s\t%d\t%s\t%s\t%s\t%.2f\t%.2f\n",goods[i].ID,goods[i].NAME,goods[i].sccj,goods[i].kcl,goods[i].scrq,goods[i].bzq,goods[i].spfl,goods[i].cp,goods[i].price);
			index=1;
			flag=i;
		}
	}
	if(index==-1) {
		printf("\t��ѯʧ��!\n");
		system("pause");
		return;
	}

	char ID[20];
	printf("������ͻ����\n");
	scanf("%s",ID);
	int j=0;
	while (strcmp(per[j].num, ID)!= 0 && j<m) j++;
    printf("\t���ι����˱��Ϊ:%s\n\t����:%s\n",ID,per[j].xm);

	if (j == m) {
		printf("\t��ѯʧ��!\n");
		system("pause");
		return;
	}
	goods[flag].kcl--;
	per[j].goods[per[j].sum]=goods[flag];
	per[j].sum++;

	printf("\t����ɹ������������Ʒ��ϢΪ��!\n");
	printf("���\t��Ʒ��\t��������\t�����\t��������\t������\t��Ʒ����\t�ɱ�\t�ۼ�\n");
	goods[flag].kcl--;
	printf("%s\t%s\t%s\t%d\t%s\t%s\t%s\t%.2f\t%.2f\n",goods[flag].ID,goods[flag].NAME,goods[flag].sccj,goods[flag].kcl,goods[flag].scrq,goods[flag].bzq,goods[flag].spfl,goods[flag].cp,goods[flag].price);
	system("pause");


}

int main() {
	read1();
	read2();
	char sign;

	while (sign != 'n'&&sign != 'N')      {


		for (;;) {

			switch (ShowMenu()) {

				case 1: {

					menu1();
					break;
				}
				case 2: {
					menu2();
					break;
				}
				case 3: {

					buy();
					break;
				}
				case 4: {

					HYbuy();
					break;
				}



				case 0: {

					printf("ϵͳ����\n");
					exit(0);
				}

			}

		}

	}

	return 0;

}
