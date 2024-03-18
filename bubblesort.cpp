#include<iostream>
#include<string>
<<<<<<< HEAD
#include<algorithm>
#include<iomanip>
#include<vector>

using namespace std;

const int N=1e6+10;
int q[N];
int n;

void quicksort(int q[],int l,int r) {
	if(l>=r)return ;
	int x=q[(l+r)/2],i=l-1,j=r+1;
	while(i<j)
	{
		do i++;while(q[i]<x);
		do j--;while(q[j]>x);
		if(i<j)swap(q[i],q[j]);
	}
	quicksort(q,l,j);
	quicksort(q,j+1,r);
}

int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&q[i]);
	quicksort(q,0,n-1);
	for(int i=0;i<n;i++)printf("%d ",q[i]);
	system("pause");
=======
using namespace std;
void swap(double &a,double &b)
{
    double temp = a;
    a = b;
    b = temp;
}
void bubblesort(double *arr,int length)
{
    for (int i = 0; i < length-1 ;i++)
        for (int j = 0; j < length - i-1;j++)
        {
        if(arr[j]>arr[j+1])
            swap(arr[j], arr[j + 1]);
        }
}
int main()
{
    double arr[]={5,2,8,1,3};
    int length = sizeof(arr) / sizeof(arr[0]);
    bubblesort(arr, length);
    for (int i = 0; i < length;i++)
        cout << arr[i] << " ";
        system("pause");
    return 0;
>>>>>>> 6d812e57760ad6850d713a4df4d869c5147588f0
}