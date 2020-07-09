class Solution{
public:
    bool duplicate(int numbers[],int length,int* duplication){
        if(length < 2) return false;

        for(int i=0;i<length;i++){
            while(numbers[i] != i){
                if(numbers[i] == numbers[numbers[i]]){
                    *duplication = numbers[i];
                    return true;
                }else{
                    swap(numbers[i],numbers[numbers[i]]);
                }
            }
        }
        return false;
    }
};