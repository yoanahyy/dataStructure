/*�ݹ�ʵ�ֶ����������򡢺����������*/
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

void Inorderf(BiTree T) 
{ 
	if(T)
	{
		Inorderf(T->lchild);
		printf("%3c",T->data);
		Inorderf(T->rchild);
	}
}

void Preorderf(BiTree T) 
{ 
	if(T)
	{
		printf("%3c",T->data);
		Preorderf(T->lchild);
		Preorderf(T->rchild);
	}
}

void Postorderf(BiTree T) 
{ 
	if(T)
	{
		Preorderf(T->lchild);
		Preorderf(T->rchild);
		printf("%3c",T->data);
	}
}

main()
{
	BiTree T;
	printf("\n");
	printf("����չ����������������������룬�Կո�����޺���");
	T=CreateBiTree(); 
	printf("���������ǣ�");
	Preorderf(T);
	printf("\n");
	printf("���������ǣ�");
	Inorderf(T);
	printf("\n");
	printf("���������ǣ�");
	Postorderf(T);
	printf("\n");
}

