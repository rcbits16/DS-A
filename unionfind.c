#include <stdio.h>

#define MAXN 100000

int arr[2][MAXN];

void merge(int a, int b);
int findp(int x);

int main(void)
{
//Read number of points.
    int n,u,i,a,b,nc;
    scanf("%d",&n);
    //Populate array
    for(i=0;i<n;++i)
    {
        arr[1][i]=i;
    }
    //No. of union operations and the pairs to carry them upon
    scanf("%d",&u);
    for(i=0;i<u;++i)
    {
        scanf("%d %d",&a,&b);
        merge(a,b);
    }
    //No. of checking union queries and pairs to carry them upon.
    scanf("%d",&nc);
    for(i=0;i<nc;i++)
    {
        scanf("%d %d",&a,&b);
        if(findp(a)==findp(b)) printf("yes\n");
        
        else printf("no\n");
        
    }
}

void merge(int a, int b)
{
    int roota,rootb;
    roota= findp(a);
    rootb= findp(b);
 
    if(roota==rootb) return;
    if(arr[0][roota]<arr[0][rootb]) arr[1][roota] = rootb;
    else if(arr[0][roota]>arr[0][rootb]) arr[1][rootb] = roota;
    else
    {
        arr[1][roota] = rootb;
        arr[0][rootb] += 1;
    }
}
int findp(int x)
{
    if(arr[1][x] != x)  arr[1][x]= findp(arr[1][x]);
    
    return arr[1][x];   
}
