#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;

struct Employee {
private:
    char Employee_ID[13]; //primarykey
    char Dept_ID[30]; //sec.key
    char Employee_Name[50];
    char Employee_Position[50];

public:
    int maxRow = 10;
    string EmpName[10] = {};
    string EmpID[10] = {};
    int i;

    void OpenFile() {
        string line;
        ifstream myfile("D:\FCI\VS projects\Project2\Project2\src\\employee.txt");
        if (myfile.is_open())
        {
            int x = 0;
            while (getline(myfile, line)) {
                int L = line.length();
                EmpName[x] = line.substr(0, 3);
                EmpID[x] = line.substr(4, 1 - 4);
                x++;
            }
        }
        else {
            cout << "enable to open the file" << endl;
        }
    }

    void AddNewEmployee() {
        for (i = 0;i < 10;i++) {
            cout << "enter employee" << i + 1 << "Employee_ID, Dept_ID, Employee_Name, Employee_Position:\n";
            cin >> obj[i].Employee_ID >> obj[i].Dept_ID >> obj[i].Employee_Name >> obj[i].Employee_Position;
        }
    }

    void DeleteEmployee(string search) {
        int counter = 0;
        for (int x = 0;x < maxRow;x++)
        {
            if (EmpID[x] == search) {

                counter++;
                EmpName[x] = "";
                EmpID[x] = "";
                cout << "successfully deleted" << endl;
                break;
            }
        }
        if (counter == 0) { cout << "ID number doesn't exist"; }
    }

    void printEmployee() {}

    void printEmployee() {}

    void saveToFile() {
        ofstream myfile;
        myfile.open("D:\FCI\VS projects\Project2\Project2\src\\employee.txt");
        for (int x = 0;x < maxRow;x++)
        {
            if (EmpID[x] == "\0") {
                break;
            }
            else {
                myfile << EmpID[x] + ", " + EmpName[x] << endl;
            }
        }
    }

}obj[10];