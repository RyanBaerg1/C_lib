/*******************
Author: Ryan Baerg
Date: 2022-01-29
******************/


static void swap(int* arr, int ind1, int ind2);
/***********************************************************************
Function for swapping 2 indicies in an array using the XOR opperator

Parameters : arr -> pointer to start of the array you want to swap values in
             ind1 -> index of the first value to swap in arr
             ind2 -> index of the second value to swap in arr
             
Return : Nothing
************************************************************************/
static void swap(int* arr, int ind1, int ind2)
{
  if(ind1 == ind2)
  {
    return;
  }
  arr[ind1] = arr[ind1] ^ arr[ind2];

  arr[ind2] = arr[ind1] ^ arr[ind2];

  arr[ind1] = arr[ind1] ^ arr[ind2];
}

/***********************************************************************
Function for performing quick sort algorithm. Algorithm is recursive.
Quick sort works by choosing a random value in the array and placing all
values smaller than it on the left and all values larger on the right 
and then repeating that process until the array is in order.

Parameters : arr -> pointer to start of the array you want to sort
             low -> index of the current lower bound section of the array
             you are looking to pivot for.
             high -> index of the current upper bound section of the array
             you are looking to pivot for.
             
Return : Nothing
************************************************************************/
void quickSort(int* arr, int low, int high)
{

  if(low<high)
  {
    int pivot = arr[high];
    int l = low;
    int r = high -1;

    while(l<r)
    {

      while(arr[l] <= pivot && l<r)
      {
        l = l +1;
      }
        if(arr[r] < pivot)
        {

          swap(arr,l,r);

          l=l+1;
        }
        r=r-1;
    }

    if(arr[l] > arr[high])
    {
      swap(arr, l, high);
    }
    
    quickSort(arr, low, l-1);
    quickSort(arr, l+1, high);
  }

}
