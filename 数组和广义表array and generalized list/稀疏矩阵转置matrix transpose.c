/*****��Ԫ�������ʾ��ϡ�����ת��*****/
#include <stdio.h>
typedef struct{
	int i,j;//����Ԫ�����±�����±�
	int e;
}Triple;

typedef struct{
	Triple data[100];
	int mu,nu,tu;//����������������ͷ���Ԫ����
}TSMatrix;

void TransposeSMatrix(TSMatrix M,TSMatrix *T)
{
	int q,col,p;
	(*T).mu=M.nu;
	(*T).nu=M.mu;
	(*T).tu=M.tu;
	if((*T).tu)
	{
		q=1;
		for(col=1;col<=M.nu;++col)
			for(p=1;p<=M.tu;++p)
				if(M.data[p].j==col)
				{
					(*T).data[q].i=M.data[p].j;
					(*T).data[q].j=M.data[p].i;
					(*T).data[q].e=M.data[p].e;
					++q;
				}
	}
}

void InputSMatrix(TSMatrix *M)
{
	int r;
	printf("������ϡ����������������������Ԫ����\n");
	scanf("%d%d%d",&(*M).nu,&(*M).mu,&(*M).tu);
	for(r=1;r<=(*M).tu;r++)
	{
		printf("�������%d������Ԫ�ص������У������У�Ԫ��ֵ����Ԫ���\n",r);
		scanf("%d",&(*M).data[r].i);
		scanf("%d",&(*M).data[r].j);
		scanf("%d",&(*M).data[r].e);
	}
	printf("\n");
}

void PrintM(TSMatrix M)
{
	int x,y,n,k;
	printf("ԭ����Ϊ��\n");
	for(x=1;x<=M.nu;x++)
	{
		for(y=1;y<=M.mu;y++)
		{
			k=0;
			for(n=1;n<=M.tu;n++)
				if((M.data[n].i==x)&&(M.data[n].j==y))
				{
					printf("%3d",M.data[n].e);
					k=1;
				}
				if(k==0)
					printf("%3d",k);
		}
		printf("\n");
	}
}



void PrintT(TSMatrix T)
{
	int x,y,n,k;
	printf("ת�ú����Ϊ��\n");
	for(x=1;x<=T.nu;x++)
	{
		for(y=1;y<=T.mu;y++)
		{
			k=0;
			for(n=1;n<=T.tu;n++)
				if((T.data[n].i==x)&&(T.data[n].j==y))
				{
					printf("%3d",T.data[n].e);
					k=1;
				}
				if(k==0)
					printf("%3d",k);
		}
		printf("\n");
	}
}

main()
{
	TSMatrix M,T;
	InputSMatrix(&M);
	PrintM(M);
	printf("\n");
	TransposeSMatrix(M,&T); 
	PrintT(T);
}