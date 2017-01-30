#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char entable[64]=CODES;

//finds the base_64 decoded values(3 characters) for the 4 characters
void print_dec_base64(unsigned char * buffer,int padding_count)
{

	char byte_buffer[4];
	int i;
	
	byte_buffer[0]=(buffer[0]<<2|buffer[1]>>4);
	byte_buffer[1]=(buffer[1]<<4|buffer[2]>>2);
	byte_buffer[2]=(buffer[2]<<6|buffer[3]>>0);

	if(padding_count==1)//if one '=' is encountered
	{
		printf("%c",byte_buffer[0]);
    	printf("%c",byte_buffer[1]);
	}
	else if(padding_count==2)//if two '=' is encountered
	{
		printf("%c",byte_buffer[0]);
	}
	else//if none of '=' is encountered
	{
		printf("%c",byte_buffer[0]);
		printf("%c",byte_buffer[1]);
		printf("%c",byte_buffer[2]);
	}
	for(i=0;i<3;i++)
		byte_buffer[i] = '\0';
}



void read_data_dec_base64(FILE *fp)
{
	unsigned char buffer[4]; //contains the four initial characters read
	unsigned char input[4];//contains the integer values of the characaters got from mapping(entable)
	// char *ch = (char *)malloc(sizeof(char));
	char ch; 
	
	int l;
	int i=0;
	while(!feof(fp))
	{
		
		ch=fgetc(fp);
		
		if(ch!='\n')//ignoring the newline
		{
			buffer[i]=ch;
			i++;
		}
	
		if(i==4)//if 4 characters are read
		{
			int k=0;
			int invalid_char=1;
			int padding_count=0;
			while(k<4)
			{
				if(buffer[k]=='=')
				{
					input[k]=0;
					invalid_char=0;
					padding_count++;
				}
				for (l =0; l < 64; ++l)
				{
					if(buffer[k]==entable[l])//entable contains list of characters
					{
						input[k]=l;
						invalid_char=0;
					}
				}
				if (invalid_char==1)
				{
					fprintf(stderr,"Error: Unknown character\n");
				}
				k++;
			}
			print_dec_base64(input,padding_count);
			i=0;
		}		
	}//end of file
			
}

