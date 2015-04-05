//
//  test_property.cpp
//  FinPr
//
//  Test files for different property members.
//
//  Created by Weifeng Liu on 4/5/15.
//  Copyright (c) 2015 Weifeng Liu. All rights reserved.
//

#include "inc/SimplePropertySet.hpp"

#include <iostream>
using namespace std;

void print(const SimplePropertySet<string,double>& pset)
{

	SimplePropertySet<string,double>::const_iterator it;
	
	cout << "\nPrinting Unique option\n";

	for (it= pset.Begin(); it!=pset.End(); it++)
	{ 
	
			cout << (*it).name() << ", " << (*it)() << endl;
	}
}

int main()
{
	
	// The properties
	SimplePropertySet<string,double> myDefaultSet;
	
	// My property set that is default for my European option class
	// You can customise this to suit your own needs and wants

	Property<string, double> r;		// Interest rate
	Property<string, double> sig;	// Volatility
	Property<string, double> K;		// Strike price
	Property<string, double> T;		// Expiry date
	Property<string, double> U;		// Current underlying price (e.g. stock, forward)
	Property<string, double> b;		// Cost of carry


	r = Property<string, double> ("Interest rate", 0.08);
	sig= Property<string, double> ("Volatility",0.30);
	K = Property<string, double>("Strike Price", 65.0);
	T = Property<string, double>("Expiry date", 0.25);
	U = Property<string, double>("Underlying Asset", 60.0);		
	b = Property<string, double>("Cost of carry rate", r());	

	myDefaultSet.add(r);
	myDefaultSet.add(sig);
	myDefaultSet.add(K);
	myDefaultSet.add(T);
	myDefaultSet.add(U);
	myDefaultSet.add(b);

	// Create another set
	SimplePropertySet<string,double> mySet2(myDefaultSet);
	mySet2.set("Volatility", 0.20);
	mySet2.set("Expiry date", 1.0);

	// Print these Psets
	print(myDefaultSet);
	print(mySet2);

	return 0;
	
}
