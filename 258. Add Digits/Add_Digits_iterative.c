int addDigits(int num){
    if(num < 10) return num;
    int temp;
    while(1){
        temp = 0;
        while(num > 0){
            temp += num % 10;
            num /=10;
        }
        num = temp;
        if(num < 10) break;
    }
    return temp;
}