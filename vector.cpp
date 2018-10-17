#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <stdio.h>
#include <fstream>
#include <string.h>
#include <sstream>
#include <string>
#include "hasp.h"

using namespace std;

template <class T>
int count_tab(T s)
{

    int count = 0;
    size_t nPos = s.find("	", 0); // first occurrence
    while(nPos != string::npos)
    {
        count++;
        nPos = s.find("	", nPos + 1);
    }

    return count;
};

template <class T>
Stack <T>::Stack(){
	first=NULL;
	last=NULL;
	num_of_dim=0;
	n=0;
}


template <class T>
Stack <T>::~Stack(){
   node <T> *temp, *next_delete;
   if (this->last==NULL){
   	cout << " list is empty "<<endl;
   }else{
   	temp=this->first->next;
   	next_delete=this->first;
   	delete next_delete;
   	while(temp!=NULL){
   		next_delete=temp;
   		temp=temp->next;
   		delete next_delete;
	   }
   }

//	delete this;

}


template <class T>
void Stack <T>::print(){
	node <T> *temp;
   if (this->last==NULL){
   	cout << " list is empty "<<endl;
   }else{
   	temp=this->first;
   	while(temp!=NULL){
   		cout<<temp->data<<endl;
   		for(int i=0; i<this->num_of_dim; i++)
   		cout<<temp->rows[i]<<" ";
   		cout<<endl;
   		temp=temp->next;
	   }
   }

}

template <class T>
void Stack<T>::push (T nodes_data) {
    node <T> *temp = new node<T>;
    this->n++;
    temp->next=NULL;
    if (this->last==NULL)  {
        this->num_of_dim=count_tab(nodes_data);
        this->first = temp;
		this->last= temp;
		import_data_in_nodes(nodes_data,temp,this->num_of_dim);
	}else{
		this->last->next=temp;
		this->last=temp;
		import_data_in_nodes(nodes_data,temp,this->num_of_dim);
	}
}

template <class T>
void  import_data_in_nodes(T string,node <T> * temp,int dims){
	size_t nPos = string.find("	", 0);
	temp->data=string.substr(0,nPos);
	int counter=0;
	size_t start=0;
	temp->rows =new float[dims];
	nPos = string.find("	", 0);
	start=nPos;
	cout<< temp->data<<endl;
	while(nPos != string::npos)
   	{
        nPos= string.find("	", nPos + 1);
        temp->rows[counter]=stof(string.substr(start,nPos-start));
        cout<<"counter "<<counter<<" temp->rows[counter] "<< temp->rows[counter]<<endl;
        counter++;
        start=nPos;

    }
}


template <class T>
void Stack<T>::readfile(std::string filename){
  std::ifstream inFile;
  std::string line;
  inFile.open(filename);
  if (inFile.is_open())
    {           
	  std::getline(inFile, line);
      int length=line.size()-9;
	  std::string sub = line.substr(8,length+1);
	  if (sub.compare("euclidean") == 0)
	  {  cout<<"euclidean" <<endl;
	  		while (std::getline(inFile, line))
		    {    length=line.size();
				  this->push(line);
      		}
	  }
	  else if(sub.compare("cosine") == 0)
	  {cout<<"cosine"<<endl;}
	  else
	  {cout<<"ERROR IN THE INPUT FILE..EXITING"<<endl; return;}
	}
    else
    {
	  std::cout << "\n File " << filename << " did not open" << std::endl;
	}

}



template <class T>
void Stack<T>::queryfile(std::string filename){
  std::ifstream inFile;
  std::string line;
  inFile.open(filename);
  int counter=0;
  float *my_vector;
  my_vector=new float[this->num_of_dim];
  if (inFile.is_open())
    {   size_t start=0;
	  	std::getline(inFile, line);
	  	size_t nPos = line.find("	", 0); // first occurrence
	  	cout<< line.substr(0,nPos)<<endl;
	  	size_t nPos2 = line.find("	", nPos+1); // first occurrence
	  	cout<< line.substr(nPos+1,nPos2)<<endl;
	  	while (std::getline(inFile, line))

		    {   counter=0;
				nPos = line.find("	", 0);
				start=nPos;
				cout<< line.substr(0,nPos)<<endl;
				 while(nPos != string::npos)
   				 {
        			nPos= line.find("	", nPos + 1);
        			my_vector[counter]=stof(line.substr(start,nPos-start));
        			counter++;
        			start=nPos;
    			}

		}
	}else{
	  std::cout << "\n File " << filename << " did not open" << std::endl;
	}

}
