#ifndef HASP_H_
#define HASP_H_
#include "vector.h"

template <class T>
class hasp_node {
public:
      node<T> *seek;                          //node anaforas
      int value;                           // timi sinartisis
      hasp_node *next;                     // epomenos komvos
      hasp_node(int value);
      int getNeigbord();
      int getValue();
      void setValue(int value);
};

template <class T> 
class HashMap {
public:
      hasp_node<T> **table;
      int table_key;
//      long long M;			//modM sthn fp- ari8mos 2^32 -5
      float** k_vectors;	//disdiastatos pinakas pou krataei ta gauusiana dianusmata
	float t; 			//real number needed for hi
	int * ri;  			//pinakas pou kratei ta r gia thn f(p)
	
      HashMap(int Table_size,int k,int d,int w);
      void put(int value);
      void print(int value);
      void set_t(int w);
	float get_t(); 
      ~HashMap(); 
      int * get_ri();
//      void set_M();
//      long long get_M();
      
};
template <class T> 
class HashMap_All {
public:
     HashMap <T> **hasp;
     int num_of_hasp_table;
     
     HashMap_All(int num_hasp, int n,int k,int d,int w);
     int print(int value);
     int put (int value);
     long long calculate_fp(HashMap_All<T>*  hasmap_all, float * a, int dimensions,int w, int k);
};

 
#endif
