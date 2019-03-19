#include <iostream>
#include <string>
#include <fstream>
#include "person.h"
//#include "person.cpp"

int readData (Person array[])
{
    string fname;
    string lname;
    float hours;
    float rate;
    string line;
    int N = 0;
    int i = 0;

    ifstream input("input.txt");


    if (input.is_open())
    {

        while (!input.eof()){
            input >> fname >> lname >> hours >> rate;

            array[i].setFirstName(fname);
            array[i].setLastName(lname);
            array[i].setHoursWorked(hours);
            array[i].setPayRate(rate);

            //cout << fname << lname << hours << rate << endl;

            i++;
            N++;
        }


        /*
        for (int i = 0; i < 20; i++)
        {
            input >> fname >> lname >> hours >> rate;
            array[i].setFirstName(fname);
            array[i].setLastName(lname);
            array[i].setHoursWorked(hours);
            array[i].setPayRate(rate);
            //cout << fname << lname << hours << rate << endl;
        } */
    }

    input.close();

    return N;

}

void writeData (Person array[], int N)
{
    string fname;
    string lname;
    float hours;
    float rate;

    ofstream output("output.txt");
    if (output.is_open())
        {


        for (int i = 0; i < N-1; i++)
            {
            output << array[i].fullName() << " ";
            output << array[i].totalPay() << endl;
        }

    }

}

int main() {

    int N;

    Person employees[20];

    N = readData(employees);
    writeData(employees, N);


    return 0;
}
