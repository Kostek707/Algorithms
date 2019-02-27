/*
Implementatation of the priority queue algorithm
*/
#include <iostream>
#include <algorithm>
using namespace std;
int kol[1000001];
int n = 0;
void push(int a){
    n++;
    kol[n]=a;
    int w = n;
    while(w>1 && kol[w]>kol[w/2]){
        swap(kol[w],kol[w/2]);
        w/=2;
    }
}
void redo(int i){
    int lewy = 2*i;
    int prawy = 2*i+1;
    int maks = i;
    if(lewy<=n && kol[lewy]>kol[maks]){
        maks=lewy;
    }
    if(prawy<=n && kol[prawy]>kol[maks]){
        maks=prawy;
    }
    if(maks>i){
        swap(kol[i],kol[maks]);
        redo(maks);
    }

}
void pop(){
    kol[1]=kol[n];
    n--;
    redo(1);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << "Press 1 to push an integer to a queue\n Press 0 to delete the first element of the queue\n Press 2 to exit\n";
    while(1){
        int a;
        cin >> a;
        if(a==1){
            int b;
            cin >> b;
            push(b);
        }
        else if (!a){
            if(n>0){
                pop();
            }
            else{
                cout << "The queue is empty so you can't remove anything!\n";
            }
        }
        else if(a==2){
            break;
        }
        else{
            cout << "Unknown input\n";
        }
        cout << "QUEUE: \n";
        int tab[n];
        int c = n;
        for(int i = 0; i<c; i++){
            cout << kol[1] << " ";
            tab[i]=kol[1];
            pop();
        }
        for(int i = 0; i<c; i++){
                push(tab[i]);
            }
            cout << "\n";
    }
    return 0;
}
