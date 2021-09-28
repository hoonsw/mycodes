#include <stdio.h>

int r, c;
int a[100][100];

int groupsize_check(int x,int y);

int main(void)
{
    int i, j;
    int cnt=0;

    scanf("%d %d", &r, &c);
    for(i=0 ; i<r ; i++)
    {
        for(j=0 ; j<c ; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    for(i=0 ; i<r-1 ; i++)
    {
        for(j=0 ; j<c-1 ; j++)
        {
            if(a[i][j]==0&&a[i+1][j]==0&&a[i][j+1]==0&&a[i+1][j+1]==0)
            {
                cnt++;
                groupsize_check(i,j);
            }
        }
    }

    printf("%d\n", cnt);

    return 0;
}

int groupsize_check(int x,int y)
{
    a[x][y]=1;
    if(0<=(y-1) && a[x][y-1]==0)
    {
        groupsize_check(x,y-1);
    }
    if((x+1)<r && a[x+1][y]==0)
    {
        groupsize_check(x+1,y);
    }
    if((y+1)<c && a[x][y+1]==0)
    {
        groupsize_check(x,y+1);
    }
    if(0<=(x-1) && a[x-1][y]==0)
    {
        groupsize_check(x-1,y);
    }
    return 0;
}
