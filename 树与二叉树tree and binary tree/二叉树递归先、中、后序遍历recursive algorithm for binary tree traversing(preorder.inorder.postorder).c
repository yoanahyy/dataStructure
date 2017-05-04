/*递归实现二叉树的先序、后序、中序遍历*/
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
	printf("以扩展先序遍历建立二叉树，输入，以空格代表无孩子");
	T=CreateBiTree(); 
	printf("先序序列是：");
	Preorderf(T);
	printf("\n");
	printf("中序序列是：");
	Inorderf(T);
	printf("\n");
	printf("后序序列是：");
	Postorderf(T);
	printf("\n");
}

