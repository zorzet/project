#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string.h>
#include <sstream>
#include <random>
#include <ctime>
#include "hasp.h"
#include "lsh.h"
using namespace std;
std::default_random_engine generator;

/* http://www.cplusplus.com/reference/random/uniform_real_distribution */
float randomRange(int min, int max)
{  
    std::uniform_real_distribution<double> distribution(min,max);
    return (float)distribution(generator); 
    
}
 

float eswteriko_ginomeno_dianusmatwn(float* a,float* b,int dims){
	float total=0;
	cout<<" dims "<<dims<<endl;
	for(int i=0;i<dims;i++){
		cout<< "gaussian"<<i<<" "<<a[i]<<" incoming"<<i<<" "<<b[i]<<endl;
		total=total+(a[i]*b[i]);
	}
	cout<<"apotelesma gaussianou ginomenou "<<total<<endl;
	return total;
}

void create_gaussian_vector(int dimensions,float a[]){
	float * gaussian_vector=new float[dimensions];
	for(int i=0;i <dimensions; i++)
	a[i]=gaussrand(0.0,0.1);
	
}

float calculate_hi(float gaussian_vector[],float incoming_vector[],int d, int w,float t){
	cout<<"calculate hi t "<<t<<endl;
	float hi=(((eswteriko_ginomeno_dianusmatwn(gaussian_vector,incoming_vector,d))+t)/w);
	cout<<" hi "<<hi<<endl;
	return hi;	
}




double random01()
{
	return std::rand() / double(RAND_MAX);
}


const double PI = 3.1415926535897;


float gaussrand(double mean, double stddev)
{
	return (float)std::sqrt(-2 * log(random01())) * std::cos(2 * PI * random01()) * stddev + mean;
}


float calculate_h_function(int w,float** hash_vector,float** incoming_vector){
	return 1.2;
}
/*

void readfile(char * filename){
  std::ifstream inFile;
  std::string line;
  inFile.open(filename);
  if (inFile.is_open())
    {
	
	  std::getline(inFile, line);
	  cout<<line<<endl;
	  
 
	  std::string euclidean;
      int length=line.size()-9;
	  std::string sub = line.substr(8,length);
	  if (sub.compare("euclidean") == 0)
	  {  cout<<"euclidean" <<endl;
	    while (std::getline(inFile, line))
	    {
	    	cout<<line<<endl;	
	    
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


int main(int argc, char* argv[]){
       char address[100];
       int i, command_port, port,err ;
  
    	for (i=0; i<= argc-1; i++) {
                if (strcmp(argv[i],"-d")==0) strcpy(address,argv[i+1]);
               	//if (strcmp(argv[i],"-p")==0) command_port= atoi (argv[i+1]);
           
        } 
       readfile(address);

	return 0; 


}*/
