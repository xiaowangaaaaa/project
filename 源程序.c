#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h>
#include <time.h>

typedef struct GOOD {
	char ID[100]; //编号
	char NAME[100]; //商品名
	char sccj[200];//生产厂家
	int kcl;//库存量
	char scrq[200];//生产日期
	char bzq[100];//保质期
	char spfl[100];//商品分类
	float cp;//成本
	float price;//售价
	float hyzk;//会员折扣
	float hyzkfk;//会员付款

} GOOD;

typedef struct person {
	char num[100]; //编号
	char xm[100]; //姓名
	char sex[200];//性别
	char birthday[200];//生日
	char phone[100];//联系方式
	GOOD goods[100];
	GOOD goods2[100];
	int sum;
	int sum2;

} person;
GOOD goods[100];  //商品定义100
person per[100];  //客户定义100
void InputProduct();
int n=0;
int m=0;




int ShowMenu() {     //菜单显示实现交互
	char c;
	do {
		system("cls");

		printf("\n");
		printf("\t\t-------------------主菜单-------------------\n");
		printf("\t\t      超市管理系统         \n");
		printf("\n");
		printf("\t\t    1. 商品信息管理       2. 客户信息管理        \n");
		printf("\t\t                               \n");
		printf("\t\t    3. 购买商品登记       4. 会员打折优惠登记       \n");
		printf("\t\t                               \n");
		printf("\t\t    0. 退出程序                \n");
		printf("\t\t--------------------------------------------\n");
		printf("\t\t请您选择(0-4):");


		c = getchar();
	} while (c<'0' || c>='5');
	return (c - '0');
}

//*********************************************************************//
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//


void InputCustomer() {    //添加会员信息

	char sign = 'y';
	char s[20];
	while (sign != 'n'&&sign != 'N') {
		int i=0;
		if(m==15) {
			printf("存储空间已满！无法继续添加数据！\n");
			system("pause");
			return;
		}

		printf("编号：\n");
		scanf("%s",s);


		for( i=0; i<m; i++) {
			if(strcmp(per[i].num,s)==0) {
				printf("数据添加重复并取消添加!\n");
				system("pause");  //实现屏幕暂停
				return;
			}
		}
		strcpy(per[m].num,s);


		printf("姓名：\n");
		scanf("%s",per[m].xm);

		printf("性别：\n");
		scanf("%s",per[m].sex);

		printf("生日（输入格式如下例如1999.2.26）:\n");
		scanf("%s",per[m].birthday);

		printf("联系方式:\n");
		scanf("%s",per[m].phone);


		printf("是否继续添加?(y/n)");
		scanf("\t%c", &sign);
		m++;

	}
	system("pause");
}



void InputProduct() {    //添加商品信息

	char sign = 'y';
	char s[20];
	while (sign != 'n'&&sign != 'N') {
		int i=0;
		if(n==15) {
			printf("存储空间已满！无法继续添加数据！\n");
			system("pause");
			return;
		}

		printf("编号：\n");
		scanf("%s",s);


		for( i=0; i<n; i++) {
			if(strcmp(goods[i].ID,s)==0) {
				printf("数据添加重复并取消添加!\n");
				system("pause");  //实现屏幕暂停
				return;
			}
		}
		strcpy(goods[n].ID,s);


		printf("商品名：\n");
		scanf("%s",goods[n].NAME);

		printf("生产厂家：\n");
		scanf("%s",goods[n].sccj);

		printf("库存量:\n");
		scanf("%d",&goods[n].kcl);

		printf("生产日期:\n");
		scanf("%s",goods[n].scrq);

		printf("保质期:\n");
		scanf("%s",goods[n].bzq);


		printf("商品分类\n");
		scanf("%s",goods[n].spfl);

		printf("成本\n");
		scanf("%f",&goods[n].cp);

		printf("售价\n");
		scanf("%f",&goods[n].price);

		printf("是否继续添加?(y/n)");
		scanf("\t%c", &sign);
		n++;

	}
	system("pause");
}



void ShowCustomer() { //显示人员信息
	printf("编号\t姓名\t性别\t生日\t联系方式\n");
	for(int i=0; i<m; i++) {

		printf("%s\t%s\t%s\t%s\t%s\n",per[i].num,per[i].xm,per[i].sex,per[i].birthday,per[i].phone);

	}
	system("pause");

}

void ShowProduct() { //显示商品信息
	printf("编号\t商品名\t生产厂家\t库存量\t生产日期\t保质期\t商品分类\t成本\t售价\n");
	for(int i=0; i<n; i++) {

		printf("%s\t%s\t%s\t%d\t%s\t%s\t%s\t%.2f\t%.2f\n",goods[i].ID,goods[i].NAME,goods[i].sccj,goods[i].kcl,goods[i].scrq,goods[i].bzq,goods[i].spfl,goods[i].cp,goods[i].price);
		if(goods[i].kcl==0) {
			printf("需要补货！！！\n");
		}
	}
	system("pause");

}

void DeleteCustomer() { //删除数据

	int i = 0;
	char sign='y';
	char ID[50];

	while (sign != 'n'&&sign != 'N')                    {
		printf(" ---------数据删除-----------\n");
		printf("请输入编号\n");
		scanf("%s",ID);

		while (strcmp(per[i].num, ID)!= 0 && i<m) i++;


		if (i == m) {
			printf("\t查询失败!\n");
			system("pause");
			return;
		}

		if (i != m) {

			for(int j=i; j<n; j++) {
				per[j]=per[j+1];

			}
			m--;


		}
		printf("是否需要继续?(y/n)");
		scanf("\t%c", &sign);
	}
	system("pause");

}

void DeleteProduct() { //删除数据

	int i = 0;
	char sign='y';
	char ID[50];

	while (sign != 'n'&&sign != 'N')                    {
		printf(" ---------数据删除-----------\n");
		printf("请输入编号\n");
		scanf("%s",ID);

		while (strcmp(goods[i].ID, ID)!= 0 && i<n) i++;


		if (i == n) {
			printf("\t查询失败!\n");
			system("pause");
			return;
		}

		if (i != n) {

			for(int j=i; j<n; j++) {
				goods[j]=goods[j+1];

			}
			n--;


		}
		printf("是否需要继续?(y/n)");
		scanf("\t%c", &sign);
	}
	system("pause");

}


void ModifyProduct() { //修改商品数据

	char s[20];
	int i = 0;
	printf("\t请输入想查询的编号:");
	scanf("\t%s", s);
	while (strcmp(per[i].num, s) != 0 && i<m) i++;            //比较per[i].NAME与所输入商品名是否相同//
	if (i == m) {
		printf("\t查询失败!\n");
		system("pause");
		return;
	}
	printf("请重新输入要修改的信息:\n");
	printf("商品名：\n");
	scanf("%s",goods[i].NAME);

	printf("生产厂家：\n");
	scanf("%s",goods[i].sccj);

	printf("库存量:\n");
	scanf("%d",&goods[i].kcl);

	printf("生产日期:\n");
	scanf("%s",goods[i].scrq);

	printf("保质期:\n");
	scanf("%s",goods[i].bzq);


	printf("商品分类\n");
	scanf("%s",goods[i].spfl);

	printf("成本\n");
	scanf("%f",&goods[i].cp);

	printf("售价\n");
	scanf("%f",&goods[i].price);

	printf("\t修改成功！！！！！!\n");
	system("pause");
}


void ModifyCustomer() { //修改人员数据


	char s[20];
	int i = 0;
	printf("\t请输入想查询的编号:");
	scanf("\t%s", s);
	while (strcmp(goods[i].ID, s) != 0 && i<n) i++;            //比较goods[i].NAME与所输入商品名是否相同//
	if (i == n) {
		printf("\t查询失败!\n");
		system("pause");
		return;
	}
	printf("请重新输入要修改的信息:\n");
	int mm;

	printf("\t\n请选择修改方式:\n");
	printf("\t  1.修改编号    \n");
	printf("\t               \n");
	printf("\t  2.修改姓名	\n");
	printf("\t               \n");
	printf("\t  3.修改性别	\n");
	printf("\t              \n");
	printf("\t  4.修改生日	\n");
	printf("\t               \n");
	printf("\t  5.修改联系方式	\n");
	printf("\t               \n");
	printf("请输入你要查询的方式\n");
	scanf("%d", &mm);
	while (mm != 1&& mm!=2&& mm!=3&& mm!=4&& mm!=5 ) {

		printf("输入错误请重新查询\n");
		scanf("%d", &mm);
	}

	if (mm == 1) {
		printf("编号：\n");
		scanf("%s",per[i].num);
		printf("\t修改成功！！！！！!\n");
	}
	if (mm == 2) {
		printf("姓名：\n");
		scanf("%s",per[i].xm);
		printf("\t修改成功！！！！！!\n");
	}
	if (mm == 3) {
		printf("性别：\n");
		scanf("%s",per[i].sex);
		printf("\t修改成功！！！！！!\n");

	}
	if (mm == 4) {
		printf("生日:\n");
		scanf("%s",per[i].birthday);
		printf("\t修改成功！！！！！!\n");
	}
	if (mm == 5) {
		printf("联系方式:\n");
		scanf("%s",per[i].phone);
		printf("\t修改成功！！！！！!\n");
	}


	system("pause");
}
void SearchCustomer() {

	char s[20];
	int i = 0;
	printf("\t请输入想查询的客户编号:");
	scanf("\t%s", s);
	int index=-1;
	printf("编号\t姓名\t性别\t生日\t联系方式\n");

	for(i=0; i<m; i++) {
		if(strstr(per[i].num, s) != 0 ) {
			printf("%s\t%s\t%s\t%s\t%s\n",per[i].num,per[i].xm,per[i].sex,per[i].birthday,per[i].phone);
			index=1;
		}
	}
	if(index==-1) {
		printf("\t查询失败!\n");
		system("pause");
		return;
	}

	system("pause");



}
void SearchProduct() {
	int i;
	int mm;

	printf("\t\n请选择查询方式:\n");

	printf("\t  1.按照编号    \n");
	printf("\t               \n");
	printf("\t  2.按照生产厂家	\n");
	printf("\t               \n");

	printf("请输入你要查询的方式\n");
	scanf("%d", &mm);
	while (mm != 1&& mm!=2 ) {

		printf("输入错误请重新查询\n");
		scanf("%d", &mm);
	}


	if (mm == 1) {
		char s[20];
		int i = 0;
		printf("\t请输入想查询的编号:");
		scanf("\t%s", s);
		int index=-1;
		printf("编号\t商品名\t生产厂家\t库存量\t生产日期\t保质期\t商品分类\t成本\t售价\n");

		for(i=0; i<n; i++) {
			if(strstr(goods[i].ID, s) != 0 ) {
				printf("%s\t%s\t%s\t%d\t%s\t%s\t%s\t%.2f\t%.2f\n",goods[i].ID,goods[i].NAME,goods[i].sccj,goods[i].kcl,goods[i].scrq,goods[i].bzq,goods[i].spfl,goods[i].cp,goods[i].price);
				index=1;
			}
		}
		if(index==-1) {
			printf("\t查询失败!\n");
			system("pause");
			return;
		}
		system("pause");



	}
	if (mm == 2) {
		char s[20];
		int i = 0;
		printf("\t请输入想查询的生产厂家:");
		scanf("\t%s", s);
		int index=-1;
		printf("编号\t商品名\t生产厂家\t库存量\t生产日期\t保质期\t商品分类\t成本\t售价\n");

		for(i=0; i<n; i++) {
			if(strstr(goods[i].sccj, s) != 0 ) {
				printf("%s\t%s\t%s\t%d\t%s\t%s\t%s\t%.2f\t%.2f\n",goods[i].ID,goods[i].NAME,goods[i].sccj,goods[i].kcl,goods[i].scrq,goods[i].bzq,goods[i].spfl,goods[i].cp,goods[i].price);
				index=1;
			}
		}
		if(index==-1) {
			printf("\t查询失败!\n");
			system("pause");
			return;
		}
		system("pause");
	}
}

void print1() { //保存数据

	printf("--------文档保存成功,写入文件完毕-------\n");
	FILE *fpWrite=fopen("data.txt","w");
	if(fpWrite==NULL) {
		printf("Can't open the file!\n");
	}

	for( int i=0; i<n; i++) { //遍历所有输出所有信息
		fprintf(fpWrite,"%s\t%s\t%s\t%d\t%s\t%s\t%s\t%f\t%f\n",goods[i].ID,goods[i].NAME,goods[i].sccj,goods[i].kcl,goods[i].scrq,goods[i].bzq,goods[i].spfl,goods[i].cp,goods[i].price);

	}
	printf("编号\t商品名\t生产厂家\t库存量\t生产日期\t保质期\t商品分类\t成本\t售价\n");
	for(int i=0; i<n; i++) {

		printf("%s\t%s\t%s\t%d\t%s\t%s\t%s\t%.2f\t%.2f\n",goods[i].ID,goods[i].NAME,goods[i].sccj,goods[i].kcl,goods[i].scrq,goods[i].bzq,goods[i].spfl,goods[i].cp,goods[i].price);

	}

	fclose(fpWrite);
	system("pause");
}
void print2() { //保存数据

	printf("--------文档保存成功,写入文件完毕-------\n");
	FILE *fpWrite=fopen("data2.txt","w");
	if(fpWrite==NULL) {
		printf("Can't open the file!\n");
	}

	for( int i=0; i<m; i++) { //遍历所有输出所有信息
		fprintf(fpWrite,"%s\t%s\t%s\t%s\t%s\n",per[i].num,per[i].xm,per[i].sex,per[i].birthday,per[i].phone);

	}
	printf("编号\t姓名\t性别\t生日\t联系方式\n");
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
	FILE *fpRead=fopen("data.txt","a+");  //读取F1.txt文件
	if(fpRead==NULL) {
		printf("文件打开失败!");
	}

	while((j=fgetc(fpRead))!=EOF) { //fgetc读取一个字符，当读到结尾会返回EOF
		if(j=='\n') { //读取到回车符
			num1++;
		}
	}
	n=num1;
	FILE *fpRead2=fopen("data.txt","r");  //读取F1.txt文件

	for( int i=0; i<n; i++) { //遍历所有输出所有信息
		fscanf(fpRead2,"%s\t%s\t%s\t%d\t%s\t%s\t%s\t%f\t%f\n",goods[i].ID,goods[i].NAME,goods[i].sccj,&goods[i].kcl,goods[i].scrq,goods[i].bzq,goods[i].spfl,&goods[i].cp,&goods[i].price);


	}


	printf("编号\t商品名\t生产厂家\t库存量\t生产日期\t保质期\t商品分类\t成本\t售价\n");
	for(int i=0; i<n; i++) {
		printf("%s\t%s\t%s\t%d\t%s\t%s\t%s\t%.2f\t%.2f\n",goods[i].ID,goods[i].NAME,goods[i].sccj,goods[i].kcl,goods[i].scrq,goods[i].bzq,goods[i].spfl,goods[i].cp,goods[i].price);

	}
	system("pause");  //实现屏幕暂停
}

void read2() {

	int i;
	int j;
	int num1=0;
	FILE *fpRead3=fopen("data2.txt","a+");  //读取F1.txt文件
	if(fpRead3==NULL) {
		printf("文件打开失败!");
	}

	while((j=fgetc(fpRead3))!=EOF) { //fgetc读取一个字符，当读到结尾会返回EOF
		if(j=='\n') { //读取到回车符
			num1++;
		}
	}
	m=num1;
	FILE *fpRead4=fopen("data2.txt","r");  //读取F1.txt文件

	for( int i=0; i<m; i++) { //遍历所有输出所有信息
		fscanf(fpRead4,"%s\t%s\t%s\t%s\t%s\n",per[i].num,per[i].xm,per[i].sex,per[i].birthday,per[i].phone);


	}


	printf("编号\t姓名\t性别\t生日\t联系方式\n");
	for(int i=0; i<m ; i++) {
		printf("%s\t%s\t%s\t%s\t%s\n",per[i].num,per[i].xm,per[i].sex,per[i].birthday,per[i].phone);

	}
	system("pause");  //实现屏幕暂停

}

void menu2() {
	while(1) {
		int index;
		printf("\t\t     客户信息管理         \n");
		printf("\n");
		printf("\t\t    1. 增加客户功能       2. 删除客户功能        \n");
		printf("\t\t                               \n");
		printf("\t\t    3. 修改客户功能       4. 查找客户功能       \n");
		printf("\t\t                               \n");
		printf("\t\t    5. 浏览客户功能       6. 返回主界面     \n");
		printf("\t\t                               \n");
		printf("\t\t                               \n");
		printf("\t\t    0. 退出程序                \n");
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
		printf("\t\t     商品信息管理         \n");
		printf("\n");
		printf("\t\t    1. 增加商品功能       2. 删除商品功能        \n");
		printf("\t\t                               \n");
		printf("\t\t    3. 修改商品功能       4. 查找商品功能       \n");
		printf("\t\t                               \n");
		printf("\t\t    5. 浏览商品功能       6. 返回主界面     \n");
		printf("\t\t                               \n");
		printf("\t\t                               \n");
		printf("\t\t    0. 退出程序                \n");
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
	printf("\t\n请选择购买方式:\n");

	printf("\t  1.会员购买登记    \n");
	printf("\t               \n");
	printf("\t  2.生日特权购买	\n");
	printf("\t               \n");

	printf("请输入你要查询的方式\n");
	scanf("%d", &mm);
	while (mm != 1&& mm!=2 ) {

		printf("输入错误请重新查询\n");
		scanf("%d", &mm);
	}


	if (mm == 1) {
		int flagg;
		int i;
		printf("编号\t商品名\t生产厂家\t库存量\t生产日期\t保质期\t商品分类\t成本\t售价\n");
		for( i=0; i<n; i++) {
			printf("%s\t%s\t%s\t%d\t%s\t%s\t%s\t%.2f\t%.2f\n",goods[i].ID,goods[i].NAME,goods[i].sccj,goods[i].kcl,goods[i].scrq,goods[i].bzq,goods[i].spfl,goods[i].cp,goods[i].price);
		}
		char s[20];
		i=0;
		printf("\t请输入想购买的编号:");
		scanf("\t%s", s);
		int index=-1;
		printf("编号\t商品名\t生产厂家\t库存量\t生产日期\t保质期\t商品分类\t成本\t售价\n");

		for(i=0; i<n; i++) {
			if(strcmp(goods[i].ID, s) == 0 ) {
				printf("%s\t%s\t%s\t%d\t%s\t%s\t%s\t%.2f\t%.2f\n",goods[i].ID,goods[i].NAME,goods[i].sccj,goods[i].kcl,goods[i].scrq,goods[i].bzq,goods[i].spfl,goods[i].cp,goods[i].price);
				index=1;
				flagg=i;
			}
		}
		if(index==-1) {
			printf("\t查询失败!\n");
			system("pause");
			return;
		}

		char ID[20];
		printf("请输入客户编号\n");
		scanf("%s",ID);
		int j=0;
		while (strcmp(per[j].num, ID)!= 0 && j<m) j++;


		if (j == m) {
			printf("\t查询失败!\n");
			system("pause");
			return;
		}
		goods[flagg].kcl--;

		printf("请输入折扣信息（例打8折则输入0.8）\n");
		scanf("%f",&goods[flagg].hyzk);


		per[j].goods2[per[j].sum]=goods[flagg];
		per[j].sum2++;

		printf("\t购买成功！！会员购买登记如下：!\n");
		printf("编号\t商品名\t生产厂家\t库存量\t生产日期\t保质期\t商品分类\t成本\t售价\t折扣\n");
		printf("%s\t%s\t%s\t%d\t%s\t%s\t%s\t%.2f\t%.2f\t%.2f\n",goods[flagg].ID,goods[flagg].NAME,goods[flagg].sccj,goods[flagg].kcl,goods[flagg].scrq,goods[flagg].bzq,goods[flagg].spfl,goods[flagg].cp,goods[flagg].price*goods[flagg].hyzk,goods[flagg].hyzk);
		system("pause");
	}
	if (mm == 2) {
		int i;
		int flagg;
		printf("编号\t商品名\t生产厂家\t库存量\t生产日期\t保质期\t商品分类\t成本\t售价\n");
		for( i=0; i<n; i++) {
			printf("%s\t%s\t%s\t%d\t%s\t%s\t%s\t%.2f\t%.2f\n",goods[i].ID,goods[i].NAME,goods[i].sccj,goods[i].kcl,goods[i].scrq,goods[i].bzq,goods[i].spfl,goods[i].cp,goods[i].price);
		}
		char s[20];
		i=0;
		printf("\t请输入想购买的编号:");
		scanf("\t%s", s);
		int index=-1;
		printf("编号\t商品名\t生产厂家\t库存量\t生产日期\t保质期\t商品分类\t成本\t售价\n");

		for(i=0; i<n; i++) {
			if(strcmp(goods[i].ID, s) == 0 ) {
				printf("%s\t%s\t%s\t%d\t%s\t%s\t%s\t%.2f\t%.2f\n",goods[i].ID,goods[i].NAME,goods[i].sccj,goods[i].kcl,goods[i].scrq,goods[i].bzq,goods[i].spfl,goods[i].cp,goods[i].price);
				index=1;
				flagg=i;
			}
		}
		if(index==-1) {
			printf("\t查询失败!\n");
			system("pause");
			return;
		}

		char ID[20];
		printf("请输入客户编号\n");
		scanf("%s",ID);
		int j=0;
		while (strcmp(per[j].num, ID)!= 0 && j<m) j++;


		if (j == m) {
			printf("\t查询失败!\n");
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
			printf("是否使用生日特权折扣（4折）请输入1/0:\n");
			scanf("%d",&flag) ;
			if(flag==0) {
				printf("请输入折扣信息（例打8折则输入0.8不超过8折）\n");
				scanf("%f",&goods[flagg].hyzk);
			} else {
				goods[flagg].hyzk=0.4;
			}
		}
		goods[flagg].kcl--;



		per[j].goods2[per[j].sum2]=goods[flagg];
		per[j].sum2++;

		printf("\t购买成功！！购买登记如下：!\n");
		printf("编号\t商品名\t生产厂家\t库存量\t生产日期\t保质期\t商品分类\t成本\t售价\t折扣\n");

		printf("%s\t%s\t%s\t%d\t%s\t%s\t%s\t%.2f\t%.2f\t%.2f\n",goods[flagg].ID,goods[flagg].NAME,goods[flagg].sccj,goods[flagg].kcl,goods[flagg].scrq,goods[flagg].bzq,goods[flagg].spfl,goods[flagg].cp,goods[flagg].price*goods[flagg].hyzk,goods[flagg].hyzk);
		system("pause");
	}

}

void buy() {
	int i;
	printf("编号\t商品名\t生产厂家\t库存量\t生产日期\t保质期\t商品分类\t成本\t售价\n");
	for( i=0; i<n; i++) {
		printf("%s\t%s\t%s\t%d\t%s\t%s\t%s\t%.2f\t%.2f\n",goods[i].ID,goods[i].NAME,goods[i].sccj,goods[i].kcl,goods[i].scrq,goods[i].bzq,goods[i].spfl,goods[i].cp,goods[i].price);
	}
	char s[20];
	i=0;
	printf("\t请输入想购买的编号:");
	scanf("\t%s", s);
	int index=-1;
	printf("编号\t商品名\t生产厂家\t库存量\t生产日期\t保质期\t商品分类\t成本\t售价\n");
	int flag;
	for(i=0; i<n; i++) {
		if(strstr(goods[i].ID, s) != 0 ) {
			printf("%s\t%s\t%s\t%d\t%s\t%s\t%s\t%.2f\t%.2f\n",goods[i].ID,goods[i].NAME,goods[i].sccj,goods[i].kcl,goods[i].scrq,goods[i].bzq,goods[i].spfl,goods[i].cp,goods[i].price);
			index=1;
			flag=i;
		}
	}
	if(index==-1) {
		printf("\t查询失败!\n");
		system("pause");
		return;
	}

	char ID[20];
	printf("请输入客户编号\n");
	scanf("%s",ID);
	int j=0;
	while (strcmp(per[j].num, ID)!= 0 && j<m) j++;
    printf("\t本次购买人编号为:%s\n\t姓名:%s\n",ID,per[j].xm);

	if (j == m) {
		printf("\t查询失败!\n");
		system("pause");
		return;
	}
	goods[flag].kcl--;
	per[j].goods[per[j].sum]=goods[flag];
	per[j].sum++;

	printf("\t购买成功！！购买后商品信息为：!\n");
	printf("编号\t商品名\t生产厂家\t库存量\t生产日期\t保质期\t商品分类\t成本\t售价\n");
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

					printf("系统结束\n");
					exit(0);
				}

			}

		}

	}

	return 0;

}
