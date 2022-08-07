class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        sort(letters.begin(),letters.end());
        vector<int> vec;
        int x=letters.size();
        int dif;
        int ans;
        for(int i=0;i<x;i++){
            dif=(int)letters[i]-target;
            vec.push_back(dif);
        }
        int flag=0;
        for(int i=0;i<x;i++){
            if(vec[i]>0){
                flag+=1;
                break;
            }
        }
        if(flag==0){
            int min=vec[0];
            int ans=0;
            for(int i=0;i<x;i++){
                if(vec[i]<min){
                    min=vec[i];
                    ans=i;
                }
            }
        return letters[ans];
        }else{
            int max=50;
            for(int i=0;i<x;i++){
                if(vec[i]<=0){
                    continue;
                }else{
                    if(vec[i]<max){
                        max=vec[i];
                        ans=i;
                    }
                }
            }
        return letters[ans];
        }
    }
};
