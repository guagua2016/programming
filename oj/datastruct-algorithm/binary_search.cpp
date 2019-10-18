//recursive
int binarySearch(int a[],int start,int end,int k){
    if(start > end) return -1;
    int mid = start + (end -start) /2;
    if(k == a[mid]) return mid;
    else if(a[mid] > k) return binarySearch(a,start,mid-1,k);
    else return binarySearch(a,mid+1,end,k);
}
//iteration
int binarySearch(int a[],int length,int k){
    int start = 0;
    int end = length-1;
    while(start <= end){
        int mid = start + (end - start)/2;
        if(a[mid] == k) return mid;
        else if(a[mid] >k) {
            end = mid-1;
        }else{
            start = mid+1;
        }
    }
    return -1;
}