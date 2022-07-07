#include <iostream>
#include <vector>
#include <cmath>
#include <time.h>
#include <cassert>

/*

  Finish Implementation of the mergeBaseInPlace() function outlines below.

  Remember to submit your data results via a copy of the google spreadsheet link provided below

  https://docs.google.com/spreadsheets/d/1PM1zjXTSZZ0pATZyeq1BJ99toRM0nAVgxYInWHjS7ks


*/

using namespace std;

long baseCount = 0; // number of times we call the base merge function (set by mergeSort() each time we call mergeBaseInPlace()
long swapCount = 0; // number of times we swap two array items (set by the myswap() function )
long compareCount = 0; // number of times we compare two array items (set by the compare() function )

// This function must be used by your mergeBaseInPlace() function provided below to keep count of compares
// compare a and b and increment counter
int compare(int a, int b){ // a<b return -1, a==b return 0; a>b return 1
  compareCount++;
  if(a > b) return 1;
  if (a < b) return -1;
  return 0;  // they must be equal
}

// This function must be used by your mergeBaseInPlace() function provided below to keep count of swaps
// swap i and j and increment counter
void myswap(int a[], int i, int j){
  swapCount++;
  int temp = a[i]; 
  a[i] = a[j];
  a[j] = temp;
}


// This function below is called by the template mergeBaseInPlace() function provided below to help you debug
// print a sub-section of the array from start to end (or all of the array)
void printSubArr(int arr[], int start, int end){ 
  for(int k=start; k<=end; k++){
    cout << arr[k] << ", ";
  }
  cout << endl;
}

// This function below is called by the template mergeBaseInPlace() function provided below to help ensure
// that each call to mergeBaseInPlace() creates a sorted result between start and end.
// It verifies that array arr[] is truly descending between start and end
bool isSortedDescending(int arr[], int start, int end){
  for(int i=start; i<end; i++){
    if (arr[i] < arr[i+1])
      return false; // not descending 
  }
  return true;
}


//
// TODO - implement an in-place version of the base merge function, which will be called from mergeSort()
// You may NOT utilize any auxilliary array storage declared inside or outside of your function
// You MAY use temporary variables as needed.
// You MUST utilize the compare() and myswap() functions for credit.
//

// Implementation Notes for mergeBaseInPlace() below:
// 
// arr[] is an array of integers that are already ordered in left and right halves between start and end
//    the left half is sorted between "start" and "mid"
//    the right half is sorted between "mid+1" and "end"
//   ....  ONLY merge in the range from "start" to "end" (inclusive)
//   remember that start and end are not the first and last positions of the array - they may be a "middle" span
//      so:  arr[] to the left of start may extend for quite a few array locations (start is not zero)
//      and: arr[] to the right of end may extend for quite a few array locations (end is not the last position of the array)

// arr[] looks like this:
//  _ _ ______________________________________________________
//      |   |   |   |   |   |   |   |   |   |   |   |   |   |
//  - - ------------------------------------------------------
//        ^           ^   ^               ^
//       start       mid  mid+1          end
//
//  assume arr[] is already sorted descending between start and mid
//  assume arr[] is already sorted descending between mid+1 and end
//
// You must "merge" these left and right halves so the entire range start->end is sorted

void mergeBaseInPlace(int arr[], int start, int mid, int end){

int start2 = mid + 1; 
if (compare(arr[mid], arr[start2]) == -1) { 
while (start <= mid && start2 <= end) { 
        if (compare(arr[start], arr[start2]) == -1) { 
           int val = arr[start2]; 
            int index = start2; 
            while (index != start) { 
                arr[index] = arr[index - 1];
                swapCount++;
                index--; 
            } 
            arr[start] = val; 
            start++; 
            mid++; 
            start2++; 
        } 
        else { 
            start++;  
        } 
    } 
}
  // uncomment below if/when you need help debugging your function
  //cout << "\n*mergeBaseInPlace() = " << start << " to " << end << ": ";
  //printSubArr(arr, start, end);

  // uncomment below if/when you need help debugging your function
  //cout << "\n*mergeBaseInPlace() done:";
  //printSubArr(arr, start, end);

//
// TODO: Your code goes here
//

  // verify that the merge worked... you can comment this out if you want...
  // but if it is failing, it indicates your final solution will be incorrect.


  if (!isSortedDescending(arr, start, end))
    cout << "mergeBaseInPlace() Warning: merged base is not descending for range " << start << " to " << end << endl;
}


//
// Merge Sort - main function
//

void mergeSort(int arr[], int start, int end){

  // cout  << "merge_sort() from " << start << " to " << end << ": ";
  // printSubArr(arr, start, end);

  if( start < end ) { // if the size of the section we are sorting is larger than one, else return
           
    int mid = (start + end ) / 2 ;     // defines the current array in left and right parts
    mergeSort(arr, start , mid ) ;  // sort the left part of array .
    mergeSort(arr, mid+1 , end ) ;  // sort the right part of array.

    // merge both parts by comparing elements of both the parts.
    // start identifies the starting position in our left sublist that we want to merge
    // mid is the ending position of the left sublist 
    // end is the ending position of the right sublist

    mergeBaseInPlace(arr, start, mid, end ); // NOTE: this calls your in-place merge function
    
    baseCount++; // how many times did we call the base merge function?
    // note that left is start->mid, while right is mid+1->end
  }    
}

int main() {
  std::cout << "HW2 Merge Sort - merge base (in-place)\n";

  srand(time(NULL)); // new seed each time

  int sampleCount = 1000; // how many times we will run our "average" test
  // note above: a value of 1 is ok for "best case" and "worse case" tests
  // set this sample to >= 1000 when you want to test "average" case

  int N = 8; // size of array
  int a[N]; // allocate array of size N

  for(int s=0; s<sampleCount; s++){ // one loop iteration per sample

    // build a random list
    for(int i= 0; i<N; i++){
      a[i] = rand()%N+1;
    }

    // build a descending list
    // for(int i=N-1; i>=0; i--){
    //   a[i] = i;
    // }

    // build an ascending list
    // for(int i=0; i<N; i++){
    //     a[i] = i;
    // }

    cout << "\nOur original list of numbers (unsorted):" << endl;
    printSubArr(a, 0, N-1);// print from zero to N-1 of array a

    mergeSort(a, 0, N-1); // mergeSort from zero to N-1 of array a

    cout << "\nOur Merge Sorted numbers:" << endl;
    printSubArr(a, 0, N-1); // print from zero to N-1 of array a

    if (!isSortedDescending(a, 0, N-1)){
      cout << "\nmain(): Warning: MergeSort() did not produce a descending sort." << endl;
    }
  

  } // end samples loop

    cout << "\nResults:" << endl;
    cout << "Number of elements (N) = " << N << endl;
    cout << "Number of samples = " << sampleCount << endl;
    cout << "Log(N) = " << log2(N) << endl;
    cout << "NLog(N) = " << N*log2(N) << endl;
    cout << "N^2 = " << N*N << endl;
    cout << "(N-1)^2 = " << (N-1)*(N-1) << endl;
    cout << "N(N-1)/2 = " << (N)*(N-1)/2 << endl;
    cout << "Ave Number of compares = " << compareCount/sampleCount << endl;
    cout << "Ave Number of swaps = " << swapCount/sampleCount << endl;
    cout << "Number of calls to base merge = " << baseCount/sampleCount << endl;
}