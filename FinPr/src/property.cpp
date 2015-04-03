//
//  property.cpp
//  FinPr
//
//  Created by Weifeng Liu on 4/1/15.
//  Copyright (c) 2015 Weifeng Liu. All rights reserved.
//

#ifndef PROPERTY_CPP
#define PROPERTY_CPP

#include "inc/property.hpp"

template <class Name, class Value>
Property<Name, Value> :: Property()
{
	// Constructor
	nam = Name();
	val = Value();
}

template <class Name, class Value>
Property<Name, Value> :: Property(const Name& name)
{
	// Constructor
	nam = name;
	val = Value();
}

template <class Name, class Value>
Property<Name, Value> :: Property(const Value& v)
{
	// Constructor
	nam = Name();
	val = v;
}

template <class Name, class Value>
Property<Name, Value> :: Property(const Name& name, const Value& v)
{
	// Constructor
	nam = name;
	val = v;
}

template <class Name, class Value>
Property<Name, Value> :: Property(const Property<Name, Value>& source)
{
	// Constructor
	nam = source.name;
	val = source.v;
}

template <class Name, class Value>
Property<Name, Value> :: ~Property()
{
	// Destructor
}

template <class Name, class Value>
Property<Name, Value>& Property<Name, Value> :: operator = (const Property<Name, Value>& source)
{
	nam = source.nam;
	val = source.val;
	return *this;
}

template <class Name, class Value>
bool Property<Name, Value> :: operator == (const Property<Name, Value>& prop2)
{
	if (nam != prop2.nam) return false;
	if (val != prop2.val) return false;
	return true;
}

template <class Name, class Value>
Name Property<Name, Value> :: name() const
{
	return nam;
}

template <class Name, class Value>
Value Property<Name, Value> :: operator ()() const
{
	return val;
}

template <class Name, class Value>
void Property<Name, Value> :: name(const Name& new_name)
{
	nam = new_name;
}

template <class Name, class Value>
void Property<Name, Value> :: operator ()(const Value& new_val)
{
	val = new_val;
}


#endif
