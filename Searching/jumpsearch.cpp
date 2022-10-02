#include<iostream>
using namespace std;
int main()
{
    int arr[8]={3,5,9,15,19,29,37,40};
    int ele,i=0,len,step,j;
    cout<<"Enter an element to be searched: ";
    cin>>ele;
    cout<<"Enter step size: ";
    cin>>step;
    len=sizeof(arr)/sizeof(arr[0]);
    while(i<len && arr[i]<=ele)
        i+=step;
    for(j=i-step;j<i;j++)
    {
        if(ele==arr[j])
        {
            cout<<"Element found at position "<<j+1;
            break;
        }
    }
    if(j==len+1)
        cout<<"Element not found";
    return 0;
}