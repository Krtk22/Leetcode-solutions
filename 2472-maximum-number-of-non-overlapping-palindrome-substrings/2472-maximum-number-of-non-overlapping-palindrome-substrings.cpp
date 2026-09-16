class Solution {
public:
    int maxPalindromes(string s, int k) {
        string st="*";
        for(int i=0; i<s.size(); i++){
            st+=s[i];
            st+="*";
        }
        int cnt=0;
        int ans=0;
        int j=0;
        for(int i=k; i<st.size(); i++){
            int l=i-1;
            int r=i+1;
            cnt=(st[i]=='*')?0:1;
            while(l>=j && r<st.size() && cnt<k){
                if(st[l]==st[r]){
                    if(st[l]!='*')cnt+=2;
                    l--;
                    r++;
                }
                else break;
            }
            // cout<<cnt<<"-"<<st[i]<<endl;
            if(cnt>=k){
                ans++;
                i=r-1;
                j=r;
            }
        }
        return ans;
    }
};