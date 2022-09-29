/*
Make tree and perform dry run
Prepare a table of both strings
Start with 0, if match found, increment diagonal by 1 
else max of previous column and previous row
*/

#include<iostream>
using namespace std;
char A[]="stone";
char B[]="longest";
int LCSRecursion(int i,int j)
{
    if(A[i]=='\0' || B[j]=='\0')
        return 0;
    else if(A[i]==B[j])
        return 1+LCSRecursion(i+1,j+1);
    else    
        return max(LCSRecursion(i+1,j),LCSRecursion(i,j+1));
}
int main()
{
    cout<<LCSRecursion(0,0);
}
