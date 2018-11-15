//
//  main.cpp
//  22C_Project
//
//  Created by Oh Reum Kwon on 11/7/18.
//  Copyright © 2018 Oh Reum Kwon. All rights reserved.
//

#include <iostream>
#include "Contact.h"
#include "Location.h"
using namespace std;

int main()
{
    Location home("John", "408-123-4567", "home", "1042 Bret Hill Court", 37.263310, -121.893110);
    Location school("De Anza College", "408-908-7654", "school", "21250 Stevens Creek Blvd, Cupertino", 37.319200, -122.044880);
    
    cout << "Printing Information about " << home.getType() << ":" << endl;
    cout << home.getName() << endl;
    cout << home.getNumber() << endl;
    cout << home.getAddress() << endl << endl;
    
    cout << "Printing Information about " << school.getType() << ":" << endl;
    cout << school.getName() << endl;
    cout << school.getNumber() << endl;
    cout << school.getAddress() << endl << endl;
    
    cout << "The distance between " << home.getType() << " and " << school.getType() <<
    " is " << home.getDistance(school) << " miles" << endl;
    
    return 0;
}
