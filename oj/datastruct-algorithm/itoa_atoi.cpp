int errnum = 0;
int atoi(const char* src){
    if(src == nullptr) {
        errnum = -1; //empty string
        return 0;
    }

    //remove whitespace characters.
    while(*src == ' ' || *src == '\t' || *src == '\n'){
        src++;
    }

    int sign = 1;
    if(*src == '+'){
        src++;
    }else if(*src == '-'){
        sign = -1;
        src++;
    }
    //only with sign bit
    if(*src == '\0') {
        errnum = -2;
        return 0;
    }

    long long res = 0;
    while(*src != '\0'){
        if(*src >= '0' && *src <= '9'){
            res = res * 10 + *src - '0';
            if((sign == 1 && res > 0x7fffffff) || (sign == -1 && (-1*res) < (int)0x80000000)){
                errnum = -3;  //out of range
                return 0;
            }
        }else{
            errnum = -4;  //illegal character
            return 0;
        }
        src++;
    }
    return sign*res;
}


char* itoa(int val,char* buf,size_t radix){
    assert(buf != nullptr);
    char* p = buf;
    if(val < 0){
        *p++ = '-';
        val = -1 * val;
    }

    int a = 0;
    do{
        a = val % radix;
        val /= radix;
        if(a > 9){
            *p++ = char(a-9+'a');
        }else{
            *p++ = (char)(a + '0');
        }
    }while(val != 0);

    *p = '\0';
    //reverse
    size_t len = strlen(buf);
    int left = 0;
    if(*buf == '-' || *buf == '+'){
        left++;
    }
    int right = len - 1;
    while(left < right){
        swap(buf[left++],buf[right--]);
    }
    return buf;
}