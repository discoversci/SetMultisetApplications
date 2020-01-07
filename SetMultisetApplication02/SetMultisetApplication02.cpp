// constructor and assignment operator � multiset
#include <set>
#include <iostream>
#include <functional>

using namespace std;

template <class T> void print(T start, T end) {
	while (start != end) {
		std::cout << *start << " "; start++;
	}
}


int main() {
	int t[] = { 2, 10, 8, 4, 5, 5, 3, 10, 7, 2 };

	//1. standard initialization - default constructor
	multiset <int> s1;

	//2. iterator constructor
	multiset <int> s2(t, t + 10);
	print(s2.begin(), s2.end()); cout << endl;

	//3. copy constructor
	multiset <int> s3(s2);
	print(s3.begin(), s3.end()); cout << endl;

	//4. providing different comparator
	multiset<int, greater <int> > s4(t, t + 10);
	print(s4.begin(), s4.end()); cout << endl;

	//5. Not allowed - source and target object are not of the same type
	//podobno kot pri prejsnjem primeru - nekompatibilen comparator
	//multi_set<int, greater<int> > s5 (s3);

	//6. assignment
	multiset <int> s6;
	s6 = s3;
	print(s6.begin(), s6.end()); cout << endl;

	//7. Not allowed - assignment of incompatible multi_set objects
	//podobno kot pri prejsnjem primeru - nekompatibilen comparator
	//s6 = s4;
	return 0;
}
