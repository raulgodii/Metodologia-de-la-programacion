int minimo(int num1,int num2){
    if(num1<num2){
        return num1;
    } else {
        return num2;
    }
}

void minimo_referencia(int num1, int num2, int *resultado){
    if(num1<num2){
        *resultado=num1;
    } else {
        *resultado=num2;
    }
}