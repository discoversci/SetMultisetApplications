// multiset
#include <set>
#include <iostream>
#include <functional>

using namespace std;

template <class T> void print(T start, T end) {
	for (; start != end; ++start) {
		std::cout << *start << " ";
	}
}

int main() {
	int t[] = { 1, 10, 5, 8, 4, 5, 6, 3, 9, 7, 2, 4 };
	multiset <int> s1(t, t + 12);
	cout << "S1: ";     
	print(s1.begin(), s1.end()); cout << endl;
	
	cout << "Finding range [4,6]:\n";
	multiset<int>::iterator it1 = s1.lower_bound(4);
	multiset<int>::iterator it2 = s1.upper_bound(6);	//upper_bound je vedno en vec kot tistega ki ga iscemo
	print(it1, it2); cout << endl << endl;
	
	cout << "Finding single value range using equal_bounds\n";
	//kle je pa drugace kot pri set, saj je mozno imeti vec enakih vrednosti
	//1 2 3 4 4 5 5 6 7 8 9 10
	//tu pride v postev pri scenarij iz listov:
		//torej prvi iterator kaze na element ki ni manjsi od x, drugi pa na prvi element, ki je vecji od x
	pair<multiset<int>::iterator, multiset<int>::iterator> p = s1.equal_range(4);	
	print(p.first, p.second); cout << endl;
	return 0;
}