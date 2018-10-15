#include <iostream>
using namespace std;
void swap(int&a, int&b)
{
  int temp = a;
  a = b;
  b = temp;
}


void QuickSort(int a[], int left, int right)
{
  int i = left, j = right;
  int pivot = a[(left + right) / 2]; // lay truc
  do
  {
    // tim vi tri can hoan vi
    while (a[i] < pivot && i < right) i++;
    while (a[j] > pivot && j > left) j--;
    if (i <= j)
    {
      swap(a[i], a[j]);
      i++; j--;
    }
  } while (i <= j);
  
  //de quy de tiep tuc
  if (left < j) QuickSort(a, left, j);
  if (i < right) QuickSort(a, i, right);
}