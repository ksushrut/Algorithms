/*Rabin Karp alogrithm is a string searching algorithm.
It makes use of a hash function to find the value of the pattern. Assign values to letters in the pattern and compute its hash value.
Check the hash value in the text.
Spurious hits can occur due to same hash values.
Solution for spurious hits: multiply the value of letter with power of length of pattern
Variables:
d is the number of characters in the input alphabet
text=Larger string
pat=Pattern to be searched
n=length of text
m=length of pattern
q=prime number for hashing and reduce the power value
h=hash value
p=hash value of pattern
t=hash value of text
*/
#define d 256
#include<iostream>
#include<cstring>
using namespace std;
void search(char text[],char pat[],int q)
{
    int n=strlen(text);
    int m=strlen(pat);
    int i,j,p=0,t=0,h=1;
    for(i=0;i<m-1;i++)
        h=(h*d)%q;
    for(i=0;i<m;i++)
    {
        p=(p*d+pat[i])%q;
        t=(t*d+text[i])%q;        
    }
    for (i = 0; i <= n-m; i++)
    {        
        if (p == t)
        {
            // Check for characters one by one
            for (j = 0; j < m; j++)
            {
                if (text[i + j] != pat[j])
                {
                    break;
                }
            }
            if (j == m)
                cout << "Pattern found at index " << i
                     << endl;
        }
 
        // Calculate hash value for next window of text. Remove leading digit, add trailing digit
        if (i < n-m) 
        {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
 
            // We might get negative value of t, converting it to positive
            if (t < 0)
                t = (t + q);
        }
    }
}
int main()
{
    char text[] = "ABCDEF";
    char pat[] = "DEF";
    int q = 11;
    search(text,pat,q);
    return 0;
}
