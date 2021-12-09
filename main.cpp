#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <sstream>

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

string formatRecordLength(short length) {
    string str;
    string len = to_string(length);
    if (length < 10) {
        str = "0" + len;
    } else {
        str = len;
    }
    return str;
}

void AddEmployee(fstream &employeeFile) {
    cout << "Add new employee >>"<<endl;
    employee e1 ; string input ="";
    cout << "Enter employee ID: ";
    cin >> e1.Employee_ID;
    cout << "Enter employee Dept_ID: ";
    cin >> e1.Dept_ID;
    cout << "Enter employee name: ";
    cin >> e1.Employee_Name;
    cout << "Enter employee position: ";
    cin >> e1.Employee_Position;

    input=input+e1.Employee_ID+' ';
    input=input+e1.Dept_ID+' ';
    input=input+e1.Employee_Name+' ';
    input=input+e1.Employee_Position+' ';
    int i = input.size();
    employeeFile<<formatRecordLength(i-1);
    employeeFile<<e1.Employee_ID;
    employeeFile<<'|';
    employeeFile<<e1.Dept_ID;
    employeeFile<<'|';
    employeeFile<<e1.Employee_Name;
    employeeFile<<'|';
    employeeFile<<e1.Employee_Position;
    employeeFile.close();




}
void AddDepartment(fstream &departmentFile){
    cout << "Add new Department >>"<<endl;
    department d1 ; string input ="";
    cout << "Enter Department ID: ";
    cin >> d1.Dept_ID;
    cout << "Enter Department name: ";
    cin >> d1.Dept_Name;
    cout << "Enter Department Manager: ";
    cin >> d1.Dept_Manager;

    input=input+d1.Dept_ID+' ';
    input=input+d1.Dept_Name+' ';
    input=input+d1.Dept_Manager+' ';
    int i = input.size();
    departmentFile<<formatRecordLength(i-1);
    departmentFile<<d1.Dept_ID;
    departmentFile<<'|';
    departmentFile<<d1.Dept_Name;
    departmentFile<<'|';
    departmentFile<<d1.Dept_Manager;
    departmentFile.close();
}

void constructPrmIND(fstream &file, fstream &pIndex){
    //ID 'delimiter' BYTE OFFSET 'another delimiter'



}




int returnByteOffset(fstream &file, int ID) {
    /*
     * int byteOffset = 0
     * seek beg of the file
     * int byteRead = value of read 2 bytes
     * read ID from file of the record(until the first delimiter)
     * if File.ID == ID(parameter)
     *     true--> return byteOffset
     *     false-->{
     *          byteOffset+= byteRead (maybe+1)
     *          seek byteOffset
     *          compare again
                }
    */

    int byteOffset = 0;
    string value = "";
    do {
    string byteRead = "";
    int read = 0;
    int position = byteOffset;
    file.seekg(byteOffset, ios::beg);
    char letter = file.get();
    byteRead += letter;
        position++;
    file.seekg(position, ios::beg);
    letter = file.get();
    byteRead += letter;
    stringstream geek(byteRead);
    geek >> read;
        position++;
    file.seekg(position, ios::beg);
    bool indicator = true;
    while (indicator) {
        letter = file.get();
        if(letter == '|'){
            break;
        }
        value += letter;
        position++;
        file.seekg(position, ios::beg);
    }
    if (value != to_string(ID)) {
        value = "";
        byteOffset =byteOffset+ read+2;
    } else {
        return byteOffset;
    }

}while(value != to_string(ID));




}
void DeleteEmployee(fstream employeeFile, int ID){
    // seek record with EMP_ID  = ID
    // curr pointer will be pointing to the start of the record then add '*'




}

int main() {
    fstream employeeFile;
    fstream departmentFile;
    fstream primaryIndex;
    int option;

    do {
        employeeFile.open("employeeFile.txt", ios::app | ios::in |ios::out);
        departmentFile.open("departmentFile.txt", ios::app| ios::in|ios::out);
        primaryIndex.open("primaryIndex.txt", ios::app| ios::in|ios::out);
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

        cin >> option;

        if (option == 1) {

            AddEmployee(employeeFile);

        }
        else if (option == 2) {
            AddDepartment(departmentFile);

        }
        else if (option == 3) {


        }
        else if (option == 4) {
        }
        else if (option == 5) {

        }
        else if (option == 6) {

        }
        else if (option == 7) {

        }
        else if (option == 8) {

        }
        else if (option == 9) {

        }
        else {
            cout << "Expected Options"
                 << " are 1/2/3/4/5/6/7/8/9/10";
        }
    } while (option != 10);


    cout << "Exit....Saving to file" << endl;
    return 0;
}