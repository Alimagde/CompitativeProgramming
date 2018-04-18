/*
    using treap to rearrange the soldiers
 */
#include <bits/stdc++.h>

using namespace std;

typedef struct node {
    int prior, size;
    long long val, sum,lazy;
    //value in array,info of segtree,lazy update
    struct node *l, *r;
} node;
typedef node* pnode;
int sz(pnode t) {
    return t ? t->size : 0;
}
void upd_sz(pnode t) {
    if (t)
        t->size = sz(t->l) + 1 + sz(t->r);
}
void lazy(pnode t) {
    if (!t || !t->lazy)
        return;
    t->val += t->lazy; //operation of lazy
    t->sum += t->lazy * sz(t);
    if (t->l)
        t->l->lazy += t->lazy; //propagate lazy
    if (t->r)
        t->r->lazy += t->lazy;
    t->lazy = 0;
}
void reset(pnode t) {
    if (t)
        t->sum = t->val; //lazy already propagated
}

void combine(pnode& t, pnode l, pnode r) { //combine segtree ranges
    if (!l || !r)
        return void(t = l ? l : r);
    t->sum = l->sum + r->sum;
}
void operation(pnode t) { //operation of segtree
    if (!t)
        return;
    reset(t); //node represents single element of array
    lazy(t->l);
    lazy(t->r); //imp:propagate lazy before combining l,r
    combine(t, t->l, t);
    combine(t, t, t->r);
}
void split(pnode t, pnode &l, pnode &r, int pos, int add = 1) {
    if (!t)
        return void(l = r = NULL);
    lazy(t);
    int curr_pos = add + sz(t->l);
    if (curr_pos <= pos) //element at pos goes to "l"
        split(t->r, t->r, r, pos, curr_pos + 1), l = t;
    else
        split(t->l, l, t->l, pos, add), r = t;
    upd_sz(t);
    operation(t);
}
void merge(pnode &t, pnode l, pnode r) { //result/left/right array
    lazy(l);
    lazy(r);
    if (!l || !r)
        t = l ? l : r;
    else if (l->prior > r->prior)
        merge(l->r, l->r, r), t = l;
    else
        merge(r->l, l, r->l), t = r;
    upd_sz(t);
    operation(t);
}
pnode init(long long val) {
    pnode ret = (pnode) malloc(sizeof(node));
    ret->prior = rand();
    ret->size = 1;
    ret->val = val;
    ret->sum = val;
    ret->lazy = 0;
    return ret;
}

int ans[200005];

int main() {

    int tc;
    scanf("%d", &tc);
    while (tc--) {
        int n;
        scanf("%d", &n);
        pnode t = init(1);
        int x;
        scanf("%d", &x);
        for (int i = 2; i <= n; ++i) {
            scanf("%d",&x);
            pnode l,r,c=init(i);
            if(x<i-1){
                split(t,l,r,i-x-1);
                merge(t,l,c);
                merge(t,t,r);
            }
            else{
                merge(t,c,t);
            }
        }
        for(int i=1;i<=n;++i){
            pnode l,r;
            split(t,l,r,1);
            ans[l->val]=i;
            t=r;
        }
        for(int i=1;i<=n;++i) printf("%d ",ans[i]);
        puts("");
    }
}
