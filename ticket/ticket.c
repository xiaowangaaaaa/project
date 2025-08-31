#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#define HEAD1 " *************************Airplane Ticket Booking*****************************\n"
#define HEAD2 " |  Flight  |Start City| Dest City|DepartureTime|ArrivalTime|price  | number |\n"
#define HEAD3 " |----------|----------|----------|-------------|-----------|-------|--------|\n"
#define FORMAT  " |%-10s|%-10s|%-10s|%-12s |%-10s | %-.2f|  %4d  |\n"
#define DATA  pst->stData.acFlight,pst->stData.acOrigin,pst->stData.acDest,pst->stData.acTakeOffTime,pst->stData.acReceiveTime,pst->stData.fPrice,pst->stData.iNum


int iSave = 0;
/**************************************
定义飞机票信息以及订票人的信息相关结构体
**************************************/

/*定义储存机票的结构体*/
struct AirPlane
{
	char acFlight[10];   /*航班号*/
	char acOrigin[10];   /*出发地*/
	char acDest[10];     /*目的地*/
	char acTakeOffTime[10];  /*起飞时间*/
	char acReceiveTime[10];  /*降落时间*/
	float fPrice;        /*票价*/
	char acDiscount[4];     /*折扣*/
	int iNum;            /*剩余票数*/

};


/*定义购票者信息的结构体*/
struct Man
{
	char acName[20];   /*姓名*/
	char acID[20];     /*身份证号*/
	char acSex[2];	  /*性别*/
	int iBookNum;     /*购票数*/
	char acBookFlight[10];   /*订购航班号*/
};


/*定义机票信息节点的结构体*/
struct PlaneNode
{
	struct AirPlane stData;
	struct PlaneNode *pstNext;
};

/*定义订票人信息节点的结构体*/
struct ManNode
{
	struct Man stData;
	struct ManNode *pstNext;
};

/*定义相关表头打印函数*/
void PrintHead()
{
	printf(HEAD1);
	printf(HEAD2);
	printf(HEAD3);
}
void PrintData(struct PlaneNode*stLp)
{
	struct PlaneNode *pst = stLp;
	printf(FORMAT, DATA);
}

/*菜单界面*/
void Menu()
{
	puts("**************************************************");
	puts("* Welcome to the airplane tickets booking system *");
	puts("*------------------------------------------------*");
	puts("*    choose the following operations(0-9);       *");
	puts("*------------------------------------------------*");
	puts("*   1.Insert flights    2.Search flights         *");
	puts("*   3.Book tickets      4.Modify flight data     *");
	puts("*   5.Show flights      6.Recommend flights      *");
	puts("*   7.Refund tickets    8.Show current time      *");
	puts("*   9.Save to files     0.quit                   *");
	puts("**************************************************");
}
/*显示时间函数*/
void NowTime()
{
	time_t lt;
	lt = time(NULL);
	printf("现在的时间是:%s\n", ctime(&lt));
}

/*添加机票函数*/
void Insert(struct PlaneNode* pstPlaneNodeHead)
{
	struct PlaneNode *pstHead,*pstTail, *pstCur, *pstNew;
	char acFlight[10];
	pstHead = pstTail = pstPlaneNodeHead;
	while (pstTail->pstNext != NULL)
	{
		pstTail = pstTail->pstNext;  /*让ptail指向最后一个节点*/
	}
	while (1)
	{
		printf("Input the new flight number(-1 to end):");
		scanf("%s", acFlight);
		if (strcmp(acFlight, "-1") == 0)
			break;
		pstCur = pstPlaneNodeHead->pstNext;
		while (pstCur != NULL)
		{
			if (strcmp(acFlight, pstCur->stData.acFlight) == 0)
			{
				printf("this flight %s exists!\n", acFlight);
				return;/*如果航班号已存在，则返回*/
			}
			pstCur = pstCur->pstNext;
		}
		/*如果航班号没有和现有记录中的航班号重复，则新建一个链表节点*/
		pstNew = (struct PlaneNode*)malloc(sizeof(struct PlaneNode));
		strcpy(pstNew->stData.acFlight, acFlight);
		printf("Input the Start City:\n");
		scanf("%s", pstNew->stData.acOrigin);
		printf("Input the Dest City:\n");
		scanf("%s", pstNew->stData.acDest);
		printf("Input the Departure Time (Format 00:00):\n");
		scanf("%s", pstNew->stData.acTakeOffTime);
		printf("Input the Arrival Time (Format 00:00):\n");
		scanf("%s", pstNew->stData.acReceiveTime);
		printf("Input the price of ticket:\n");
		scanf("%f", &pstNew->stData.fPrice);
		printf("Input the discount (Format 0.0):\n");
		scanf("%s", pstNew->stData.acDiscount);
		printf("Input the number of the tickets:\n");
		scanf("%d", &pstNew->stData.iNum);
		pstNew->pstNext = NULL;
		pstTail->pstNext = pstNew;
		pstTail = pstNew;
		iSave = 1;/*有新的航班信息，保存标志置为1，若退出需提示是否保存信息*/
	}
}


/*查找机票函数*/
void Search(struct PlaneNode* pstPlaneNodeHead)
{
	struct PlaneNode *pstPlaneNode;
	int iSel = 0, iCount = 0;
	char acFlight[10], acDest[10];
	pstPlaneNode = pstPlaneNodeHead->pstNext;
	if (pstPlaneNode == NULL)
	{
		printf("No flight record!\n");
		return;
	}
	printf("Choose one way according to:\n1.flight number;\n2.Dest:\n");
	scanf("%d", &iSel);
	
	if (iSel == 1)
	{
		printf("Input the flight number:");
		scanf("%s", acFlight);
		PrintHead();
		while (pstPlaneNode != NULL)
		{
			if (strcmp(pstPlaneNode->stData.acFlight, acFlight) == 0)
			{
				PrintData(pstPlaneNode);
				break;/*由于航班号是唯一的，找到一条即可退出*/
			}
			else
				pstPlaneNode = pstPlaneNode->pstNext;
		}
		/*遍历一遍，均没有中途break，则提示用户没有记录*/
		if (pstPlaneNode == NULL)
			printf("Sorry, no record!\n");

	}
	else if (iSel == 2)
	{
		printf("Input the Dest City:");
		scanf("%s", acDest);
		PrintHead();
		while (pstPlaneNode != NULL)
		{
			if (strcmp(pstPlaneNode->stData.acDest, acDest) == 0)
			{
				/*由于相同目的地的航班可能是多条，所以需要遍历完整个链表*/
				PrintData(pstPlaneNode);
				iCount++;
			}
			pstPlaneNode = pstPlaneNode->pstNext;
		}
		if (iCount == 0)/*如果记录数仍为0，则提示用户没有记录*/
			printf("Sorry, no record!\n");
	}
	else
	{
		printf("Sorry, please input right number:1-2\n");
		return;
	}
}

/*订票函数*/

void Book(struct ManNode* pstManNodeHead, struct PlaneNode* pstPlaneNodeHead)
{
	struct PlaneNode *pstPlaneNodeCur, *astPlaneNode[10]; /*定义临时指针和指针数组*/
	struct ManNode *pstManNodeCur, *pstManNodeTemp = 0;
	char acDest[10], acID[20], acName[20], acSex[2], acDecision[2], acFlight[10];
	/*iNum表示预定票数，iRecord记录符合要求的航班数*/
	int iNum = 0, iRecord = 0, k = 0, iFlag = 0;
	pstManNodeCur = pstManNodeHead;/*接收订票人信息链表的头指针*/
	while (pstManNodeCur->pstNext != NULL)
		pstManNodeCur = pstManNodeCur->pstNext;
	printf("Input the Dest City:\n");
	scanf("%s", acDest);/*输入目的地*/
	pstPlaneNodeCur = pstPlaneNodeHead->pstNext;
	while (pstPlaneNodeCur != NULL)/*循环条件为链表不为空*/
	{
		if (strcmp(pstPlaneNodeCur->stData.acDest, acDest) == 0)/*比较目的地*/
		{
			astPlaneNode[iRecord++] = pstPlaneNodeCur;/*目的地吻合的节点地址存到指针数组中*/
		}
		pstPlaneNodeCur = pstPlaneNodeCur->pstNext;/*指针后移*/
	}
	printf("\nthere are %d flight you can choose!\n", iRecord);
	PrintHead();/*输出表头*/
	for (k = 0; k < iRecord; k++)/*循环输出指针数组中的指针指向的航班信息*/
		PrintData(astPlaneNode[k]);
	if (iRecord == 0)/*若记录为0，表示没有符合条件的航班*/
		printf("sorry,no flight you can book!\n");
	else
	{
		printf("do you want to book it<y(Y)/n(N)>?\n");/*提示用户是否预定*/
		scanf("%s", acDecision);
		getchar(); /*提取多余的回车符，否则下面输入姓名的gets函数将获得一个回车符*/
		if (strcmp(acDecision, "y") == 0 || strcmp(acDecision, "Y") == 0)
		{
			printf("Input your information!\n");/*输入订票的详细信息*/
			pstManNodeTemp = (struct ManNode*)malloc(sizeof(struct ManNode));
			printf("Input your name:");
			gets(acName);/*由于姓和名中间会有空格，只能用gets函数，不能用scanf结合%s*/
			strcpy(pstManNodeTemp->stData.acName, acName);
			printf("Input your id:");
			scanf("%s", acID);
			strcpy(pstManNodeTemp->stData.acID, acID);
			printf("Input your sex (M/F):");
			scanf("%s", acSex);
			strcpy(pstManNodeTemp->stData.acSex, acSex);
			printf("Input the flight number:");
			scanf("%s", acFlight);
			strcpy(pstManNodeTemp->stData.acBookFlight, acFlight);
			for (k = 0; k<iRecord; k++)
			if (strcmp(astPlaneNode[k]->stData.acFlight, acFlight) == 0)
			{
				if (astPlaneNode[k]->stData.iNum < 1)/*判断是否有剩余的票*/
				{
					printf("no ticket!");
					return;
				}
				printf("remain %d tickets\n", astPlaneNode[k]->stData.iNum);
				iFlag = 1;
				break;
			}
			if (iFlag == 0)
			{
				printf("error");
				return;
			}
			printf("Input the book number:");
			scanf("%d", &iNum);/*输入预定的票数，剩余票数相应减少*/
			astPlaneNode[k]->stData.iNum = astPlaneNode[k]->stData.iNum - iNum;
			pstManNodeTemp->stData.iBookNum = iNum;
			pstManNodeCur->pstNext = pstManNodeTemp;
			pstManNodeTemp->pstNext = NULL;
			pstManNodeCur = pstManNodeTemp;
			printf("success!\n");
			iSave = 1;
		}
	}
}
struct ManNode *FindMan(struct ManNode* pstManNodeHead, char acID[20])
{
	struct ManNode *pstManNodeCur;
	pstManNodeCur = pstManNodeHead->pstNext;
	while (pstManNodeCur)
	{
		if (strcmp(pstManNodeCur->stData.acID, acID) == 0)
		{
			return pstManNodeCur;
		}
		pstManNodeCur = pstManNodeCur->pstNext;
	}
	return NULL;
}

struct PlaneNode *FindPlane(struct PlaneNode* pstPlaneNodeHead, char acFlight[10])
{
	struct PlaneNode *pstPlaneNodeCur;
	pstPlaneNodeCur = pstPlaneNodeHead->pstNext;
	while (pstPlaneNodeCur)
	{
		if (strcmp(pstPlaneNodeCur->stData.acFlight, acFlight) == 0)
		{
			//iMark = 1;
			return pstPlaneNodeCur;
		}
		pstPlaneNodeCur = pstPlaneNodeCur->pstNext;
	}
	return NULL;
}


/*退票系统*/
void Refund(struct ManNode* pstManNodeHead, struct PlaneNode* pstPlaneNodeHead)
{
	struct ManNode *pstManNodeCur, *pstManNodeFind = 0;
	struct PlaneNode *pstPlaneNodeFind = 0;
	char acID[20], acDecision[2];
	int iNum, iBookNum;
	
	printf("\nInput your ID:");
	scanf("%s", acID);
	pstManNodeFind = FindMan(pstManNodeHead, acID);
	if (pstManNodeFind == NULL)
		printf("can't find!\n");
	else  /*找到了相应的旅客订票信息*/
	{
		printf("\t\tthis is your tickets:\n");
		printf("id number:%s\n", pstManNodeFind->stData.acID);
		printf("name:%s\n", pstManNodeFind->stData.acName);
		printf("sex:%s\n", pstManNodeFind->stData.acSex);
		printf("book flight:%s\n",pstManNodeFind->stData.acBookFlight);
		printf("book number:%d\n", pstManNodeFind->stData.iBookNum);
		
		printf("do you want to cancel it?<y/n>");
		scanf("%s", acDecision);
		if (strcmp(acDecision, "y") == 0 || strcmp(acDecision, "Y") == 0)
		{
			/*将pstManNodeCur定位到指向pstManNodeFind前面那个节点*/
			pstManNodeCur = pstManNodeHead;
			while (pstManNodeCur->pstNext != pstManNodeFind)
				pstManNodeCur = pstManNodeCur->pstNext;
			/*找到该旅客订票信息中对应的航班记录*/
			pstPlaneNodeFind = FindPlane(pstPlaneNodeHead, pstManNodeFind->stData.acBookFlight);
			if (pstPlaneNodeFind != NULL)/*退票后，对应航班的剩余票数相应增加*/
			{
				iNum = pstPlaneNodeFind->stData.iNum;
				iBookNum = pstManNodeFind->stData.iBookNum;
				pstPlaneNodeFind->stData.iNum = iNum + iBookNum;
			}				
			pstManNodeCur->pstNext = pstManNodeFind->pstNext;
			free(pstManNodeFind);/*释放该乘客订票记录的链表节点空间*/
			printf("successful!\n");
			/*航班信息有调整，保存标志置为1，退出系统时提示用户是否保存*/
			iSave = 1;
		}
	}
}


/*修改机票信息函数*/
void Modify(struct PlaneNode* pstPlaneNodeHead)
{
	struct PlaneNode *pstPlaneNodeCur;
	char acFlight[10];
	pstPlaneNodeCur = pstPlaneNodeHead->pstNext;
	if (pstPlaneNodeCur == NULL)
	{
		printf("no flight to modify!\n");
		return;
	}
	else
	{
		printf("Input the flight number you want to modify:");
		scanf("%s", acFlight);
		while (pstPlaneNodeCur != NULL)
		{
			if (strcmp(pstPlaneNodeCur->stData.acFlight, acFlight) == 0)
				break;
			else
				pstPlaneNodeCur = pstPlaneNodeCur->pstNext;
		}
		if (pstPlaneNodeCur)
		{
			printf("Input new Start City:\n");
			scanf("%s", pstPlaneNodeCur->stData.acOrigin);
			printf("Input new Dest City:\n");
			scanf("%s", pstPlaneNodeCur->stData.acDest);
			printf("Input new Departure Time:\n");
			scanf("%s", pstPlaneNodeCur->stData.acTakeOffTime);
			printf("Input new Arrival Time:\n");
			scanf("%s", pstPlaneNodeCur->stData.acReceiveTime);
			printf("Input new price of ticket:\n");
			scanf("%f", &pstPlaneNodeCur->stData.fPrice);
			printf("Input new discount:\n");
			scanf("%s", pstPlaneNodeCur->stData.acDiscount);
			printf("Input new number of the tickets:\n");
			scanf("%d", &pstPlaneNodeCur->stData.iNum);
			printf("successful!\n");
			iSave = 1;
			return;
		}
		else
			printf("\tcan't find your ticket!\n");
	}
}

/*显示机票信息函数*/
void Show(struct PlaneNode* pstPlaneNodeHead)
{
	struct PlaneNode *pstPlaneNodeCur;
	pstPlaneNodeCur = pstPlaneNodeHead->pstNext;
	PrintHead();
	if (pstPlaneNodeHead->pstNext == NULL)
	{
		printf("no flight ticket!\n");
	}
	else
	{
		while (pstPlaneNodeCur != NULL)
		{
			PrintData(pstPlaneNodeCur);
			pstPlaneNodeCur = pstPlaneNodeCur->pstNext;
		}
	}
}

/*快速终点站推荐机票函数*/
void Recommend(struct PlaneNode* pstPlaneNodeHead)
{
	struct PlaneNode *pstPlaneNodeCur;
	char acDest[10],acTime[10];
	int iNum = 0;
	pstPlaneNodeCur = pstPlaneNodeHead->pstNext;
	printf("Input your destination:");
	scanf("%s", acDest);
	printf("Input the earliest time you can take:");
	scanf("%s",acTime);
	PrintHead();
	while (pstPlaneNodeCur != NULL)
	{
		if (strcmp(pstPlaneNodeCur->stData.acDest, acDest) == 0)
		{
			if (strcmp(acTime, pstPlaneNodeCur->stData.acTakeOffTime) < 0)
			{
				PrintData(pstPlaneNodeCur);
				iNum++;
			}
		}
		pstPlaneNodeCur = pstPlaneNodeCur->pstNext;
	}
	printf("there are %d flight you can take!\n", iNum);
	if (iNum != 0)
	{
		printf("please choose 3rd operation to book it!\n");
	}
}


/*保存机票信息函数*/
void SavePlane(struct PlaneNode* pstPlaneNodeHead)
{
	FILE *pfPlane;
	struct PlaneNode *pstPlaneNodeCur;
	int iCount = 0, iFlag = 1;
	pfPlane = fopen("plane.txt", "wb");
	if (pfPlane == NULL)
	{
		printf("the file can't be opened!");
		return;
	}
	pstPlaneNodeCur = pstPlaneNodeHead->pstNext;
	while (pstPlaneNodeCur != NULL)
	{
		if (fwrite(pstPlaneNodeCur, sizeof(struct PlaneNode), 1, pfPlane) == 1)
		{
			pstPlaneNodeCur = pstPlaneNodeCur->pstNext;
			iCount++;
		}
		else
		{
			iFlag = 0;
			break;
		}
	}
	if (iFlag)
	{
		printf("you have save %d flights!\n", iCount);
		iSave = 0;
	}
	fclose(pfPlane);
}

/*保存订票人信息函数*/
void SaveMan(struct ManNode* pstManNodeHead)
{
	FILE *pfMan;
	struct ManNode *pstManNodeCur;
	int iCount = 0, iFlag = 1;
	pfMan = fopen("man.txt", "wb");
	if (pfMan == NULL)
	{
		printf("the file can't bo opened!");
		return;
	}
	pstManNodeCur = pstManNodeHead->pstNext;
	while (pstManNodeCur != NULL)
	{
		if (fwrite(pstManNodeCur, sizeof(struct ManNode), 1, pfMan) == 1)
		{
			pstManNodeCur = pstManNodeCur->pstNext;
			iCount++;
		}
		else
		{
			iFlag = 0;
			break;
		}
	}
}

int main()
{

	FILE *pfPlane, *pfMan;
	struct PlaneNode *pstPlaneNodeTemp, *pstPlaneNodeHead, *pstPlaneNodeCur;
	struct ManNode  *pstManNodeTemp, *pstManNodeHead, *pstManNodeCur;
	int iSel = 0;
	char c1;
	pstPlaneNodeHead = (struct PlaneNode*)malloc(sizeof(struct PlaneNode));
	pstPlaneNodeHead->pstNext = NULL;
	pstPlaneNodeCur = pstPlaneNodeHead;
	pstManNodeHead = (struct ManNode*)malloc(sizeof(struct ManNode));
	pstManNodeHead->pstNext = NULL;
	pstManNodeCur = pstManNodeHead;
	pfPlane = fopen("plane.txt", "ab+");
	if (pfPlane == NULL)
	{
		printf("can't open plane.txt!");
		return 0;
	}

	while (!feof(pfPlane))
	{
		pstPlaneNodeTemp = (struct PlaneNode*)malloc(sizeof(struct PlaneNode));
		if (fread(pstPlaneNodeTemp, sizeof(struct PlaneNode), 1, pfPlane) == 1)
		{
			pstPlaneNodeTemp->pstNext = NULL;
			pstPlaneNodeCur->pstNext = pstPlaneNodeTemp;
			pstPlaneNodeCur = pstPlaneNodeTemp;
		}
	}
	free(pstPlaneNodeTemp);
	fclose(pfPlane);
	pfMan = fopen("man.txt", "rb+");
	if (pfMan == NULL)
	{
		printf("can't open man.txt!");
		return 0;
	}

	while (!feof(pfMan))
	{
		pstManNodeTemp = (struct ManNode*)malloc(sizeof(struct ManNode));
		if (fread(pstPlaneNodeHead, sizeof(struct ManNode), 1, pfMan) == 1)
		{
			pstManNodeTemp->pstNext = NULL;
			pstManNodeCur->pstNext = pstManNodeTemp;
			pstManNodeCur = pstManNodeTemp;
		}
	}
	free(pstManNodeTemp);
	fclose(pfMan);
	while (1)
	{
		system("cls");
		Menu();
		printf("Input 0-9 operations:");
		scanf("%d", &iSel);
		getchar();/*取走数字后面多余的回车符*/
		system("cls");
		if (iSel == 0)
		{
			if (iSave == 1)
			{
				printf("do you want to save?<y/n>");
				scanf("%c", &c1);
				if (c1 == 'y' || c1 == 'Y')
				{
					SaveMan(pstManNodeHead);
					SavePlane(pstPlaneNodeHead);
				}

			}
			break;
		}
		switch (iSel)
		{
		case 1:Insert(pstPlaneNodeHead); break;
		case 2: Search(pstPlaneNodeHead); break;
		case 3: Book(pstManNodeHead, pstPlaneNodeHead); break;
		case 4:Modify(pstPlaneNodeHead); break;
		case 5:Show(pstPlaneNodeHead); break;
		case 6:Recommend(pstPlaneNodeHead); break;
		case 7:Refund(pstManNodeHead, pstPlaneNodeHead); break;
		case 8:NowTime(); break;
		case 9:SaveMan(pstManNodeHead); SavePlane(pstPlaneNodeHead); break;
		case 0:return 0;
		}
		printf("\nplease press any key to continue.......\n");
		getch();
	}
}

