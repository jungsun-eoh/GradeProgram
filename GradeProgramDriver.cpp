//
//  main.cpp
//  GradeProgram
//
//

#include <iostream>
#include "Grade_Book.hpp"
#include "StudentList.hpp"
#include "Assignment.hpp"   // Provides grade class
using namespace std;

void add_new_Assignment(Gradebook &possiblePTS, Assignment::value_type input);
void add_new_student(StudentList& list, string input, Gradebook source);
void erase_student(StudentList& list, string input);
void add_new_grades(StudentList& list);
void display_list(Gradebook posssiblePTS, StudentList list);
void display_final_grades(Gradebook possiblePTS, StudentList list);

int main()
{
    int choice(1);
    Assignment::value_type user_input;
    string input;
    StudentList css2b;
    StudentList list_of_student_name;
    Gradebook point_possible;

    cout << "This is GradeBook program for Mrs.Weise." << endl;
    cout << "It is very comportable to use and very accurate." << endl;
    cout << "Not to mention very fun. (wink)." << endl;
    cout << "So tell me, what do you want to do?" << endl;

    while (choice > 0)
    {
        cout << "   [1] Add a new student" << endl;
        cout << "   [2] Add a new Assignment" << endl;
        cout << "   [3] Add new grades" << endl;
        cout << "   [4] Kick out a lazy student" << endl;
        cout << "   [5] Display how are your students doing so far" << endl;
        cout << "   [6] Display final grades of students" << endl;
        cout << "   [0] EXIT THE PROGRAM" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the name of the student." << endl;
                cin >> input;
                add_new_student(css2b, input, point_possible);
                break;
            case 2:
                cout << "Enter the possible points of the new assingment" << endl;
                cin >> user_input;
                add_new_Assignment(point_possible, user_input);
                break;
            case 3:
                add_new_grades(css2b);
                break;
            case 4:
                cout << "Enter the name of the student that you want to erase from your list" << endl;
                cin >> input;
                erase_student(css2b, input);
                break;
            case 5:
                display_list(point_possible, css2b);
                break;
            case 6:
                display_final_grades(point_possible, css2b);
                break;
            case 0:
                break;
            default:
                cout << "You input wrong! Again!" << endl;
                break;
        }
    }

    return 0;
}

void add_new_student(StudentList& list, string input, Gradebook source)
{
    Gradebook new_student(source, input);
    list.insert(new_student);
}
void add_new_Assignment(Gradebook &possiblePTS, Assignment::value_type input)
{
    possiblePTS.insert(input);
}
void add_new_grades(StudentList& list)
{
    list.add_grades();
}
void erase_student(StudentList& list, string input)
{
    if (list.erase_one(input)) {
        cout << "your student " << input << " is now gone! " << endl;
    }
    else
    {
        cout << "There is no such a student." << endl;
    }
}
void display_list(Gradebook posssiblePTS, StudentList list)
{
    cout << " ******************************************************** " << endl;
    posssiblePTS.list_print();
    cout << " ******************************************************** " << endl;
    list.print();
    cout << " ******************************************************** " << endl;
}
void display_final_grades(Gradebook possiblePTS, StudentList list)
{
    list.fianl_grade(possiblePTS);
}
