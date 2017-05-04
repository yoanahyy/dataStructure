/*****链队的出队、入队、及输出*****/
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct qnode
{
	char data;
	struct qnode *next;
}QNode;//数据结点

typedef struct
{
	QNode *front;
	QNode *rear;
}LiQueue;//头结点

//初始化
LiQueue *InitQueue()
{
	LiQueue *q;
	q=(LiQueue *)malloc(sizeof(LiQueue));
	q->front=q->rear=NULL;
	return q;
}

//入队
void enQueue(LiQueue *q,char e)
{
	QNode *p;
	p=(QNode *)malloc(sizeof(QNode));
	p->data=e;
	p->next=NULL;
	if(q->rear==NULL)//若链队为空
		q->front=q->rear=p;
	else 
	{
		q->rear->next=p;
		q->rear=p;
	}
	printf(">>>>入队成功！");
}

//出队
int deQueue(LiQueue *q,char *e)
{
	QNode *t;
	if(q->rear==NULL)
	{
		printf(">>>队为空！");
		return 0;
	}
	t=q->front; 
	if(q->front==q->rear)//队中只有一个结点时
		q->front=q->rear=NULL;
	else
		q->front=q->front->next;//队中有多个结点时
	*e=t->data;
	free(t);
	printf(">>>>出队成功！");
	return 1;
}

//输出队
int PrintQueue(LiQueue *p) 
{
	QNode *q;
	q=p->front;
	if(p->rear==NULL)
	{
		printf("\n【从队头到队尾依次输出队中元素】：NULL\n\n\n");
		return 0;
	}
	printf("\n【从队头到队尾依次输出队中元素】：\n");
	while(q!=NULL)
	{
		printf("%c ",q->data);
		q=q->next;
	}
	printf("\n");
	return 1;
}

//主函数
main()
{
	int i;
	char e;
	LiQueue Q; 
	Q=*InitQueue(); 
	while(1)  
	{   
		printf("***********************\n");
		printf("1.链队的入队操作\n");
		printf("2.链队的出队操作\n");
		printf("3.退出\n");
		printf("***********************\n");
		printf("请选择(1/2/3)：");
		scanf("%d",&i);
		getchar();
		switch(i)
		{ 
		case 1: 
			printf("\n");
			printf("请输入入队的一个元素：\n");   
			scanf("%c",&e); 
			enQueue(&Q,e);
			PrintQueue(&Q);
			printf("\n");
			break;
		case 2:
			deQueue(&Q,&e);  
			PrintQueue(&Q);
			printf("\n");
			break;
		case 3:
			printf("\n感谢您的使用！\n");
			exit(0);
		default: 
			printf("请重新输入!\n"); 
			printf("\n");
			break;
		}
	}
}