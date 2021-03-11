
#include <algorithm>    // Provides copy function
#include <cassert>       // Provides assert function
#include <iostream>
#include "StudentList.hpp"
#include "Grade_Book.hpp"
#include "Assignment.hpp"
using namespace std;

const StudentList::size_type StudentList::DEFAULT_CAPACITY;

StudentList::StudentList(size_type initial_capacity)
{
    data = new value_type[initial_capacity];
    capacity = initial_capacity;
    used = 0;
}

StudentList::StudentList(const StudentList& source)
// Library facilities used: algorithm
{
    data = new value_type[source.capacity];
    capacity = source.capacity;
    used = source.used;
    copy(source.data, source.data + used, data);
}

StudentList::~StudentList( )
{
    delete [ ] data;
}

void StudentList::reserve(size_type new_capacity)
// Library facilities used: algorithm
{
    value_type *larger_array;

    if (new_capacity == capacity)
        return; // The allocated memory is already the right size.

    if (new_capacity < used)
        new_capacity = used; // Canít allocate less than we are using.

    larger_array = new value_type[new_capacity];
    copy(data, data + used, larger_array);
    delete [ ] data;
    data = larger_array;
    capacity = new_capacity;
}
Gradebook StudentList::grab_student(const string target)
{
    Gradebook student;
    size_type index;
    index = 0;
    while ((index < used) && (data[index].getName() != target))
    {
        ++index;
        if (index == used) // target isn't in the StudentList, so no work to do
        {
            break;
        }
        student = data[index];
        // When execution reaches here, target is in the StudentList at data[index].
        // So, reduce used by 1 and copy the last item onto data[index].
    }
    return student;
}

bool StudentList::erase_one(const string target)
{
    size_type index; // The location of target in the data array

    // First, set index to the location of target in the data array,
    // which could be as small as 0 or as large as used-1.
    // If target is not in the array, then index will be set equal to used.
    index = 0;
    while ((index < used) && (data[index].getName() != target))
    {
        ++index;
        if (index == used) // target isn't in the StudentList, so no work to do
        {
            return false;
        }

    // When execution reaches here, target is in the StudentList at data[index].
    // So, reduce used by 1 and copy the last item onto data[index].
        --used;
        data[index] = data[used];
    }
    return true;
}

void StudentList::insert(const value_type& entry)
{
    if (used == capacity)
    {
        reserve(used+1);
    }
    data[used] = entry;
    ++used;
}

void StudentList::add_grades()
{
    size_type index;
    index = 0;


    while (index < used)
    {
        data[index].insert();
        index++;
    }
}

void StudentList::print()
{
    size_type index;
    index = 0;

    while (index < used)
    {
        data[index].list_print();
        index++;
    }
}

void StudentList::fianl_grade(const Gradebook source)
{
    size_t index;
    index = 0;

    while (index < used)
    {
        cout << data[index].getName() << " : ";
        cout << (data[index].total_pts() * 100) / source.total_pts();
        cout << " % " << endl;
        index++;
    }
}

