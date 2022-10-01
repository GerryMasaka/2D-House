// miniproject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>

#include <string>

#include <fstream>

#include <algorithm>

#include <ctime>

#include <cstdlib>

using namespace std;

//Functions for beautification of output



int main()

{
	//reading csv files

	ifstream icsA("C:\\Users\\gerry\\source\\repos\\inputICSA.csv");

	ifstream icsB("C:\\Users\\gerry\\source\\repos\\inputICSB.csv");

	ifstream icsC("C:\\Users\\gerry\\source\\repos\\inputICSC.csv");

	//If file is open in another folder, show error

	if (!icsA.is_open() || !icsB.is_open() || !icsC.is_open())

	{

		cout << "The file is open in another folder. Please close it first.\n";
	}

	else

	{

		string admNo, name, gender;

		//array of all studnets

		string all_students[113][3];

		//fetch student details from  .csv files

		if (icsA.good())

		{

			for (int x = 0; x < 30; x++)

			{

				//Fetching for ICSA and add to all_students

				getline(icsA, admNo, '"');

				getline(icsA, name, '"');

				getline(icsA, gender, '\n');

				//Erase all commas so as to populate the array

				admNo.erase(std::remove(admNo.begin(), admNo.end(), ','), admNo.end());

				name.erase(std::remove(name.begin(), name.end(), ','), name.end());

				gender.erase(std::remove(gender.begin(), gender.end(), ','), gender.end());
				//populate all_students array

				all_students[x][0] = admNo;

				all_students[x][1] = name;

				all_students[x][2] = gender;

			}

		}
		if (icsB.good())

		{

			//Fetch for ICSB

			for (int x = 30; x < 58; x++) {

				getline(icsB, admNo, '"');

				getline(icsB, name, '"');

				getline(icsB, gender, '\n');

				//Erase all commas

				admNo.erase(std::remove(admNo.begin(), admNo.end(), ','), admNo.end());

				name.erase(std::remove(name.begin(), name.end(), ','), name.end());

				gender.erase(std::remove(gender.begin(), gender.end(), ','), gender.end());

				//Populate the all students array

				all_students[x][0] = admNo;

				all_students[x][1] = name;

				all_students[x][2] = gender;

			}
		}
		if (icsC.good())

		{

			//Fetch data from ICSC

			for (int x = 58; x < 113; x++)

			{

				getline(icsC, admNo, '"');

				getline(icsC, name, '"');

				getline(icsC, gender, '\n');



				//Erase all commas

				admNo.erase(std::remove(admNo.begin(), admNo.end(), ','), admNo.end());

				name.erase(std::remove(name.begin(), name.end(), ','), name.end());

				gender.erase(std::remove(gender.begin(), gender.end(), ','), gender.end());



				//Add data to all_students array

				all_students[x][0] = admNo;

				all_students[x][1] = name;

				all_students[x][2] = gender;

			}
		}
		//Shuffling of students using srand()

		srand(time(0)); //seed random number

		for (int i = 0; i < 113; i++)

		{

			int index = rand() % 113; // random index



			//swap all elements in merged array

			string tempAdmNo = all_students[i][0];

			string tempName = all_students[i][1];

			string tempGender = all_students[i][2];



			all_students[i][0] = all_students[index][0];

			all_students[i][1] = all_students[index][1];

			all_students[i][2] = all_students[index][2];

			all_students[index][0] = tempAdmNo;

			all_students[index][1] = tempName;

			all_students[index][2] = tempGender;

		}
		// Create arrays to store students in ICSA and B

		string icsA[57][3];

		string icsB[56][3];
		//Declare and initialise variables for counting male students and female students

		int males = 0;

		int females = 0;

		int i = 0;

		int j = 0;



		for (int x = 0; x < 113; x++)

		{

			//Take the first 36 males and add to ICSA

			//57 is the total number of students in ICSA

			if (all_students[x][2] == "M" && males < 36 && i < 57)

			{

				icsA[i][0] = all_students[x][0];

				icsA[i][1] = all_students[x][1];

				icsA[i][2] = all_students[x][2];

				males++;

				i++;

			}

			//Take the remaining 35 males and add to ICSB

			//56 is the total number of students in ICSB

			else if (all_students[x][2] == "M" && males < 71 && j < 56)

			{

				icsB[j][0] = all_students[x][0];

				icsB[j][1] = all_students[x][1];

				icsB[j][2] = all_students[x][2];

				males++;

				j++;

			}

			//Take the first 21 females and add to ICSA

			else if (all_students[x][2] == "F" && females < 21 && i < 57)

			{

				icsA[i][0] = all_students[x][0];

				icsA[i][1] = all_students[x][1];

				icsA[i][2] = all_students[x][2];

				females++;

				i++;

			}

			//Take the remaining 21 and add to ICSB

			else if (all_students[x][2] == "F" && females < 42 && j < 56)

			{

				icsB[j][0] = all_students[x][0];

				icsB[j][1] = all_students[x][1];

				icsB[j][2] = all_students[x][2];

				females++;

				j++;

			}
			else

			{

				cout << "Could not find M or F in data\n";

			}

		}

		//Print out classes and write them to csv files

		//Create the objects of the new csv files

		ofstream NewIcsA("C:\\Users\\gerry\\source\\repos\\outputICSA.csv");

		ofstream NewIcsB("C:\\Users\\gerry\\source\\repos\\outputICSA.csv");

		//Output the files

	here:

		cout << "Please choose which class list you would wish to display\n";



		cout << "1. New ICSA\n2.New ICSB\n3. Exit the Program\n";

		cout << "Enter 1,2 or 3\n";

		char option;

		cin >> option;

		switch (option)

		{

		case '1':

			cout << "\n\n\t\t\t ICS A MEMBERS\n";



			for (int y = 0; y < 57; y++)

			{

				NewIcsA << icsA[y][0] << "," << icsA[y][1] << "," << icsA[y][2] << endl;



				cout << icsA[y][0] << "\t" << icsA[y][1] << "\t\t" << icsA[y][2] << endl;



			}

			break;

		case '2':

			cout << "\n\n\t\t\tICS B MEMBERS\n";



			for (int y = 0; y < 56; y++)

			{

				NewIcsB << icsB[y][0] << "," << icsB[y][1] << "," << icsB[y][2] << endl;



				cout << icsB[y][0] << "\t" << icsB[y][1] << "\t\t" << icsB[y][2] << endl;



			}

			break;

		case '3':

			cout << "Thank you for using our program\n Feel Free to come back again\n";



			system("cls");

		default:

			cout << "Thank you :-)\n";

			break;

		}



	}

	icsA.close();

	icsB.close();

	icsC.close();

	system("pause");
	system("cls");
	return 0;
}