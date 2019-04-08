#pragma once
#ifndef NETWORK_FINDER_H
#define NETWORK_FINDER_H
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include "Address.h"
using namespace std;

class Network_Finder
{
private:
	int size;
	Address *Array1;//IP address
	Address *Array2;//Subnet masks
	Address *Array3;//Network address
public:
	Network_Finder() { // constructor initializer
		cout << "Enter the size of the array: ";
		cin >> size;
		Array1 = new Address[size];
		Array2 = new Address[size];
		Array3 = new Address[size];
		cout << "Enter the IP address in decimal format: ";
		for (int i = 0; i < size; i++) {
			cin >> Array1[i];
			if (Array1[i].getClass() == 'A') {
				int subnetMask[4] = { 255,0,0,0 };
				Array2[i].setAddress(subnetMask);
			}
			else if (Array1[i].getClass() == 'B') {
				int subnetMask[4] = { 255,255,0,0 };
				Array2[i].setAddress(subnetMask);
			}
			else if (Array1[i].getClass() == 'C') {
				int subnetMask[4] = { 255,255,255,0 };
				Array2[i].setAddress(subnetMask);
			}
		}
	}

	Network_Finder(Network_Finder &network) {
		this->size = network.size;
		Array1 = new Address[this->size];
		Array2 = new Address[this->size];
		Array3 = new Address[this->size];
		for (int i = 0; i < size; i++) {
			this->Array1[i] = network.Array1[i];
			this->Array2[i] = network.Array2[i];
			this->Array3[i] = network.Array3[i];
		}
	}

	Network_Finder operator= (const Network_Finder &network) {
		delete[] Array1;
		delete[] Array2;
		delete[] Array3;
		this->size = network.size;
		Array1 = new Address[this->size];
		Array2 = new Address[this->size];
		Array3 = new Address[this->size];

		for (int i = 0; i < size; i++) {
			this->Array1[i] = network.Array1[i];
			this->Array2[i] = network.Array2[i];
			this->Array3[i] = network.Array3[i];
		}
		return *this;
	}

	void calculateThirdArray() {
		for (int i = 0; i < size; i++)
			Array3[i] = Array1[i] * Array2[i];
	}

	friend ostream& operator << (ostream &out, Network_Finder &network) {
		cout << "Addrres1 -> [";
		for (int i = 0; i < network.size; i++)
			out << network.Array1[i];
		cout << "]" << endl;
		cout << "(Addrres2 -> ["<< endl;
		for (int i = 0; i < network.size; i++)
			out << network.Array2[i];
		cout << "]" << endl;
		cout << "Addrres3 -> [" << endl;
		for (int i = 0; i < network.size; i++)
			out << network.Array3[i];
		cout << "])" << endl;
		return out;
	}

	~Network_Finder(void) {
		delete[] Array1;
		delete[] Array2;
		delete[] Array3;
	}
};
#endif