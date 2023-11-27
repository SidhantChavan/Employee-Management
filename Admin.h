#pragma once

class Admin
{


public:


	int AdminLogin();
	void Add_Emp();
	void Save();
	void Display();
	void ReadData();
	int Search();
	int Delete();
	int SearchName();
	int SearchById();
	int SearchByJoinDate();
	


private:
	vector<Employee>V;
	


};
