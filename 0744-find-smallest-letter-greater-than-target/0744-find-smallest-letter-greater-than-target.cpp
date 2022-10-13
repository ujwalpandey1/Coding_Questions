class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l=0;
        int h=letters.size()-1;
        char res='#';
        while(l<=h){
            int mid=(l+h)/2;
            if(letters[mid]==target) l=mid+1;
            else if(letters[mid]<target) l=mid+1;
            else{ 
                res=letters[mid];
                h=mid-1;
                }
        }
        return res=='#'?letters[0]:res;
    }
};