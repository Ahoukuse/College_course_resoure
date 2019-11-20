#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	FILE *fp;
	int i=0;
	char *str[]={"Visual C++","Visual Basic","Dev-C++","Visual Foxpro"};
	if((fp=fopen("file9_4.txt","w"))==NULL)
	{
		printf("%s 不能打开！\n","file9_4.txt");
		exit(1);
	}
	while(i<4)
	{
		fprintf(fp,"%s\n",str[i]);
		i++;
	}
	fclose(fp);
	return 0;
}