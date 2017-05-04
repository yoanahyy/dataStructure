/*****��ջ����ջ����ջ�����*****/
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct node
{
	char data;
	struct node *next;
}LinkStack;

//��ʼ��
LinkStack *InitStack() 
{
	LinkStack *s;
	s=(LinkStack*)malloc(sizeof(LinkStack));
	s->next=NULL;
	return s;
}

//��ջ
int Push(LinkStack *s,char e) 
{
	LinkStack *p;
	p=(LinkStack*)malloc(sizeof(LinkStack));
	p->data=e;
	p->next=s->next;
	s->next=p;
	printf(">>>>��ջ�ɹ���");
	return 1;
}

//��ջ
int Pop(LinkStack *s,char *e)
{
	LinkStack *p;
	if(s->next==NULL)//ջ���ж�
	{
		printf(">>>ջΪ�գ�");
		return 0;
	}
	p=s->next;
	*e=p->data;
	s->next=p->next;
	free(p);
	printf(">>>>��ջ�ɹ���");
	return 1;
}

//���ջ
int PrintStack(LinkStack *s) 
{
	LinkStack *p;
	p=s->next;
	if(s->next==NULL)
	{
		
		printf("\n����ջ����ջ���������ջ��Ԫ�ء���NULL\n\n\n");
		return 0;
	}
	printf("\n����ջ����ջ���������ջ��Ԫ�ء���\n");
	while(p!=NULL)
	{
		printf("%c\n",p->data);
		p=p->next;
	}
	printf("\n");
	return 1;
}

//������
main()
{
	int i;
	char e;
	LinkStack p; 
	p=*InitStack();
	while(1)  
	{   
		printf("***********************\n");
		printf("1.��ջ����ջ����\n");
		printf("2.��ջ�ĳ�ջ����\n");
		printf("3.�˳�\n");
		printf("***********************\n");
		printf("��ѡ��(1/2/3)��");
		scanf("%d",&i);
		getchar();
		switch(i)
		{ 
		case 1: 
			printf("\n");
			printf("��������ջ��һ��Ԫ�أ�\n");   
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
			printf("\n��л����ʹ�ã�\n");
			exit(0);
		default: 
			printf("����������!\n"); 
			printf("\n");
			break;
		}
	}
}