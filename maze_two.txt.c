#include <stdio.h>
int solve(int m[100][100],int a[100][100],int c,int r,int n)
{
    int i,j;
    if(r==n&&c==n)
    {
        a[r][c]=1;
        return 1;
    }
    if((r<n&&(m[r+1][c]==1))||r!=n&&c==n&&(m[r+1][c]==1))
    {
       if(solve(m,a,c,r+1,n))
       {
           a[r+1][c]=1;
           return 1;
       }
    }
    if((c<n&&(m[r][c+1]==1))||(r==n&&c!=n&&(m[r][c+1]==1)))
    {
        if(solve(m,a,c+1,r,n))
        {
            a[r][c+1]=1;
            return 1;
        }
    }
    return 0;
}

int main(void) {
	// your code goes here
	int i,j,n;
	scanf("%d",&n);
	int m[100][100],a[100][100];
	for(i=1;i<=n;i++)
	{
	    for(j=1;j<=n;j++)
	    {
	        scanf("%d",&m[i][j]);
	        a[i][j]=0;
	    }
	}
	a[1][1]=1;
	if(solve(m,a,1,1,n))
	{
	   for(i=1;i<=n;i++)
	{
	    for(j=1;j<=n;j++)
	    {
	        printf("%d ",a[i][j]);
	    }
	    printf("\n");
	} 
	}
	return 0;
}

