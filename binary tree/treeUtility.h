#include <iostream>
#include <queue>

using namespace std;
class Node{
public:
    int val;
    Node *left = NULL;
    Node *right = NULL;
    Node(int val)
    {
        this->val = val;
        return;
    }
    Node() = default;
};

typedef Node node;

void inOrder(node *head)
{
    if(head != NULL)
    {
        inOrder(head->left);
        cout << head->val << ' ';
        inOrder(head->right);
    }
}

void preOrder(node* head)
{
    if (head != NULL)
    {
        cout << head->val << ' ';
        preOrder(head->left);
        preOrder(head->right);
    }
}

void postOrder(node* head)
{
    if (head != NULL)
    {
        postOrder(head->left);
        postOrder(head->right);
        cout << head->val << ' ';
    }
}

void levelOrder(node *head)
{
    if(head != NULL)
    {
        queue<node *>q;
        q.push(head);
        while(!q.empty())
        {
            node *temp = q.front();
            q.pop();
            cout << temp->val << ' ';
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
}

int leafNodes(node *head)
{
    queue<node *>q;
    int ans = 0;
    if(head != NULL)
    {
        q.push(head);
        while(!q.empty())
        {
            node *temp = q.front();
            q.pop();
            if(temp->left == NULL && temp->right == NULL)
            {
                ans++;
            }
            else
            {
                if (temp->left != NULL)
                {
                    q.push(temp->left);
                }
                if (temp->right != NULL)
                {
                    q.push(temp->right);
                }
            }
        }   
    }
    return ans;
}

int totalNodes(node *head)
{
    queue<node*>q;
    node* temp;
    int ans = 0;
    q.push(head);
    while(!q.empty())
    {
        temp = q.front();
        ans++;
        q.pop();
        if(temp->left  != NULL)
        {
            q.push(temp->left);
        }
        if(temp->right != NULL)
        {
            q.push(temp->right);
        }
    }
    return ans;
}

int height(node *head)
{
    /*
    * Height is counted from bottom and NOT the head
    * Height(leaf node) = 0;
    ? FORMULA: Height(node) = Height(parent) - 1
    */
    if(head == NULL)
    {
        return -1; // from FORMULA above, height of a null node = 0 - 1
    }
    int v1 = 1 + height(head->left);
    int v2 = 1 + height(head->right);
    return max(v1, v2);
}




int diameterUtil1(node* head)
{
    return height(head->left) + height(head->right) + 2;
}

void diamUtil2(node* head, int& ans)
{
    if (head != NULL)
    {
        int temp = diameterUtil1(head);
        if (temp > ans)
        {
            ans = temp;
        }
        diamUtil2(head->left, ans);
        diamUtil2(head->right, ans);
    }
}

bool isBalanced(node* head)
{
    queue<node*>q;
    if (head == NULL)
    {
        return true;
    }
    q.push(head);
    while (!q.empty())
    {
        node* temp = q.front();
        q.pop();
        if (abs(height(temp->left) - height(temp->right)) > 1)
        {
            return false;
        }
        if (temp->left != NULL)
        {
            q.push(temp->left);
        }
        if (temp->right != NULL)
        {
            q.push(temp->right);
        }
    }
    return true;
}

node* rrRotation(node* head)
{
    node* a = head, * b = a->left, * c = a->left->left;
    node* temp = b->right;
    a->left = NULL;
    b->right = a;
    a->left = temp;
    return b;
}

node* llRotation(node* head)
{
    node* a = head, * b = a->right, * c = b->right;
    node* temp = b->left;
    a->right = NULL;
    b->left = a;
    a->right = temp;
    return b;
}

node* lrRotation(node* head)
{
    node* a = head;
    node* b = head->left;
    node* c = head->left->right;
    node* temp1 = c->left;
    node* temp2 = c->right;
    c->left = b;
    c->right = a;
    b->right = temp1;
    a->left = temp2;
    return c;
}

node* rlRotation(node* head)
{
    node* a = head;
    node* b = head->right;
    node* c = b->left;
    node* temp1 = c->left;
    node* temp2 = c->right;
    c->left = a;
    c->right = b;
    a->right = temp1;
    b->left = temp2;
    return c;
}

node* minNodeRight(node* head)
{
    node* temp = head;
    while (temp && temp->left)
    {
        temp = temp->left;
    }
    return temp;
}

int balanceFactor(node* head)
{
    return height(head->left) - height(head->right);
}
