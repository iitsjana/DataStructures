/*
* Final - Using STL stacks to implement an application that sorts a stack.
* I. Jana Batiya.
* We start filling 20 elements into the stack.
* Then, using an array, we sort the elements within the stack using merge sort.
* Lastly, we place the sorted items into the stack again (so the stack becomes sorted) and we print the stack's content.
*/
#include <iostream>
#include <stack>
using namespace std;


/** merge Function
* Here we will implement the first part of the merge sort algorithm.
* @param array is the array of integers.
* @param left is the left side of the array.
* @param mid is the middle of the array.
* @param right is the right side of the array.
*... No  returns for functions with no  return value.
*/

void merge(int array[], int left, int mid, int right)
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
* @return recursively
*/
void mergeSort(int array[],int left,int right){
    if(left>=right){
        return;// returns recursively
    }
    int middle =left+ (right-left)/2;
    // Sort first and second halves
    mergeSort(array,left,middle);
    mergeSort(array,middle+1,right);

    // Finally merge them
    merge(array,left,middle,right);
}



/** Main Function
* Here we will test our mergeSort function that we have written above.
* And print the content of the sorted stack.
*... No params or returns for functions with no parameters or return value.
*/
int main() {

    stack<int> data; // we create our stack of type int
    int arr[20]; // we create our array of size 20

    // we push 20 elements onto the stack
    data.push(5);
    data.push(95);
    data.push(0);
    data.push(12);
    data.push(45);
    data.push(87);
    data.push(9);
    data.push(3);
    data.push(7);
    data.push(16);
    data.push(888);
    data.push(75);
    data.push(2);
    data.push(22);
    data.push(11);
    data.push(18);
    data.push(177);
    data.push(20);
    data.push(1);
    data.push(37);


    int k=0; // initializing k to zero

    // do this until the stack is empty
    while (!data.empty())
    {
        int elements = data.top();
        data.pop(); // pops elements from the stack

        arr[k++] = elements; // adds popped elements into the array
    }

    int size = sizeof(arr) / sizeof(arr[0]); // size of the array



    mergeSort(arr, 0, size - 1); // calls mergeSort function

    // does this until the array is empty
    for (int i=0; i<size; i++)
    {
        data.push(arr[i]); // adds sorted array elements to the stack
    }
    cout<<"\nStack elements after sorting: \n\n";

    // does this until stack is empty
    while (!data.empty())
    {
        int elements = data.top();
        data.pop();

        cout<<elements<<" "; // displays the content of the sorted stack
    }


}



