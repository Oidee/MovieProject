#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <Windows.h>
#include <dos.h>
#include <cstdlib>
#include <stdio.h>
#include <conio.h>
#include <fstream>
#include <windows.h>
#include "Data.h"
#include"Header.h"


using namespace std;

int menu();

int csMenu();

int main()
{
	//declare object of eachoiceoice classes
	videoList video;
	Customers customerNow;
	Rent rent;

	int customerID;
	int vidID;           // myCode
	string vidTitle;     // myTitle
	string vidGenre;     // myGenre
	string vidProd;      // myYear
	int vidCopy;
	string vidImage;     /// myImage

	int vidRent;



	int csChoice;

	int csIDchoice;

	int choice;                                 // choice from menu

	do
	{
		choice = menu();

		if (choice == 1)
		{

			video.addVideo();

			system("pause");
			system("CLS");

		}

		else if (choice == 2)
		{
			cout << "\n\n\n\n\n\n\n\n";
			cout << "\t|-----------------------------<< Rent a Movie >>----------------------------------|" << endl;
			cout << "\t|^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^|" << endl << endl << endl;
			cout << "\t                              Enter a Customer ID: ";
			cin >> customerID;
			customerNow.ShowDetails(customerID);
			video.rentVideo(customerID);
			cout << "        ";
			system("pause");
			system("CLS");


		}

		else if (choice == 3)
		{
			cout << "\n\n\n\n\n\n\n\n";
			cout << "\t|-------------------------------<< Return a Video >>------------------------------|" << endl;
			cout << "\t|^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^|" << endl;
			cout << "\t                              Enter a Customer ID: ";
			cin >> customerID;
			customerNow.ListRented(customerID);
			video.vidLoad(customerID);
			video.returnVideo(customerID);

			cout << "\n\t\t\t\t\t";

			system("pause");
			system("CLS");

		}

		if (choice == 4)
		{
			cout << "\n\n\n\n\n\n\n\n";
			cout << "\t|----------------------<< Showing the details of a specific video >>-------------------|" << endl;
			cout << "\t|^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v|" << endl;
			cout << "\t                              Enter Movie ID: ";
			cin >> vidID;
			cin.ignore();
			video.vidDetails(vidID);
			cout << "        ";
			system("pause");
			system("CLS");

		}



		else if (choice == 5)
		{
			cout << "\n\n\n\n\n\n\n\n";
			cout << "\t|----------------------------<< Displaying all Movies >>-----------------------------|" << endl;
			cout << "\t|^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v|" << endl;
			video.vidDisplayMovies();
			cout << "        ";
			system("pause");
			system("CLS");

		}

		else if (choice == 6)
		{
			cout << "\n\n\n\n\n\n\n\n";
			cout << "\t|----------------------<< Checking the Availability of the Video >>-------------------|" << endl;
			cout << "\t|^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^|" << endl;
			cout << "\t                              Enter Movie ID: ";
			cin >> vidID;

			cin.ignore();
			video.vidAvail(vidID);
			cout << endl;
			cout << "\t\t\t\t";
			system("pause");
			system("CLS");

		}
		else if (choice == 7) {

			do
			{
				csChoice = csMenu();

				switch (csChoice)
				{
				case 1:
					customerNow.AddCustomer();
					//			cout << "\n\n\tPress ENTER to go back to the menu...  ";
					system("pause");
					system("CLS");
					break;

				case 2:
					cout << endl << endl;
					cout << "\t\t\t\t       Enter customer ID: ";
					cin >> csIDchoice;
					customerNow.ShowDetails(csIDchoice);
					//			cout << "\n\n\tPress ENTER to go back to the menu...  ";
					system("pause");
					system("CLS");
					break;

				case 3:
					cout << endl << endl;
					cout << "\t\t\t\t       Enter customer ID: ";
					cin >> csIDchoice;
					customerNow.ListRented(csIDchoice);
					video.vidLoad(csIDchoice);
					//			movie.pleaseLoad(custIDchoice);
					//			cout << "\n\n\tPress ENTER to go back to the menu...  ";
					system("pause");
					system("CLS");
				}
			} while (csChoice >= 1 && csChoice <= 3);

		}
		else if (choice == 8)
		{
			cout << "\t\t\t\tThank you for using the program!" << endl;
			video.saveMovie();
			customerNow.saveCustomers();
			exit(0);
		}

	} while (choice >= 1 && choice <= 8);
}

int menu()
{
	int choice;

	cout << "\n\n\n";
	cout << "|--------------------------------------<< Welcome to Codehead >>--------------------------------------|" << endl;
	cout << "|^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^|" << endl;
	cout << "|                                   [1] Insert a New Video                                            |" << endl;
	cout << "|                                   [2] Rent a Video                                                  |" << endl;
	cout << "|                                   [3] Return a Video                                                |" << endl;
	cout << "|                                   [4] Show Details of Particular Video                              |" << endl;
	cout << "|                                   [5] Display all video                                             |" << endl;
	cout << "|                                   [6] Check if the a video is available                             |" << endl;
	cout << "|                                   [7] Customer Maintenance                                          |" << endl;
	cout << "|-----------------------------------------------------------------------------------------------------|" << endl;
	cout << "|                                   [8] Quit the Program                                              |" << endl;
	cout << "|^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^|" << endl;
	cout << "\n\t                               Enter Choice: ";
	cin >> choice;
	return(choice);
}

int csMenu()
{
	int csChoice;

	cout << "\n\n\n";
	cout << "|--------------------------------------<< CUSTOMER MAINTENANCE >>--------------------------------------|" << endl;
	cout << "|^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^|" << endl;
	cout << "|                                   [1] Add a new Customer                                            |" << endl;
	cout << "|                                   [2] Show Customer Details                                         |" << endl;
	cout << "|                                   [3] List videos rented by Customer                                |" << endl;
	cout << "|^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^|" << endl;
	cout << "\n\t                               Enter Choice: ";
	cin >> csChoice;
	return(csChoice);
}