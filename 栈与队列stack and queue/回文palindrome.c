/*****����ջ���ʵ�ֻ����ж�*****/
#include<stdio.h>
#include<string.h>
#define MAX 100

//ջ
typedef struct
{
	char data[MAX];
	int top;
}SqStack;

//����
typedef struct
{
	char data[MAX];
	int front,rear;
}SqQueue;

//��ʼ��ջ
void InitStack(SqStack *S)
{
	S->top=-1;
}

//��ջ
int Push(SqStack *S,char x,int pl)
{
	if(S->top==pl-1)
		return 0;
	S->top++;
	S->data[S->top]=x;
	return 1;
}

//��ջ
int Pop(SqStack *S,char *x)
{
	if(S->top==-1)
		return 0;
	else
	{
		*x=S->data[S->top];
		S->top--;
		return 1;
	}
}

//��ʼ������
void InitQueue(SqQueue *Q)
{
	Q->front=Q->rear=0;
}

//���
int enQuene(SqQueue *Q,char x,int pl)
{
	if((Q->rear+1)%(pl+1)==Q->front)
		return 0;
	Q->data[Q->rear]=x;
	Q->rear=(Q->rear+1)%(pl+1);
	return 1;
}

//����
int deQueue(SqQueue *Q,char *x,int pl)
{
	if(Q->front==Q->rear)
		return 0;
	*x=Q->data[Q->front];
	Q->front=(Q->front+1)%(pl+1);
	return 1;
}

//������
main()
{
	int i,pl,flag=0;
	char a[MAX],b[MAX],c[MAX]; 
	SqStack s;
	SqQueue q;
	printf("�������ַ�������$����ʾ�ַ���������ϣ���\n");
	for(i=0;i<MAX+1;i++)
	{
		scanf("%c",&a[i]);
		if(a[i]=='$')
			break;
	}
	pl=i;
	InitStack(&s);
	InitQueue(&q);
	for(i=0;i<pl;i++)
	{
		enQuene(&q,a[i],pl);
		Push(&s,a[i],pl);
	}
	printf("\n��ջ���������ַ���1Ϊ��\n");
	for(i=0;i<pl+1;i++)
	{
		deQueue(&q,&b[i],pl);
		printf("%c",b[i]);
	}
	printf("\n");

	printf("\n�ö�����������ַ���2Ϊ��\n");
	for(i=0;i<pl+1;i++)
	{
		Pop(&s,&c[i]);
		printf("%c",c[i]);
	}
	printf("\n");

	for(i=0;i<pl+1;i++)
	{
		if(b[i]==c[i])
			flag=1;
		else
		{
			flag=0;
			break;
		}
	}

	if(flag)
	{   
		printf("\n�ַ���1=�ַ���2��");
		printf("\n>>>���ַ����ǻ��ģ�");
	}

	else
	{
		printf("\n�ַ���1���ַ���2��");
		printf("\n>>>���ַ������ǻ��ģ�");}

	printf("\n");
}
