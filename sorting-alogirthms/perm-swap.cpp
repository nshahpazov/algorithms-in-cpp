#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int binSearch(int A[], int key, int imin, int imax)
{
  // test if array is empty
  if (imax < imin){
    // set is empty, so return value showing not found
    return -1;
  }else
    {
      // calculate midpoint to cut set in half
      int imid = (imin + imax) / 2;

      // three-way comparison
      if (A[imid] > key){
        // key is in lower subset
        return binSearch(A, key, imin, imid-1);
      }else if (A[imid] < key){
        // key is in upper subset
        return binSearch(A, key, imid+1, imax);
      }else{
        // key has been found
        return imid;
      }
    }
}

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int getInversions(int a[],int b[], int length){
    int result = 0;
    for(int i = 0; i < length; i++){
        if(a[i] == 0 || binSearch(b, a[i], 0, length) == 0){

        }else{
            result += binSearch(b, a[i], 0, length);
            a[i] = 0;
            b[binSearch(b, a[i], 0, length)] = 0;
        }


       // printf("%d\n", result);
    }
    return result;
}

int main()
{

    int n;
    scanf("%d", &n);
    int array[n];
    int coppy[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &array[i]);
        coppy[i] = array[i];
    }
    qsort(coppy, n, sizeof(int), compare);
    int result = getInversions(array, coppy, n);
    printf("%d", result);
    return 0;
}
