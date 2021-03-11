//
//  Grade_Book.hpp
//  AssignmentProgram
//
//  Created by Eohjungsun on 3/25/16.
//  Copyright © 2016 AssignmentEX. All rights reserved.
//

#ifndef Grade_Book_hpp
#define Grade_Book_hpp

#include <cstdlib>   // Provides size_t and NULL
#include "Assignment.hpp"   // Provides Assignment class
#include <string>
using namespace std;

class Gradebook
{
public:
    //TYPEDEF
    typedef std::size_t size_type;
    typedef Assignment::value_type value_type;
    //CONSTUCTORS and DESTRUCTOR
    Gradebook();
    Gradebook(const Gradebook& source);
    ~Gradebook();
    // MODIFICATION MEMBER FUNCTIONS
    size_type erase(const value_type& target);
    bool erase_one(const value_type& target);
    void insert();
    void insert(const value_type& entry);
    // CONSTANT MEMBER FUNCTIONS
    size_type size( ) const { return many_Assignments; }
    size_type count(const value_type& target) const;
    value_type total_pts() const { return earned_pts; }
    Assignment headPtr() const { return *head_ptr; }
    void list_print();
    value_type name() const;
    
private:
    Assignment *head_ptr;       // List head pointer
    size_type many_Assignments; // Number of Assignments on the Gradebook
    value_type earned_pts;  // Whole Assignments Gradebook earned
};


#endif /* Gradebook_hpp */
