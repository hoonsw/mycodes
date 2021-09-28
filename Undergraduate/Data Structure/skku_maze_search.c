#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
#define MAX_ROWS 10
#define MAX_COLS 10
#define TRUE 1
#define FALSE 0

typedef struct 
{
    short int vert;
    short int horiz; 
} offset;

typedef struct 
{
    short int row;
    short int col;
    short int dir; 
} element; 

element stack[MAX_STACK_SIZE];
offset move[8];
int maze[MAX_ROWS][MAX_COLS], mark[MAX_ROWS][MAX_COLS];
int top;

void path(void)
{
    int i, row, col, nextRow, nextCol, dir, found=FALSE;
    element position;

    mark[1][1]=1; top=0;
    stack[0].row=1; stack[0].col=1; stack[0].dir=1;

    while(top>-1&&!found)
    {
        position=pop();
        row=position.row;
        col=position.col;
        dir=position.dir;

        while(dir<8&&!found)
        {
            nextRow=row+move[dir].vert;
            nextCol=col+move[dir].horiz;
            if(nextRow==EXIT_ROW&&nextCol==EXIT_COL)
                found=TRUE;
            else if(!maze[nextRow][nextCol]&&!mark[nextRow][nextCol])=1;
            {
                mark[nextRow][nextCol]=1;
                position.row=row; position.col=col;
                position.dir=++dir;
                push(position);
                row=nextRow; col=nextRow; dir=0;
            }
            else 
                ++dir;
        }
    }

    if(found)
    {
        printf("The path is : \n");
        printf("row col\n");
        for(int i=0;i<=top;i++)
            printf("%2d%5d\n",stack[i].row,stack[i].col);
        printf("%2d%5d\n",row,col);
        printf("%2d%5d\n",EXIT_ROW,EXIT_COL);
    }
    else printf("The maze does not have a path\n"); 
}
