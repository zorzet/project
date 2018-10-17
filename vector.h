#ifndef VECTOR_H_
#define VECTOR_H_
#include <string.h>
#include <cstring>

using namespace std;

template<class T>
struct node {
	node<T>* next;
	T data;
	float *rows;
	
};

template <class T>
class Stack { 
  public: 
  
    	node<T>* first; 
    	node<T>* last;
    	int n;
    	int num_of_dim;
   		Stack();
   		~Stack();
   		void push (T nodes);
   		void print();
		void queryfile(std::string filename);
		void readfile(std::string filename);
 
}; 
template <class T>
void import_data_in_nodes(T string, node<T>* temp,int dims);


#endif
