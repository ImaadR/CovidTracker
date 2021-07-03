
//  Created on 2020-08-02.
//
//  Copyright © 2020 Imaad Remtula All rights reserved.
//

#ifndef Contact_Tracer_HPP
#define Contact_Tracer_HPP
#include <string>
#include <vector>
using namespace std;

// PURPOSE: Models a container that stores individual drone records


class ContactBetween; // For refenecing purposes

class CovidCase
{
    public:
    string PersonID, FirstName, TestDate;
    bool Positive;
    vector<ContactBetween> myContacts; //Each person gets a vector of their own cotacts
   
    //Constructors
    
    CovidCase() : PersonID(" "), FirstName (" "), Positive(false), TestDate(" "), myContacts() {}

    CovidCase(string PersonIdNew, string FirstNameNew, bool PositiveNew, string TestDateNew) :
        PersonID(PersonIdNew), FirstName(FirstNameNew),
        Positive(PositiveNew), TestDate(TestDateNew) {}

    
};

class ContactBetween
{
    public:
    CovidCase* A, *B; //Pointers to the two people who have come into contact
    unsigned int NumberDays;
    string Location;
    
    //Constructors
    
    ContactBetween() : NumberDays(0), Location (" "), A(NULL), B(NULL) {}
    
    ContactBetween (CovidCase *ANew, CovidCase *BNew, unsigned NumberDaysNew, string LocationNew) :
    A(ANew), B(BNew),NumberDays(NumberDaysNew), Location(LocationNew) {}
    
};


class CovidGraph
{

public:
    
    friend class BinarySearchTreeTest;
    
     // Vector of all people who are of interest, Note: the word "cases" here means people who tested positive or people who tested negative. There is no distiction here
    vector <CovidCase> TotalCases;
    
    // Function Definitions
    
    void addCase (CovidCase);
    void addContact (ContactBetween);
    int count_virus_positive_contacts(string person_id);
    int get_location (string PersonID);
    int find_largest_cluster_with_two_positive();
    void print ();
    
    
};

#endif
