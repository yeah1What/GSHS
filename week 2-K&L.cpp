// 마지막 테스트 케이스가 틀려서 추가 보정 필요.

#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, s[15][15], a, ma;

vector<int> vec;

vector<int> ans;

int chk[15];

void dfs(int num, int sum){
    if(num==1&&sum!=0){ // 목적지에 도달한 경우
        if(sum>ma){
            ma=sum;
            ans.clear();
            for(int i=0; i<n; i++){
                ans.push_back(vec[i]);
            }

        }
        return;
    }
    for(int i=1; i<=n; i++){
        if(!chk[i]){
            chk[i]=1;
            vec.push_back(i);
            dfs(i, sum+s[num][i]);
            chk[i]=0;
            vec.pop_back();
        }
    }
}

main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>a;
            s[i][j]=s[j][i]=a; // 인접 행렬 만들기
        }
    }
    vec.push_back(1);
    dfs(1, 0);
    cout<<ma<<endl;
    for(int i=0; i<n; i++){
        cout<<ans[i]<<' ';
    }
    cout<<1;
}