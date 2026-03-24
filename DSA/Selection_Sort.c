#include<stdio.h>
#include<time.h>
#include<stdlib.h>
clock_t start,end;
int n;
void main()
{
    int i,j,min_idx,n;
     printf("Enter Size of N: ");
    scanf("%d",&n);
   
    int A[n];
    for(int i=0;i<n;++i)
        A[i] = rand()%100;


    printf("Unsorted Array:-\n");  
  for(int i=0;i<n;++i)
        printf("%d ,",A[i]);


    start = clock();
    for(i=0; i<n-1; ++i)
    {
        min_idx = i;
        for(j=i+1 ; j<n ;++j){
            if(A[j] < A[min_idx]){
                min_idx = j;
    }   
        int temp=A[i];
        A[i] =A[min_idx];
        A[min_idx]=temp;
    }
}
end = clock();
printf("Sorted Array:-\n");
    for(int i=0;i<n;++i)
        printf("%d ,",A[i]);
printf("Time Taken: %lfms\n",(end-start)/(double)(CLOCKS_PER_SEC)*1000);
}
