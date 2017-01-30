#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//finds the base_64 encoded values(4 characters) for the 3 characters
void print_enc_base64(unsigned char * buffer,int count,int * char_count,int *first_time)
{

	char entable[64]=CODES;
	unsigned char * byte_buffer=(unsigned char*) malloc(4*sizeof(char)); //will contain 4 encoded characters
	int i;

	byte_buffer[0]=entable[(buffer[0] & 0xFC)>>2];
	byte_buffer[1]=entable[((buffer[0] & 0x03)<<4)|((buffer[1] & 0xF0)>>4)];

	if (count==0)
	{
		if(*char_count<64)
		{
			printf("\n");
		}
		exit(0);
	}
	if(count==1)//if only 1 of 3-byte character is read
	{
		byte_buffer[2]='=';
		byte_buffer[3]='=';
	}
	else if (count==2)//if only 2 of 3-byte character is read
	{
		
		byte_buffer[2]=entable[((buffer[1] & 0x0F)<<2)|((buffer[2] & 0xC0)>>6)];
		byte_buffer[3]='=';
	}
	else if (count==3)//if all 3-byte character are read
	{
		byte_buffer[2]=entable[((buffer[1] & 0x0F)<<2)|((buffer[2] & 0xC0)>>6)];
		byte_buffer[3]=entable[(buffer[2] & 0x3F)];
	}
	for (i = 0; i < 4; i++)//used to print 64 characters on a line
	{
		if((*char_count)==64 && (*first_time)==1)
		{
			printf("%c\n",byte_buffer[i]);
			*first_time=0;
			*char_count=0;
		}
		else if((*char_count)==63 && (*first_time)!=1)
		{
			printf("%c\n",byte_buffer[i]);

			*char_count=0;
		}
		else
		{

			printf("%c",byte_buffer[i]);
			(*char_count)++;
		}
	}
	free(byte_buffer);
	
}

//reads 3 or less characters from the input file
void read_data_enc_base64(FILE *fp)
{
	unsigned char * buffer=(unsigned char*) malloc(3*sizeof(char));
	int count,k;

	int  char_count=1;
	int first_time=1;
	while(!feof(fp))
	{

		count=fread(buffer,sizeof(char),3,fp);

		if(count==0)//if no characters are read
		{
			buffer[0]='0';
			buffer[1]='0';
			buffer[2]='0';
		}
		if(count==1)//if only one character is read
		{
			buffer[1]=0;
			buffer[2]=0;
		}
		else if (count==2)//if two characters are read
		{
			buffer[2]=0;
		}

		print_enc_base64(buffer,count,&char_count,&first_time);
		
		for (k = 0; k < 4; ++k)
		{
			buffer[k]='\0';
		}
	}
	printf("\n");
	fclose(fp);
	free(buffer);
}



 
