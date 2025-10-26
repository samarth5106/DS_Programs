#include <stdio.h>
#include <stdlib.h>

typedef struct BST_node {
    int data;
    struct BST_node *left, *right;
} *BST;

BST Q[100], h;
int f = 0, r = -1;

BST getnode() {
    BST new1 = (BST)malloc(sizeof(struct BST_node));
    new1->left = NULL;
    new1->right = NULL;
    return new1;
}

void display_tree(BST root) {
    BST temp;
    f = 0; r = -1;
    Q[++r] = root;
    Q[++r] = NULL;

    while (f <= r) {
        temp = Q[f++];
        if (temp == NULL) {
            printf("\n");
            if (f <= r) Q[++r] = NULL;
        } else {
            printf("%d ", temp->data);
            if (temp->left != NULL) Q[++r] = temp->left;
            if (temp->right != NULL) Q[++r] = temp->right;
        }
    }
}

void cal_height(BST root) {
    int ht = 0;
    BST temp;
    f = 0; r = -1;
    Q[++r] = root;
    Q[++r] = NULL;

    while (f <= r) {
        temp = Q[f++];
        if (temp == NULL) {
            ht++;
            if (f <= r) Q[++r] = NULL;
        } else {
            if (temp->left != NULL) Q[++r] = temp->left;
            if (temp->right != NULL) Q[++r] = temp->right;
        }
    }
    printf("\n\tHeight of tree is: %d\n", ht);
}

void disp_children(BST root) {
    BST temp;
    int val;
    f = 0; r = -1;
    Q[++r] = root;

    printf("\nEnter the parent node value: ");
    scanf("%d", &val);

    while (f <= r) {
        temp = Q[f++];
        if (temp->data == val) {
            if (temp->left != NULL)
                printf("\nLeft child: %d", temp->left->data);
            else
                printf("\nNo left child");
            if (temp->right != NULL)
                printf("\nRight child: %d\n", temp->right->data);
            else
                printf("\nNo right child\n");
            return;
        } else {
            if (temp->left != NULL) Q[++r] = temp->left;
            if (temp->right != NULL) Q[++r] = temp->right;
        }
    }
    printf("\nParent not found in tree.\n");
}

void disp_sibling(BST root) {
    BST temp;
    int val;
    f = 0; r = -1;
    Q[++r] = root;

    printf("\nEnter node value to find sibling: ");
    scanf("%d", &val);

    while (f <= r) {
        temp = Q[f++];

        if (temp->left && temp->left->data == val) {
            if (temp->right != NULL)
                printf("\nRight sibling is: %d\n", temp->right->data);
            else
                printf("\nNo right sibling.\n");
            return;
        } else if (temp->right && temp->right->data == val) {
            if (temp->left != NULL)
                printf("\nLeft sibling is: %d\n", temp->left->data);
            else
                printf("\nNo left sibling.\n");
            return;
        }

        if (temp->left != NULL) Q[++r] = temp->left;
        if (temp->right != NULL) Q[++r] = temp->right;
    }

    printf("\nNode not found or has no sibling.\n");
}

void disp_parent(BST root) {
    BST temp;
    int val;
    f = 0; r = -1;
    Q[++r] = root;

    printf("\nEnter the child node value: ");
    scanf("%d", &val);

    if (root->data == val) {
        printf("\nNo parent for root node.\n");
        return;
    }

    while (f <= r) {
        temp = Q[f++];

        if (temp->left && temp->left->data == val) {
            printf("\nParent is: %d\n", temp->data);
            return;
        } else if (temp->right && temp->right->data == val) {
            printf("\nParent is: %d\n", temp->data);
            return;
        }

        if (temp->left != NULL) Q[++r] = temp->left;
        if (temp->right != NULL) Q[++r] = temp->right;
    }

    printf("\nNode not found.\n");
}

void Mirror(BST root) {
    if (root == NULL)
        return;
    BST temp;
    temp = root->left;
    root->left = root->right;
    root->right = temp;

    Mirror(root->left);
    Mirror(root->right);
}

void inorder(BST root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}

void preorder(BST root) {
    if (root != NULL) {
        printf("%d\t", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(BST root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t", root->data);
    }
}

int main() {
    BST root = NULL, temp, new1;
    char res;
    int val, ch, flag;

    // Build BST
    do {
        if (root == NULL) {
            root = getnode();
            printf("Enter data for root node: ");
            scanf("%d", &val);
            root->data = val;
            temp = root;
        } else {
            flag = 0;
            temp = root;
            new1 = getnode();
            printf("Enter data for new node: ");
            scanf("%d", &val);
            new1->data = val;

            do {
                if (new1->data < temp->data) {
                    if (temp->left == NULL) {
                        temp->left = new1;
                        flag = 1;
                    } else
                        temp = temp->left;
                } else {
                    if (temp->right == NULL) {
                        temp->right = new1;
                        flag = 1;
                    } else
                        temp = temp->right;
                }
            } while (flag == 0);
        }
        printf("\nWant to add more nodes? (y/n): ");
        scanf(" %c", &res);
    } while (res == 'y');

    do {
        printf("\n===== MENU =====\n");
        printf("1. Display Level Order\n");
        printf("2. Height of Tree\n");
        printf("3. Display Children\n");
        printf("4. Display Sibling\n");
        printf("5. Display Parent\n");
        printf("6. Mirror Tree\n");
        printf("7. Inorder Traversal\n");
        printf("8. Preorder Traversal\n");
        printf("9. Postorder Traversal\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: display_tree(root); break;
            case 2: cal_height(root); break;
            case 3: disp_children(root); break;
            case 4: disp_sibling(root); break;
            case 5: disp_parent(root); break;
            case 6: Mirror(root); printf("\nTree Mirrored Successfully!\n"); break;
            case 7: inorder(root); printf("\n"); break;
            case 8: preorder(root); printf("\n"); break;
            case 9: postorder(root); printf("\n"); break;
            case 10: exit(0);
            default: printf("Invalid choice!\n");
        }
    } while (ch != 10);

    return 0;
}
