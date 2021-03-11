//
//  Grade_Book.cpp
//  AssignmentProgram
//
//  Created by Eohjungsun on 3/25/16.
//  Copyright © 2016 AssignmentEX. All rights reserved.
//

#ifndef Grade_Book_H
#define Grade_Book_H

#include <iostream>
#include <cassert>  // Provides assert
#include <cstdlib>  // Provides NULL, rand, size_t
#include "Assignment.hpp"  // Provides Assignment and the linked list functions
#include "Grade_Book.hpp"
using namespace std;


Gradebook::Gradebook()
// Library facilities used: cstdlib
{
    head_ptr = NULL;
    many_Assignments = 0;
    earned_pts = 0;
}

Gradebook::Gradebook(const Gradebook& source)
// Library facilities used: Assignment1.h
{
    Assignment *tail_ptr;  // Needed for argument of list_copy
    Assignment *cursor;
    
    list_copy(source.head_ptr, head_ptr, tail_ptr);
    many_Assignments = source.many_Assignments;
    earned_pts = 0;
    for(cursor = head_ptr; cursor != NULL; cursor = cursor->link())
    {
        cursor->set_data(0);
    }
}

Gradebook::~Gradebook()
// Library facilities used: Assignment1.h
{
    list_clear(head_ptr);
    many_Assignments = 0;
    earned_pts = 0;
}

Gradebook::size_type Gradebook::count(const value_type& target) const
// Library facilities used: cstdlib, Assignment1.h
{
    size_type answer;
    const Assignment *cursor; // Use const Assignment* since we don't change the Assignments.
    
    answer = 0;
    cursor = list_search(head_ptr, target);
    while (cursor != NULL)
    {
        // Each time that cursor is not NULL, we have another occurrence of
        // target, so we add one to answer, and move cursor to the next
        // occurrence of the target.
        ++answer;
        cursor = cursor->link( );
        cursor = list_search(cursor, target);
    }
    return answer;
}

Gradebook::size_type Gradebook::erase(const value_type& target)
// Library facilities used: cstdlib, Assignment1.h
{
    size_type answer = 0;
    Assignment *target_ptr;
    
    target_ptr = list_search(head_ptr, target);
    while (target_ptr != NULL)
    {
        // Each time that target_ptr is not NULL, we have another occurrence
        // of target. We remove this target using the same technique that
        // was used in erase_one.
        target_ptr->set_data( head_ptr->data( ) );
        target_ptr = target_ptr->link( );
        target_ptr = list_search(target_ptr, target);
        list_head_remove(head_ptr);
        --many_Assignments;
        earned_pts = earned_pts - target;
        ++answer;
    }
    return answer;
}

bool Gradebook::erase_one(const value_type& target)
// Library facilities used: cstdlib, Assignment1.h
{
    Assignment *target_ptr;
    
    target_ptr = list_search(head_ptr, target);
    if (target_ptr == NULL)
        return false; // target isn't in the Gradebook, so no work to do
    
    target_ptr->set_data( head_ptr->data( ) );
    list_head_remove(head_ptr);
    --many_Assignments;
    earned_pts = earned_pts - target;
    return true;
}

void Gradebook::list_print()
{
    Assignment * cursor;
    
    for(cursor = head_ptr; cursor != NULL; cursor = cursor -> link())
    {
        cout << cursor ->data() << " | ";
    }
    cout << endl;
    cout << "       Whole points: " << total_pts() << endl;
}

void Gradebook::insert(const value_type& entry)
// Library facilities used: Assignment1.h
{
    list_head_insert(head_ptr, entry);
    ++many_Assignments;
    earned_pts = earned_pts + entry;
}

void Gradebook::insert()
{
    value_type entry;
    cin >> entry;
    list_head_insert(head_ptr, entry);
    ++many_Assignments;
    earned_pts = earned_pts + entry;    
}

Gradebook::value_type Gradebook::name() const
{
    Assignment *cursor;
    
    
    return 
}


#endif

