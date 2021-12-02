#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubbleSort(int* array, int sizeOfArray)
{

    int i,j,k,temp=0;
    int* tempArray = malloc(sizeof(int)*sizeOfArray);
    int tempArr[sizeOfArray];
    // make ascending order
    for(i=0;i<sizeOfArray;i++)
    {
        for(j=0;j<sizeOfArray-i;j++)
        {
            if(array[j]>array[j+1])
            {
                temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
    }

    temp=sizeOfArray;
    // remove duplicate 
    for(i=0;i<sizeOfArray;i++)
    {
        for(j=i+1;j<sizeOfArray;j++)
        {
            if(array[i]==array[j])
            {
                for(k=j;k<sizeOfArray-1;k++)
                {
                    array[k]=array[k+1];
                }
                j--;
                sizeOfArray--;
            }
        }
    }

    for(i=sizeOfArray;i<temp;i++)
        array[i]=-1;
}

int compFunc(int* pages, int* workingset, int sizeOfPages, int sizeOfWS) // compare Pages&WS, remove elements in Pages not in WS
{
    int i,j=0;
    int temp=-1;
    int ret=-1;
    for(i=0;i<sizeOfPages;i++)
    {
        for(j=0;j<sizeOfWS;j++)
        {
            if((pages[i]==-1)||(pages[i]==workingset[j]))
                break;
        }
        if(j==sizeOfWS)
        {
            pages[i]=-1;
            temp=i;
        }
    }
    
    if(temp!=-1)
        ret=pages[temp];

    if(sizeOfPages<sizeOfWS) // synchronize two arrays 
    {
        for(i=0;i<sizeOfPages;i++)
            pages[i]=workingset[i];
    }
    else
    {
        for(i=0;i<sizeOfWS;i++)
            pages[i]=workingset[i];
    }

    return ret;
}

void wsFunc(int _page,int _windowSize,int _refStringSize,int* _refString)
{
    int faultCnt=0;
    int i,j,k=0;
    int flag=0;
    int out;
    int out2;
    int refSize=_refStringSize+_windowSize;
    int ref[refSize];

    FILE* fp3 = fopen("C:\\Users\\rhyth\\Desktop\\Github\\Undergraduate\\OS\\EXERCISE2\\output.txt","a");
    fprintf(fp3,"WS====================\n");
    /* init pages */
    int Pages[_page]; // memory
    for(i=0;i<_page;i++)
        Pages[i]=-1;
    int WS[_windowSize]; // working set
    for(i=0;i<_windowSize;i++)
        WS[_windowSize]=-1; 

    // init ref[] for dealing with minus time 
    for(i=0;i<_refStringSize;i++)
        ref[i+_windowSize]=_refString[i];
    for(i=0;i<_windowSize;i++)
        ref[i]=-1;
    
    
    for(i=_windowSize+1;i<refSize;i++)
    {
        bubbleSort(Pages,_page);

        for(j=0;j<_windowSize;j++) // renew Woking Set
            WS[j]=ref[i-_windowSize+j];

        bubbleSort(WS,_windowSize);
        // WS update OK 

        for(j=0;j<_page;j++)
        {
            if((Pages[j]!=-1)&&(Pages[j]==ref[i])) // hit 
            {
                out=compFunc(Pages,WS,_page,_windowSize); // compare Pages&WS, remove elements in Pages not in WS
                flag=1;
                for(k=0;k<_page;k++)
                    fprintf(fp3,"%d ",Pages[k]);
                if(out!=-1)
                    fprintf(fp3,"<-%d out",out);
                fprintf(fp3,"\n");
                break;
            }
        }

        if(flag==1)
        {
            flag=0;
            continue;
        }
        else if(flag==0) // miss, something problem here 
        {
            /* for test */
            /*for(k=0;k<_page;k++)
                printf("PAGES[%d] : %d ",k,Pages[k]);
            printf("\n");
            for(k=0;k<_windowSize;k++)
                printf("WS[%d] : %d ",k,WS[k]);
            printf("\n");*/

            faultCnt++;
            out2=compFunc(Pages,WS,_page,_windowSize);
            //Pages[in]=ref[i];
            for(k=0;k<_page;k++)
                fprintf(fp3,"%d ",Pages[k]);
            fprintf(fp3,"!! page fault !!");
            if(out2!=-1)
                fprintf(fp3,"<-%d out",out2);
            fprintf(fp3,"\n");
        }
    }

    
    fprintf(fp3,"TOTAL PAGE FAULT : %d\n",faultCnt);
    fclose(fp3);
}

int main(void)
{
    int page;
    int pageFrame; // not used in WS algorithm
    int windowSize; // only used in WS algorithm
    int refStringSize;
    int refString[1000];
    char buf[1024]; // buffer for input&output
    int i=0;

    FILE* fp = fopen("C:\\Users\\rhyth\\Desktop\\Github\\Undergraduate\\OS\\EXERCISE2\\input.txt","r"); 
    
    fgets(buf,sizeof(buf),fp); // get first line of input.txt

    // assign variables 
    page=atoi(buf);
    pageFrame=atoi(buf+2);
    windowSize=atoi(buf+4);
    refStringSize=atoi(buf+6);

    // error handling (input)
    for(i=0;i<4;i++)
    {
        if(*(buf+2*i)<-1||*(buf+2*i)>1001)
            {
                printf("input error\n");
                exit(0);
            }
    }
    if((refStringSize-windowSize)<0)
    {
        printf("size of window is less than size of reference string\n");
        exit(0);
    }

    i=0;

    fgets(buf,sizeof(buf),fp); // get second line of input.txt
    // assign string to array 
    char* ptr=strtok(buf," ");
    while(ptr!=NULL)
    {
        refString[i]=atoi(ptr);
        i++;

        ptr = strtok(NULL, " ");
    }

    fclose(fp);

    FILE* fp2 = fopen("C:\\Users\\rhyth\\Desktop\\Github\\Undergraduate\\OS\\EXERCISE2\\output.txt","w"); // make output.txt

    wsFunc(page,windowSize,refStringSize,refString);

    fclose(fp2);

    return 0;
}