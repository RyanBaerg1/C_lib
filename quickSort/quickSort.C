static void swap(int* arr, int ind1, int ind2);

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