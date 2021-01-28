#include<bits/stdc++.h>
using namespace std;

struct cell
{
    int x,y,dis;
    cell(){
        cout<<"bonjour"<<endl;
        x=1;
        y=1;
        dis=1;
    }
    cell(int x,int y,int dis) :x(x),y(y),dis(dis)
    {
        cout<<"intialization list constructor"<<endl;
    }

};


int main(){
    // cell t(2,3,4);
    // cout<<"t.x: "<<t.x<<endl;
    // cout<<"t.y: "<<t.y<<endl;
    // cout<<"t.dis: "<<t.dis<<endl;
    // queue<cell> q;
    // q.push(cell(5,6,7));
    // cell m= q.front();
    cell m= cell(5,6,7);
    cout<<"m.x: "<<m.x<<endl;
    cout<<"m.y: "<<m.y<<endl;
    cout<<"m.dis: "<<m.dis<<endl;

}