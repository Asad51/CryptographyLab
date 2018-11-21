#include <bits/stdc++.h>
using namespace std;

class TranspositionCipher
{
	int row, col, fullCol, extRow;
	char plainTable[100][100];
public:
	TranspositionCipher(int w, int p){
		col = min(w, p);
		row = floor(double(p)/double(w));
		fullCol = p % col;
		extRow = ceil(double(fullCol)/double(col));
	}

	string encrypt(string p){
		string cipherText;
		for(int j=0; j<col; j++){
			for(int i=0; i<row + extRow; i++){
				if(i >= row && j >= fullCol)
					continue;
				int k = i * col + j;
				cipherText += p[k];
			}
		}
		return cipherText;
	}

	string decrypt(string c){
		string plainText;
		for(int i=0; i<row + extRow; i++){
			for(int j=0; j<fullCol; j++){
				int k = (row + extRow) * j + i;
				plainText += c[k];
			}
			if(i<row){
				for(int j=0; j<col - fullCol; j++){
					int k = (fullCol * (row + extRow)) + (row * j) + i;
					plainText += c[k];
				}
			}
		}
		return plainText;
	}

	~TranspositionCipher(){

	}
};

int main(int argc, char const *argv[])
{
	int width;
	string plainText, cipherText;
	while(cin>>width){
		getchar();
		getline(cin, plainText);
		TranspositionCipher tp(width, plainText.size());
		cipherText = tp.encrypt(plainText);
		cout<<"Encrypted Text: "<<cipherText<<endl;

		cout<<"Decrypted Text: "<<tp.decrypt(cipherText)<<endl;
	}
	return 0;
}
