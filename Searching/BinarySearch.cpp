#include<iostream>
using namespace std;
int main()
{
    int arr[10]={2,5,9,13,19,25,55,100,104,111};
    int ele,low,high,mid;
    cout<<"Enter a number to be searched: ";
    cin>>ele;
    low=0;
    high=sizeof(arr) / sizeof(arr[0]);          //Calculating the length of the array using sizeof operator
    while(low<=high)                            
    {
        mid=(low+high)/2;                       //Get the middle of the array
        if(arr[mid]==ele)                       //Check if the element to be searched is in the middle
        {
            cout<<"Element found at "<<mid+1;
            break;
        }
        else                                    //If not, then search in the two subarrays partitioned at middle
        {
            if(arr[mid]>ele)                    //If element to be searched is smaller than element at middle, search in left subarray
                high=mid-1;                     
            else                                //Else search in right subarray
                low=mid+1;
        }    
    }                                           //Repeat till the condition holds true
    if(low>high)                                //This condition is true if entire array is traversed and element is not found
        cout<<"Element not in the array";
    return 0;
}
