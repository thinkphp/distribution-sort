/**
 *  @Author: 
 *  Adrian Statescu <mergesortv@gmail.com>
 *
 *  @title
 *  Distribution Sort - Non-comparison Sort - Counting Sort Algorithm
 *  
 *  @Description
 *  Counting sort assumes that each of elements is an integer in the range 0 to k, for some integer k
 *
 *  @Reference
 *  http://www.ccodechamp.com/c-program-for-counting-sort-algorithm/
 *  http://www.personal.kent.edu/~rmuhamma/Algorithms/MyAlgorithms/Sorting/countingSort.htm
 *  http://www.nttvu.com/sec/kcjx/visualDataStructure/visualization/CountingSort.html
 */

#include <stdio.h>
#include <string.h>
#define FIN  "algsort.in"
#define FOUT "algsort.out"
#define MAXN 500005
#define MAXB 1000000

typedef unsigned int uint;

 int arr[ MAXN ],

      C[ MAXN ],

      B[ MAXB ],
  
      n, 

      range;

void read() {

     int i;

     freopen(FIN, "r", stdin);

     scanf("%d", &n);

     range = 0;

     for(i = 1; i <= n; i++) { 

             scanf("%d", &arr[ i ]);

             if(arr[ i ] > range) range = arr[ i ];
     }

     fclose( stdin ); 
};

void write() {

     int i;  

     //freopen(FOUT, "w", stdout);

     for(i = 1; i <= n; i++) printf("%d ", C[ i ]);

     //fclose( stdout ); 

};

void sort() {

     int i,

         j,

         k, 

         f;

     //first loop
     memset(B, 0, sizeof( B ));

     //second loop
     for(j = 1; j <= n; j++) B[ arr[ j ] ]++;

     //third loop
     for(k = 1; k <= range; k++) B[ k ] = B[ k - 1 ] + B[ k ];

     //final loop
     for(f = n; f >= 1; f--) C[ B[ arr[ f ] ] ] = arr[ f ], B[ arr[ f ] ] = B[ arr[ f ] ] - 1;
};

int main() {

    read();
    sort();
    write();

    return(0);
}
