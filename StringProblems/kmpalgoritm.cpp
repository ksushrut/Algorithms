#include<iostream>
#include<cstring>
using namespace std;
void computeLPSArray(char* pat, int M, int* lps);
void KMPSearch(char* pat, char* txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
    // lps or pi table is a structure that holds longest prefix suffix
    int lps[M];
    computeLPSArray(pat, M, lps);    
    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    /*
    t=ababcabd
    p=abcabd
    */
    while ((N - i) >= (M - j))
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }
 
        if (j == M)
        {
            printf("Found pattern at index %d ", i - j);
            j = lps[j - 1];
        }
        else if (i < N && pat[j] != txt[i])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}
void computeLPSArray(char* pat, int M, int* lps)
{
    //lps or pi maintains length of the previous longest prefix suffix
    int len = 0;
 
    lps[0] = 0; // lps[0] is always 0
 
    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M) 
    {
        /* abcabd
           000120 
        */
        if (pat[i] == pat[len]) 
        {
            len++;
            lps[i] = len;
            i++;
        }
        else 
        {
            if (len != 0) 
                len = lps[len - 1];
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
int main()
{
    char txt[] = "abcabcd";
    char pat[] = "abcd";
    KMPSearch(pat, txt);
    return 0;
}