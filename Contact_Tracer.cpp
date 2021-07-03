
//  Created on 2020-08-02.
//
//  Copyright © 2020 Imaad Remtula rights reserved.
//

#include "Contact_Tracer.hpp"
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>


using namespace std;


//Add a person to the vector of people, Note: the word "cases" here means people who tested positive or people who tested negative. there is no distiction here
void CovidGraph::addCase(CovidCase obj)
{
        
        CovidGraph::TotalCases.push_back(obj);
}

// Add an edge between two people
void CovidGraph::addContact(ContactBetween Obj)
{
        ContactBetween this_contact = Obj; // take in the parameter which includes the two people and all other information
        unsigned long size = CovidGraph::TotalCases.size();
        int a = 0;
        int b = 0;
        
        for (int i = 0; i < size; i++)
        {
                 if (CovidGraph::TotalCases[i].PersonID == this_contact.A->PersonID) // Find person A in the graph
                         a = i;
                 else if (CovidGraph::TotalCases[i].PersonID == this_contact.B->PersonID) // Find person B in the graph
                         b = i;
        }
                this_contact.A = &TotalCases[a]; // Assign the location of person A from the graph
                this_contact.B = &TotalCases[b]; // Assign the location of person B from the graph
                
                CovidGraph::TotalCases[a].CovidCase::myContacts.push_back(this_contact); // give person A this contact such that in the ContactBetween, A is the current person, i.e TotalCases[a], and person B is the person they came in contact with
                
                swap(this_contact.A, this_contact.B); // Swap person A and B, so that in the next line, the ContactBetween is given such that A is the new current person, i.e TotalCases[b], and person B is the person they came in contact with
               
                CovidGraph::TotalCases[b].CovidCase::myContacts.push_back(this_contact);
        
}

// Helper function to output the graph for testing and verification purposes
void CovidGraph::print()
{
    for (int a = 0; a < TotalCases.size(); a++)
    {
        cout << TotalCases[a].PersonID << " -> Came in Contact with -> ";
        for(int b = 0; b < TotalCases[a].myContacts.size(); b++)
        {
            if (TotalCases[a].myContacts.size() !=0)
            {
                cout << TotalCases[a].myContacts[b].B->PersonID << ", ";
            }
        }
       cout << endl;
    }
}

// Helper function that given the person_id, returns the index of that person within the total cases vector
int CovidGraph::get_location (string person_id)
{
    unsigned long size = CovidGraph::TotalCases.size();
    int a = 0;
    bool found = false;
    while (a<size && !found)
           {
                   if(CovidGraph::TotalCases[a].PersonID == person_id)
                   {
                        found = true;
                   }
                   a++;
           }
           a--;
    return a;
}

int CovidGraph::count_virus_positive_contacts(string person_id)
{
    queue <CovidCase> theQue;
    unsigned long size = CovidGraph::TotalCases.size();
    vector<int> visited (size); // unvisited is 0, visited is 1;
    int TotalPositive = 0;
    
    
    visited[get_location(person_id)] = 1; // Mark this node as visited since it is being pushed into the que in the next line
    theQue.push(TotalCases[get_location(person_id)]);
    
    
    while (!theQue.empty())
    {
        if (theQue.front().Positive == true) // check to see is the counter needs to be increased
        {
                TotalPositive++;
        }
       
        for (int a = 0; a < theQue.front().myContacts.size(); a++) // This for loop goes through every person in the myContacts list of the given person
        {
            int location = get_location(theQue.front().myContacts[a].B->PersonID); // get location of the person in the contacts list
            if(visited[location] == 0) // only proceed if this person has not been visited yet
            {
                theQue.push(TotalCases[location]); //push into the que
                visited[location] = 1; //mark their location as visited
                
            }
        }
        theQue.pop();
    }
    
    // Since the given person will have been included in the positive count, check to see if they are positive and count is not 0. if so, decrement count
    if (TotalCases[get_location(person_id)].Positive && TotalPositive > 0)
    {
        return (TotalPositive-1);
    }
    else
        return TotalPositive; // if given person did not test positive, just return the count
    
    
}


int CovidGraph::find_largest_cluster_with_two_positive()
{
    queue <CovidCase> theQue;
    unsigned long size = CovidGraph::TotalCases.size();
    vector<int> visited (size); // Keeps track of visited people
    vector<int> TotalPositive (100,0); // keeps track of the total positive people per cluster. Assume not more than 100 clusters present
    int iteration_number = 1;
    vector <int> iterations (100,0); // keeps track of the total people per cluster. Assume not more than 100 clusters present
    
    
    // This for loop checks if there are any unvisited people. Once/if it finds such a person, it ques them, so that they and all their contacts can be checked, as was done in the above code.
    for (int b = 0; b < size; b++)
       {
           if (visited[b] == 0)
           {
                visited[b] = 1;
                theQue.push(TotalCases[b]);
                iterations[iteration_number]++;
               // everytime a push occurs, a person gets processed, therefore increment the iterations vector at index iteration, i.e for the current cluster
                
                
                while (!theQue.empty())
                {
                    if (theQue.front().Positive == true)
                    {
                            TotalPositive[iteration_number]++;
                        // if a positive person is found, increment the positive vector at index iteration, i.e for the current cluster
                    }
                   
                    for (int a = 0; a < theQue.front().myContacts.size(); a++)
                    {
                        int location = get_location(theQue.front().myContacts[a].B->PersonID); // Same functionality as previous function
                        if(visited[location] == 0)
                        {
                            theQue.push(TotalCases[location]);
                            iterations[iteration_number]++; // Only diffence is that the number of pushes is counted
                            visited[location] = 1;
                        }
                    }
                    theQue.pop();
                }
    
           }
           
           iteration_number++; // end of loop, move onto the next iteration, i.e next cluster of people who are connected
       }
    
    int Largest_Cluster = 0; // arbitrary max
    bool noneAbove2 = true;
    
    for (int c = 0; c<20; c++)
    {
        if (TotalPositive[c] >= 2) // if atleast two positive
        {
            if (iterations[c] > Largest_Cluster) // look through the vector which essentially stored number of times push was called per cluster
            {
                Largest_Cluster = iterations[c]; // find the real largest
                noneAbove2=false; // change this so that the next line knows clusters above 2 positive exist
            }
        }
            
    }
    
    if (noneAbove2) // is this is still true, no clusters of atleast 2 positive
        return -1;
    else
        return Largest_Cluster; // return the max
}
