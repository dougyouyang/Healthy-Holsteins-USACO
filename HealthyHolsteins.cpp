//  Copyright © 2017 Dougy Ouyang. All rights reserved.

#include <iostream>
#include <algorithm>

using namespace std;
int vi, gg, v[25], g[15][25], tv[25], tg[15];
int small, ty[15];
bool finaly=false;

void choose(int comb, int nc, int s)
{
    if(finaly)
        return;
    int i, j;
    if(comb==nc){
        bool mr=true;
        for(i=0;i<vi;i++){
            if(tv[i]<v[i]){
                mr=false;
            }
        }
        if(mr==true){
            small=comb;
            finaly=true;
        }
        return;
    }
    for(i=s;i<gg;i++){
        tg[nc]=i+1;
        for(j=0;j<vi;j++)
            tv[j]+=g[i][j];
        choose(comb, nc+1, i+1);
        if(finaly)
            return;
        for(j=0;j<vi;j++)
            tv[j]-=g[i][j];
    }
}

int main()
{
    int i, j;
    
    cin >> vi;
    for(i=0;i<vi;i++){
        cin >> v[i];
    }
    cin >> gg;
    for(i=0;i<gg;i++){
        for(j=0;j<vi;j++){
            cin >> g[i][j];
        }
    }
    
    for(i=1;i<=gg;i++){
        choose(i, 0, 0);
        if(finaly){
            sort(tg, tg+small);
            cout << small << " ";
            for(j=0;j<small;j++){
                cout << tg[j] << " ";
            }
            cout << endl;
            return 0;
        }
    }
    
    return 0;
}
