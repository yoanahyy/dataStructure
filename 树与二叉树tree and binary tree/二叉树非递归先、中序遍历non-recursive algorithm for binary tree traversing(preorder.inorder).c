/*非递归方式实现二叉树的先序、中序、后序遍历*/
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
			printf("%3c",p->data);//根
			s[top++]=p;
			p=p->lchild;//左
		}
		if(top>0)
		{
			p=s[--top];
			p=p->rchild;//右
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
			p=p->lchild;//左
		}
		if(top>0)
		{
			p=s[--top];
			printf("%3c",p->data);//根
			p=p->rchild;//右
		}
	}
}



main()
{
	BiTree T;
	printf("\n");
	printf("以扩展先序遍历建立二叉树，输入，以空格代表无孩子：");
	T=CreateBiTree(); 
	printf("先序遍历的结果为：");
	Preorderf(T);
	printf("\n");
	printf("中序遍历的结果为：");
	Inorderf(T);
	printf("\n");

}
