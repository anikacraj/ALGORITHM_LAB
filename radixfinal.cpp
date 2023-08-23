#include<stdio.h>
int Maximum(int a[],int n)
{
    int i;
    int max=a[0];
    for(i=1; i<n; i++)
    {
        if(max<a[i])
        {
            max=a[i];
        }
    }
    return max;
}

void CountSort(int a[],int n,int pos)
{
    int count[10]= {0};
    int output[n],i;
    for(i=0; i<n; i++)
    {
        ++count[(a[i]/pos)%10];
    }
    for(i=0; i<10; i++){
        printf("%d ",count[i]);
    }
        printf("\n\n");
    for(i=1; i<10; i++)
    {
        count[i]=count[i]+count[i-1];
        printf("%d ",count[i]);
    }
        printf("\n\n");
    for(i=n-1; i>=0; i--)
    {
        output[count[(a[i]/pos)%10]-1]=a[i];
        count[(a[i]/pos)%10]--;
        printf("%d ",output[i]);
    }
        printf("\n\n");
    for(i=0; i<n; i++)
    {
        a[i]=output[i];
        printf("%d ",a[i]);
    }
    printf("\n\n");
}
void radix(int a[],int n)
{
    int m =Maximum(a,n),i=1;
    for(int pos=1; m/pos>0; pos*=10)
    {
        CountSort(a,n,pos);
        i++;
    }
}
int main()
{
    int a[]= {40, 1, 9, 300, 500, 100, 200, 2, 3};
    int n=sizeof(a)/sizeof(a[0]);
    radix(a,n);
    for(int i=0; i<n; i++)
    {
        printf(" %d",a[i]);
    }
}
