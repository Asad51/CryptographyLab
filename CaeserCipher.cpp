/**
 * Suppose you are given a line of text, find out the
 * corresponding Caeser Cipher (i.e. character three to the right modulo 26)
 * Then perform the reverse operation to get original plaintext
 */

#include <bits/stdc++.h>
using namespace std;

class CaeserCipher
{
	int length, plainText, cipherText;
public:
	CaeserCipher(int l){
		length = l; 
	}

	string encrypt(string p){
		for(int i=0; i<p.size(); i++){
			if(p[i] >= 'A' && p[i] <= 'Z')
				p[i] = (p[i]-'A' + length) % 26 + 'A';
			else if(p[i] >= 'a' && p[i] <= 'z')
				p[i] = (p[i]-'a' + length) % 26 + 'a';
		}
		return p;
	}

	string decrypt(string c){
		for(int i=0; i<c.size(); i++){
			if(c[i] >= 'A' && c[i] <= 'Z')
				c[i] = (c[i] - 'A' - length + 26) % 26 + 'A';
			else if(c[i] >= 'a' && c[i] <= 'z')
				c[i] = (c[i] - 'a' - length + 26) % 26 + 'a';
		}
		return c;
	}

};

int main(int argc, char const *argv[])
{
	int length;
	string plainText, cipherText;
	while(cin >> plainText >> length){
		CaeserCipher cp(length);
		cipherText = cp.encrypt(plainText);
		cout << "Encrypted Text : " << cipherText << "\n";
		cout << "Original Plaintext : " << cp.decrypt(cipherText) << "\n";
	}
	return 0;
}
