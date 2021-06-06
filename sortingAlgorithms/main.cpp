/*
* Assignment 6 - Implementation of Sorting Algorithms
* I. Jana Batiya.
* In this assignment we are going to implement a couple of sorting algorithms and test their performances.
* We write a program to sort an array using Insertion sort and merge sort.
* For each algorithm, we have a counter to count how many times a comparison is made to sort the array.
* Once this logic is implemented, we create integer arrays of 1000 and 10000 elements with random values inside.
* Then we output the result which shows how many comparisons it made for each algorithm for 1000 and 10000 elements.
*/

#include <iostream>
#include<time.h>
using namespace std;

/** insertionSort Function
* Here we will implement the insertion sort algorithm.
* @param arr is the array of integers.
* @param n is the size of the array.
* @param comparisonsCount keeps track of the Comparisons.
*... No  returns for functions with no  return value.
*/
// Insertion sort sorting function it will take array and its size an argument
void insertionSort(int arr[], int n, int& comparisonsCount)
{
    int i, key, j;
    for (i = 1; i < n; i++) //starts with 1
    {
        key = arr[i]; // takes the value
        j = i - 1;
        comparisonsCount++;
        while (j >= 0 && arr[j] > key)
        {
            comparisonsCount++;
            arr[j + 1] = arr[j]; // moves element forward
            j = j - 1;
        }
        arr[j + 1] = key; //inserts element in the right place
    }
}

/** merge Function
* Here we will implement the first part of the merge sort algorithm.
* @param array is the array of integers.
* @param left is the left side of the array.
* @param mid is the middle of the array.
* @param right is the right side of the array.
* @param comparisonsCount keeps track of the Comparisons.
*... No  returns for functions with no  return value.
*/

void merge(int array[], int left, int mid, int right,int& comparisonsCount)
{
    int size_left = mid - left + 1;// Size of left sublist
    int size_right = right - mid; // Size of right sublist
    int Left[size_left], Right[size_right]; // create temp arrays

    // Copy data to temp arrays Left[] and Right[]
    for (int i = 0; i < size_left; i++)
        Left[i] = array[left + i];
    for (int j = 0; j < size_right; j++)
        Right[j] = array[mid + 1 + j];

    // Merge the temp arrays back into arr[left..right]
    int i = 0; // Initial index of left subarray
    int j = 0; // Initial index of right subarray
    int k = left; // Initial index of merged subarray

    while (i < size_left && j < size_right) {
        if (Left[i] <= Right[j]) {
            comparisonsCount++;
            array[k] = Left[i];
            i++;
        }
        else {
            array[k] = Right[j];
            j++;
        }
        k++;
    }
    // Copy the remaining elements of Left[]
    while (i < size_left) {

        array[k] = Left[i];
        i++;
        k++;
    }
    // Copy the rest elements of Right[]
    while (j < size_right) {
        array[k] = Right[j];
        j++;
        k++;
    }
}

/** mergeSort Function
* Here we will implement the second part of the merge sort algorithm.
* @param array is the array of integers.
* @param left is the left side of the array.
* @param mid is the middle of the array.
* @param right is the right side of the array.
* @param comparisonsCount keeps track of the Comparisons.
* @return recursively
*/
void mergeSort(int array[],int left,int right, int& comparisonsCount){
    if(left>=right){
        return;// returns recursively
    }
    int middle =left+ (right-left)/2;
    // Sort first and second halves
    mergeSort(array,left,middle,comparisonsCount);
    mergeSort(array,middle+1,right,comparisonsCount);

    // Finally merge them
    merge(array,left,middle,right,comparisonsCount);
}
/** Main Function
* Here we will test our insertion and merge sort functions that we have written above
*... No params or returns for functions with no parameters or return value.
*/
int main()
{

    srand(time(0));
    // maximum array sizes
    int array1[1000]; int copyArray1[1000];
    int array2[10000]; int copyArray2[10000];

    // for 1000 elements
    for(int i=0; i<1000; i++)
    {
        array1[i]=rand(); // randomizing numbers for array1
        copyArray1[i]=array1[i]; // copying elements to copyArray1
    }
    // initializing counts
    int count_insertion=0;
    int count_merge=0;


    insertionSort(array1,1000,count_insertion); // passing arguments to insertionSort function
    mergeSort(copyArray1,0,1000-1,count_merge); // passing arguments to mergeSort function

    // Displaying information
    cout<<"For a 1000 length array: \n\n";
    cout<<"Insertion sort comparisons: "<<count_insertion<<"\n";
    cout<<"Merge sort comparisons: "<<count_merge<<"\n";


    // for 10000 elements
    for(int i=0; i<10000; i++)
    {
        array2[i]=rand(); // randomizing numbers for array2
        copyArray2[i]=array2[i];// copying elements to copyArray2
    }

    // initializing counts
    count_insertion=0;
    count_merge=0;
    insertionSort(array2,10000,count_insertion); // passing arguments to insertionSort function
    mergeSort(copyArray2,0,10000-1,count_merge); // passing arguments to mergeSort function

    // Displaying information
    cout<<"\n--------------------\n"<<endl;
    cout<<"For a 10000 length array: \n\n";
    cout<<"Insertion sort comparisons: "<<count_insertion<<"\n";
    cout<<"Merge sort comparisons: "<<count_merge;
}