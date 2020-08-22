#include "linkedlist.h"
#include <iostream>
#include <string>

using namespace std;
bool isValid(string& text, string& key);

int main(){
    VigenereLL vigenere;
    string sel, text, key, ctext;
    bool valid_input;
    int selection;
    cout << "-----Menu-----\n1. Encrypt\n2. Decrypt\n3. Exit." << endl;
    cout << "SELECTION: ";
    getline(cin, sel);
    selection = stoi(sel);

    cout << endl;
    switch(selection){
        case 1:
            valid_input = false;
            while(!valid_input){
                cout << "Input text to encrypt: ";
                getline(cin, text);
                cout << "Input desired key: ";
                getline(cin, key);
                if(isValid(text,key)){
                    valid_input = true;
                }else{
                    cout << "Invalid input. Input cannot contain special characters." << endl;
                }
            }
            cout << "ENCRYPTED RESULT: " << vigenere.encryptText(text, key) << endl;
            break;
        case 2:
            valid_input = false;
            while(!valid_input){
                cout << "Input encrypted text to decrypt: ";
                getline(cin, ctext);
                cout << "Input key for decryption: ";
                getline(cin, key);
                if(isValid(ctext, key)){
                    valid_input = true;
                }else{
                    cout << "Invalid input. Input cannot contain special characters." << endl;
                }
            }
            cout << "DECRYPTED RESULT: " << vigenere.decryptText(ctext, key) << endl;
            break;
        case 3:
            break;
        default:
            break;
    }
    return 0;
}


bool isValid(string& text, string& key){
    for(unsigned int i = 0; i < text.size(); i++){
        char cur = text[i];
        if(cur >= 97 && cur <=122){
            cur = cur-32;
            text[i] = cur;
        }else if (cur >= 65 && cur <= 90){
            //expected input
        }else{
            return false;
        }
    }
    for(unsigned int i = 0; i < key.size(); i++){
        char cur = key[i];
        if(cur >= 97 && cur <=122){
            cur = cur-32;
            key[i] = cur;
        }else if (cur >= 65 && cur <= 90){
            //expected input
        }else{
            return false;
        }
    }
    return true;
}