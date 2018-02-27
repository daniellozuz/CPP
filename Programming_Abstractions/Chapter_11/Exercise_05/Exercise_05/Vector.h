#ifndef _vector_h
#define _vector_h

template <typename T>
class Vector {
public:
	Vector();
	~Vector();

	int size();
	bool is_empty();
	void clear();
	T get_at(int index);
	void set_at(int index, T value);
	void insert_at(int index, T element);
	void remove_at(int index);
	void add(T element);
	T &operator[](int index);

	class Iterator {
	public:
		Iterator();
		bool has_next();
		T next();
	private:
		Vector *vp;
		int index;
		Iterator(Vector *vp);
		friend class Vector;
	};
	friend class Iterator;

	Iterator iterator();

private:
	static const int INITIAL_CAPACITY = 100;
	T *elements;
	int capacity;
	int count;
	void expand_capacity();
};

#include "Vector.hpp"

#endif
