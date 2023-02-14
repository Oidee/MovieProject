#pragma once

#include <iostream>
#include <string>
#include <queue>
#include <list>
#include <stack>
#include <vector>
#include <fstream>
#include <sstream>
#include <chrono>
#include <thread>
#include <windows.h>
#include <ShellApi.h>
#include <conio.h>


using namespace std;

class Customers
{
private:

	int customerID;
	string customerName;
	string customerAddress;

	queue<int> cIDQueue;
	queue<string> cNameQueue;
	queue<string> cAddressQueue;

public:

	Customers();

	void ReadCFile();
	void AddCustomer();
	void ShowDetails(int Cschoice);
	void ListRented();
	void ListRented(int);
	void saveCustomers();

	int menu7();
};

class Rent : public Customers
{

private:

	stack <int> movieRentStack;
	stack <int> customerRentStack;

public:

	Rent();
	~Rent();

	void returnMovie(int ex, int why);
	void saveRent(stack <int> tmp1, stack <int> tmp2);

};

