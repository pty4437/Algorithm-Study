#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>


using namespace std;

int tree[1000000][2];

void postorder(int root) {

    if (tree[root][0] != 0) postorder(tree[root][0]);
    if (tree[root][1] != 0) postorder(tree[root][1]);

    if (root != -1) cout << root << '\n';
}


void preorder2(int curr, int root) {
    if (curr > root) {
        if (tree[root][1] == 0) {
            tree[root][1] = curr; return;
        }
        else {
            preorder2(curr, tree[root][1]);
        }
    }
    else if (curr < root) {
        if (tree[root][0] == 0) {
            tree[root][0] = curr; return;
        }
        else {
            preorder2(curr, tree[root][0]);
        }
    }
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, root = -1;

    while (true) {
        cin >> n;
        if (cin.eof() == 1) break;
        if (root == -1) root = n;
        else preorder2(n, root);
    }

    postorder(root);

    return 0;
}