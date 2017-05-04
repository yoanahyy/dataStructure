/*�ǵݹ鷽ʽʵ�ֶ��������������򡢺������*/
#include<stdio.h>
#include<malloc.h>

typedef struct BTNode{
	char data;
	struct BTNode *lchild,*rchild;
}BTNode,*BiTree;

BiTree CreateBiTree(){   
	BiTree T;
	char ch;
	scanf("%c",&ch);
	if (ch==' ') 
		T=NULL;
	else 
	{
		T=(BiTree)malloc(sizeof(BTNode));
		T->data=ch;
		T->lchild=CreateBiTree();
		T->rchild=CreateBiTree();
	}
	return T;
}

void Preorderf(BiTree T) 
{ 
	int top=0;
	BiTree p,s[30];
	p=T;
	while(p||top)
	{
		while(p!=NULL)
		{
			printf("%3c",p->data);//��
			s[top++]=p;
			p=p->lchild;//��
		}
		if(top>0)
		{
			p=s[--top];
			p=p->rchild;//��
		}
	}
}

void Inorderf(BiTree T) 
{
	int top=0;
	BiTree p,s[30];
	p=T;
	while(p||top)
	{
		while(p!=NULL)
		{
			s[top++]=p;
			p=p->lchild;//��
		}
		if(top>0)
		{
			p=s[--top];
			printf("%3c",p->data);//��
			p=p->rchild;//��
		}
	}
}



main()
{
	BiTree T;
	printf("\n");
	printf("����չ����������������������룬�Կո�����޺��ӣ�");
	T=CreateBiTree(); 
	printf("��������Ľ��Ϊ��");
	Preorderf(T);
	printf("\n");
	printf("��������Ľ��Ϊ��");
	Inorderf(T);
	printf("\n");

}
