// @author Bhabaranjan Panigrahi
// https://codeforces.com/problemset/problem/761/C

#include<bits/stdc++.h>

using namespace std;
int number[70];
int alphabet[70];
int sym[70];

int main(){
    int n , m, ans = 1000000;
    string s;
    cin>>n >> m ;

    for(int i =0 ; i < n ; i++){
        cin >> s;
        number[i] = 1000; sym[i] = 1000; alphabet[i] = 1000;
        for(int j = 0 ; j  < s.length(); j++){
            if(s[j]>='0' && s[j]<= '9'){
                number[i] = min(number[i], min(j, m-j));
            }
            if(s[j]>='a' && s[j]<= 'z'){
                alphabet[i] = min(alphabet[i], min(j, m-j));
            }
            if(s[j] == '*' || s[j] == '#' || s[j] == '&'){
                sym[i] = min(sym[i], min(j, m-j));
            }
        }
    }

    for(int i=0 ; i < n ; i++){
        for(int j = 0 ; j < n; j++){
            for(int k =0  ; k < n ; k++){
                if(i==j || j==k || k ==i ) continue;
                ans =  min(ans,number[i]+ alphabet[j] + sym[k]);
            }
        }
    }
    cout<< ans;
}