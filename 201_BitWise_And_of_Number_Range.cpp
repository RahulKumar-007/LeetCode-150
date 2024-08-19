/*
 Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.

 

Example 1:

Input: left = 5, right = 7
Output: 4

Example 2:

Input: left = 0, right = 0
Output: 0

Example 3:

Input: left = 1, right = 2147483647
Output: 0

 

Constraints:

    0 <= left <= right <= 231 - 1

*/
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        string l = bitset<32>(left).to_string();
        string r = bitset<32>(right).to_string();

        int len = 32;

        int sum = 0;

        for(int i =0;i<len;i++){
            if(l[i]==r[i]){
                if(l[i]=='1'){
                    sum+=(pow(2,len-i-1));
                }
            }
            else{
                break;
            }
        }

        return sum;

    }
};
