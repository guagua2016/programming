void* memcpy(void* dest,void* src,size_t n){
    assert(dest != NULL && src != NULL);

    if(src < dest && (char*)src + n > dest){
        char* pdst = (char*)dest+n-1;
        char* psrc = (char*)src+n-1;
        while(n--){
            *pdst-- = *psrc--;
        }
    }else{
        char* pdest = (char*)dest;
        char* psrc = (char*)src;
        while(n--){
            *pdest++ = *psrc++;
        }
    }
    return dest;
}


void* memset(void* src,int c,size_t n){
    assert(src != NULL);
    char* psrc = (char*)src;
    while(n--){
        *psrc++ = (char)c;
    }
    return src;
}

char* strcpy(char* dest,const char* src){
    assert(dest != NULL && src != NULL);

    size_t n = strlen(src);
    if(src < dest && src + n > dest){
        char* pdst = dest + n;
        *pdst-- = '\0';
        src = src + n - 1;
        while(n--){
            *pdst-- = *src--;
        }
    }else{
        char* pdst = dest;
        while((*pdst++ = *src++) != 0);
    }
    return dest;
}

char* strncpy(char* dest,const char* src,size_t n){
    assert(dest != NULL && src != NULL);

    if(src < dest && src + n > dest){
        int m = strlen(src) < n ? strlen(src):n;
        char* pdst = dest+m;
        *pdst-- = '\0';
        src = src + m-1;
        while(m--){
            *pdst-- = *src--;
        }
    }else{
        char* pdst = dest;
        size_t i = 0;
        while(i++ < n && (*pdst++ = *src++) != '\0');
        if(*(pdst-1) != '\0') *pdst = '\0';
    }
    return dest;
}

char* strcat(char* dest,const char* src){
    assert(dest != NULL && src != NULL);
    char* pdst = dest;
    while(*pdst != '\0'){
        pdst++;
    }
    while((*pdst++ = *src++) != '\0');
    return dest;
}

int strcmp(const char* s1,const char* s2){
    assert(s1 != NULL && s2 != NULL);
    while(s1 && s2 && *s1 == *s2){
        s1++;
        s2++;
    }
    return *s1 - *s2;
}


size_t strlen(const char* src){
    assert(src != NULL);
    size_t ret = 0;
    while(*src++ != '\0'){
        ret++;
    }
    return ret;
}