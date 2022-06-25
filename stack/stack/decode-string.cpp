//394. 字符串解码
//https://leetcode.cn/problems/decode-string/

/*题目描述
给定一个经过编码的字符串，返回它解码后的字符串。
编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。
你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。

输入：s = "3[a]2[bc]"
输出："aaabcbc"

输入：s = "3[a2[c]]"
输出："accaccacc"

输入：s = "2[abc]3[cd]ef"
输出："abcabccdcdcdef"

输入：s = "abc3[cd]xyz"
输出："abccdcdcdxyz"
*/

class Solution {
public:
    string decodeString(string s) {
        stack<string> stk;
        stack<int> value; 
        string str = "";
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '['){
            //数字读取
                int j = 1;
                int beishu = 0;
                while(i-j>=0 && s[i-j]<='9' && s[i-j]>='0'){
                    beishu += (s[i-j] - '0')*pow(10,j-1);
                    j++;
                }
                value.push(beishu);
                stk.push(str);
                str = "";
            }else if(s[i] == ']'){
                string tempstr = "";
                for(int i = 0; i < value.top();i++){
                    tempstr += str;
                }                    
                value.pop();
                str = stk.top() + tempstr;

                // for(auto m:str){
                //     cout<<m;
                // }
                // cout<<endl;

                stk.pop();
            }else if(s[i]>'9' || s[i]<'0'){
                str += s[i] ;
            }
        }
       
        // for(auto m:str){
        //     cout<<m;
        // }
        // cout<<endl;

        return str;
    }
};