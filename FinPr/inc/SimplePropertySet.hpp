//
//  SimplePropertySet.hpp
//  FinPr
//
//  Created by Weifeng Liu on 4/3/15.
//  Copyright (c) 2015 Weifeng Liu. All rights reserved.
//

#ifndef FinPr_SimplePropertySet_hpp
#define FinPr_SimplePropertySet_hpp

#include "src\property.cpp"
#include <list>

using namespace std;

template <class N, class V> class SimplePropertySet
{
private:
	N nam;
	list<Property<N, V>> pl;
	
public:
	typedef typename list<Property<N, V>>::iterator iterator;
	typedef typename list<Property<N, V>>::const_iterator const_iterator;
	
	// Constructors and Destructors
	SimplePropertySet();
	SimplePropertySet(const N& name);
	SimplePropertySet(const SimplePropertySet<N, V>& source);
	
	virtual ~SimplePropertySet();
	
	// Iterator functions
	iterator Begin();
	const_iterator Begin() const;
	iterator End();
	const_iterator End() const;
	
	// Selectors
	int Count() const;
	N operator ()() const;
	bool hasProperty(const N& search_name) const;
	
	// Modifiers
	void operator () (const N& name);
	Property<N, V> value(const N& name) const;
	void set(const N& name, const V & value);
	
	// Add and remove functions
	void add(const Property<N, V>& p);
	void add(const SimplePropertySet<N, V>& sp);
	void remove(const N& name);
	
	// Operators
	SimplePropertySet<N, V> operator = (const SimplePropertySet<N, V>& source);
}

#endif
