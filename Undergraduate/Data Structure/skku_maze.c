#define MAX_STACK_SIZE 100

typedef struct
{
    short int vert; //-1, 0, +1
    short int horiz; // -1, 0, +1
} offsets;

typedef struct 
{
    short int row;
    short int col;
    short int dir;
} element; 

element stack[MAX_STACK_SIZE];
int maze[MAX_ROWS][MAX_COLS], mark[MAX_ROWS][MAX_COLS];
offsets move[8];
int top;

void path(void)
{
    int i,row,col,nextRow,nextCol,dir,found=FALSE;
    element position;

    mark[1][1]=1; top=0;
    stack[0].row=1; stack[0].col=1; stack[0].dir=1; 

    while(top-1>&&!found)
    {
        position=pop();
        row=position.row;
        col=position.col;
        dir=position.dir;
    

        while(dir<8&&!found)
        {
            nextRow=row+move[dir].vert;
            nextCol=col+move[dir].horiz;
            if(nextRow==EXIT_ROW && nextCol==EXIT_COL)
                found==TRUE;
            else if (!maze[nextRow][nextCol]&&!mark[nextRow][nextCol])
            {
                mark[nextRow][nextCol]=1;
                position.row=row; position.col=col;
                position.dir=++dir;
                push(position);
                row=nextRow; col=nextCol; dir=0;
            }
            else ++dir;
        }
    }
}