#pragma once
#include <string>

using namespace std;
class CircularLL{ //vigenere table as a circular linked list
    struct Node{
        Node* _next = nullptr;
        const char* _data = nullptr;
        Node(char character){
            _data = new char(character);
        }
    };
    Node* _ahead;
    Node* _khead;
    unsigned int _asize;
    unsigned int _ksize;

    public:
        CircularLL();
        ~CircularLL();
        void initKey(string key);
        string encryptText(string text, string key);
        string decryptText(string ctext, string key);
};