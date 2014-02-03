#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <ctime> // time function
#include <cstdlib> // rand and srand function

// function prototypes
void quickSort(int [], int, int);
int partition(int [], int, int);
void randomizedQuickSort(int [], int, int); // improved version of quicksort
int randomizedPartition(int [], int, int);
void swap(int &, int &);

int main()
{
	// variable declarations
	const int SIZE = 10;
	int a[SIZE];

	// initialize the array and display it
	srand(time(NULL));
	for(int i = 0; i < SIZE; i++) {
		a[i] = (rand() % 100) + 1;
		cout << a[i] << ' ';
	}
	cout << '\n' << endl;

	// call to quicksort
	//quickSort(a,0,SIZE-1);
	randomizedQuickSort(a,0,SIZE-1);

	// display the array after calling quicksort
	for(int i = 0; i < SIZE; i++)
		cout << a[i] << ' ';
	cout << endl;

	return 0;
}

// quicksort function
void quickSort(int a[], int p, int r)
{
	if(p < r) {
		int q = partition(a, p, r); // partition the array
		quickSort(a, p, q-1); // quicksort on the partition less than or equal to the pivot
		quickSort(a, q+1, r); // quicksort on the partition greater than the pivot
	}
}

// partition function
int partition(int a[], int p, int r)
{
	int x = a[r]; // set the pivot to the last element
	int i = p-1; // initialize the index for elements less than the pivot

	for(int j = p; j < r; j++) {
		if(a[j] <= x) {
			i = i + 1; // increment i
			swap(a[i], a[j]); // swap the lesser value with the greater value;
		}					  // j is the index for elements greater than the pivot
	}
	swap(a[i+1], a[r]); // place the pivot in its correct position
	return i + 1; // return the index of the pivot
}

// this version of quick sort uses the randomized partition function
void randomizedQuickSort(int a[], int p, int r)
{
	if(p < r) {
		int q = randomizedPartition(a, p, r); // partition the array using a random pivot
		randomizedQuickSort(a, p, q-1); // quicksort on the partition less than or equal to the pivot
		randomizedQuickSort(a, q+1, r); // quicksort on the partition greater than the pivot
	}
}

// randomized the selection of the pivot to achieve better splits
int randomizedPartition(int a[], int p, int r)
{
	int i = (rand() % (r-p+1)) + p;  // randomly selects an index from p to r; r-p+1 is the range and p is the offset value
	swap(a[r],a[i]); // swap the last element with the pivot
	return partition(a,p,r); // call partition to split the array
}

// swap function
void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}