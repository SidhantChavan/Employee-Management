#include"Headers.h"
#include "Myexception.h"

using namespace std;
#include <string>
/********************READ DATA FROM FILE *******************/
namespace
{
	const std::string strFileName("employeeData.txt");
	const std::string strFileName1("employeeData2.txt");
	const std::string Password("Welcome123");
	const std::string Username("MAN");
};


void Admin::ReadData()
{
	
	int iterator = 0, Empid = 0, LeaveCount = 0,JoinYear=0;
	string LoopingVariable, FirstName, LastName, ContactNo, Designation;
	ifstream file;

	file.open(strFileName1, ios::in);
	if (!file)
	{
		
		return;
	}
	

	file.seekg(0, std::ios::end);
	long length = file.tellg();
	file.seekg(0, std::ios::beg);

	char* buffer = new char[length];

	file.read(buffer, length);


	stringstream is(buffer);

	while (is << LoopingVariable)
	{
		if (iterator == 0)
		
			is >> Empid;
		
		else if (iterator == 1)
			is >> FirstName;

		else if (iterator == 2)
			is >> LastName;

		else if (iterator == 3)
			is >> ContactNo;

		else if (iterator == 4)
			is >> Designation;

		else if (iterator == 5)
			is >> LeaveCount;

		else if (iterator == 6)
			is >> JoinYear;




		iterator++;
		 if (iterator == 7)
		{
			iterator = 0;

			Employee emp(Empid, LeaveCount, FirstName, LastName, ContactNo, Designation,JoinYear);
			V.push_back(emp);
		}

	}
	delete[] buffer;
	file.close();

}
		

//****************** ADDING RECORDS  *****************************//

void Admin::Add_Emp()
{
	
	bool flag = false;
	int LeaveCount = 0,Empid = 0,JoinYear=0;
	string FirstName, LastName, ContactNo="Not Available", Designation;
	char s;

	Empid = V.size() + 1;
	cin.ignore();
	cout << "Enter First Name";
	cin >> FirstName;
	
	cin.ignore();
	
cout << "Enter Last Name";

if (cin.get() == '\n')
{
	LastName = " ";
}
else
cin>>LastName;


	
	
	
	cout << "Enter Leave Allocated";
	cin >> LeaveCount;
	
	
	cin.ignore();
	
	cout << "Enter Contact";
	if (cin.get() == '\n')
	{
		ContactNo = "Not Available";
	}
	else
		cin>>ContactNo;

	
	

	cout << "Enter Designation";
	cin >> Designation;
	
	cin.ignore();
	

	cout << "Enter Join Year";
	
	if (cin.get() == '\n')
	{
		cout << "Joinning Year is mandatory";
		return;
	}
	else
		cin>>JoinYear;
	


	Employee emp(Empid, LeaveCount, FirstName, LastName, ContactNo, Designation,JoinYear);
	Empid++;
	V.push_back(emp);

}

//******************** SAVE RECORDS IN FILE ****************//


void Admin::Save()
{
	fstream file, file2;

	try {
		file.open(strFileName, std::ios_base::out);
		if (!file)
		{
			throw Fileexptn;
		}
	}

	catch (exception& e)
	{
		cout << e.what() << '\n';
	}
	try {
		file2.open(strFileName1, std::ios_base::out);

		if (!file2)
		{
			throw Fileexptn;
		}
	}

	catch (exception& e)
	{
		cout << e.what() << '\n';
	}
	if (file.is_open())
	{

		for (int i = 0; i < V.size(); i++)
		{
			V[i].saveToFile(file, file2);

		}
		file.close();

	}


}

//**********************DELETING  RECORDS ***********/

 int Admin:: Delete()
 {
	 int id = 0;
	 fstream file, file2;
	 bool Flag = false, EmpFlag = false;
	 file.open(strFileName, std::ios_base::out);
	 file2.open(strFileName1, std::ios_base::out);

	 cout << "ENTER THE EMPLOYEE ID ...!" << endl;
	 cin >> id;

	 for (int i = 0; i < V.size(); i++)
	 {
		// Flag = V[i].GetEmployee(id);
		 if (Flag)
		 { 
			 EmpFlag = true;
			 continue;
		 }
		 else
		 {
			 V[i].saveToFile(file, file2);
		 }

	 }
	 if (EmpFlag == false)
	 {
		 cout << "EMPLOYEE NOT AVAILABLE" << endl;
	 }
	 else
		 cout << "EMPLOYEE DELETED SUCCESSFULLY...!" << endl;
	 return 0;

 }


 //********************Search by Empid*******************//


 int Admin::SearchById()
 {
	 int id;
	 bool Flag = false, EmpFlag = false;
	 cout << "enter the employee Id...!" << endl;
	 cin >> id;

	 for (int i = 0; i < V.size(); i++)
	 {
		 Flag = V[i].GetEmployeeByid(id);
		 if (Flag)
		 {
			 V[i].DisplayEmployee();
			 EmpFlag = true;
		 }
	 }
	 if (EmpFlag == false)
	 {
		 cout << "EMPLOYEE NOT AVAILABLE" << endl;
	 }
	 return 0;
 }


 //********************Search by JoinDate*******************//


 int Admin::SearchByJoinDate()
 {

	 int date;
	 bool Flag = false, Empflag = false;
	 cout << "enter the employee date...!" << endl;
	 cin >> date;

	 for (int i = 0; i < V.size(); i++)
	 {
		 Flag = V[i].GetEmployeeByDate(date);
		 if (Flag)
		 {
			 V[i].DisplayEmployee();
			 Empflag = true;
		 }
	 }
	 if (Empflag == false)
	 {
		 cout << "employee not available" << endl;
	 }
	 return 0;

 }

 /*************SEARCHING EMPLOYEE *******************/



int Admin::Search()
{
	int id = 0,choise=0;
	bool Flag = false,EmpFlag=false;

	while (1)
	{
		cout <<  "1.search empid 2.search by joinning year" << endl;
		cin >> choise;
		switch (choise)
		{

		

		case 1: SearchById(); break;

		case 2: SearchByJoinDate(); break;

		default: exit(1);
		}
	}



}



//*************** DISPLAYING RECORDS *************/

void Admin::Display()
{
	if (V.size() == 0)
	{
		cout << "NO RECORDS AVAILABLE...!" << endl;
	}

	else
	{
		for (int i = 0; i < V.size(); i++)
		{
			V[i].DisplayEmployee();

		}
	}
}

// ************ ADMIN LOGIN *********************//


int Admin::AdminLogin()
{

	int Attempt = 0, i = 0, choise = 0, j = 0, count = 0;
	string username, password;


	while (Attempt <= 3)
	{
		if (Attempt == 3)
		{
			cout << "USERNAME HAS BLOCKED...PLEASE CONTACT ADMINISTRATION" << endl;
			return 0;
		}
		cout << "ENTER USERNAME" << endl;
		cin >> username;
		if (username ==Username)
		{
			cout << "ENTER PASSWORD" << endl;
			cin >> password;
			if (password == Password)
			{
				cout << "WELCOME TO ADMIN PANNEL..." << endl << endl;

				while (1)
				{

					cout << "1. ADD 2.SAVE 3.DISPLAY 4.SEARCH 5. DELETE " << endl;
					try {
						cin >> choise;
						if (choise < 0 || choise > 7)
						{
							throw exptn;
						}
					}
					catch (exception& e)
					{
						cout << e.what() << '\n';
					}

								switch (choise)
								{
								case 1: Add_Emp(); break;
								case 2: Save();    break;
								case 3: Display(); break;
								case 4: Search();  break;
								case 5: Delete();  break;
						             
								}
				}
			}
			else
			{

				cout << "WRONG PASSWORD...TRY AGAIN..!" << endl;
				Attempt++;
				continue;
			}
		}

		else
		{
			cout << "WRONG USERNAME...TRY AGAIN..!" << endl;
			Attempt++;
			continue;
		}
	}
	return 0;
}




/***********************Get EMPLOYEE********************/









						

