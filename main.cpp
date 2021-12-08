#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include "Employee.cpp"
#include "Department.cpp"

using namespace std;



struct employee {
    char Employee_ID[13]; //primarykey
    char Dept_ID[30]; //sec.key
    char Employee_Name[50];
    char Employee_Position[50];
};
struct department {
    char Dept_ID[30]; //primarykey
    char Dept_Name[50]; //sec.Key
    char Dept_Manager[50];
};

int mySize(char array[]){
    int i=0;
    while (array[i]){

    }
}
employee AddEmployee() {
    employee e1;
    cout << "Enter employee ID: ";
    cin >> e1.Employee_ID;
    cout << "Enter employee Dept_ID: ";
    cin >> e1.Employee_Name;
    cout << "Enter employee name: ";
    cin >> e1.Employee_Name;
}

int main() {
    fstream employeeFile;
    employeeFile.open("employeeFile.txt", ios::app | ios::in | ios::out);
    fstream departmentFile;
    employeeFile.open("departmentFile.txt", ios::app | ios::in | ios::out);

    int option;

    do {
        cout << "Available Options:\n\n";
        cout << "Add New Employee         (1)\n";
        cout << "Add New Department       (2)\n";
        cout << "Delete Employee(ID)      (3)\n";
        cout << "Delete Department(ID)    (4)\n";
        cout << "print Employee(ID)       (5)\n";
        cout << "print Employee(Dept_ID)  (6)\n";
        cout << "print Department(ID)     (7)\n";
        cout << "print Department(name)   (8)\n";
        cout << "Write a Query            (9)\n";
        cout << "Exit                     (10)\n";

        cout << "select option >>";

        // Input Options

        cin >> option;

        // Call function on the bases of the
        // above option
        if (option == 1) {
            cout << "Add new employee >>";
            char Employee_ID[13]; //primarykey
            char Dept_ID[30]; //sec.key
            char Employee_Name[50];
            char Employee_Position[50];
            cin>>

        } else if (option == 2) {
            cout << "delete department by ID >>";
            D.AddNewDepartment();
        } else if (option == 3) {
            cout << "delete employee by ID >>";
            E.DeleteEmployee();
        } else if (option == 4) {
            cout << "delete department by ID >>";
            D.DeleteDepartment();
        } else if (option == 5) {

        } else if (option == 6) {

        } else if (option == 7) {

        } else if (option == 8) {
            return;
        } else if (option == 9) {
            return;
        } else {
            cout << "Expected Options"
                 << " are 1/2/3/4/5/6/7/8/9/10";
        }
    } while (option != 10);

    E.saveToFile();
    D.saveToFile1();
    cout << "Exit....Saving to file" << endl;
    return 0;
}