#ifndef LSH_H_
#define LSH_H_
#include "vector.h"
#include "hasp.h"
float randomRange(int min, int max);
void create_gaussian_vector(int dimensions,float a[]);
float gaussrand(double mean, double stddev);
float eswteriko_ginomeno_dianusmatwn(float a[],float b[],int dims);
//float calculate_h_function(int w,float **hash_vector, float** incoming_vector);
float calculate_hi(float gaussian_vector[],float incoming_vector[],int d, int w,float t);


/*
int file(char *fileName, int * columns)  // epistrefei tomikos arxeiou

{   size_t pos;
	std::ifstream inFile;
  	int numLines=0;
  	std::string line;
  	inFile.open(fileName);
  	int weight=1;
  	if (inFile.is_open())
    {
	       std::getline(inFile, line); 
	  		while (std::getline(inFile, line))
		    {    
				numLines++;
			
				if (numLines==2){
					pos = line.find("	", 0);
		         	while(pos != string::npos)
					{
 					   //positions.push_back(pos);
 						pos = line.find("	",pos+1);
 						if (pos<100)  weight++;
 						
 					}	
					
				}
      		}
			 			  
	  }
	  
    else
    {
	  std::cout << "\n File " << fileName << " did not open" << std::endl;
	}
	*columns=weight;
    return numLines;
}
*/
#endif
