/*˳���Ĳ��롢ɾ�����������*/
#include <stdio.h>
#include <stdlib.h>

typedef struct
{ 
	int data[50];
	int length;
}Sqlist;

//������Ĳ���
int ListInsert (Sqlist *L,int i,int x)
{ 
	int j;
	if(i<1||i>L->length+1)
	{
		printf("��λ��Ϊ�Ƿ������ַ��\n");
		return 0;
	}
	i--;
	for(j=L->length;j>=i;j--)
		L->data[j]=L->data[j-1];
	L->data[i]=x;
	L->length++;
	return 1; 

}

//�������ɾ��
int ListDelete(Sqlist *L,int i)
{ 
	int j;
	if(i<1||i>L->length)
	{
		printf("��λ��û��Ԫ�أ��Ƿ�ɾ����\n");
		return 0;
	}
	i--;
	for(j=i;j<=L->length-1;j++)
		L->data[j]=L->data[j+1];
	L->length--;
	return 1; 

}

//����������
void ListPrint(Sqlist *L)
{ 
	int k;
	printf("�����ǰ˳�����Ԫ�����У�\n");
	for(k=0;k<L->length;k++)
		printf("%5d",L->data[k]); 
	printf("\n");

}

//��ʼ��
void ListInit(Sqlist *L)
{ 
	L->length=0;
}

//�˵���ʾ
void Menu()
{ 
	printf("1.˳���Ĳ������\n");
	printf("2.˳����ɾ������\n");
	printf("3.�˳�\n");
	printf("��ѡ��(1/2/3)��");

}

void ListCreat(Sqlist *L,int n)
{
	int k;
	for(k=0;k<n;k++)
		scanf("%d",&L->data[k]);
	L->length=n;
}

//������
main()
{ 
	int m,p,pl,num;
	Sqlist sq;
	printf("�����뽨��˳���ĳ��ȣ�\n");
	scanf("%d",&m);
	printf("����������˳�����Ԫ����ֵ��\n");
	
	ListInit(&sq);
	ListCreat(&sq,m);
	ListPrint(&sq);
	printf("\n");
	Menu();

	while(1){
		scanf("%d",&p);
		printf("\n");

		switch(p)
		{ 
		case 1:
			printf("����������Ԫ��λ�ã�\n");
			scanf("%d",&pl);
			printf("����������Ԫ����ֵ��\n");
			scanf("%d",&num);
			ListInsert(&sq,pl,num);
			ListPrint(&sq);
			printf("\n");
			printf("\n");
			Menu();
			break;
		case 2:
			printf("������ɾ����Ԫ��λ�ã�\n");
			scanf("%d",&pl);
			ListDelete(&sq,pl);
			ListPrint(&sq);
			printf("\n");
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