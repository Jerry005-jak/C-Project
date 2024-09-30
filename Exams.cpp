#include <iostream>
using namespace std;

//Base Employee class
class Employee{
	protected:
	    string empID, empLName, empFName;
		int empDWorked;
		double empDRate;
		double empBSal, empGSal, empNetSal;
		double empTax, empSocSec;
	
	public:
	    Employee() {}
	    void inputDetails()
		{
	        cout << "Enter Employee ID: ";
	        cin >> empID;
	        cout << "Enter Last Name: ";
	        cin >> empLName;
	        cout << "Enter First Name: ";
	        cin >> empFName;
	        cout << "Enter Rate per Day: GHc";
	        cin >> empDRate;
	        cout << "Enter Number of Days Worked: ";
	        cin >> empDWorked;
	        
	        empBSal = empDRate * empDWorked;
	    }
	
	    void displayDetails()
		{
	        cout << "\nAFRICAN DEVELOPMENT BANK (ADB)" << endl;
	        cout << "................................" << endl;
	        cout << "Name: " << empFName << " " << empLName << endl;
	        cout << "ID: " << empID << endl;
	        cout << "Net Salary for Month: GHc" << empNetSal << endl << endl;
	    }
};

//Class function for CEO
class CEOstaff:
	public Employee{
		private:
		    double empDutyAllow, empFuelAllow, empEntAllow;
		    double empRentAllow, empTravelAllow, empRiskAllow;
		    
		public:
		    void calculateNetSalary()
			{
		        empDutyAllow = 0.15 * empBSal;
		        empFuelAllow = 0.14 * empBSal;
		        empEntAllow = 0.15 * empBSal;
		        empRentAllow = 0.20 * empBSal;
		        empTravelAllow = 0.135 * empBSal;
		        empRiskAllow = 0.14 * empBSal;
		        empTax = 0.105 * empBSal;
		        empSocSec = 0.125 * empBSal;
		        
				double totAllow = empDutyAllow + empFuelAllow + empEntAllow + empRentAllow + empTravelAllow + empRiskAllow;
		        
		        double totDeduct = empTax + empSocSec + (60000 / 12);
		
		        empGSal = empBSal + totAllow;
		        empNetSal = empGSal - totDeduct;
		    }
};

//Class function for Administrator
class AdminStaff:
	public Employee {
		private:
		    double empDutyAllow, empFuelAllow;
		    double empProfAllow, empRentAllow;
		
		public:
		    void calculateNetSalary()
			{
		        empDutyAllow = 0.13 * empBSal;
		        empFuelAllow = 0.12 * empBSal;
		        empProfAllow = 0.10 * empBSal;
		        empRentAllow = 0.15 * empBSal;
		        empTax = 0.105 * empBSal;
		        empSocSec = 0.125 * empBSal;
		
		        double totAllow = empDutyAllow + empFuelAllow + empProfAllow + empRentAllow;
		        
		        double totDeduct = empTax + empSocSec + ((20000 * 0.025) / 24);
		
		        empGSal = empBSal + totAllow;
		        empNetSal = empGSal - totDeduct;
		    }
};

//Class function for Accountant
class AccountStaff:
	public Employee{
		private:
		    double empDutyAllow, empFuelAllow, empProfAllow;
		
		public:
		    void calculateNetSalary() {
		        empDutyAllow = 0.15 * empBSal;
		        empFuelAllow = 0.12 * empBSal;
		        empProfAllow = 0.10 * empBSal;
		        empTax = 0.105 * empBSal;
		        empSocSec = 0.125 * empBSal;
		
		        double totAllow = empDutyAllow + empFuelAllow + empProfAllow;
		        
		        double totDeduct = empTax + empSocSec;
		
		        empGSal = empBSal + totAllow;
		        empNetSal = empGSal - totDeduct;
		    }
};

//Class function for Secretary
class SecStaff:
	public Employee{
		private:
		    double empDutyAllow, empFuelAllow;
		    
		public:
		    void calculateNetSalary()
			{
		        empDutyAllow = 0.13 * empBSal;
		        empFuelAllow = 0.11 * empBSal;
		        empTax = 0.105 * empBSal;
		        empSocSec = 0.125 * empBSal;
		
		        double totAllow = empDutyAllow + empFuelAllow;
		        
		        double totDeduct = empTax + empSocSec + ((empBSal * 3) / 12);
		
		        empGSal = empBSal + totAllow;
		        empNetSal = empGSal - totDeduct;
		    }
};

//Funtion To Check Login Security
bool login()
{
    string username, password;
    string Username = "admin";
    string Password = "password123";

    cout << "LOGIN PORTAL" << endl;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if(username == Username and password == Password)
	{
        cout << "Login successful!" << endl;
        return true;
    }
	else
	{
        cout << "Login failed! Incorrect username or password." << endl;
        return false;
    }
}

int main()
{
    if (!login())
	{
        return 0;
    }

    CEOstaff ceo;
    AdminStaff admin;
    AccountStaff accountant;
    SecStaff secretary;

    cout << "\nCEO:" << endl;
    ceo.inputDetails();
    ceo.calculateNetSalary();
    ceo.displayDetails();

    cout << "\nAdministrator:" << endl;
    admin.inputDetails();
    admin.calculateNetSalary();
    admin.displayDetails();

    cout << "\nAccountant:" << endl;
    accountant.inputDetails();
    accountant.calculateNetSalary();
    accountant.displayDetails();

    cout << "\nSecretary:" << endl;
    secretary.inputDetails();
    secretary.calculateNetSalary();
    secretary.displayDetails();

    return 0;
}
