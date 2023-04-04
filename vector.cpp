#include<iostream>
using namespace std;

template<typename T>
class MyVector {
public:
	typedef T value;
	typedef T* iterator;
	typedef T& reference;

	MyVector(int len = 0) : data(nullptr), start(nullptr), len(len), pos(0) {
		if (len > 0) {
			data = new value[len];
			start = data;
		}
	}

	~MyVector() {
		delete[]data;
	}

	void push_back(const value v) {
		if (len != pos) {
			*(start + pos) = v;
			pos++;
		}
		else {
			cout << "Can't push more element, out of bounds" << endl;
		}
		
	}
	value pop_back() {
		pos--;
		return *(start + pos);
	}
	
	int size() {
		return this->len;
	}
	iterator begin() {
		return this->start;
	}
	iterator end() {
		return this->start + pos;
	}

	value& operator[](int n) {
		if (n <= pos) {
			return *(start + n);
		}
		else {
			cout << "index is out of bounds" << endl;
		}
	}
protected:
	iterator data;
	iterator start;
	int len;
	int pos;
};

int main() {
	MyVector<int> vec(10);
	for (int i = 0; i < vec.size(); i++) {
		vec.push_back(i);
	}

	for (MyVector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
		cout << *it << " ";
	}
}