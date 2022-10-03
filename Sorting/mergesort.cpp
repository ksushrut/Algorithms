#include<iostream>
using namespace std;
void Merge(int arr[],int low, int mid, int high)
{
    int i, j, k;  
    int n1 = mid - low + 1;    
    int n2 = high - mid;          
    int LeftArray[n1], RightArray[n2]; //temporary arrays  
      
    /* copy data to temp arrays */  
    for (int i = 0; i < n1; i++)    
        LeftArray[i] = arr[low + i];    
    for (int j = 0; j < n2; j++)    
        RightArray[j] = arr[mid + 1 + j];    
      
    i = 0, /* initial index of first sub-array */  
    j = 0; /* initial index of second sub-array */   
    k = low;  /* initial index of merged sub-array */  
      
    while (i < n1 && j < n2)    
    {    
        if(LeftArray[i] <= RightArray[j])    
        {    
            arr[k] = LeftArray[i];    
            i++;    
        }    
        else    
        {    
            arr[k] = RightArray[j];    
            j++;    
        }    
        k++;    
    }    
    while (i<n1)    //copy remaining elements in Left array to into arr
    {    
        arr[k] = LeftArray[i];    
        i++;    
        k++;    
    }    
    while (j<n2)    //copy remaining elements in Right Array into arr
    {    
        arr[k] = RightArray[j];    
        j++;    
        k++;    
    }    
}    
void MergeSort(int arr[],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        MergeSort(arr,low,mid);
        MergeSort(arr,mid+1,high);
        Merge(arr,low,mid,high);
    }
}
int main()
{
    int len,i;
    int arr[]={3,6,1,0,9,2,4,8,5,7};
    len=sizeof(arr)/sizeof(arr[0]);
    MergeSort(arr,0,len);
    for(i=0;i<len;i++)
        cout<<arr[i]<<" ";
    return 0;
}