#pragma once
#include <iosfwd>
#include<iostream>
using namespace std;

class Employee
{

public:
	void DisplayEmployee();
	fstream& saveToFile(fstream&, fstream&);
	bool GetEmployeeByid(int );
	bool GetEmployeeByDate(int);


	


	Employee()
	{

	};
	


	Employee(int empid, int LeaveCount, string FirstName, string LastName, string ContactNo, string Designation,int joinYear)
	{
		this->EmpId = empid;
		this->LeaveCount = LeaveCount;
		this->FirstName = FirstName;
		this->LastName = LastName;
		this->ContactNo = ContactNo;
		this->Designation = Designation;
		this->JoinYear = joinYear;


	}
	

private:
	int  EmpId, LeaveCount,JoinYear;
	string FirstName, LastName, ContactNo, Designation;



};

