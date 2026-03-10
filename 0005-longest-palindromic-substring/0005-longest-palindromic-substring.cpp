class Solution {
public:
    string longestPalindrome(string s) {
        
        
        
        int max=INT_MIN;
        string ans="";
        ans.push_back(s[0]);
        for(int i=0;i<s.size();i++){
            int end=s.size()-1;
            while(i < end){
                int temp=end;
                while(temp > i && s[temp]!=s[i]){
                    temp--;
                }
                
                if(temp==i){
                    break;
                }
                bool check=true;
                int l=i;
                int r=temp;
                while(l < r){
                    if(s[l]!=s[r]){
                        check=false;
                        break;
                    }
                    l++;
                    r--;
                }
                if(check){
                    int len=temp-i+1;
                    if(len > max){
                        max=len;
                        ans=s.substr(i,len);
                    }
                    break;
                }
                end=temp-1;
            }
        }

        return ans;
    }
};