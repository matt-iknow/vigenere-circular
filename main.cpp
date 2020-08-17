#include "linkedlist.h"
#include <iostream>
#include <string>

using namespace std;
int main(){
    CircularLL vigenere_table;
    string text, key, ctext;
    int selection;
    cout << "-----Menu-----\n1. Encrypt\n2. Decrypt" << endl;
    cout << "\n";

    cin >> selection;
    switch(selection){
        case 1:
            cout << "input text: ";
            cin  >> text;
            cout << "input key: ";
            cin  >> key;
            cout << "\nencrypted text: " << vigenere_table.cipherText(text, key) << endl;
            break;
        case 2:
            //if(true);
            break;
        default:
            //if(true);
            break;
    }
    return 0;
}