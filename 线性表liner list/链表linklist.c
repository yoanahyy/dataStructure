/*单链表的插入、删除及输出操作*/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct LNode{
	int data;
	struct LNode *next;
}LinkList;

//尾插法建立单链表
LinkList *CreatListF(LinkList *L,int a[],int n)
{
	LinkList *head,*r,*q;//用q指向新生成的结点
	int i;
	head=(LinkList *)malloc(sizeof(LinkList));//创建头结点
	r=head;//r始终指向尾节点，开始时指向头结点
	for(i=0;i<n;i++)
	{       
		q=(LinkList *)malloc(sizeof(LinkList));
		q->data=a[i];
		r->next=q;//将*q插入*r之后
		r=q;//r始终指向表尾
	}
	r->next=NULL;//尾结点指针置为空
	return head;

}

//单链表的插入
int InsertList(LinkList *L,int pl,int x)
{   
	int i=0;
	LinkList *q=L,*S;
	S=(LinkList *)malloc(sizeof(LinkList));
	while(q && i<pl-1)
	{
		q=q->next;
		i++;
	}
	if(!q||i>pl-1)
	{
		printf("该插入位置为非法输入地址！\n");
		return 0;
	}
	S->data=x;
	S->next=q->next;
	q->next=S;
	return 1;
}

//单链表的删除
int DeleteList(LinkList *L,int pl)
{
	LinkList *p,*q=L;
	int i=0;
	while(q->next && i<pl-1)
	{
		q=q->next;
		i++;
	}
	if(!q->next||i>pl-1)
	{
		printf("该位置没有元素，非法删除！\n");
		return 0;
	}
	p=q->next;
	q->next=p->next;
	free(p);
	return 1;
}

//单链表的初始化定义
void InitList(LinkList *L)
{
	//L=(LinkList *)malloc(sizeof(LinkList));
	L->next=NULL;
}

//单链表的输出
void PrintList(LinkList *l)
{       
	LinkList *q=l->next;
	printf("输出当前单链表中结点排列：\n");
	while(q!=NULL)
	{
		printf("%5d",q->data);
		q=q->next;
	}
	printf("\n");

}

//菜单显示
void Menu()
{

	printf("1.单链表的插入操作\n");
	printf("2.单链表的删除操作\n");
	printf("3.退出\n");
	printf("请选择(1/2/3)：");
}

//主函数
main()
{
	int m,i,p,pl,num;
	int a[100];
	LinkList head;

	printf("请输入建立单链表的长度：\n");
	scanf("%d",&m);
	printf("请依次输入结点数值：\n");
	for(i=0;i<m;i++)
	{
		scanf("%d",&a[i]);
	} 

	InitList(&head);
	head=*CreatListF(&head,a,m);
	PrintList(&head);
	printf("\n");
	Menu();

	while(1){
		scanf("%d",&p);
		printf("\n");
		switch(p)
		{
		case 1:
			printf("请输入插入的结点位置：\n");
			scanf("%d",&pl);
			printf("请输入插入的结点数值：\n");
			scanf("%d",&num);
			InsertList(&head,pl,num);
			PrintList(&head);
			printf("\n");
			Menu();
			break;
		case 2:
			printf("请输入删除的结点位置：");
			scanf("%d",&pl);
			DeleteList(&head,pl);
			PrintList(&head);
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