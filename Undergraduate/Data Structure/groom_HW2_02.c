#include <stdio.h>

int row,col;
int wall[100][100];

int groupsize_check(int x,int y)
{
    wall[x][y]=1;

    if((y-1)>=0&&wall[x][y-1]==0)
        groupsize_check(x,y-1);
    if((x+1)<row&&wall[x+1][y]==0)
        groupsize_check(x+1,y);
    if((y+1)<col&&wall[x][y+1]==0)
        groupsize_check(x,y+1);
    if((x-1)>=0&&wall[x-1][y]==0)
        groupsize_check(x-1,y);
    
    return 0;
}

int main(void)
{
    int count=0;

    scanf("%d %d",&row,&col);

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            scanf("%d",&wall[i][j]);
        }
    }

    for(int i=0;i<row-1;i++)
    {
        for(int j=0;j<col-1;j++)
        {
            if(wall[i][j]==0&&wall[i+1][j]==0&&wall[i][j+1]==0&&wall[i+1][j+1]==0)
            {
                count++;
                groupsize_check(i,j);
            }
        }
    }

    printf("%d",count);

    return 0;
}