int minPartitions(char * n){
    int res = 0;
    for(int i = 0; i < strlen(n); i++){
        int digit = n[i] - '0';
        if(digit == 9) return 9;
        res = res > digit ? res : digit;
    }
    return res;
}

int minPartitions(char * n){
    int biggestCharNum = '0';
    while(*n != '\0') {
        if(*n == '9') return 9;
        if(*n > biggestCharNum) { 
            biggestCharNum = *n;
        }
        n++;
    }
    return biggestCharNum - '0';
}