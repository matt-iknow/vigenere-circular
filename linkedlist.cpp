#include "linkedlist.h"

CircularLL::CircularLL(){ //default, constructs a repeating sequence of all english letters
    _khead = nullptr;
    _ahead = new Node(65); //character A
    Node* currnode = _ahead;
    for(char i = 66; i <= 90; i++){ //characters B-Z
        currnode->_next = new Node(i);
        currnode = currnode->_next;
    }
    currnode->_next = _ahead; //linking final node back to head
    _asize = 26;
}
void CircularLL::initKey(string key){ //constructs a repeating sequence of key
    _khead = new Node(key[0]);
    Node* currnode = _khead;
    for(unsigned int i = 1; i < key.size(); i++){
        currnode->_next = new Node(key[i]);
        currnode = currnode->_next;
    }
    currnode->_next = _khead;
    _ksize = key.size();
}
CircularLL::~CircularLL(){
    //delete vigenere sequence
    Node* currnode = _ahead;
    Node* prevnode = nullptr;
    for(unsigned int i = 0; i < _asize; i++){
        delete currnode->_data;
        prevnode = currnode;
        if(currnode->_next != nullptr)
            currnode = currnode->_next;
        delete prevnode;
    }
    //delete key sequence
    currnode = _khead;
    prevnode = nullptr;
    for(unsigned int i = 0; i < _ksize; i++){
        delete currnode->_data;
        prevnode = currnode;
        if(currnode->_next != nullptr)
            currnode = currnode->_next;
        delete prevnode;
    }
}

string CircularLL::cipherText(string text, string key){
    initKey(key);
    string ctext;
    Node* curr_char = _ahead;
    Node* curr_keychar = _khead;
    for(unsigned int i = 0; i < text.size(); i++){
        while(*(curr_char->_data) != text[i])
            curr_char = curr_char->_next;
        for(char j = 0; j < *(curr_keychar->_data) - 65; j++)
            curr_char = curr_char->_next;
        ctext += *(curr_char->_data);
        curr_keychar = curr_keychar->_next;
    }
    return ctext;
}
