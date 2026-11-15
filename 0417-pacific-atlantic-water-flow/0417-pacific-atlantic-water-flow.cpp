class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int m=h.size(),n=h[0].size();
        vector<char> p(m*n),a(m*n);
        vector<int> s;
        int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
        auto dfs=[&](vector<char>& v, bool pac){
            s.clear();
            for(int i=0;i<m;i++){
                int x=i*n+(pac?0:n-1);
                if(!v[x]) v[x]=1,s.push_back(x);
            }
            for(int j=0;j<n;j++){
                int x=(pac?0:m-1)*n+j;
                if(!v[x]) v[x]=1,s.push_back(x);
            }
            while(!s.empty()){
                int u=s.back();s.pop_back();
                int r=u/n,c=u%n;
                for(int k=0;k<4;k++){
                    int x=r+dx[k],y=c+dy[k],z=x*n+y;
                    if(x>=0&&x<m&&y>=0&&y<n&&!v[z]&&h[x][y]>=h[r][c])
                        v[z]=1,s.push_back(z);
                }
            }
        };
        dfs(p,true);
        dfs(a,false);
        vector<vector<int>> ans;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(p[i*n+j]&&a[i*n+j]) ans.push_back({i,j});
        return ans;
    }
};
