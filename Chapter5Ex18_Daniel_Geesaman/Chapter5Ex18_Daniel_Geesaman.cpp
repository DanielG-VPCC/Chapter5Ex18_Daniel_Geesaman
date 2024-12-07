/*
Title:Chapter 5 Exercise 18 - Population Bar Chart
File name:Chapter5Ex18_Daniel_Geesaman.cpp
Programmer:Daniel Geesaman
Date:12/7/2024
Requirements:

Population Bar Chart:

Write a program that produces a bar chart showing the population growth of Prairieville, a small town in the Midwest, 
at 20-year intervals during the past 100 years. The program should read in the population figures 
(rounded to the nearest 1,000 people) for 1900, 1920, 1940, 1960, 1980, and 2000 from a file. For each year, 
it should display the date and a bar consisting of one asterisk for each 1,000 people. The data can be found in the People.txt file.

Here is an example of how the chart might begin:
     
     PRAIRIEVILLE POPULATION GROWTH
     (each * represents 1,000 people)
     1900 **
     1920 ****
     1940 *****
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

fstream OpenFile(string fileName);
string getFileName();

int main()
{
    string fileName = getFileName();
    fstream OpenFile(string fileName);
    fstream fhandle = OpenFile(fileName);
    while (fhandle.fail())
    {
        cout << "could not find that file" << endl;
        string fileName = getFileName();
        fstream fhandle = OpenFile(fileName);
    }
    int population;
    int dotPerLine;
    int year = 1900;
    cout << "PRAIRIEVILLE POPULATION GROWTH" << endl << "(each * represents 1,000 people)" << endl;
    while (fhandle >> population)
    {
        cout << year << " ";
        year += 20;
        dotPerLine = population / 1000;
        for (int i = 0; i < dotPerLine; i++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

string getFileName()
{
    string fileName;
    cout << "What is the name of your file?";
    cin >> fileName;
    return fileName;
}

fstream OpenFile(string fileName)
{
    fstream fhandle;
    fhandle.open(fileName);
    return fhandle;
}