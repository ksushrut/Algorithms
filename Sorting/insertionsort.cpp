#include<iostream>
int main()
{
    int arr[4]={3,6,1,0};
    int i,j,temp,k;
    int len=sizeof(arr)/sizeof(arr[0]);
    std::cout<<"Array before sorting: \n";
    for(i=0;i<len;i++)
        std::cout<<arr[i]<<" ";
    
    //Insertion Sort Logic    
    for(i=1;i<len;i++)
    {
        temp=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>temp)              //Less than sign for descending
        {
            arr[j+1]=arr[j];           
            j--;
        }
        arr[j+1]=temp;
    }
    std::cout<<"\n*Array after sorting: \n";
    for(i=0;i<len;i++)
        std::cout<<arr[i]<<" ";
    return 0;
}