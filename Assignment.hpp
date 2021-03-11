//
//  Assignment.hpp
//  AssignmentProgram
//
//  Created by Eohjungsun on 3/25/16.
//  Copyright © 2016 AssignmentEX. All rights reserved.
//

#ifndef Assignment_hpp
#define Assignment_hpp

#include <cstdlib> // Provides size_t and NULL

class Assignment
{
public:
    // TYPEDEF
    typedef double value_type;
    
    // CONSTRUCTOR
    Assignment(
         const value_type& init_data = value_type( ),
         Assignment* init_link = NULL
         )
    { data_field = init_data; link_field = init_link; }
    
    // Member functions to set the data and link fields:
    void set_data(const value_type& new_data) { data_field = new_data; }
    void set_link(Assignment* new_link)             { link_field = new_link; }
    
    // Constant member function to retrieve the current data:
    value_type data( ) const { return data_field; }
    
    // Two slightly different member functions to retreive
    // the current link:
    const Assignment* link( ) const { return link_field; }
    Assignment* link( )             { return link_field; }
    
private:
    value_type data_field; // points that student earned
    Assignment* link_field;
};

// FUNCTIONS for the linked list toolkit
std::size_t list_length(const Assignment* head_ptr);
void list_head_insert(Assignment*& head_ptr, const Assignment::value_type& entry);
void list_insert(Assignment* previous_ptr, const Assignment::value_type& entry);
Assignment* list_search(Assignment* head_ptr, const Assignment::value_type& target);
const Assignment* list_search
(const Assignment* head_ptr, const Assignment::value_type& target);
Assignment* list_locate(Assignment* head_ptr, std::size_t position);
const Assignment* list_locate(const Assignment* head_ptr, std::size_t position);
void list_head_remove(Assignment*& head_ptr);
void list_remove(Assignment* previous_ptr);
void list_clear(Assignment*& head_ptr);
void list_copy(const Assignment* source_ptr, Assignment*& head_ptr, Assignment*& tail_ptr);

#endif /* Assignment_hpp */
