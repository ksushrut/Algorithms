#include<iostream>
using namespace std;
/*
Quick sort works on the logic that an element is in its sorted place if 
all elements to the right are smaller than it and to the left are greater than it
1. It is based on Divide and Conquer approach
2. Pivot can be first, last, random or median value of the array
*/
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int arr[],int low, int high)
{
    int pivot=arr[low];
    int i,j;
    i=low,j=high;
    while(i<j)
    {
        do
        {
            i++;
        } while (arr[i]<=pivot);
        do
        {
            j--;
        } while (arr[j]>pivot);
        if(i<j)
        {
            swap(&arr[i],&arr[j]);
        }        
    }
    /*Now the actual position of pivot is j. So swap element at j with arr[low]*/
    swap(&arr[low],&arr[j]);
    return j;
}
void QuickSort(int arr[],int low,int high)
{
    int p;
    if(low<high)
    {
        p=partition(arr,low,high);
        QuickSort(arr,low,p);
        QuickSort(arr,p+1,high);
    }
}
int main()
{
    int arr[8]={3,6,1,0,7,2,4,5};
    int high,low=0,i;
    high=(sizeof(arr)/sizeof(arr[0]));
    QuickSort(arr,low,high);
    for(i=0;i<high;i++)
        cout<<arr[i]<<" ";
    return 0;
}