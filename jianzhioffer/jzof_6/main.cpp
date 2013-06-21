#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

struct BinTreeNode {
    int val;
    BinTreeNode* left;
    BinTreeNode* right;
};

BinTreeNode* ConstructorCore(int* startPreorder, int* endPreorder,
                             int* startInorder, int* endInorder) {
    /// printf("(%c, %c) (%c, %c)\n", (*startPreorder) + 'A',(*endPreorder) + 'A', (*startInorder) + 'A', (*endInorder) + 'A');
    BinTreeNode* root = new BinTreeNode();
    root->val = *startPreorder;
    root->left = NULL;
    root->right = NULL;

    if (startPreorder == endPreorder) {
        if (startInorder == endInorder && *startPreorder == *startInorder) {
            return root;
        } else {
            puts("1.Invalid input!\n");
            return NULL;
        }
    }

    int* rootInorder = startInorder;
    while (rootInorder <= endInorder && *rootInorder != *startPreorder) rootInorder++;

    if (rootInorder == endInorder && *rootInorder != *startPreorder) {
        puts("2.Invalid input!");
        return NULL;
    }

    int* leftPreorder = startPreorder + (int)(rootInorder - startInorder);
    if (leftPreorder - startPreorder - 1 >= 0) {
        root->left = ConstructorCore(startPreorder + 1, leftPreorder,
                                     startInorder, rootInorder-1);
    }
    if (endPreorder - leftPreorder - 1 >= 0) {
        root->right = ConstructorCore(leftPreorder + 1, endPreorder,
                                      rootInorder + 1, endInorder);
    }
    return root;
}

BinTreeNode* Constructor(int* preorder, int* inorder, int length) {
    if (preorder == NULL || inorder == NULL || length == 0) return NULL;
    return ConstructorCore(preorder, preorder + length -1,
                           inorder, inorder + length - 1);
}

void PostorderPrint(BinTreeNode* root) {
    if (root == NULL) return ;
    PostorderPrint(root->left);
    PostorderPrint(root->right);
    printf("%c", char(root->val) + 'A');
}

int main()
{
    freopen("in", "r", stdin);
    int* preorder = new int[30];
    int* inorder = new int[30];

    char s1[30], s2[30];
    while (EOF != scanf("%s %s", s1, s2)) {
        int len = (int)strlen(s1);
        for (int i = 0; i < len; i++) {
            preorder[i] = (int)s1[i] - 'A';
            inorder[i] = (int)s2[i] - 'A';
        }

        BinTreeNode* ans = Constructor(preorder, inorder, len);
        PostorderPrint(ans);
        printf("\n");
    }
    return 0;
}
