//
//  SimplePropertySet.cpp
//  FinPr
//
//  Created by Weifeng Liu on 4/4/15.
//  Copyright (c) 2015 Weifeng Liu. All rights reserved.
//

#ifndef FinPr_SimplePropertySet_hpp
#define FinPr_SimplePropertySet_hpp

#include "inc/SimplePropertySet.hpp"

// Constructors and Destructor
template <class N, class V>
SimplePropertySet<N, V> :: SimplePropertySet()
{
	nam = N();
	pl = list<Property<N, V>>();
}

template <class N, class V>
SimplePropertySet<N, V> :: SimplePropertySet(const N& name)
{
	nam = name;
	pl = list<Property<N, V>>();
}

template <class N, class V>
SimplePropertySet<N, V> :: SimplePropertySet(const SimplePropertySet<N, V>& source)
{
	nam = source.nam;
	pl = source.pl;
}

template <class N, class V>
SimplePropertySet<N, V> :: ~SimplePropertySet()
{
}

// Iterator functions
template <class N, class V>
SimplePropertySet<N, V> :: iterator SimplePropertySet<N, V> :: Begin()
{
	return pl.begin();
}

template <class N, class V>
SimplePropertySet<N, V> :: const_iterator SimplePropertySet<N, V> :: Begin() const
{
	return pl.begin();
}

// Iterator functions
template <class N, class V>
SimplePropertySet<N, V> :: iterator SimplePropertySet<N, V> :: End()
{
	return pl.end();
}

template <class N, class V>
SimplePropertySet<N, V> :: const_iterator SimplePropertySet<N, V> :: End() const
{
	return pl.end();
}

// Selectors
template <class N, class V>
int SimplePropertySet<N, V> :: Count() const
{
	return pl.size();
}

template <class N, class V>
N SimplePropertySet<N, V> :: operator ()() const
{
	return nam;
}

template <class N, class V>
bool SimplePropertySet<N, V> :: hasProperty(const N& search_name) const
{
	const_iterator it;
	for (it=pl.begin(); it != pl.end(); it++)
	{
		if ((*it).name() == search_name)
		{
			return true;
		}
	}
	return false;
}

// Modifiers
template <class N, class V>
void SimplePropertySet<N, V> :: operator () (const N& name)
{
	nam = name;
}

template <class N, class V>
Property<N, V> SimplePropertySet<N, V> :: value(const N& name) const
{
	const_iterator it;
	for (it=pl.begin(); it != pl.end(); it++)
	{
		if ((*it).name() == name)
		{
			return *it;
		}
	}
	
	// If not found, then take no action, caveat emptor.
}

template <class N, class V>
void SimplePropertySet<N, V> :: set(const N& name, const V & value)
{
	const_iterator it;
	for (it=pl.begin(); it != pl.end(); it++)
	{
		if ((*it).name() == name)
		{
			(*it)(value);
			break;
		}
	}
	
	// If not found, then take no action, caveat emptor.
}

// Add and remove functions
template <class N, class V>
void SimplePropertySet<N, V> :: add(const Property<N, V>& p)
{
	pl.push_back(p);
}

template <class N, class V>
void SimplePropertySet<N, V> :: add(const SimplePropertySet<N, V>& sp)
{
	const_iterator it;
	for (it=sp.begin(); it != sp.end(); it++)
	{
		add(*it);
	}	
}

template <class N, class V>
void SimplePropertySet<N, V> :: remove(const N& name)
{
	const_iterator it;
	for (it=pl.begin(); it != pl.end(); it++)
	{
		if ((*it).name() == name)
		{
			pl.erase(it);
		}
	}
}

// Operators
template <class N, class V>
SimplePropertySet<N, V> SimplePropertySet<N, V> :: operator = (const SimplePropertySet<N, V>& source)
{
	nam = source.name;
	pl = source.pl;
	
	return *this;
}













#endif