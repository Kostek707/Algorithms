#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
void q_sort(int l, int r){
    int s = l;
    int a = v[r-1];
    for(int i = l; i<r-1; i++){
        if(v[i]<a){
            int h = v[i];
            v[i]=v[s];
            v[s]=h;
            s++;
        }
    }
    v[r-1]=v[s];
    v[s]=a;

    if(s>1){
        q_sort(0, s);
    }
    if(s+1<r-1){
        q_sort(s+1, r);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    for(int i = 0; i<n ; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    q_sort(0,v.size());

    for(int i = 0; i<n; i++){
        cout << v[i] << " ";
    }

    return 0;
}
