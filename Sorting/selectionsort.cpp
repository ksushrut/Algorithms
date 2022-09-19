#include<iostream>
int main()
{
    int arr[4]={3,6,1,0};
    int i,j,temp,k,min;
    int len=sizeof(arr)/sizeof(arr[0]);
    std::cout<<"Array before sorting: \n";
    for(i=0;i<len;i++)
        std::cout<<arr[i]<<" ";
    
    //Selection Sort Logic
    for(i=0;i<len-1;i++)
    {
        min=i;
        for(j=i+1;j<len;j++)
        {
            if(arr[min]>arr[j])
                min=j;                
            temp=arr[min];
            arr[min]=arr[j];
            arr[j]=temp;
        }
    }
    std::cout<<"\n*Array after sorting: \n";
    for(i=0;i<len;i++)
        std::cout<<arr[i]<<" ";
    return 0;
}