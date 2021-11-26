#ifndef Binary_H
#define Binary_H

#include <string>
#include <bitset>

using std::string;
using std::to_string;
using std::bitset;

class Binary{
private:
    int _size;
    string _valueString;
    bitset<100> _bitValue;

public:
    Binary(){ }

    Binary(int input[],int s){
        if(s == 0) {
            throw string("error");
        }

        _size = s;
        for(int i = 0; i < _size; i++) {
            int currentBit = input[i];
            if(currentBit != 0 && currentBit != 1) {
                throw string("error");
            }
            _valueString += to_string(currentBit);
        }

        _bitValue = bitset<100>(_valueString);

    }
    Binary(const Binary & b){
        _size = b._size;
        _bitValue = b._bitValue;
        _valueString = b._valueString;
    }

    ~Binary(){ }

    Binary & operator=(Binary const &b){
        _size = b._size;
        _bitValue = b._bitValue;
        _valueString = b._valueString;
        return *this;
    }

    Binary operator+(Binary const &b){
        int result = this->toInt() + b.toInt();
        this->_bitValue = bitset<100>(result);
        _valueString =  _bitValue.to_string().substr(100 - _size, _size);
        int sizeOfLimit = _size > b._size ? _size : b._size;
        for(int i = 0; i < 100; i++) {
            if(i >= sizeOfLimit && _bitValue[i] == 1) {
                throw string("error");
            }
        }
        return *this;
    }

    Binary operator-(Binary const &b){
        int result = this->toInt() - b.toInt();
        if(result < 0) {
            throw string("error");
        }
        this->_bitValue = bitset<100>(result);
        _valueString =  _bitValue.to_string().substr(100 - _size, _size);
        return *this;
    }

    Binary operator>>(int a){ 
        _bitValue >>= a;
        _valueString =  _bitValue.to_string().substr(100 - _size, _size);
        return *this;
    }

    Binary operator<<(int a){
        _bitValue <<= a;
        _valueString =  _bitValue.to_string().substr(100 - _size, _size);
        return *this;
    }

    void resize(int new_size){
        if(new_size < _size) {
            throw string("Error");
        }

        for(int i = _size; i < new_size; i++) {
            _valueString = "0" + _valueString;
        }
        _bitValue = bitset<100>(_valueString);
        _size = new_size;
    }
    
    void setBit(int pos,int a){
        if(a != 0 && a != 1) {
            throw string("error");
        }

        if(pos >= _size) {
            throw string("error");
        }

        _bitValue.set(_size - 1 - pos, a);
        _valueString =  _bitValue.to_string().substr(100 - _size, _size);
    }

    int toInt() const{
        return (int)_bitValue.to_ullong();
    }

    string toString() const{
        return _valueString;
    }
};

#endif
