#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

#define YEL   "\x1B[33m"
#define RESET "\x1B[0m"


char str[20], *token[20];
int i,j=0,k=0;
char pipe[]="|",or[]="<",ir[]=">";


void listen()
{
	printf(YEL "MenduShell $ " RESET);
	gets(str);

}

void tokenizer()
{
	memset(token, 0, sizeof(token[0][0]) * 10 * 20);
	char *p;
	int i=0,j;
	for (p = strtok(str," "); p != NULL; p = strtok(NULL, " "))
	{
	  token[i]=p;
	  i++;
	}
	token[i]=NULL;
}

void execute()
{
	pid_t  pid;
	int status;
	
	pid=fork();
	wait(&status);
	if (pid == 0) 
	{          
          execvp(token[0], token);
	}
}


void main()
{


	system("clear");
	while(1)
	{
		listen();
		
		tokenizer();
		

		
		if(strcmp(token[0],"exit") == 0)
		{
			system("clear");
			exit(0);
		}
		
		execute();
		
		/*
		system(str);
		for(i=0;i<=j;i++)
		printf("%s\n",token[i]);
		*/
	}

}
