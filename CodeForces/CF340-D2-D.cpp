#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("in.txt", "rt", stdin);
    int n,x;
    scanf("%d",&n);
    set<int> st;
    for(int i=0;i<n;++i){
        scanf("%d",&x);
        auto it=st.lower_bound(x);
        if(it!=st.end()) st.erase(it);
        st.insert(x);
    }
    printf("%d",(int)st.size());
 }
