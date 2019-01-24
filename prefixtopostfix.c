#include<stdio.h>
#include<stdlib.h>
char* pretopost(char *pre,char *post)
{
	if(*pre>='a' && *pre<='z')
	{
		strncat(post,pre,1);
		return pre;
	}
	else
	{
		char *p=pretopost(pre+1,post);
		p=pretopost(p+1,post);
				strncat(post,pre,1);
				return p;
	}
}
void main()
{
	char pre[20];
	char post[20]="";
	printf("enter a expression");
	scanf("%s",pre);
	pretopost(pre,post);
	printf("the converted string is %s",post);
}

