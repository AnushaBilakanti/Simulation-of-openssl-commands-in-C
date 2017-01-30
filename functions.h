//will contain all the declarations
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CODES "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
#define PADDING "="

void read_data(FILE *fp);
void print_hex_data(unsigned char * buffer, int count);
void read_data_enc_base64(FILE *fp);
void read_data_dec_base64(FILE *fp);
