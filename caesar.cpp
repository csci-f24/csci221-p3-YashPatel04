#include <fstream>
#include "caesar.h"
#include <iostream>
#include <string>
using namespace std;

int addition(int val, int shift){
	int f = shift+val;
	if(val<=122 && val>=97){
		if(f>122){
			f = f-122;
			val = 96 + f;
			return val;
		}else{
			return f;
		}
	}else if(val>=65 && val<=90){
		if(f>90){
			f = f - 90;
			val = 64+f;
			return val;
		}else{
			return f;
		}
	}else{
		return val;
	}	
}

int subtraction(int val, int shift){
	int f = val-shift;
	if(val<=122 && val>=97){
		if(f<97){
			f = shift - (val - 96);
			val = 122-f;
			return val;
		}else{
			return f;
		}
	}else if(val>=65 && val<=90){
		if(f<65){
			f = shift - (val - 64);
			val = 90 - f;
			return val;
		}else{
			return f;
		}
	}else{
		return val;
	}	
}
void decrypt(int shift, string inputFile, string outputFile) {
    string line;
    string out;
    fstream outFile(outputFile, ios::out);
    fstream myfile(inputFile, ios::in);
    
    if (myfile.is_open()) {
        while (getline(myfile, line)) {  // Read each line
            for (char c : line) {
                int val = int(c);
                val = subtraction(val, shift);
                out += static_cast<char>(val);
            }
            out += '\n';  // Preserve line breaks
        }
        myfile.close();
        
        if (outFile.is_open()) {
            outFile << out;
            outFile.close();
        } else {
            cout << "Unable to open the output file." << endl;
        }
    } else {
        cout << "Unable to open the file!" << endl;
    }
}

void encrypt(int shift, string inputFile, string outputFile) {
    string line;
    string out;
    fstream outFile(outputFile, ios::out);
    fstream myfile(inputFile, ios::in);
    
    if (myfile.is_open()) {
        while (getline(myfile, line)) {  // Read each line
            for (char c : line) {
                int val = int(c);
                val = addition(val, shift);
                out += static_cast<char>(val);
            }
            out += '\n';  // Preserve line breaks
        }
        myfile.close();
        
        if (outFile.is_open()) {
            outFile << out;
            outFile.close();
        } else {
            cout << "Unable to open the output file." << endl;
        }
    } else {
        cout << "Unable to open the file!" << endl;
    }
}

