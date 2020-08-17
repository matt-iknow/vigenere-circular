#include "linkedlist.h"
#include <iostream>
#include <string>

using namespace std;
int main(){
    CircularLL vigenere;
    string text, key, ctext;
    bool valid_input;
    int selection;
    cout << "-----Menu-----\n1. Encrypt\n2. Decrypt\nEnter any other character to exit." << endl;
    cout << "\n";

    cin >> selection;
    switch(selection){
        case 1:
            valid_input = false;
            while(!valid_input){
                cout << "input text: ";
                cin  >> text;
                cout << "input key: ";
                cin  >> key;
                if(true){ //TODO: filter for valid input
                    valid_input = true;
                }
            }
            cout << "\nencrypted text: " << vigenere.encryptText(text, key) << endl;
            break;
        case 2:
            valid_input = false;
            while(!valid_input){
                cout << "input encrypted text: ";
                cin  >> ctext;
                cout << "input key: ";
                cin  >> key;
                if(true){ //TODO: filter for valid input
                    valid_input = true;
                }
            }
            cout << "\ndecrypted text: " << vigenere.decryptText(ctext, key) << endl;
            break;
        default:
            break;
    }
    return 0;
}


bool isValid(string& text, string& key){
    return true;
}