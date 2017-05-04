/*������Ĳ��롢ɾ�����������*/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct LNode{
	int data;
	struct LNode *next;
}LinkList;

//β�巨����������
LinkList *CreatListF(LinkList *L,int a[],int n)
{
	LinkList *head,*r,*q;//��qָ�������ɵĽ��
	int i;
	head=(LinkList *)malloc(sizeof(LinkList));//����ͷ���
	r=head;//rʼ��ָ��β�ڵ㣬��ʼʱָ��ͷ���
	for(i=0;i<n;i++)
	{       
		q=(LinkList *)malloc(sizeof(LinkList));
		q->data=a[i];
		r->next=q;//��*q����*r֮��
		r=q;//rʼ��ָ���β
	}
	r->next=NULL;//β���ָ����Ϊ��
	return head;

}

//������Ĳ���
int InsertList(LinkList *L,int pl,int x)
{   
	int i=0;
	LinkList *q=L,*S;
	S=(LinkList *)malloc(sizeof(LinkList));
	while(q && i<pl-1)
	{
		q=q->next;
		i++;
	}
	if(!q||i>pl-1)
	{
		printf("�ò���λ��Ϊ�Ƿ������ַ��\n");
		return 0;
	}
	S->data=x;
	S->next=q->next;
	q->next=S;
	return 1;
}

//�������ɾ��
int DeleteList(LinkList *L,int pl)
{
	LinkList *p,*q=L;
	int i=0;
	while(q->next && i<pl-1)
	{
		q=q->next;
		i++;
	}
	if(!q->next||i>pl-1)
	{
		printf("��λ��û��Ԫ�أ��Ƿ�ɾ����\n");
		return 0;
	}
	p=q->next;
	q->next=p->next;
	free(p);
	return 1;
}

//������ĳ�ʼ������
void InitList(LinkList *L)
{
	//L=(LinkList *)malloc(sizeof(LinkList));
	L->next=NULL;
}

//����������
void PrintList(LinkList *l)
{       
	LinkList *q=l->next;
	printf("�����ǰ�������н�����У�\n");
	while(q!=NULL)
	{
		printf("%5d",q->data);
		q=q->next;
	}
	printf("\n");

}

//�˵���ʾ
void Menu()
{

	printf("1.������Ĳ������\n");
	printf("2.�������ɾ������\n");
	printf("3.�˳�\n");
	printf("��ѡ��(1/2/3)��");
}

//������
main()
{
	int m,i,p,pl,num;
	int a[100];
	LinkList head;

	printf("�����뽨��������ĳ��ȣ�\n");
	scanf("%d",&m);
	printf("��������������ֵ��\n");
	for(i=0;i<m;i++)
	{
		scanf("%d",&a[i]);
	} 

	InitList(&head);
	head=*CreatListF(&head,a,m);
	PrintList(&head);
	printf("\n");
	Menu();

	while(1){
		scanf("%d",&p);
		printf("\n");
		switch(p)
		{
		case 1:
			printf("���������Ľ��λ�ã�\n");
			scanf("%d",&pl);
			printf("���������Ľ����ֵ��\n");
			scanf("%d",&num);
			InsertList(&head,pl,num);
			PrintList(&head);
			printf("\n");
			Menu();
			break;
		case 2:
			printf("������ɾ���Ľ��λ�ã�");
			scanf("%d",&pl);
			DeleteList(&head,pl);
			PrintList(&head);
			printf("\n");
			Menu();
			break;
		case 3: 
			exit(0);
		default:
			Menu();
			break;
		}
	}
}