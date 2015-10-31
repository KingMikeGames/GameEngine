#pragma once


/*
keeps count of how many things are referencing an object that
inherits this referenceCounter
*/
class ReferenceCounter
{
public:

	/*
	sets reference count to 1
	when an object is created
	*/
	ReferenceCounter() :
		m_refCount(1) {}

	/*
	returns number of objects referencing this object
	*/
	inline int GetReferenceCount() { return m_refCount; }

	/*
	increment refernece count
	*/
	inline void AddReference() { m_refCount++; }

	/*
	decrement count
	*/
	inline bool RemoveReference() { m_refCount--; return m_refCount == 0; }
protected:
private:

	/*
	total number of references in memory
	*/
	int m_refCount;
};