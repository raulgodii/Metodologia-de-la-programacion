int suma_digitos(int* num, int n, int i, int sum){
    if(i==n){
        return sum;
    } else {
        sum = num[i]+suma_digitos(num, n, i+1, sum);
    }
}