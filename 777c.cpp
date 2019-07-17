/**
 * @author Bhabaranjan Panigrahi
 * Problem Link: https://codeforces.com/problemset/problem/777/C
 */
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    int k, l, r;

    cin >> n >> m;
    int arr[n][m];
    int mask[n][m];
    int res[1000001];
    int maxV = -1;
    memset(res, 0 , sizeof res);
    memset(mask, 1, sizeof mask);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (!i)
            {
                mask[i][j] = 1;
            }
            if (i > 0)
            {
                if (arr[i - 1][j] <= arr[i][j])
                {                    
                    mask[i][j] = mask[i - 1][j] + 1;
                }
                else
                {
                    mask[i][j] = 1;
                }
            }
            res[i] = max(res[i], mask[i][j]);
        }
    }

      cin >> k;

    for (int i = 0; i < k; i++)
    {
        cin >> l >> r;
        bool flag = true;
        if (l == r)
        {
            cout << "Yes\n";
            continue;            
        }
        else
        {
            l--;
            r--;
            if(res[r] >= r-l+1){
                cout << "Yes\n";
                continue;
            }else{
                cout << "No\n";
            }
        }        
    }
}