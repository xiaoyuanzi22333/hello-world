#include <iostream>
#include <cstring>
#include "set.h"
using namespace std;


// maybe it is not a quite nice day today.


// TODO #1: Implement the constructor for an empty set
// Initialize an empty set with array_size equal to 1 
set::set(){
	sptr = new element[1];// Allocate memory for one element
    array_size = 1;
    num_elements = 0;
	// ADD YOUR CODE HERE
}

// TODO #7: Implement the constructor for an array of elements
set::set(const element array_ele[], int n){
    sptr = new element[1];
	array_size=1;
	num_elements=0;
	for(int k=0;k<n;k++){
		add(array_ele[k]);
	}
	// ADD YOUR CODE HERE
}

// TODO #2: Implement the destructor
// Release the memory of the set pointer
set::~set(){
    delete [] sptr;
	// ADD YOUR CODE HERE
}

// TODO #3: Return true if some element is in the set and false otherwise
bool set::in(const element &e) const{
	//DELETE THIS LINE
	for(int i = 0 ; i < num_elements ; i++){
		if(e.get_element() == sptr[i].get_element()){
			return true;
		}
	}

	return false;
	// ADD YOUR CODE HERE
}

// TODO #4: Add a new element and return true if it is successfully added
// Note that we double the array_size once it is full
bool set::add(const element &e) {
	//DELETE THIS LINE
    if(in(e) == true){
		return false;
	}
	if(num_elements+1 == array_size){
		array_size *= 2;
		element* newroot = new element[array_size];
		for(int i=0 ; i<num_elements ; i++){
			newroot[i] = sptr[i];
		}
		delete [] sptr;
		sptr = new element[array_size];
		sptr = newroot;
		
	}
	num_elements = num_elements + 1;
	sptr[num_elements - 1] = e;
	return true;
	// ADD YOUR CODE HERE
}

// TODO #5: Remove an element and return true if there is such an element
// Note that we halve the array_size when num_elements is smaller than a quarter of array_size
bool set::remove(const element &e) {
	//DELETE THIS LINE
	if(in(e) == false){
		return false;
	}
	num_elements--;
	if(num_elements*4 <= array_size){
		array_size = array_size/2;
	}
    element* newroot = new element[array_size];
	int k=0;
	for(int i=0 ; i<num_elements+1 ; i++){
		if(sptr[i].get_element() == e.get_element()){
			continue;
		}
		newroot[k] = sptr[i];
		k++;
	}
	delete [] sptr;
	sptr = newroot;
	return true;

	// ADD YOUR CODE HERE
}

// TODO #6: Include all elements from the new set
void set::s_union(const set& s) {

	// ADD YOUR CODE HERE
	for(int i=0 ; i< s.num_elements ; i++){
		add(s.sptr[i]);
	}
}

int set::size() const{
	return num_elements;
}

void set::print() const{
	// Print the information of the set
	cout << "The current number of elements is " << num_elements << ".\n";
	cout << "The array size is " << array_size << ".\n"; 
	cout << "The set is {";
	for (int i = 0; i < num_elements; i++){
		cout << sptr[i].get_element();
		if(i != num_elements-1)
			cout << ", ";
	}
	cout << "}.\n";
}

int main(){
	element a = element('a');
	element b = element('b');
	element c = element('c');
	element d = element('d');

	cout << "------1. Test construct function------" << endl;

	cout << "construct {}:" << endl;
	set cs = set();
	cs.print();
	cout << endl;

	cout << "construct {a, d}:" << endl;
	element array_ele[4] = {a, d, a, a};
	set cs2 = set(array_ele, 4);
	cs2.print();
	cout << endl;

	cout << "------2. Test add function------" << endl;
	
	cout << "add a:" << endl;
	if(cs.add(a))
		cout << "Successfully add the new element " << a.get_element() << ".\n";
	else 
		cout << "Fail to add the element " << a.get_element() << ".\n";
	cs.print();
	cout << endl;

	cout << "add b:" << endl;
	if(cs.add(b))
		cout << "Successfully add the new element " << b.get_element() << ".\n";
	else 
		cout << "Fail to add the element " << b.get_element() << ".\n";
	cs.print();
	cout << endl;

	cout << "add c:" << endl;
	if(cs.add(c))
		cout << "Successfully add the new element " << c.get_element() << ".\n";
	else 
		cout << "Fail to add the element " << c.get_element() << ".\n";
	cs.print();
	cout << endl;

	cout << "add a:" << endl;
	if(cs.add(a))
		cout << "Successfully add the new element " << a.get_element() << ".\n";
	else 
		cout << "Fail to add the element " << a.get_element() << ".\n";
	cs.print();
	cout << endl;
	
	cout << "------3. Test union function------" << endl;

	cout << "union {}:" << endl;
	cs.s_union(set());
	cs.print();
	cout << endl;

	cout << "union {a,d}:" << endl;
	cs.s_union(cs2);
	cs.print();
	cout << endl;
	
	cout << "------4. Test remove function------" << endl;

	cout << "remove d:" << endl;
	if(cs.remove(d))
		cout << "Successfully remove the element " << d.get_element() << ".\n";
	else 
		cout << "Fail to remove the element " << d.get_element() << ".\n";
	cs.print();
	cout << endl;

	cout << "remove c:" << endl;
	if(cs.remove(c))
		cout << "Successfully remove the element " << c.get_element() << ".\n";
	else 
		cout << "Fail to remove the element " << c.get_element() << ".\n";
	cs.print();
	cout << endl;

	cout << "remove c:" << endl;
	if(cs.remove(c))
		cout << "Successfully remove the element " << c.get_element() << ".\n";
	else 
		cout << "Fail to remove the element " << c.get_element() << ".\n";
	cs.print();
	cout << endl;
	
	return 0;
}
