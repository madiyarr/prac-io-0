#include <stdio.h>
int i, N, buf;
int a[100];
void Merge(int l, int m, int r) {
	int l1,l2;
	int buff[100];
	l1=i=l;
	l2=m;
	while ((l1<m)&&(l2<r)) {
		if (a[l1]<a[l2]) {
			buff[i]=a[l1];
			++l1;
		}
		else {	
			buff[i]=a[l2];
			++l2;
		}
		++i;
	}
	while (l2<r) {
		buff[i]=a[l2];
		++l2;
		++i;
	}
	while (l1<m) {
		buff[i]=a[l1];
		++l1;
		++i;
	}
	for (i=l; i<r; i++)
		a[i]=buff[i];
}
int MergeSort(int l, int r) {
	int m;
	if (r-l==1)
		return a[l];
	m=(l+r)/2;
	MergeSort(l, m);
	MergeSort(m, r);
	Merge(l,m,r);
}

int QuickSort(int l, int r) {
	int pivot, l1, r1;
	//if (r-l<=2)
	//	return ?;
	pivot=a[(l+r)/2];
	l1=l;
	r1=r;
        while (l1<r1) 
	{
		while (a[l1]<pivot)
			++l1;
		while (a[r1]>pivot)
			--r1;
		if (l1<=r1)
		{
			printf("%d with %d\n", a[r1],a[l1]);
			buf=a[r1];
			a[r1]=a[l1];
			a[l1]=buf;
			++l1;
			--r1;
		}
        }
	if (l1<r) 
		QuickSort(l1,r);
	if (l<r1) 
		QuickSort(l,r1);
}

int MaxHeapify(int l, int r)
{
	int child;
	i=l;
	while (2*i<=r)
	{
		child = 2*i;
        if ((child+1<=r) && (a[child+1]>a[child]))
		child++;
        if (a[child]>a[i])
        {
			printf("%d with %d\n", a[child],a[i]);
			buf = a[child];
			a[child] = a[i];
			a[i] = buf;
            i=child;
        }
        else break;
	}
}
int HeapSort(int n)
{ 	int j;
	for (j=n; j>0; j--)
		MaxHeapify(j,n);
	for (j=n; j>0; j--)
		{	
			printf("%d with %d\n", a[j],a[1]);
			buf = a[j];
			a[j] = a[1];
			a[1] = buf;
			MaxHeapify(1, j-1);}
	return 0;
}

int main() {
	printf("Input N:");
	scanf("%d", &N);
	for (i=1; i<=N; i++)
		scanf("%d", &a[i]);
	//MergeSort(1, N+1);
	//QuickSort(1, N);
	HeapSort(N);
        printf("Sorted:");
	for (i=1; i<=N; ++i)
		printf("%d ", a[i]);
	return 0;
}


	
