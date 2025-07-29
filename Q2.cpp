#include<stdio.h>

int main()
{
    int n;
    printf("enter the no. of elements:");
    scanf("%d",&n);

    int arr[n];
    int sum=0;
    printf("enter %d integers:",n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
            sum+=arr[i];
        }
        float avg=(float)sum/n;
        printf("the avg is:%.2f/n",avg);

    return 0;
}


