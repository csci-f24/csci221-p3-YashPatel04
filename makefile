.PHONY:all clean

encrypt:
	./main -e -i plaintext.txt -o CaesarCipher.bin
decrypt:
	./main -d -o plaintext.txt -i CaesarCipher.bin

all:CaesarCipher

CaesarCipher: caesar.o main.o
	@g++ main.o caesar.o -o main
caesar.o: caesar.cpp caesar.h
	@g++ -c -O2 caesar.cpp
main.o:
	@g++ -c -O2 main.cpp
clean:
	@rm -f *.o main
