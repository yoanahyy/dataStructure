/*顺序表的插入、删除与输出操作*/
#include <stdio.h>
#include <stdlib.h>

typedef struct
{ 
	int data[50];
	int length;
}Sqlist;

//单链表的插入
int ListInsert (Sqlist *L,int i,int x)
{ 
	int j;
	if(i<1||i>L->length+1)
	{
		printf("该位置为非法输入地址！\n");
		return 0;
	}
	i--;
	for(j=L->length;j>=i;j--)
		L->data[j]=L->data[j-1];
	L->data[i]=x;
	L->length++;
	return 1; 

}

//单链表的删除
int ListDelete(Sqlist *L,int i)
{ 
	int j;
	if(i<1||i>L->length)
	{
		printf("该位置没有元素，非法删除！\n");
		return 0;
	}
	i--;
	for(j=i;j<=L->length-1;j++)
		L->data[j]=L->data[j+1];
	L->length--;
	return 1; 

}

//单链表的输出
void ListPrint(Sqlist *L)
{ 
	int k;
	printf("输出当前顺序表中元素排列：\n");
	for(k=0;k<L->length;k++)
		printf("%5d",L->data[k]); 
	printf("\n");

}

//初始化
void ListInit(Sqlist *L)
{ 
	L->length=0;
}

//菜单显示
void Menu()
{ 
	printf("1.顺序表的插入操作\n");
	printf("2.顺序表的删除操作\n");
	printf("3.退出\n");
	printf("请选择(1/2/3)：");

}

void ListCreat(Sqlist *L,int n)
{
	int k;
	for(k=0;k<n;k++)
		scanf("%d",&L->data[k]);
	L->length=n;
}

//主函数
main()
{ 
	int m,p,pl,num;
	Sqlist sq;
	printf("请输入建立顺序表的长度：\n");
	scanf("%d",&m);
	printf("请依次输入顺序表中元素数值：\n");
	
	ListInit(&sq);
	ListCreat(&sq,m);
	ListPrint(&sq);
	printf("\n");
	Menu();

	while(1){
		scanf("%d",&p);
		printf("\n");

		switch(p)
		{ 
		case 1:
			printf("请输入插入的元素位置：\n");
			scanf("%d",&pl);
			printf("请输入插入的元素数值：\n");
			scanf("%d",&num);
			ListInsert(&sq,pl,num);
			ListPrint(&sq);
			printf("\n");
			printf("\n");
			Menu();
			break;
		case 2:
			printf("请输入删除的元素位置：\n");
			scanf("%d",&pl);
			ListDelete(&sq,pl);
			ListPrint(&sq);
			printf("\n");
			printf("\n");
			Menu();
			break;
		case 3:
			exit(0);
		default:
			Menu();
			break;
		}
	}
}