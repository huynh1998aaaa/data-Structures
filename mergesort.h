#include <iostream>
using namespace std;
void swap(int&a, int&b)
{
  int temp = a;
  a = b;
  b = temp;
}
void Merge(int a[], int left, int mid, int right)
{
  // tao 2 vi tri mang con left -> mid và mid + 1 -> right
  int left1 = left, right1 = mid, left2 = mid + 1, right2 = right;
  int index = left;
  int *b = new int[right - left + 1];
   
  while (left1 <= right1 && left2 <= right2)
  {
    if (a[left1] < a[left2]) //  so sanh  vi tri dau trong 2 mang con
    {
      b[index] = a[left1]; // tron
      index++; left1++; // xe dich vi tri va so sanh
    }
    else
    {
      
      b[index] = a[left2];
      index++; left2++;
    }
  }
  // 1 trong 2 mang het phan tu
  if (left2 > right2)
  {
    while (left1 <= right1)
    {
      b[index] = a[left1];
      index++; right1++;
    }
  }
  if (left1 > right1)
  {
    while (left2 <= right2)
    {
      b[index] = a[left2];
      index++;
      left2++;
    }
  }
 
  // gan mang tron vao mang goc
  for (index = left; index <= right; index++)
  {
    a[index] = b[index];
  }
}
 
void MergeSort(int a[], int left, int right)
{
  if (left < right)
  {
    int mid = (left + right) / 2;
    
    MergeSort(a, left, mid);
    MergeSort(a, mid + 1, right);
    Merge(a, left, mid, right);
  }
}