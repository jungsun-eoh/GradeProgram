//
//  StudentList.hpp
//  GradeProgram
//
//  Created by Eohjungsun on 4/4/16.
//  Copyright © 2016 nodeEX. All rights reserved.
//

#ifndef StudentList_hpp
#define StudentList_hpp

#include <string>
#include "Assignment.hpp"
#include "Grade_Book.hpp"
using namespace std;

class StudentList
{
public:
    // TYPEDEFS and MEMBER CONSTANTS
    typedef Gradebook value_type;
    typedef std::size_t size_type;
    static const size_type DEFAULT_CAPACITY = 10;
    // CONSTRUCTORS and DESTRUCTOR
    StudentList(size_type initial_capacity = DEFAULT_CAPACITY);
    StudentList(const StudentList& source);
    ~StudentList( );
    // MODIFICATION MEMBER FUNCTIONS
    void reserve(size_type new_capacity);
    bool erase_one(const string target);
    void insert(const value_type& entry);
    Gradebook grab_student(const string target);
    void add_grades();
    void fianl_grade(const Gradebook source);
    // CONSTANT MEMBER FUNCTIONS
    size_type size( ) const { return used; }
    size_type count(const value_type& target) const;
    void print();
private:
    value_type *data;     // Pointer to partially filled dynamic array
    size_type used;       // How much of array is being used
    size_type capacity;   // Current capacity of the StudentList};
};
#endif /* StudentList_hpp */
