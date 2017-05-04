/*****链栈的入栈、出栈及输出*****/
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct node
{
	char data;
	struct node *next;
}LinkStack;

//初始化
LinkStack *InitStack() 
{
	LinkStack *s;
	s=(LinkStack*)malloc(sizeof(LinkStack));
	s->next=NULL;
	return s;
}

//入栈
int Push(LinkStack *s,char e) 
{
	LinkStack *p;
	p=(LinkStack*)malloc(sizeof(LinkStack));
	p->data=e;
	p->next=s->next;
	s->next=p;
	printf(">>>>入栈成功！");
	return 1;
}

//出栈
int Pop(LinkStack *s,char *e)
{
	LinkStack *p;
	if(s->next==NULL)//栈空判断
	{
		printf(">>>栈为空！");
		return 0;
	}
	p=s->next;
	*e=p->data;
	s->next=p->next;
	free(p);
	printf(">>>>出栈成功！");
	return 1;
}

//输出栈
int PrintStack(LinkStack *s) 
{
	LinkStack *p;
	p=s->next;
	if(s->next==NULL)
	{
		
		printf("\n【从栈顶到栈底依次输出栈中元素】：NULL\n\n\n");
		return 0;
	}
	printf("\n【从栈顶到栈底依次输出栈中元素】：\n");
	while(p!=NULL)
	{
		printf("%c\n",p->data);
		p=p->next;
	}
	printf("\n");
	return 1;
}

//主函数
main()
{
	int i;
	char e;
	LinkStack p; 
	p=*InitStack();
	while(1)  
	{   
		printf("***********************\n");
		printf("1.链栈的入栈操作\n");
		printf("2.链栈的出栈操作\n");
		printf("3.退出\n");
		printf("***********************\n");
		printf("请选择(1/2/3)：");
		scanf("%d",&i);
		getchar();
		switch(i)
		{ 
		case 1: 
			printf("\n");
			printf("请输入入栈的一个元素：\n");   
			scanf("%c",&e);    
			Push(&p,e);   
			PrintStack(&p);
			printf("\n");
			break;
		case 2:
			Pop(&p,&e);  
			PrintStack(&p);
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