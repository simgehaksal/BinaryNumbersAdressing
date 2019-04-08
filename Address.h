#pragma once
#ifndef ADDRESS_H
#define ADDRESS_H
#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;

class Address
{
private:
	unsigned int decimal[4];
	unsigned int binary[4];
	char classification;
public:
	Address() { // default constructor
		for (int i = 0; i < 4; i++)
			this->decimal[i] = 0;

		this->findBinary();
		this->findClass();
	}

	Address(int decimal[4]) {
		for (int i = 0; i < 4; i++)
			this->decimal[i] = decimal[i];

		this->findBinary();
		this->findClass();
	}

	Address(Address &address) {
		for (int i = 0; i < 4; i++) {
			this->decimal[i] = address.decimal[i];
			this->binary[i] = address.binary[i];
		}
		this->classification = address.classification;
	}

	void setAddress(int decimal[4]) {
		for (int i = 0; i < 4; i++)
			this->decimal[i] = decimal[i];

		this->findBinary();
		this->findClass();
	}

	void findBinary(void) {
		int j;
		for (j = 0; j < 4; j++) {
			int n = decimal[j];
			int binaryNumber = 0;
			int remainder, i = 1, step = 1;
			while (n != 0) {
				remainder = n % 2;
				n /= 2;
				binaryNumber += remainder * i;
				i *= 10;
			}
			binary[j] = binaryNumber;
		}
	}

	void findClass(void) {
		//Reference-http://www.vlsm-calc.net/ipclasses.php
		// Class A: (1 - 126), Subnet = 255.0.0.0
		if ((decimal[0] > 1) && (decimal[0] <= 126))
			classification = 'A';
		// Class B : (128 - 191), Subnet = 255.255.0.0
		else if ((decimal[0] >= 128) && (decimal[0] <= 191))
			classification = 'B';
		// Class C : (192 - 223), Subnet = 255.255.255.0
		else if ((decimal[0] >= 192) && (decimal[0] <= 223))
			classification = 'C';
		else
			classification = 'F';//The general IP classes are from A to E. I assume that F means an invalid class.
	}

	char getClass() {
		return classification;
	}

	Address operator + (const Address &address) {
		Address temp;
		for (int i = 0; i < 4; i++)
			temp.decimal[i] = this->decimal[i] | address.decimal[i];

		temp.findBinary();
		temp.findClass();
		return temp;
	}

	Address operator = (const Address &address) {
		for (int i = 0; i < 4; i++) {
			this->binary[i] = address.binary[i];
			this->decimal[i] = address.decimal[i];
		}
		this->classification = address.classification;
		return *this;
	}

	Address operator * (const Address &address) {
		Address temp;
		for (int i = 0; i < 4; i++)
			temp.decimal[i] = this->decimal[i] & address.decimal[i];

		temp.findBinary();
		temp.findClass();
		return temp;
	}

	Address operator - (const Address &address) {
		Address temp;
		for (int i = 0; i < 4; i++)
			temp.decimal[i] = ~(this->decimal[i] | address.decimal[i]);

		temp.findBinary();
		temp.findClass();
		return temp;
	}

	double operator / (int x) {
		double total = 0;
		for (int i = 0; i < 4; i++) {
			total += this->binary[i] * pow(x, this->binary[i]);
			total += this->decimal[i] * pow(x, this->decimal[i]);
		}
		return total;
	}

	bool operator == (const Address &address) {
		if (this->classification != address.classification) return false;
		else {
			for (int i = 0; i < 4; i++) {
				if (this->binary[i] != address.binary[i])
					return false;
				else if (this->decimal[i] != address.decimal[i])
					return false;
			}
		}
		return true;
	}

	bool operator != (const Address &address) {
		return !(*this == address);
	}

	friend istream& operator >> (istream &in, Address &address) {
		for (int i = 0; i < 4; i++)
			in >> address.decimal[i];
		address.findBinary();
		address.findClass();
		return in;
	}

	friend ostream& operator << (ostream &out, Address &address) { //if binary starts with 0s, this will fill the beginning of the digits
		out << address.decimal[0] << "." << address.decimal[1] << "." << address.decimal[2] << "." << address.decimal[3] << endl;
		out << setfill('0') << setw(8) << address.binary[0] << ".";
		out << setfill('0') << setw(8) << address.binary[1] << ".";
		out << setfill('0') << setw(8) << address.binary[2] << ".";
		out << setfill('0') << setw(8) << address.binary[3] << endl;
		return out;
	}
};
#endif