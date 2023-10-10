#include<iostream>
#include<string>
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
}