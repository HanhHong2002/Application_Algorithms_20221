#include<bits/stdc++.h>

using namespace std;

string text_replacement(string p1, string p2, string T){
    string tmp="";
    string result = "";
    stringstream ss(T);
    string token;
    while(ss >> token){
        // if(!isalpha(token[token.length()-1])){
        //     cout << token[token.length()-1] << " = ";
        //     cout << "ecec" << endl;
        //     if(token.substr(0, token.length()-1)==p1){
        //         if(tmp!=""){
        //             result += tmp;
        //             result += " ";
        //             tmp = "";
        //         }  
        //         result += p2;
        //         result += token[token.length() -1];
        //         result += " ";
        //         continue;
        //     }
        // }
        if(tmp.length()<p1.length()){
            if(token==p1){
                result += tmp;
                if(tmp[tmp.length()-1]!=' '){
                    result += " ";
                }
                tmp = "";
                result += p2;
                result += " ";
                continue;
            }
            tmp += token;
            if(tmp.length()<p1.length()){
                tmp+= " ";
            }
            if(tmp.length()>p1.length()){
                result += tmp;
                if(tmp[tmp.length()-1]!=' '){
                    result += " ";
                }
                tmp = "";
            }
            if(tmp.length()==p1.length()){
                if(tmp==p1){
                    result += p2;
                    result += " ";
                    tmp = "";
                }
                else{
                    result += tmp;
                    if(tmp[tmp.length()-1]!=' '){
                        result += " ";
                    }
                    tmp = "";
                }
            }
        }
    }
    return result;
}

int main(){
    string p1, p2, T, result;
    getline(cin, p1);
    getline(cin, p2);
    while(getline(cin, T)){
        cout << text_replacement(p1,p2,T);
    }
}
