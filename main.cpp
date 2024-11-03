#include <iostream>
#include <unistd.h>
#include "caesar.h"
using namespace std;

int main(int argc, char** argv){
	char opt;
	string inputFile;
	string outputFile;
	int eflag, dflag, iflag, oflag;
	eflag = 0;
	dflag = 0;
	iflag = 0;
	oflag = 0;
	while( (opt = getopt(argc, argv, "i:o:ed")) != -1){
		switch(opt){
			case 'i':
				iflag = 1;
				inputFile = optarg;
				break;
			case 'o':
				oflag = 1;
				outputFile = optarg;
				break;
			case 'e':
				eflag = 1;
				break;
			case 'd':
				dflag = 1;
				break;
			default:
				cout << "Unknown option " << argv[0] << endl;
		}
	}
	if(argc != 6 || (iflag == 0) || (oflag == 0) ||
			(eflag == dflag)){
		cout << "Error!" << endl;
	}else{
		cout<< "Welcome to the Caesar Cipher"<< endl;
		if(eflag==1){
			int shiftVal;
			cout<<"Selected Mode: Encrypt"<<endl;
			cout<<"Input File: "<<inputFile<<endl;
			cout<<"Output File: "<<outputFile<<endl;
			cout<<"Please enter the shift value (1-25): ";
			cin >> shiftVal;
			while(shiftVal>26||shiftVal<1){
				cout<<"The shift value should be between 1-25"<<endl;
				cout<<"Please enter the shift value (1-25): ";
				cin>>shiftVal;
			}
			encrypt(shiftVal,inputFile, outputFile);
			cout<<endl<<"Encrypted ciphertext binary file created: "<<outputFile<<endl;
		}else if(dflag==1){
			int shiftVal;
			cout<<"Selected Mode: Decrypt"<<endl;
			cout<<"Input File: "<<inputFile<<endl;
			cout<<"Output File: "<<outputFile<<endl;
			cout<<"Please enter the shift value (1-25): ";
			cin >> shiftVal;
			while(shiftVal>25||shiftVal<1){
				cout<<"The shift value should be between 1-25"<<endl;
				cout<<"Please enter the shift value (1-25): ";
				cin>>shiftVal;
			}
			decrypt(shiftVal,inputFile, outputFile);
			cout<<endl<<"Decrypted plaintext file created: "<<outputFile<<endl;
		}
		return 0;
	}
}

