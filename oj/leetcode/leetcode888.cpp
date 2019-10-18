class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());

        int sumA=0,sumB=0;
        for(int a : A){
            sumA += a;
        }

        for(int b : B){
            sumB += b;
        }
        

        int a = 0,b=0;
        if(sumA >= sumB){
            while(a < A.size() && b < B.size()){
                if((A[a] - B[b])*2 == sumA - sumB){
                    return vector<int>{A[a],B[b]};
                }else if((A[a] - B[b])*2 > sumA - sumB){
                    b++;
                }else{
                    a++;
                }
            }
        //if(sumA < sumB)
        }else{
            while(a < A.size() && b < B.size()){
                if((B[b] -A[a])*2 == sumB-sumA){
                    return vector<int>{A[a],B[b]};
                }else if((B[b]-A[a])*2 > sumB-sumA){
                    a++;
                }else{
                    b++;
                }
            }
        }
        return vector<int>(2,0);
    }
};