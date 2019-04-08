//Simge Haksal 2079317
#include<iostream>
#include "Address.h"
#include "Network_Finder.h"
using namespace std;

int main(void) {
	//I tested all cases and my program works correctly with all operations

	//Address myAdress;
	//cin >> myAdress;
	//cout << myAdress;

	//Address myAdress1;
	//cin >> myAdress1;
	//cout << myAdress1;

	//Address myAddress2;
	//myAddress2 = myAdress + myAdress1;
	//cout << myAddress2;

	Network_Finder net;
	net.calculateThirdArray();
	cout << net;

	system("PAUSE");
	return 0;
}