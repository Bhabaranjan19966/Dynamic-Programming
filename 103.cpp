/*
    [103 - Stacking Boxes] UVA oj
*/
#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > boxes; 


vector<int> LIS (int start, vector<int>res[]){
  
  if(start < 0){
    vector<int> last;
    return  last;
  }
  //return value if already computed
  if(res[start].size() > 0){
    return res[start];
  }
  vector<int>curr;
  vector<int> b;
  curr.push_back(boxes[start][boxes[start].size() -1]);

  for(int i = start -1 ; i >= 0 ; i-- ){
    bool vio = false;
    for(int j =0 ; j < boxes[start].size() -1 ; j++){
      //overlap condition check
      if(boxes[start][j] <= boxes[i][j]){
        vio = true;
        break;
      }
    }
    //if condition is not violated
    if(!vio){      
      vector<int> temp;
      temp = LIS(i, res);
      //checking for largest length 
      if(temp.size() > b.size()){
        b = temp;
      }      
    }
  }

  if(b.size() > 0){
    curr.insert(curr.end(), b.begin(), b.end());
  }
  // store optimal length and return. 
  return res[start] = curr;
}

int main () {

  while(true){
    //this is used to memorize computed value
    vector<int>res[30];

    int n, d;
    cin >> n;
    if(cin.eof()){
      return 0;
    }
    cin >> d;
    int temp;
    boxes.resize(n);
    
    for(int i =0 ; i < n ; i++){
      boxes[i].resize(d);
      for(int j =0 ; j < d; j++){
        cin >> temp;
        boxes[i][j] = temp;                
      }
      sort(boxes[i].begin(),boxes[i].end());
      //Adding index of at the end to identify real index of the box after sorting at step 75
      boxes[i].push_back(i);
    }
    sort(boxes.begin(), boxes.end());
    int maxLen = -1, index = -1;

    //check for maximum length in the sequence
    for(int i = 0; i < n ; i++){
      int tempLen = LIS(i,res).size();
      if (maxLen < tempLen ){
        maxLen = tempLen;
        index = i;
      }
    }

    if(index > -1){
      cout<< res[index].size()<<"\n";
      for(int i =res[index].size() -1 ; i >-1 ; i--){
        cout << res[index][i]+1<<" ";
      }
      cout << "\n";
    }
  }

}