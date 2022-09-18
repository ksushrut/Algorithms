#include<iostream>
int main()
{
    int arr[10]={3,6,1,0,2,8,9,4,7,5};
    int i,j,temp;
    int len=sizeof(arr)/sizeof(arr[0]);
    std::cout<<"Array before sorting: \n";
    for(i=0;i<len;i++)
        std::cout<<arr[i]<<" ";
    
    //BubbleSort Logic
    for(i=0;i<len;i++)
    {
        for(j=0;j<len;j++)
        {
            /*arr[i] > arr[j] implies the element to be compared with other elements is greater, swap it. Sorts in descending
            Lesser than sign sorts in ascending order*/
            if(arr[i]<arr[j])           
            {
                temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
            }
        }
    }
    std::cout<<"\nArray after sorting: \n";
    for(i=0;i<len;i++)
        std::cout<<arr[i]<<" ";
    return 0;
}