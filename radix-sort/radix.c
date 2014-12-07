#include <stdio.h>
#define FIN "radixsort.in"
#define FOUT "radixsort.out"
#define MAXN 10000005
#define MASK 65535

int N,

    A,

    B,

    C,

    V[ MAXN ],

    temp1[ MAXN ],

    temp2[ MAXN ];

void read() {

     int i;

     freopen(FIN, "r", stdin);

     scanf("%d %d %d %d", &N, &A, &B, &C);

     V[ 1 ] = B;

     for(i = 2; i <= N; i++) {

         V[ i ] = ( 1LL * A * V[ i - 1 ] + B) % C;  
     }

     fclose( stdin ); 
};

void RadixSort() {

     int aux[ MASK + 1 ],

         shift, 

         i;

     for(shift = 0; shift <= 16; shift +=16) {

         for( i = 0; i <= MASK; i++) aux[ i ] = 0;

         for( i = 1; i <= N; ++i) temp1[ i ] = (V[ i ] >> shift) & MASK, aux[ temp1[i] ]++; 

         for( i = 1; i <= MASK; i++) aux[ i ] += aux[ i - 1 ];

         for( i = N; i; i--) temp2[ aux[ temp1[i] ]-- ] = V[ i ];

         for( i = 1; i <= N; i++) V[ i ] = temp2[ i ];
     } 
};

void write() {

     int i;

     freopen(FOUT, "w", stdout);

     for(i = 1; i <= N; i += 10) printf("%d ", V[ i ]); 

     fclose( stdout );
};

int main() {

    read();

    RadixSort();

    write();

    return(0);
};