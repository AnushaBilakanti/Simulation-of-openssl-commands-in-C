hw1: main.o hex_dump.o enc_base64.o dec_base64.o
	gcc -g main.o hex_dump.o enc_base64.o dec_base64.o -o hw1

main.o: main.c functions.h
	gcc  -c -g -Wall main.c

hex_dump.o: hex_dump.c functions.h
	gcc  -c -g -Wall hex_dump.c

enc_base64.o: enc_base64.c functions.h
	gcc -c -g -Wall enc_base64.c

dec_base64.o: dec_base64.c functions.h
	gcc -g -c -Wall dec_base64.c

clean:
	rm *.o
	rm hw1

