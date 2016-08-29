#include <iostream>
#include <vector>
#include <string>
using namespace std;


void merge_sort(vector<char> & a, int fromIndex, int toIndex) ;

void merge(vector<char> & a, int fromIndex, int mid, int toIndex);

int main(void)
{

	vector<char> a("COMPUTERSCIENCEINFORMATICS");
	sort(a.begin(),a.end())
	merge_sort(a, fromIndex=0;toIndex=a.size()-1)
}



void merge_sort(vector<char> & a, int fromIndex, int toIndex) 
{
   if (fromIndex < toIndex) // don't sort single elements
   {
      int mid = (fromIndex + toIndex) / 2;
 
      // break vector into two halves and sort each half
      merge_sort(a, fromIndex, mid);
      merge_sort(a, mid + 1, toIndex);

      // merge sorted halves together
      merge(a, fromIndex, mid, toIndex);
   }
}
This routine is used to perform the actual merging of the two halves of the vector - a[fromIndex..mid] and a[mid+1..toIndex]:

void merge(vector<char> & a, int fromIndex, int mid, int toIndex)
{  
   int n = toIndex - fromIndex + 1; // size of the range to be merged
   
	// merge both halves into a temporary vector b
   vector<int> b(n);

   int i1 = fromIndex;  // next element to consider in the first half
   int i2 = mid + 1;    // next element to consider in the second half
   int j = 0;           // next open position in b

   // as long as neither i1 nor i2 is past the end, 
   // move the smaller element into b 

   while (i1 <= mid and i2 <= toIndex)
   {
      if (a[i1] < a[i2])
      {
         b[j] = a[i1];
         i1++;
      }
      else
      {
         b[j] = a[i2];
         i2++;
      }
      j++;
   }

   // note that only one of the two while loops below is executed

   // copy any remaining entries of the first half
   while (i1 <= mid)
   {
      b[j] = a[i1];
      i1++;
      j++;
   }
   // copy any remaining entries of the second half
   while (i2 <= toIndex)
   {
      b[j] = a[i2];
      i2++;
      j++;
   }

   // copy back from the temporary vector
   for (j = 0; j < n; j++)
      a[fromIndex + j] = b[j];
}
