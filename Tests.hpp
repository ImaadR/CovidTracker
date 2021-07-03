
//
//  Created on 2020-08-04.
//
//  Copyright © 2020 Imaad Remtula All rights reserved.
//

#ifndef TESTS_HPP
#define TESTS_HPP

#define ASSERT_TRUE(T) if (!(T)) return false;
#define ASSERT_FALSE(T) if ((T)) return false;

#include <algorithm>
#include <sstream>
#include <queue>
#include <iostream>

#include "Contact_Tracer.hpp"

using namespace std;

class CovidGraphTest {
public:
    
    // All people came into contact, so no seperation in the graph. Lots of connections
    bool test1() {
         

          CovidCase Case1 ("BenStiller", "Ben", true, "2/2/2020");
          CovidCase Case2 ("MathewMconohay", "Mathew", false, "2/2/2020");
          CovidCase Case3 ("JhonnyDepp", "Jhonny", true, "2/2/2020");
          CovidCase Case4 ("MargotRobbie", "Margot", false, "2/2/2020");
          CovidCase Case5 ("KateUpton", "Kate", true, "2/2/2020");
          CovidCase Case6 ("EmmaWatson", "Emma", true, "2/2/2020");
          CovidCase Case7 ("MeghanFox", "Meghan", true, "2/2/2020");
          CovidCase Case8 ("SarahCameron", "Sarah", true, "2/2/2020");
        
          
          
          CovidGraph Graph;
          
          Graph.addCase(Case1);
          Graph.addCase(Case2);
          Graph.addCase(Case3);
          Graph.addCase(Case4);
          Graph.addCase(Case5);
          Graph.addCase(Case6);
          Graph.addCase(Case7);
          Graph.addCase(Case8);
          
          ContactBetween Contact1 (&Case1,&Case6, 5, "BoraBora");
          ContactBetween Contact2 (&Case6,&Case2, 5, "BoraBora");
          ContactBetween Contact3 (&Case4,&Case5, 5, "BoraBora");
          ContactBetween Contact4 (&Case3,&Case5, 5, "BoraBora");
          ContactBetween Contact5 (&Case1,&Case3, 5, "BoraBora");
          ContactBetween Contact6 (&Case7,&Case8, 5, "BoraBora");
          ContactBetween Contact7 (&Case7,&Case4, 5, "BoraBora");
          ContactBetween Contact8 (&Case7,&Case1, 5, "BoraBora");
          ContactBetween Contact9 (&Case7,&Case3, 5, "BoraBora");

          
          Graph.addContact(Contact1);
          Graph.addContact(Contact2);
          Graph.addContact(Contact3);
          Graph.addContact(Contact4);
          Graph.addContact(Contact5);
          Graph.addContact(Contact6);
          Graph.addContact(Contact7);
          Graph.addContact(Contact8);
          Graph.addContact(Contact9);
          
          

         
         cout << "Test 1 Graph and contacts: " << endl << endl;
         Graph.print();
         cout << endl;

         ASSERT_TRUE(Graph.count_virus_positive_contacts("MargotRobbie") == 6); //Person called on tested Negative
         ASSERT_TRUE(Graph.count_virus_positive_contacts("MeghanFox") == 5); //Person called on tested Positive
         ASSERT_TRUE(Graph.count_virus_positive_contacts("BenStiller") == 5); //Person called on tested Positive
         ASSERT_TRUE(Graph.find_largest_cluster_with_two_positive() == 8); //Only one cluster to manage, atleast 2 positive
           

           return true;
      }

    
      bool test2() {
         
          

           CovidCase Case1 ("BenStiller", "Ben", true, "2/2/2020");
           CovidCase Case2 ("MathewMconohay", "Mathew", true, "2/2/2020");
           CovidCase Case3 ("JhonnyDepp", "Jhonny", true, "2/2/2020");
           
           CovidCase Case4 ("MargotRobbie", "Margot", false, "2/2/2020");
           CovidCase Case5 ("KateUpton", "Kate", true, "2/2/2020");
           CovidCase Case6 ("EmmaWatson", "Emma", false, "2/2/2020");
           CovidCase Case7 ("MeghanFox", "Meghan", true, "2/2/2020");
           CovidCase Case8 ("SarahCameron", "Sarah", false, "2/2/2020");
         
           
           
           CovidGraph Graph;
           
           Graph.addCase(Case1);
           Graph.addCase(Case2);
           Graph.addCase(Case3);
          
           Graph.addCase(Case4);
           Graph.addCase(Case5);
           Graph.addCase(Case6);
           Graph.addCase(Case7);
           Graph.addCase(Case8);
           
           ContactBetween Contact1 (&Case1,&Case2, 5, "BoraBora");
           ContactBetween Contact2 (&Case2,&Case3, 5, "BoraBora");
           
           ContactBetween Contact3 (&Case4,&Case5, 5, "BoraBora");
           ContactBetween Contact4 (&Case4,&Case8, 5, "BoraBora");
           ContactBetween Contact5 (&Case5,&Case6, 5, "BoraBora");
           ContactBetween Contact6 (&Case6,&Case7, 5, "BoraBora");
           
           Graph.addContact(Contact1);
           Graph.addContact(Contact2);
          
           Graph.addContact(Contact3);
           Graph.addContact(Contact4);
           Graph.addContact(Contact5);
           Graph.addContact(Contact6);
           
          cout << "Test 2 Graph and contacts: " << endl << endl;
          Graph.print();
          cout << endl;
          
          ASSERT_TRUE(Graph.count_virus_positive_contacts("KateUpton") == 1); //Person called on tested positive
          ASSERT_TRUE(Graph.count_virus_positive_contacts("EmmaWatson") == 2); //Person called on tested negative, Person not connected to everyone in the graph
          ASSERT_TRUE(Graph.count_virus_positive_contacts("BenStiller") == 2); //Person called on tested positive, Person not connected to everyone in the graph
          ASSERT_TRUE(Graph.find_largest_cluster_with_two_positive() == 5); // Two clusters to manage, both have alteast 2 positive
          

          return true;
      }
    
    
    bool test3() {
       
        

         CovidCase Case1 ("BenStiller", "Ben", false, "2/2/2020");
         CovidCase Case2 ("MathewMconohay", "Mathew", false, "2/2/2020");
         CovidCase Case3 ("JhonnyDepp", "Jhonny", true, "2/2/2020");
        
         CovidCase Case4 ("MargotRobbie", "Margot", false, "2/2/2020");
         CovidCase Case5 ("KateUpton", "Kate", true, "2/2/2020");
         CovidCase Case6 ("EmmaWatson", "Emma", false, "2/2/2020");
        
         CovidCase Case7 ("MeghanFox", "Meghan", true, "2/2/2020");
         CovidCase Case8 ("SarahCameron", "Sarah", false, "2/2/2020");
       
         
         
         CovidGraph Graph;
         
         Graph.addCase(Case1);
         Graph.addCase(Case2);
         Graph.addCase(Case3);
         Graph.addCase(Case4);
         Graph.addCase(Case5);
         Graph.addCase(Case6);
         Graph.addCase(Case7);
         Graph.addCase(Case8);
         
         ContactBetween Contact1 (&Case1,&Case3, 5, "BoraBora");
         ContactBetween Contact2 (&Case3,&Case2, 5, "BoraBora");
        
         ContactBetween Contact3 (&Case4,&Case5, 5, "BoraBora");
         ContactBetween Contact4 (&Case6,&Case4, 5, "BoraBora");
         ContactBetween Contact5 (&Case6,&Case5, 5, "BoraBora");
        
         ContactBetween Contact6 (&Case7,&Case8, 5, "BoraBora");
         
         Graph.addContact(Contact1);
         Graph.addContact(Contact2);
         Graph.addContact(Contact3);
         Graph.addContact(Contact4);
         Graph.addContact(Contact5);
         Graph.addContact(Contact6);
         

        
        cout << "Test 3 Graph and contacts: " << endl << endl;
        Graph.print();
        cout << endl;

        ASSERT_TRUE(Graph.count_virus_positive_contacts("KateUpton") == 0); //Person called on tested positive, Person not connected to everyone in the graph
        ASSERT_TRUE(Graph.count_virus_positive_contacts("SarahCameron") == 1); //Person called on tested negative, Person not connected to everyone in the graph
        ASSERT_TRUE(Graph.count_virus_positive_contacts("BenStiller") == 1); //Person called on tested negative, Person not connected to everyone in the graph
        ASSERT_TRUE(Graph.find_largest_cluster_with_two_positive() == -1); // 3 clusters to manage, no clusters with 2 positive
          

          return true;
    }

};
#endif

