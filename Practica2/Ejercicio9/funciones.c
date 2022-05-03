int division(int a, int b){
    int r=0;
    if(a<b){
        return r;
    } else {
        r = 1 + division(a-b, b);
    }
}