#include<iostream>
using namespace std;
int main()
{
    int arr[4]={3,6,1,0};
    int ele,i,len;
    cout<<"Enter an element to be searched: ";
    cin>>ele;
    len=sizeof(arr)/sizeof(arr[0]);
    for(i=0;i<len;i++)
    {
        if(arr[i]==ele)
        {
            cout<<"Element found at position "<<i+1;
            break;
        }

    }
    if(i==len)
        cout<<"Element not found";
    return 0;
}
