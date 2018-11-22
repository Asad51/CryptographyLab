#include <bits/stdc++.h>
using namespace std;

class OneTimePad
{
	string key;
	int length;
public:
	OneTimePad(string k){
		key = k;
		length = k.size();
	}

	string encrypt(string plainText){
		string cipherText;
		for(int i = 0; i < length; i++){
			if(plainText[i] >= 'A' && plainText[i] <= 'Z'){
				char ch = ((plainText[i] - 'A') + (key[i] - 'A')) % 26 + 'A';
				cipherText += ch;
			}
			else if(plainText[i] >= 'a' && plainText[i] <= 'z'){
				char ch = ((plainText[i] - 'a') + (key[i] - 'a')) % 26 + 'a';
				cipherText += ch;
				if(ch < 'a' && ch > 'z')
					cout << ch <<" "<< plainText[i] << " "<< key[i]<<endl;
			}
			else
				cipherText += plainText[i];
		}
		return cipherText;
	}

	string decrypt(string cipherText){
		string plainText;
		for(int i = 0; i < length; i++){
			if(cipherText[i] >= 'A' && cipherText[i] <= 'Z'){
				int tmp = (cipherText[i] - 'A') - (key[i] - 'A');
				char ch = (tmp < 0) ? tmp + 26 + 'A' : tmp + 'A';
				plainText += ch;
			}
			else if(cipherText[i] >= 'a' && cipherText[i] <= 'z'){
				int tmp = (cipherText[i] - 'a') - (key[i] - 'a');
				char ch = (tmp < 0) ? tmp + 26 + 'a' : tmp + 'a';
				plainText += ch;
			}
			else
				plainText += cipherText[i];
		}
		return plainText;
	}

	~OneTimePad(){

	}
	
};

string generateKey(string msg){
	string capsLetters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string smallLetters = "abcdefghijklmnopqrstuvwxyz";
	string key;
	for(int i=0; i<msg.size(); i++){
		int randomNumber = rand() % 26;
		if(msg[i] >= 'A' && msg[i] <= 'Z')
			key += capsLetters[randomNumber];
		else if(msg[i] >= 'a' && msg[i] <= 'z')
			key += smallLetters[randomNumber];
		else{
			key += msg[i];
		}
	}
	return key; 
}

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	string msg, key;
	string plaintext, cipherText;
	while(getline(cin, msg)){
		key = generateKey(msg);
		OneTimePad otp(key);
		cipherText = otp.encrypt(msg);
		cout << "OTP key : " << key << "\n";
		cout << "Encrypted Message: " << cipherText << "\n";
		cout << "Decrypted Message: " << otp.decrypt(cipherText) << "\n\n";
	}
	return 0;
}

