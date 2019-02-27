/*
The program calculates a number of inversions in a given sequence of
the length 1 <=n<= 60000 where numbers are integers in a range between 10^-9 and 10^9.

The program scales the values of the numbers in the given sequence,
and then, starting from the end of the sequence for each value it 
counts the number of smaller numbers placed before that value.
It performs calculations in the optimal time by using the segment tree.
*/
#include <iostream>
#include <algorithm>

using namespace std;
const int BASE=1<<20;

int tr[2*BASE];
void up(int ix){
    ix += BASE;
    tr[ix]++;
    while(ix>1){
        ix /= 2;
        tr[ix]=tr[ix*2]+tr[ix*2+1];
    }
}

int sum(int l, int p){

    l+=BASE;
    p+=BASE;
    //int w= tr[l];
    int sum = 0;
    while(l<p){
        if(l%2){
            sum += tr[l];
            l++;
        }
        if(!(p%2)){
            sum += tr[p];
            p--;
        }
        p=p/2;
        l=l/2;
    }
    if(l==p){
        sum += tr[l];
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    pair<int,int>tab[n];

    for(int i = 0; i<n; i++){
        int a;
        cin >> a;
        tab[i]=make_pair(a,i);
    }

    sort(tab,tab+n);
    int scaled_tab[n];
    int number = 0;
    for(int i = 0; i<n; i++){
        if(i>0 && tab[i]==tab[i-1]){
            scaled_tab[tab[i].second]=number;
        }
        else{
            number++;
            scaled_tab[tab[i].second]=number;
        }
    }
    int result = 0;
    for(int i = n-1; i>=0; i--){
        result+=sum(1,scaled_tab[i]-1);
        up(scaled_tab[i]);
    }
    cout << result << "\n";

    return 0;
}
