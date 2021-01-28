
#include <bits/stdc++.h>
using namespace std;

struct cell{
    int i; 
    int j; 
    int dis;
    cell(int i, int j,int dis) :i(i),j(j),dis(dis)
    {

    }

};

bool isInside(int i,int j,int N){
    if(i>=1 && i<=N && j>=1 && j>=1 && j<=N ) return true;
    else return false;
}


int minStepToReachTarget( int knightPos[], int targetPos[],int N)
{
    int di[8]= {-2,-2,-1,-1,1,1,2,2};
    int dj[8]= {-1,1,-2,2,2,-2,1,-1};
    queue<cell> q;
    q.push(cell(knightPos[0],knightPos[1],0));
    bool vis[N+1][N+1];
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            vis[i][j]=false;
        }
    }
    vis[knightPos[0]][knightPos[1]]= true;
    while(!q.empty()){
        cell t= q.front();
        q.pop();
        if(t.i==targetPos[0] && t.j==targetPos[1]) return t.dis;
        for(int k=0;k<8;k++){
            int i= t.i+di[k];
            int j= t.j +dj[k];
            int curr_dis=t.dis;
            if(!vis[i][j] && isInside(i,j,N))
            {
                vis[i][j]= true;
                q.push(cell(i,j,curr_dis+1)); 

            }
        } 
    }
    return 0;

}

// Driver code to test above methods
int main()
{
    int N = 30;
    int knightPos[] = { 1, 1 };
    int targetPos[] = { 30, 30 };
    cout << minStepToReachTarget(knightPos, targetPos, N);
    return 0;
}
