/*Develop a Program in C for the following operations on Strings.
Read a main String (STR), a Pattern String (PAT) and a Replace String (REP)
Perform Pattern Matching Operation: 
Find and Replace all occurrences of PAT in STR with REP if PAT exists in STR.
 Report suitable messages in case PAT does not exist in STR.*/

 
#include <stdio.h>
#include <string.h>
int main()
{
    char str[100], pat[100], rep[100], ans[200];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; 
    printf("Enter a pattern string: ");
    fgets(pat, sizeof(pat), stdin);
    pat[strcspn(pat, "\n")] = '\0';
    printf("Enter a replace string: ");
    fgets(rep, sizeof(rep), stdin);
    rep[strcspn(rep, "\n")] = '\0';
    int i=0, j=0, m=0, c=0, k=0, flag=0;
    while(str[c] != '\0')
    {
        i = c;
        j = 0;
        while(str[i] != '\0' && pat[j] != '\0' && str[i] == pat[j])
        {
            i++;
            j++;
        }
        if(pat[j] == '\0') 
        {
            flag = 1;
            
            for(k=0; rep[k] != '\0'; k++, m++)
                ans[m] = rep[k];
            c = i; 
        }
        else
        {
            ans[m++] = str[c];
            c++;
        }
    }


    ans[m] = '\0';

    if(flag == 0)
        printf("Pattern not found in the main string.\n");
    else
        printf("Result after replacement: %s\n", ans);


    return 0;
}
