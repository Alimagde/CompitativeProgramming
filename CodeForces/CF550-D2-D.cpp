/*
    if k is even the answer is no
    lets make a graph with three levels first level have one node the other nodes have k-1 nodes
    if k = 3
      1      O

      2    O   O

      3    O   O
    1 - connect the first level node with all nodes in the second level so the degree of the
        first level node is k-1
    2 - connect every node in the second level with the nodes in the third level so the degree
        of the second level nodes is k
    3 - now every node in the third level has degree of k-1 divide the third level nodes into
        pairs and connect them so the degree of the third level nodes will become k
    4 - make two graphs and then connect the first level nodes.
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
    int k;
    scanf("%d", &k);
    if (k % 2 == 0) {
        puts("NO");
        return 0;
    }
    vector<pair<int, int> > vec;
    for (int i = k; i <= 2 * k - 2; ++i) {
        vec.push_back(make_pair(i, 2 * k - 1));
    }

    for (int i = 2; i < k; i+=2) {
        vec.push_back(make_pair(i, i-1));
    }
    for (int i = k; i <= 2 * k - 2; ++i) {
        for (int j = 1; j < k; ++j) {
            vec.push_back(make_pair(i, j));
        }
    }

    puts("YES");
    printf("%d %d\n",2*(2*k-1),(int)vec.size()*2+1);
    for (auto x:vec) {
        printf("%d %d\n", x.first, x.second);
    }
    for (auto x:vec) {
        printf("%d %d\n", x.first + (k * 2 - 1), x.second + (k * 2 - 1));
    }
    printf("%d %d\n",(2*k-1),2*(2*k-1));
}
