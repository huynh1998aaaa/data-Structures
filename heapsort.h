#include <iostream>
using namespace std;
void swap(int&a, int&b)
{
  int temp = a;
  a = b;
  b = temp;
}
void MaxHeapify(int a[], int n, int i)
{
  int left = 2*(i + 1) - 1;
  int right = 2*(i + 1);
  int max;
  if (left < n && a[left] > a[i]) max = left;
  else max = i;
  if (right < n && a[right] > a[max]) max = right;
   
  if (i != max)
  {
    swap(a[i], a[max]);
    MaxHeapify(a, n, max);
  }
}
void BuildHeap(int a[],int n){
  for (int i = n / 2 - 1; i >= 0; i--)
  {
    MaxHeapify(a, n, i);
  }
}
void HeapSort(int a[], int n)
{
  BuildHeap(a, n);
  for (int i = n - 1; i > 0; i--)
  {
    swap(a[0], a[i]);
    MaxHeapify(a, i, 0);
  }
}