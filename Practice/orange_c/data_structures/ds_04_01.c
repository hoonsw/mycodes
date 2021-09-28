int pmatch(char* string, char* par)
{
    int i=0; int j=0;
    int lens=strlen(string); int lenp=strlen(pat);
    while(i<lens&&j<lenp)
    {
        if(string[i]==pat[j]) {i++; j++;}
        else if (j==0) i++;
        else {j=failure[j-1]+1;}
    }
    return (j==lenp?i-lenp:-1);
}


for(i=0,j=0;i<lens&&j<lenp;i++)
{
    if(string[i]==pat[j]) {j++;}
    else if (j==0) i++;
    else {j=failure[j-1]+1;i--;}
}
return (j==lenp?i-lenp:-1);


void fail(char* pat)
{
    int n=strlen(pat);
    failure[0]=-1;
    for(int j=0;j<n;j++)
    {
        int i=failure[j-1];
        while (pat[j]!=pat[i+1]&&i>=0)
            i=failure[i];
        if (pat[j]==pat[i+1]) failure[j]=i+1;
        else failure[j] = -1;
    }
}