#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
#include <complex>
#include "vector.h"
#include "lsh.h"
#include "hasp.h"
#include <math.h>
using namespace std;
 
template <class T>
hasp_node<T>::hasp_node(int value) {
	this->value = value;
      this->next = NULL;
}
template <class T>
int hasp_node<T>::getNeigbord() { 
            return seek->data;
}
template <class T>
int hasp_node<T>::getValue(){
            return value;
}
template <class T>
void hasp_node<T>::setValue(int value) {
            this->value = value;
}
template <class T>
int * HashMap<T>::get_ri(){
	return this->ri;
}
template <class T> 
HashMap<T>::HashMap(int Table_size,int k,int d,int w) {
 set_t(w);
 this->table_key=Table_size;
 this->k_vectors=new float *[k];
 for( int i = 0 ; i < k ; i++ )
 this->k_vectors[i] = new float[d];
 this->ri=new int[k];
 for( int i = 0 ; i < k ; i++ ){
 this->ri[i]=rand();
 cout<< "r"<<i<<" "<<this->ri[i]<<endl;
}
 for(int i=0; i<k; i++){
	create_gaussian_vector(d,this->k_vectors[i]);	
 	cout<<" gaussian "<<i<<" ";
 	for(int g=0; g<d; g++)
 	cout<<this->k_vectors[i][g];
 	cout<<endl;
 }
 	
 table  = new hasp_node <T> *[Table_size];
 for (int i = 0; i < Table_size; i++)
 table[i] = NULL;
 this->set_t(w);
}
template <class T>
void HashMap<T>::set_t(int w){
	this->t=randomRange(0,w);
}
template <class T>
void HashMap<T>::put(int value) {
 int hash = (value% table_key);
 if (table[hash] == NULL)
      table[hash] = new hasp_node <T> (value);
 else {
      hasp_node <T> *entry = table[hash];
      while (entry->next != NULL)
      entry = entry->next;
      entry->next=new hasp_node <T> (value);
      }
}
template <class T>
float HashMap<T>::get_t(){
 return this->t;
}     
template <class T>
void HashMap<T>::print(int value) {
 hasp_node <T> *entry = table[value];
  while(entry->next != NULL){
	cout<< entry->value<<endl;
      entry = entry->next;
                   	 
}
}
template <class T>
HashMap<T>::~HashMap() {
 for(int i = 0; i < table_key; i++){
 	if(table[i] != NULL) {
            hasp_node <T> *prevEntry = NULL;
            hasp_node <T> *entry = table[i];
            while (entry != NULL) {
                  prevEntry = entry;
                  entry = entry->next;
                  delete prevEntry;
            }
      }
	delete[] table;
 }
}

template <class T> 
HashMap_All<T>::HashMap_All(int num_hasp, int n,int k,int d,int w) {
 num_of_hasp_table=num_hasp;
 hasp = new HashMap<T>* [num_hasp];
 for (int i = 0; i <num_of_hasp_table; i++)
 hasp[i] =  new HashMap<T>(n/2,k,d,w);
}
template <class T> 
int HashMap_All<T>::print(int value){      
 for (int i = 0; i <num_of_hasp_table; i++) {
	cout<< "   table key =" << hasp[i]->table_key <<endl;
      hasp[i]->print(value);
 }
}
template <class T> 
int HashMap_All<T>::put (int value){
 for (int i = 0; i < num_of_hasp_table; i++)
      hasp[i]->put(value);
       	
}
template <class T> 
long long HashMap_All<T>::calculate_fp(HashMap_All<T>* hasmap,float * a, int dimensions,int w, int k){
	float hi;
	cout<<"calculate fp dimensions "<<dimensions<<endl;
	long long total=0; //na allaxei to 4 na ginei oso to k
	for(int i=0; i<k; i++){    
		hi=calculate_hi(hasmap->hasp[0]->k_vectors[i] ,a,dimensions,w, hasmap->hasp[0]->get_t()); 
		total=((hi*hasmap->hasp[0]->ri[i])+total);
		cout<<"total "<<total<<endl;
	}
	long long M=pow(2,32)-5;
	return total;

}
/*
template <class T> 
void HashMap<T>::set_M(){
	this->M=pow(2,32)-5;
	cout<<"M "<<M<<endl;
}
      
template <class T>      
long long HashMap<T>::get_M(){
	return this->M;
}*/
 /*
      int get(int key) {
            int hash = (key % TABLE_SIZE);
            if (table[hash] == NULL)
                  return -1;
            else {
                  LinkedHashEntry *entry = table[hash];
                  while (entry != NULL && entry->getKey() != key)
                        entry = entry->getNext();
                  if (entry == NULL)
                        return -1;
                  else
                        return entry->getValue();
            }
      }
 
      void put(int key, int value) {
            int hash = (key % TABLE_SIZE);
            if (table[hash] == NULL)
                  table[hash] = new LinkedHashEntry(key, value);
            else {
                  LinkedHashEntry *entry = table[hash];
                  while (entry->getNext() != NULL)
                        entry = entry->getNext();
                  if (entry->getKey() == key) 
                        entry->setValue(value); 
                  else 
                        entry->setNext(new LinkedHashEntry(key, value));
            }
      }
 
      void remove(int key) {
            int hash = (key % TABLE_SIZE);
            if (table[hash] != NULL) {
                  LinkedHashEntry *prevEntry = NULL;
                  LinkedHashEntry *entry = table[hash];
                  while (entry->getNext() != NULL && entry->getKey() != key) {
                        prevEntry = entry;
                        entry = entry->getNext();
                  }
                  if (entry->getKey() == key) {
                        if (prevEntry == NULL) {
                             LinkedHashEntry *nextEntry = entry->getNext();
                             delete entry;
                             table[hash] = nextEntry;
                        } else {
                             LinkedHashEntry *next = entry->getNext();
                              delete entry;
                             prevEntry->setNext(next);
                        }
                  }
            }
      }
 
      ~HashMap() {
            for (int i = 0; i < TABLE_SIZE; i++)
                  if (table[i] != NULL) {
                        LinkedHashEntry *prevEntry = NULL;
                        LinkedHashEntry *entry = table[i];
                        while (entry != NULL) {
                             prevEntry = entry;
                             entry = entry->getNext();
                             delete prevEntry;
                        }
                  }
            delete[] table;
      }
	  */


