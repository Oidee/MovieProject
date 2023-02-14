#include"Header.h"
#include"Data.h"

Customers::Customers()
{

	this->customerID = 0;

	ReadCFile();
}

void Customers::ReadCFile() {

	int ID = 0;
	string line;
	ifstream inFile;
	inFile.open("customers.txt");

	if (!inFile.is_open()) {
		perror("File error.");
		exit(EXIT_FAILURE);
	}

	if (inFile.peek() == inFile.eof()) {
		return;
	}

	else {

		while (!inFile.eof()) {
			ID++;

			cIDQueue.push(ID);

			//read line with the number indicator but no need to push 
			//since ID is provided
			getline(inFile, line);

			getline(inFile, line);
			cNameQueue.push(line);

			getline(inFile, line);
			cAddressQueue.push(line);

		}
		inFile.close();
		customerID = ID;
	}

}


void Customers::AddCustomer()
{
	customerID++;

	cout << endl << endl;

	cout << "\t\t\t\t       Customer ID: " << customerID << endl;

	cin.ignore();

	cout << "\t\t\t\t       Name: ";
	getline(cin, customerName);

	cout << "\t\t\t\t       Address: ";
	getline(cin, customerAddress);

	//push new info into the respective queues
	cIDQueue.push(customerID);
	cNameQueue.push(customerName);
	cAddressQueue.push(customerAddress);

	cout << "\n\n\n\t\t\t              Customer sucessfully added!" << endl << endl;

	cout << "\n\t\t\t              ";

}


void Customers::saveCustomers() { // call sa 8

	ofstream outFile("customers.txt");

	if (!outFile.is_open()) {
		perror("File error.");
		exit(EXIT_FAILURE);
	}

	if (cNameQueue.front() == "")
	{
		return;
	}

	while (!cIDQueue.empty()) {

		outFile << cIDQueue.front();
		outFile << endl << cNameQueue.front();

		cIDQueue.pop();
		cNameQueue.pop();


		if (cIDQueue.empty()) {

			outFile << endl << cAddressQueue.front();

		}
		else
		{
			outFile << endl << cAddressQueue.front() << endl;
		}

		cAddressQueue.pop();
	}
	outFile.close();

}



void Customers::ShowDetails(int CsChoice)
{

	Rent rent;
	queue<int> cIDQueueNew = cIDQueue;
	queue<string> cNameQueueNew = cNameQueue;
	queue<string> cAddressQueueNew = cAddressQueue;



	for (int g = 1; g < CsChoice; g++) {
		cNameQueueNew.pop();
		cAddressQueueNew.pop();
	}

	cout << "\t\t\t\t       Customer ID: " << CsChoice << endl;
	cout << "\t\t\t\t       Customer Name: " << cNameQueueNew.front() << endl;
	cout << "\t\t\t\t       Customer Address: " << cAddressQueueNew.front() << endl << endl << endl;
	cout << "\t\t\t\t       ";


}

void Customers::ListRented()
{
	int customerID;
	Rent rent;
	cout << "\t\tEnter Customer ID: ";
	cin >> customerID;

	ShowDetails(customerID);
	cout << "       List of Videos Rented...\n\n" << "\t\t\t\t       Video ID            Movie Title\n\n\t\t\t\t\t";
}

void Customers::ListRented(int x)
{

	Rent rent;

	ShowDetails(x);
	cout << "       List of Videos Rented...\n\n" << "\t\t\t\t        Video ID            Movie Title\n\n\t\t\t\t\t";

}

Rent::Rent()
{

}

Rent::~Rent()
{

}


void Rent::returnMovie(int ex, int why)
{
	std::stringstream str;
	string line;
	int customer = ex;
	int movie = why;
	int compareC;
	int compareM;

	ifstream inFile("rent.txt");
	ofstream outFile("rent.txt");

	if (outFile.is_open())
	{

		while (getline(inFile, line))
		{

			str.str(line);
			str >> compareC;
			str >> compareM;

			str.clear();
			if (customer == compareC && movie == compareM)
			{

				continue;

			}
			else
			{

				outFile << line << endl;

			}

		}

	}

}

void Rent::saveRent(stack <int> tmp1, stack <int> tmp2)
{

	stack <int> movies = tmp1;
	stack <int> custies = tmp2;
	stack <int> saveIt;

	int item;

	ofstream outFile;
	outFile.open("rent.txt");

	while (!movies.empty())
	{

		item = movies.top();
		movies.pop();
		saveIt.push(item);

	}

	movies = saveIt;

	if (outFile.is_open())
	{

		while (!movies.empty()) {

			outFile << custies.top() << " " << movies.top() << endl;

			movies.pop();

		}

	}

	outFile.close();

}

