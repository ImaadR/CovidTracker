
//  Created on 2020-08-02.
//
//  Copyright © 2020 Imaad Remtula  All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include "Tests.hpp"



int main(int argc, const char * argv[]) {
    
    CovidGraphTest obj;
    
    if (obj.test1())
        cout << "******** Test 1 Passed ********" << endl << endl << endl << endl;
    
    if (obj.test2())
           cout << "******** Test 2 Passed ********" << endl << endl << endl << endl;
    
    if (obj.test3())
           cout << "******** Test 3 Passed ********" << endl<< endl << endl << endl;

    return 0;
}

/*
 
 Console Output:
 
 Test 1 Graph and contacts:

 BenStiller -> Came in Contact with -> EmmaWatson, JhonnyDepp, MeghanFox,
 MathewMconohay -> Came in Contact with -> EmmaWatson,
 JhonnyDepp -> Came in Contact with -> KateUpton, BenStiller, MeghanFox,
 MargotRobbie -> Came in Contact with -> KateUpton, MeghanFox,
 KateUpton -> Came in Contact with -> MargotRobbie, JhonnyDepp,
 EmmaWatson -> Came in Contact with -> BenStiller, MathewMconohay,
 MeghanFox -> Came in Contact with -> SarahCameron, MargotRobbie, BenStiller, JhonnyDepp,
 SarahCameron -> Came in Contact with -> MeghanFox,

 ******** Test 1 Passed ********



 Test 2 Graph and contacts:

 BenStiller -> Came in Contact with -> MathewMconohay,
 MathewMconohay -> Came in Contact with -> BenStiller, JhonnyDepp,
 JhonnyDepp -> Came in Contact with -> MathewMconohay,
 MargotRobbie -> Came in Contact with -> KateUpton, SarahCameron,
 KateUpton -> Came in Contact with -> MargotRobbie, EmmaWatson,
 EmmaWatson -> Came in Contact with -> KateUpton, MeghanFox,
 MeghanFox -> Came in Contact with -> EmmaWatson,
 SarahCameron -> Came in Contact with -> MargotRobbie,

 ******** Test 2 Passed ********



 Test 3 Graph and contacts:

 BenStiller -> Came in Contact with -> JhonnyDepp,
 MathewMconohay -> Came in Contact with -> JhonnyDepp,
 JhonnyDepp -> Came in Contact with -> BenStiller, MathewMconohay,
 MargotRobbie -> Came in Contact with -> KateUpton, EmmaWatson,
 KateUpton -> Came in Contact with -> MargotRobbie, EmmaWatson,
 EmmaWatson -> Came in Contact with -> MargotRobbie, KateUpton,
 MeghanFox -> Came in Contact with -> SarahCameron,
 SarahCameron -> Came in Contact with -> MeghanFox,

 ******** Test 3 Passed ********
 
 */
