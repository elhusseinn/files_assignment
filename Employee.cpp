#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

class Employee {

private:
    char Employee_ID[13]; //primarykey
    char Dept_ID[30]; //sec.key
    char Employee_Name[50];
    char Employee_Position[50];

public:
    Employee(char *employeeId, char *deptId, char *employeeName, char *employeePosition) : Employee_ID(employeeId),
                                                                                           Dept_ID(deptId),
                                                                                           Employee_Name(employeeName),
                                                                                           Employee_Position(
                                                                                                   employeePosition) {}
};