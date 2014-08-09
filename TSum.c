#include<stdio.h>
#define SIZE 1000000

/*void merge(long el[],long start,long end)
{
	long mid=(start+end)/2;
	//~ printf("2start: %ld end: %ld\n",start,end);
	long n1=mid-start+1;
	long n2=end-mid+1;
	long t1[n1];
	long t2[n2];
	long i,j;
	//~ printf("H1\n");
	for(i=0;i<n1;i++)
	{
		t1[i]=el[start+i];
	}
	for(j=0;j<n2;j++)
	{
		t2[j]=el[mid+1+j];
	}
	i=0;
	j=0;
	//~ printf("H2\n");
	long k=start;
	while((i<n1)&&(j<n2))
	{
		if(t1[i]<t2[j])
		{
			el[k]=t1[i];
			i++;
		}
		else
		{
			el[k]=t2[j];
			j++;
		}
		k++;
	}
	//~ printf("H3\n");
	while(i<n1)
	{
		el[k]=t1[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		el[k]=t2[j];
		j++;
		k++;
	}
	//~ printf("H4\n");
}

void mSort(long el[],long start,long end)
{
	
	if(end>start)
	{
		long mid=(start+end)/2;
		//~ printf("1start: %ld end: %ld\n",start,end);
		mSort(el,start,mid);
		mSort(el,mid+1,end);
		//~ printf("start: %ld end: %ld\n",start,end);
		merge(el,start,end);
	}
}*/

void swap(long A[],long i,long j)
{
	long temp=A[i];
	A[i]=A[j];
	A[j]=temp;
}

void qSort(long A[],long i,long j)
{
	if(j>i)
	{
		long pindex=i+1;
		long pivot=A[i];
		long k;
		for(k=i+1;k<=j;k++)
		{
			if(A[k]<pivot)
			{
				swap(A,k,pindex);
				pindex++;
			}
		}
		swap(A,i,pindex-1);
		qSort(A,i,pindex-2);
		qSort(A,pindex,j);
	}
}
int main()
{
	FILE* f=fopen("2sum.txt","r");
	long i;
	long el[SIZE];
	for(i=1;i<=SIZE;i++)
	{
		fscanf(f,"%ld",&el[i]);
	}
	qSort(el,1,SIZE);
	//~ printf("%ld\n",el[500000]);
	return 0;
}
