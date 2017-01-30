#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "functions.h"
int main(int argc, char const *argv[])
{

	if(argc<2 || argc>3)
	{
		fprintf(stderr, "Error-invaid input\n");
	}
	if(argc==2)//read from standard input
	{
		if(strcmp(argv[1],"hexdump")==0)
		{
			read_data(stdin);
		}
		else if(strcmp(argv[1],"enc-base64")==0)
		{
			read_data_enc_base64(stdin);
		}
		else if(strcmp(argv[1],"dec-base64")==0)
		{
			read_data_dec_base64(stdin);
		}
		else
		{
			fprintf(stderr, "Error-invaid input\n");
		}

	}
	if(argc==3)//read from file
	{
		FILE * fp=NULL;
		fp=fopen(argv[2],"rb");
		if (fp==NULL)
		{
			fprintf(stderr, "Error-no valid input file\n");
			exit(0);
		}
		if(strcmp(argv[1],"hexdump")==0)
		{
			read_data(fp);
		}
		else if(strcmp(argv[1],"enc-base64")==0)
		{
			read_data_enc_base64(fp);
		}
		else if(strcmp(argv[1],"dec-base64")==0)
		{
			read_data_dec_base64(fp);
		}
		else
		{
			fprintf(stderr, "Error-invaid input\n");
		}

	}
	return 0;
}
