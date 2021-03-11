//
//  Assignment.cpp
//  AssignmentProgram
//
//  Created by Eohjungsun on 3/25/16.
//  Copyright © 2016 AssignmentEX. All rights reserved.
//

#include "Assignment.hpp"
#include <cassert>    // Provides assert
#include <cstdlib>    // Provides NULL and size_t
using namespace std;

size_t list_length(const Assignment* head_ptr)
// Library facilities used: cstdlib
{
    const Assignment *cursor;
    size_t answer;
    
    answer = 0;
    for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
        ++answer;
    
    return answer;
}

void list_head_insert(Assignment*& head_ptr, const Assignment::value_type& entry)
{
    head_ptr = new Assignment(entry, head_ptr);
}

void list_insert(Assignment* previous_ptr, const Assignment::value_type& entry)
{
    Assignment *insert_ptr;
    
    insert_ptr = new Assignment(entry, previous_ptr->link( ));
    previous_ptr->set_link(insert_ptr);
}

Assignment* list_search(Assignment* head_ptr, const Assignment::value_type& target)
// Library facilities used: cstdlib
{
    Assignment *cursor;
    
    for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
        if (target == cursor->data( ))
            return cursor;
    return NULL;
}

const Assignment* list_search(const Assignment* head_ptr, const Assignment::value_type& target)
// Library facilities used: cstdlib
{
    const Assignment *cursor;
    
    for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
        if (target == cursor->data( ))
            return cursor;
    return NULL;
}

Assignment* list_locate(Assignment* head_ptr, size_t position)
// Library facilities used: cassert, cstdlib
{
    Assignment *cursor;
    size_t i;
    
    assert (0 < position);
    cursor = head_ptr;
    for (i = 1; (i < position) && (cursor != NULL); i++)
        cursor = cursor->link( );
    return cursor;
}

const Assignment* list_locate(const Assignment* head_ptr, size_t position)
// Library facilities used: cassert, cstdlib
{
    const Assignment *cursor;
    size_t i;
    
    assert (0 < position);
    cursor = head_ptr;
    for (i = 1; (i < position) && (cursor != NULL); i++)
        cursor = cursor->link( );
    return cursor;
}

void list_head_remove(Assignment*& head_ptr)
{
    Assignment *remove_ptr;
    
    remove_ptr = head_ptr;
    head_ptr = head_ptr->link( );
    delete remove_ptr;
}

void list_remove(Assignment* previous_ptr)
{
    Assignment *remove_ptr;
    
    remove_ptr = previous_ptr->link( );
    previous_ptr->set_link( remove_ptr->link( ) );
    delete remove_ptr;
}

void list_clear(Assignment*& head_ptr)
// Library facilities used: cstdlib
{
    while (head_ptr != NULL)
    list_head_remove(head_ptr);
}

void list_copy(const Assignment* source_ptr, Assignment*& head_ptr, Assignment*& tail_ptr)
// Library facilities used: cstdlib
{
    head_ptr = NULL;
    tail_ptr = NULL;
    
    // Handle the case of the empty list.
    if (source_ptr == NULL)
        return;
    
    // Make the head Assignment for the newly created list, and put data in it.
    list_head_insert(head_ptr, source_ptr->data( ));
    tail_ptr = head_ptr;
    
    // Copy the rest of the Assignments one at a time, adding at the tail of new list.
    source_ptr = source_ptr->link( );
    while (source_ptr != NULL)
    {
        list_insert(tail_ptr, source_ptr->data( ));
        tail_ptr = tail_ptr->link( );
        source_ptr = source_ptr->link( );
    }
}
