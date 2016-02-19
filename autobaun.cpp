#include <iostream>

using namespace std;

#define X 3
#define Y 3
#define Z 3
#define NUM_THREAD 1

int A[X][Y]; 
int B[Y][Z];
int C[X][Z];

void *pthread_multiply(void *arg){
//Create void pointers to hold address of the subset max arg
//To dereference a void pointer, first cast the vp to the pointer type of the desired value and then dereference that with the dereference star
int y = *(int*)arg;
//int col = *(int*)arg;
int row;
int col;
int inner;

//Now using this value we want to take C and compute the values up to
// the row columns of matrixes A and B

for(int i = 0; i <3; i++)
{
for(int x = 0; x < 3; x++)
{
std::cout << " Row : " << i << " Column: " << x <<" For Matrix A " << std::endl;
std::cout << A[i][x] << std::endl;
//std::cout << std::endl << B[i][x];
}
}
for (row = 0; row < X; row++) {
for (col = 0; col < Z; col++) {
for (inner = 0; inner < Y; inner++) 
	{
  C[row][col] += A[row][inner] * B[inner][col];
  	}
   				}
     				}
	std::cout << std::endl << C[0][0];
}

struct matador
{
int subset_o;

};

int main()
{
int basicA[] = {1,2,3};
for(int i = 0; i < 3; i++)
{
	for(int x = 0; x < 3; x++)
{
A[i][x] = basicA[x];
B[i][x] = basicA[x];
C[i][x] = 0;
}
}
matador vals[NUM_THREAD];
pthread_t id[NUM_THREAD];

std::cout << "2 Matracies of 10x10 have been created" << std::endl;

for(int i = 0; i < NUM_THREAD; i++)
{
std::cout << "What is the subset for the thread ? ";
std::cin >> vals[i].subset_o;
pthread_create(&id[i],NULL, (void*(*)(void *)) pthread_multiply, &vals[i] );
}


pthread_exit(0);

}
