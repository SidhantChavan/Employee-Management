#include"Employee.h"
#include<fstream>
#include <iosfwd>
#include"Headers.h"
#include<string.h>
using namespace std;

void Employee::DisplayEmployee()
{

	std::cout << "EMPLOYEE ID :" << this->EmpId << endl;
	std::cout << "FIRST NAME  :" << this->FirstName << endl;
	std::cout << "LAST NAME   :" << this->LastName << endl;
	std::cout << "CONTACT NO  :" << this->ContactNo << endl;
	std::cout << "Leave Available :" << this->LeaveCount << endl;
	std::cout << "JOINING YEAR :" << this->JoinYear << endl;
	std::cout << "----------------------------------------" << endl;
	

}
bool Employee::GetEmployeeByid(int id)
{

	if (this->EmpId == id)
	{

		return true;

	}

	else
		return false;



}
bool Employee::GetEmployeeByDate(int date)
{

	

	 if (this->JoinYear >= date)
	{

		return true;

	}
	else
	{
		return false;
	}




}





fstream& Employee::saveToFile(fstream& file, fstream& file2)
{

	


	file << "EMP ID     :" << this->EmpId << endl;
	file << "FIRST NAME :" << this->FirstName << endl;
	file << "LAST NAME  :" << this->LastName << endl;
	file << "CONTACT NO :" << this->ContactNo << endl;
	file << "DESIGNATION:" << this->Designation << endl;
	file << "LEAVE AVAILABLE :" << this->LeaveCount << endl;
	file << "JOINING YEAR :" << this->JoinYear << endl;
	file << "------------------------------------" << endl;



	file2 << this->EmpId << endl;
	file2 << this->FirstName << endl;
	file2 << this->LastName << endl;
	file2 << this->ContactNo << endl;
	file2 << this->Designation << endl;
	file2 << this->LeaveCount << endl;
	file2 << this->JoinYear << endl;



	return file;





}



