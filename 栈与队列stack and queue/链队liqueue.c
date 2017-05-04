/*****���ӵĳ��ӡ���ӡ������*****/
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct qnode
{
	char data;
	struct qnode *next;
}QNode;//���ݽ��

typedef struct
{
	QNode *front;
	QNode *rear;
}LiQueue;//ͷ���

//��ʼ��
LiQueue *InitQueue()
{
	LiQueue *q;
	q=(LiQueue *)malloc(sizeof(LiQueue));
	q->front=q->rear=NULL;
	return q;
}

//���
void enQueue(LiQueue *q,char e)
{
	QNode *p;
	p=(QNode *)malloc(sizeof(QNode));
	p->data=e;
	p->next=NULL;
	if(q->rear==NULL)//������Ϊ��
		q->front=q->rear=p;
	else 
	{
		q->rear->next=p;
		q->rear=p;
	}
	printf(">>>>��ӳɹ���");
}

//����
int deQueue(LiQueue *q,char *e)
{
	QNode *t;
	if(q->rear==NULL)
	{
		printf(">>>��Ϊ�գ�");
		return 0;
	}
	t=q->front; 
	if(q->front==q->rear)//����ֻ��һ�����ʱ
		q->front=q->rear=NULL;
	else
		q->front=q->front->next;//�����ж�����ʱ
	*e=t->data;
	free(t);
	printf(">>>>���ӳɹ���");
	return 1;
}

//�����
int PrintQueue(LiQueue *p) 
{
	QNode *q;
	q=p->front;
	if(p->rear==NULL)
	{
		printf("\n���Ӷ�ͷ����β�����������Ԫ�ء���NULL\n\n\n");
		return 0;
	}
	printf("\n���Ӷ�ͷ����β�����������Ԫ�ء���\n");
	while(q!=NULL)
	{
		printf("%c ",q->data);
		q=q->next;
	}
	printf("\n");
	return 1;
}

//������
main()
{
	int i;
	char e;
	LiQueue Q; 
	Q=*InitQueue(); 
	while(1)  
	{   
		printf("***********************\n");
		printf("1.���ӵ���Ӳ���\n");
		printf("2.���ӵĳ��Ӳ���\n");
		printf("3.�˳�\n");
		printf("***********************\n");
		printf("��ѡ��(1/2/3)��");
		scanf("%d",&i);
		getchar();
		switch(i)
		{ 
		case 1: 
			printf("\n");
			printf("��������ӵ�һ��Ԫ�أ�\n");   
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
			printf("\n��л����ʹ�ã�\n");
			exit(0);
		default: 
			printf("����������!\n"); 
			printf("\n");
			break;
		}
	}
}