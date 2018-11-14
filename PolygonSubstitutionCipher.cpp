#include<bits/stdc++.h>
using namespace std;

class Polygram{
    ofstream encrypted, decrypted;
    string str1, str2;
    string plainText, cipherText;
    map<string, string>blocks1, blocks2;
public:
    Polygram(){
        encrypted.open("encrypted.txt");
        decrypted.open("decrypted.txt");
    }

    string generaterandonString(){
        string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
        string s;
        for(int i=0; i<3; i++){
            int st = rand()%62;
            s += chars[st];
        }
        
        return s;
    }

    void generateCombination(string p){
        ofstream combination;
        combination.open("combination.txt");
        map<string, string>comb;
        for(int i = 0; i < p.size();)
        {
            string s, randomString;
            for(int j = 0; j < 3 && i<p.size(); j++)
                s += p[i++];

            while(true){
                randomString = generaterandonString();
                if(comb.count(randomString) <= 0){
                    break;
                }
            }

            comb[randomString] = s;
            //cout<< comb[randomString] << "-" <<randomString<<endl;
            combination << s << " " << randomString << endl;
        }
        combination.close();
    }

    void readCombination(){
        ifstream combination;
        combination.open("combination.txt");
        while(combination >> str1 >> str2){
            blocks1[str1] = str2;
            blocks2[str2] = str1;
            //cout<<blocks2[str2] << "-" <<blocks1[str1]<<endl;
        }
        combination.close();
    }

    string encrypt(string p){
        for(int i = 0; i < p.size();)
        {
            string s;
            for(int j = 0; j < 3 && i < p.size(); j++)
                s += p[i++];
           // cout<<s<< "-" <<blocks1[s]<<endl;
            cipherText += blocks1[s];

        }
        encrypted << cipherText;
        return cipherText;
    }

    string decrypt(string c){
        for(int i = 0; i < c.size();)
        {
            string s;
            for(int j = 0; j < 3; j++)
                s += c[i++];
            plainText += blocks2[s];

        }
        decrypted << plainText;
        return plainText;
    }

    ~Polygram(){
        encrypted.close();
        decrypted.close();
    }

};

int main(){
    string plainText, cipherText, str;
    srand(time(NULL));
    while(getline(cin, str)){
        for(int i=0; i<str.size(); i++){
            if(str[i] == ' ')
                str[i] = char(169);
        }
        //cout<<str<<endl;
        Polygram pl;
        pl.generateCombination(str);
        pl.readCombination();
        cipherText = pl.encrypt(str);
        cout << "Cipher Text : " << cipherText << endl;
        plainText = pl.decrypt(cipherText);
        for(int i=0; i<plainText.size(); i++){
            if(plainText[i] < 0)
                plainText[i] = ' ';
            //cout<<int(plainText[i])<<endl;
        }
        cout << "Original Text : " << plainText << "\n\n";
    }
	return 0;
}
