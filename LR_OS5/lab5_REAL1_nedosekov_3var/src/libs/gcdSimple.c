
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

int GCF (int A, int B) {
    for( int i = min ( A, B ); i > 1; i-- ){
        if ( A % i == 0 && B % i == 0 ){
            return i;
        }
    }
    return 1;
}