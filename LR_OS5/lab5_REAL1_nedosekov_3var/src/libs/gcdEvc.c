


int GCF (int A, int B) {
    while (B) {
        A %= B;
        int temp = A;
        A = B;
        B = temp;
        
    }
    return A;
}