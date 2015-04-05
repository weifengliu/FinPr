//
//  property.hpp
//  FinPr
//
//  Base class for Properties.
//
//  Created by Weifeng Liu on 3/28/15.
//  Copyright (c) 2015 Weifeng Liu. All rights reserved.
//

#ifndef PROPERTY_HPP
#define PROPERTY_HPP

#include <string>
#include <stdio.h>

using namespace std;

template <class Name = string, class Value = double> class Property
{
private:
	Name nam;
	Value val;
	
public:
	Property();
	Property(const Name& name);
	Property(const Value& v);
	Property(const Name& name, const Value& v);
	Property(const Property<Name, Value>& source);
	
	virtual ~Property();
	
	virtual Name name() const;
	virtual Value operator ()() const;
	virtual void name(const Name& new_name);
	virtual void operator ()(const Value& new_val);
	
	bool operator == (const Property<Name, Value>& prop2);
	Property<Name, Value>& operator = (const Property<Name, Value>& source);

};

#endif