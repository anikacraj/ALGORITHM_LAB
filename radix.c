#include<stdio.h>


int Maximum(int a[], int n)
{
    int max = a[0];
    int i;
    for (i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}
void RadixSort(int a[], int n)
{
    int m = Maximum(a, n);


    for (int pos = 1; m / pos > 0; pos *= 10)
        CountSort(a, n, pos);
}


void CountSort(int a[], int n, int pos)
{

    int output[n];


    int i, cnt[10] = { 0 };


    for (i = 0; i < n; i++)
        cnt[(a[i] / pos) % 10]++;


    for (i = 1; i < 10; i++)
        cnt[i] =  cnt[i] +cnt[i - 1];


    for (i = n - 1; i >= 0; i--)
    {
        output[cnt[(a[i] /pos) % 10] - 1] = a[i];
        cnt[(a[i] /pos) % 10]--;
    }


    for (i = 0; i < n; i++)
        a[i] = output[i];
}






int main()
{

    int a[]= {21,3,123,432,453,4,5};

    int N=sizeof(a)/sizeof(a[0]);
    int i;
    RadixSort(a, N);
    for(i=0; i<N; i++)
    {
        printf("%d ",a[i]);
    }
}




