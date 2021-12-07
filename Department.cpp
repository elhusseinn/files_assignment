#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;

struct Department {
private:
    char Dept_ID[30]; //primarykey
    char Dept_Name[50]; //sec.Key
    char Dept_Manager[50];

public:
    int maxRow = 5;
    string DeptName[5] = {};
    string DeptID[5] = {};
    int i;

    void OpenFile1() {
        string line;
        ifstream myfile("D:\FCI\VS projects\Project2\Project2\src\\department.txt");
        if (myfile.is_open())
        {
            int x = 0;
            while (getline(myfile, line)) {
                int L = line.length();
                DeptName[x] = line.substr(0, 3);
                DeptID[x] = line.substr(4, 1 - 4);
                x++;
            }
        }
        else {
            cout << "enable to open the file" << endl;
        }
    }

    void AddNewDepartment() {
        for (i = 0;i < 10;i++) {
            cout << "enter department" << i + 1 << "Dept_ID, Dept_Name, Dept_manager:\n";
            cin >> obj[i].Dept_ID >> obj[i].Dept_Name >> obj[i].Dept_Manager;
        }
    }

    void DeleteDepartment(string search) {
        int counter = 0;
        for (int x = 0;x < maxRow;x++)
        {
            if (DeptID[x] == search) {

                counter++;
                DeptName[x] = "";
                DeptID[x] = "";
                cout << "successfully deleted" << endl;
                break;
            }
        }
        if (counter == 0) { cout << "ID number doesn't exist"; }
    }

    void printDepartment() {}

    void printDepartment() {}

    void saveToFile1() {
        ofstream myfile;
        myfile.open("D:\FCI\VS projects\Project2\Project2\src\\employee.txt");
        for (int x = 0;x < maxRow;x++)
        {
            if (DeptID[x] == "\0") {
                break;
            }
            else {
                myfile << DeptID[x] + ", " + DeptName[x] << endl;
            }
        }
    }

}obj[5];