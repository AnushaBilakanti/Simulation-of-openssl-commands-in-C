#include "functions.h"
int address=0;


//finds the hex values of the 16 characters
void print_hex_data(unsigned char * buffer,int count)
{
	
	
	printf("%06x: ",address);	
	address=address+16;
	int i;
	for(i=0;i<8;i++) //to print the first 8 bytes
	{
		if(count<8 && i>=count)
		{
			printf("-- ");
		}
		else
		{
			printf("%02x ",buffer[i]);
		}

	}
	printf(" ");
	for(i=8;i<16;i++) //to print the next 8 bytes(8-16)
	{
		if(count<16 && i>=count)
		{
			printf("-- ");
		}
		else
		{
			printf("%02x ",buffer[i]);
		}

	}
	printf(" ");
	/*Display of ASCII characters*/
	for(i=0;i<8;i++) //to print the first 8 ASCII characters
	{
		if(count<8 && i>=count)
		{
			printf(" ");
		}
		else
		{
			if(buffer[i]>=0x20 && buffer[i]<=0x7e)
			{
				printf("%c",buffer[i]);
			}
			else if (buffer[i]<=0x1f || buffer[i]==0x7f)
			{
				printf(".");
			}
			else if (buffer[i]>=0x80)
			{
				printf("~");
			}
		}

	}
	for(i=8;i<16;i++) //to print the next 8 ASCII characters(8-16)
	{
		if(count<16 && i>=count)
		{
			printf(" ");
		}
		else
		{
			if(buffer[i]>=0x20 && buffer[i]<=0x7e)
			{
				printf("%c",buffer[i]);
			}
			else if (buffer[i]<=0x1f || buffer[i]==0x7f)
			{
				printf(".");
			}
			else if (buffer[i]>=0x80)
			{
				printf("~");
			}
		}

	}

	printf("\n");
}


//reads 16 characters from file
void read_data(FILE *fp)
{
	unsigned char * buffer=(unsigned char*) malloc(16);
	int count,k;

	while(!feof(fp))
	{
		
		count=fread(buffer,sizeof(char),16,fp);
		print_hex_data(buffer,count);
		
		for(k = 0; k < 16; ++k)
		{
			buffer[k]='\0';
		}
	}
	fclose(fp);
	free(buffer);
}
