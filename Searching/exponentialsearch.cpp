#include<iostream>
using namespace std;
void BinarySearch(int arr[],int low,int high,int ele)
{    
    int mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(arr[mid]==ele)
        {
            cout<<"Element found at "<<mid+1;
            break;
        }
        else if(arr[mid]<ele)
            low=mid+1;
        else
            high=mid-1;
    }
    if(low>high)
        cout<<"Element not found!";
}
int main()
{
    int arr[10]={2,5,9,13,19,25,55,100,104,111};
    int ele,step,i=1,length;
    cout<<"Enter a number to be searched: ";
    cin>>ele;
    cout<<"Enter the step size:";
    cin>>step;
    length=sizeof(arr)/sizeof(arr[0]);
    if(ele==arr[0])
        cout<<"Element foun at position 1";
    while(i<length && ele>arr[i])
        i*=step;
    BinarySearch(arr,i/step,length,ele);
    return 0;    
}