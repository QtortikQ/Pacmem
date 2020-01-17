#ifndef SMART_POINTER_
#define SMART_POINTER_

template <typename T>

class SmartPointer
{
public:

	SmartPointer(T* obj)
		: m_obj(obj){ 
	}

	~SmartPointer() {
		delete m_obj;
	}

	T* operator->() { return m_obj; }


	T& operator* () { return *m_obj; }
public:
	T* m_obj;
};

#endif // !SMART_POINTER_
