#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>


int CountWords(char* dirname, char* word)
{
	DIR *dir=NULL;
	struct dirent *entry;
	struct stat buf; 
	char buffer[LINE_MAX];
	int count=0;
	
	if((dir=opendir(dirname))==NULL)
	{
		puts("cannot open directory"); 
		return 0;
	}

	while((entry=readdir(dir))!=NULL)
	{
		if(strcmp(entry->d_name,".")==0||strcmp(entry->d_name,"..")==0)
			continue;	

		char path[PATH_MAX]={"\0",};
		strcat(path,dirname);
		strcat(path,"/");
		strcat(path,entry->d_name);
		
		if(entry->d_type==DT_DIR)
		{
			count+=CountWords(path,word);
		}
		if(entry->d_type==DT_REG)
		{
			FILE *fp = fopen(path,"r");
			if(fp==NULL)
				puts("cannot open file");
			while(fgets(buffer,LINE_MAX,fp)!=NULL)
			{
				char *ptr = strstr(buffer,word);
				while(ptr!=NULL)
				{
					count++;
					ptr = strstr(ptr+1,word);
				}	
			}
			fclose(fp);
		}	
	}
	closedir(dir);

	return count; 
}

int main(int argc, char* argv[])
{
	printf("%d \n",CountWords(argv[1],argv[2]));
	return 0; 
}



