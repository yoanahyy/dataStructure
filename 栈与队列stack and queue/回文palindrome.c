/*****利用栈与队实现回文判断*****/
#include<stdio.h>
#include<string.h>
#define MAX 100

//栈
typedef struct
{
	char data[MAX];
	int top;
}SqStack;

//队列
typedef struct
{
	char data[MAX];
	int front,rear;
}SqQueue;

//初始化栈
void InitStack(SqStack *S)
{
	S->top=-1;
}

//入栈
int Push(SqStack *S,char x,int pl)
{
	if(S->top==pl-1)
		return 0;
	S->top++;
	S->data[S->top]=x;
	return 1;
}

//出栈
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

//初始化队列
void InitQueue(SqQueue *Q)
{
	Q->front=Q->rear=0;
}

//入队
int enQuene(SqQueue *Q,char x,int pl)
{
	if((Q->rear+1)%(pl+1)==Q->front)
		return 0;
	Q->data[Q->rear]=x;
	Q->rear=(Q->rear+1)%(pl+1);
	return 1;
}

//出队
int deQueue(SqQueue *Q,char *x,int pl)
{
	if(Q->front==Q->rear)
		return 0;
	*x=Q->data[Q->front];
	Q->front=(Q->front+1)%(pl+1);
	return 1;
}

//主函数
main()
{
	int i,pl,flag=0;
	char a[MAX],b[MAX],c[MAX]; 
	SqStack s;
	SqQueue q;
	printf("请输入字符串（以$来表示字符串输入完毕）：\n");
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
	printf("\n用栈输出输入的字符串1为：\n");
	for(i=0;i<pl+1;i++)
	{
		deQueue(&q,&b[i],pl);
		printf("%c",b[i]);
	}
	printf("\n");

	printf("\n用队列逆序输出字符串2为：\n");
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
		printf("\n字符串1=字符串2！");
		printf("\n>>>该字符串是回文！");
	}

	else
	{
		printf("\n字符串1≠字符串2！");
		printf("\n>>>该字符串不是回文！");}

	printf("\n");
}
