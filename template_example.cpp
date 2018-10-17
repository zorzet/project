#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <stdio.h>
#include <fstream>
#include <string.h>
#include <sstream>
#include <math.h>
#include "vector.h"
#include "lsh.h"
#include "vector.cpp"
#include "lsh.cpp"
#include "hasp.cpp"
#include <cstdlib>

using namespace std;



int main() { 
   try {
     //int k,L;
    //char* input_file, query_file[100],output_file[100];
    //	for (i=0; i<= argc-1; i++) {
     //           if (strcmp(argv[i],"-d")==0) strcpy(input_file,argv[i+1]);
               	//if (strcmp(argv[i],"-q")==0) strcpy(query_file,argv[i+1]);
               	//if (strcmp(argv[i],"-k")==0) strcpy(query_file,argv[i+1]);
               	//if (strcmp(argv[i],"-L")==0) strcpy(query_file,argv[i+1]);
               	//if (strcmp(argv[i],"-o")==0) strcpy(output_file,argv[i+1]);
           
     //   }
      int k=4;
      int w=4;
      int r;
	node<string> simple_node;
	Stack<string> stringStack;      	
    	stringStack.readfile("input.txt");
      cout<< " dimension = " << stringStack.num_of_dim<<endl;
    	stringStack.print();
    	cout << "  Query"  << endl;
    	stringStack.queryfile("query.txt");
	cout<< "sum of record "<<stringStack.n<<endl;
      HashMap_All<string> my_all_hasp(4,stringStack.n,k,stringStack.num_of_dim,w);
	float a[2]={0.22,0.33};
	//to a einai to ekastote eisagomeno-elegxomeno dianusma
	cout<<" t "<<my_all_hasp.hasp[0]->get_t()<<endl;
	cout<< "stringStack.num_of_dim "<<stringStack.num_of_dim<<endl;
	int total=my_all_hasp.calculate_fp(&my_all_hasp,a, stringStack.num_of_dim, w, k);

		
   }catch (exception const& ex) { 
    cerr << "Exception: " << ex.what() <<endl; 
    return -1;
   } 
} 

