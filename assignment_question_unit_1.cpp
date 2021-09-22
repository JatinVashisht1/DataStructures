/*
    Question 1:
    
    Let’s say there’s a class of 30 students, and we want to store their grades for each of their courses (six courses in total).
    All we need to do is to keep the first column(i.e., Column 0), fixed for students, and the rest of the columns to store grades. 
    We will have to follow a specific order to make sure the scores and students don’t get mixed up. Each element of the first column will 
    hold a reference to an array containing marks of the student. So, there will be 30 rows and 6 columns. Now we can calculate the student’s 
    percentage, class average, and the student’s position, write a program
    
*/


/* By Jatin Vashisht*/

#include <iostream>
using namespace std;

class Map
{
    string index;
    float data[6] = {0, 0, 0, 0, 0, 0};

public:
    Map(string ind, float dat[])
    {
        index = ind;
        for (int i = 0; i < 6; i++)
        {
            data[i] = dat[i];
        }
    }

    void getData()
    {
        cout << "Name: " << index << "\nMarks = { ";
        for (int i = 0; i < 6; i++)
        {
            cout << "course " << i + 1 << ": ";
            cout << data[i] << "   ";
        }
        cout << "}\n";
        cout << "Average marks: " << getAverage() << "\n";
    }

    void addData(string ind, float dat[])
    {
        index = ind;
        for (int i = 0; i < 6; i++)
        {
            data[i] = dat[i];
        }
    }

    float getAverage()
    {
        float total = 0;
        for (int i = 0; i < 6; i++)
        {
            total += data[i];
        }
        return (total / 6.0);
    }

    float getPercentage()
    {
        float total = 0;
        for (int i = 0; i < 6; i++)
        {
            total += data[i];
        }

        return (total / 6.0);
    }
    Map()
    {
    }
};

void printDataOfStudents(Map *std, int n);
float classAverage(Map *students, int size);

int main()
{
    cout << "Enter the number of students\n";
    int std;
    cin >> std;

    Map record[std];
    float marks[6];

    cout << "Enter data of each student\n";
    for (int i = 0; i < std; i++)
    {
        cout << "Enter name of student " << i + 1 << "\n";
        string name;
        cin >> name;
        cout << "Enter marks \n";

        for (int i = 0; i < 6; i++)
        {
            cout << "course " << i + 1 << ": ";
            cin >> marks[i];
        }

        record[i].addData(name, marks);
    }

    printDataOfStudents(record, std);
    cout << "class average is " << classAverage(record, std);
}

float classAverage(Map *students, int size)
{
    float total = 0;
    for (int i = 0; i < size; i++)
    {
        total += students[i].getAverage();
    }

    return (total / (float)size);
}

void printDataOfStudents(Map *std, int n)
{
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        // std[i].getData();
        cout<<"\n";
        (std + i)->getData();
    }
    cout << "\n";
}
