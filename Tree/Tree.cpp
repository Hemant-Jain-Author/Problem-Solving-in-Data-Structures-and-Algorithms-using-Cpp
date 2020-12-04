#include "Tree.h"

int main1()
{
    Tree t;
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    t.levelOrderBinaryTree(arr, 10);
    t.printPostOrder();
    std::cout << std::endl;
    t.iterativePostOrder();
    t.printBredthFirst();
    //t.treeToListRec();
    t.printAllPath();
    std::cout << (t.lca(10, 3));
    t.iterativePreOrder();
    t.printPreOrder();
    t.createBinaryTree(arr, 10);
    std::cout << "is bst " << (t.isBST2());
    return 0;
}

int main()
{
    Tree t;
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    t.levelOrderBinaryTree(arr, 10);
    /*    std::cout << t.isHeap() << std::endl;
        std::cout << t.isHeap2() << std::endl;
        std::cout << t.isCompleteTree() << std::endl;

        std::cout << std::endl;;
        t.printBredthFirst();
        std::cout << std::endl;;
        t.printPreOrder();
        std::cout << std::endl;;
        t.printLevelOrderLineByLine();
        std::cout << std::endl;;
        t.printLevelOrderLineByLine2();
    */
    std::cout << std::endl;;
    t.printSpiralTree();
    /*    std::cout << std::endl;;
        t.printAllPath();
        std::cout << std::endl;;
        t.nthInOrder(4);
        std::cout << std::endl;;
        t.nthPostOrder(4);
        std::cout << std::endl;;
        t.nthPreOrder(4);
        std::cout << std::endl;;
    */
    /*
      * t.printPostOrder(); std::cout << ); t.iterativePostOrder();
      * t.printBredthFirst(); // t.treeToListRec(); t.printAllPath();
      * std::cout << t.lca(10, 3) << std::endl; t.iterativePreOrder(); t.printPreOrder();
      * // t.CreateBinaryTree(arr); // std::cout << t.isBST2());
      */
}


Tree::Node::Node(int v, Node *l, Node *r)
{
    value = v;
    lChild = l;
    rChild = r;
}

Tree::Node::Node(int v)
{
    value = v;
    lChild = nullptr;
    rChild = nullptr;
}

Tree::Tree()
{
    root = nullptr;
}

void Tree::levelOrderBinaryTree(int arr[], int size)
{
    root = levelOrderBinaryTree(arr, 0, size);
}

Tree::Node *Tree::levelOrderBinaryTree(int arr[], int start, int size)
{
    Node *curr = new Node(arr[start]);

    int left = 2 * start + 1;
    int right = 2 * start + 2;

    if (left < size)
    {
        curr->lChild = levelOrderBinaryTree(arr, left, size);
    }
    if (right < size)
    {
        curr->rChild = levelOrderBinaryTree(arr, right, size);
    }

    return curr;
}

void Tree::insertNode(int value)
{
    root = insertNode(value, root);
}

Tree::Node *Tree::insertNode(int value, Node *node)
{
    if (node == nullptr)
    {
        node = new Node(value, nullptr, nullptr);
    }
    else
    {
        if (node->value > value)
        {
            node->lChild = insertNode(value, node->lChild);
        }
        else
        {
            node->rChild = insertNode(value, node->rChild);
        }
    }
    return node;
}

void Tree::printPreOrder()
{
    printPreOrder(root);
}

void Tree::printPreOrder(Node *node)
{
    if (node != nullptr)
    {
        std::cout << " " << node->value;
        printPreOrder(node->lChild);
        printPreOrder(node->rChild);
    }
}

void Tree::nthPreOrder(int index)
{
    int counter = 0;
    nthPreOrder(root, index, counter);
}

void Tree::nthPreOrder(Node *node, int index, int& counter)
{
    if (node != nullptr)
    {
        counter++;
        if (counter == index)
        {
            std::cout << " " << node->value;
        }
        nthPreOrder(node->lChild, index, counter);
        nthPreOrder(node->rChild, index, counter);
    }
}

void Tree::printPostOrder()
{
    printPostOrder(root);
}

void Tree::printPostOrder(Node *node)
{
    if (node != nullptr)
    {
        printPostOrder(node->lChild);
        printPostOrder(node->rChild);
        std::cout << " " << node->value;
    }
}

void Tree::nthPostOrder(int index)
{
    int counter = 0;
    nthPostOrder(root, index, counter);
}

void Tree::nthPostOrder(Node *node, int index, int& counter)
{
    if (node != nullptr)
    {
        nthPostOrder(node->lChild, index, counter);
        nthPostOrder(node->rChild, index, counter);
        counter++;
        if (counter == index)
        {
            std::cout << " " << node->value;
        }
    }
}

void Tree::printInOrder()
{
    printInOrder(root);
}

void Tree::printInOrder(Node *node)
{
    if (node != nullptr)
    {
        printInOrder(node->lChild);
        std::cout << " " << node->value;
        printInOrder(node->rChild);
    }
}

void Tree::nthInOrder(int index)
{
    int counter = 0;
    nthInOrder(root, index, counter);
}

void Tree::nthInOrder(Node *node, int index, int& counter)
{
    if (node != nullptr)
    {
        nthInOrder(node->lChild, index, counter);
        counter++;
        if (counter == index)
        {
            std::cout << " " << node->value;
        }
        nthInOrder(node->rChild, index, counter);
    }
}

void Tree::printBredthFirst()
{
    std::queue<Node*> que;
    Node *temp;

    if (root != nullptr)
    {
        que.push(root);
    }

    while (que.empty() == false)
    {
        temp = que.front();
        que.pop();
        std::cout << temp->value << std::endl;

        if (temp->lChild != nullptr)
        {
            que.push(temp->lChild);
        }
        if (temp->rChild != nullptr)
        {
            que.push(temp->rChild);
        }
    }
}

void Tree::printDepthFirst()
{
    std::stack<Node*> stk;
    Node *temp;

    if (root != nullptr)
    {
        stk.push(root);
    }

    while (stk.empty() == false)
    {
        temp = stk.top();
        stk.pop();
        std::cout << temp->value << std::endl;

        if (temp->lChild != nullptr)
        {
            stk.push(temp->lChild);
        }
        if (temp->rChild != nullptr)
        {
            stk.push(temp->rChild);
        }
    }
}


void Tree::printLevelOrderLineByLine()
{
    std::queue<Node*> que1;
    std::queue<Node*> que2;
    Node* temp = nullptr;
    if (root != nullptr)
        que1.push(root);
    while (que1.size() != 0 || que2.size() != 0)
    {
        while (que1.size() != 0)
        {
            temp = que1.front();
            que1.pop();
            std::cout << " " << temp->value;
            if (temp->lChild != nullptr)
                que2.push(temp->lChild);
            if (temp->rChild != nullptr)
                que2.push(temp->rChild);
        }
        std::cout << std::endl;

        while (que2.size() != 0)
        {
            temp = que2.front();
            que2.pop();
            std::cout << " " << temp->value;
            if (temp->lChild != nullptr)
                que1.push(temp->lChild);
            if (temp->rChild != nullptr)
                que1.push(temp->rChild);
        }
        std::cout << std::endl;
    }
}

void Tree::printLevelOrderLineByLine2()
{
    std::queue<Node*> que;
    Node* temp = nullptr;
    int count = 0;

    if (root != nullptr)
        que.push(root);
    while (que.size() != 0)
    {
        count = que.size();
        while (count > 0)
        {
            temp = que.front();
            que.pop();
            std::cout << " " << temp->value;
            if (temp->lChild != nullptr)
                que.push(temp->lChild);
            if (temp->rChild != nullptr)
                que.push(temp->rChild);
            count -= 1;
        }
        std::cout << std::endl;
    }
}

void Tree::printSpiralTree()
{
    std::stack<Node*> stk1;
    std::stack<Node*> stk2;

    Node* temp;
    if (root != nullptr)
        stk1.push(root);

    while (stk1.empty() == false ||
            stk2.empty() == false)
    {
        while (stk1.empty() == false)
        {
            temp = stk1.top();
            stk1.pop();
            std::cout << temp->value << " ";
            if (temp->rChild != nullptr)
                stk2.push(temp->rChild);
            if (temp->lChild != nullptr)
                stk2.push(temp->lChild);
        }
        while (stk2.empty() == false)
        {
            temp = stk2.top();
            stk2.pop();
            std::cout << temp->value << " ";
            if (temp->lChild != nullptr)
                stk1.push(temp->lChild);
            if (temp->rChild != nullptr)
                stk1.push(temp->rChild);
        }
    }
}

bool Tree::find(int value)
{
    Node *curr = root;

    while (curr != nullptr)
    {
        if (curr->value == value)
        {
            return true;
        }
        else if (curr->value > value)
        {
            curr = curr->lChild;
        }
        else
        {
            curr = curr->rChild;
        }
    }
    return false;
}

bool Tree::find2(int value)
{
    Node *curr = root;
    while (curr != nullptr && curr->value != value)
    {
        curr = (curr->value > value) ? curr->lChild : curr->rChild;
    }
    return curr != nullptr;
}

int Tree::findMin()
{
    Node *node = root;
    if (node == nullptr)
    {
        throw ("EmptyTreeException");
    }

    while (node->lChild != nullptr)
    {
        node = node->lChild;
    }
    return node->value;
}

int Tree::findMax()
{
    Node *node = root;
    if (node == nullptr)
    {
        throw ("EmptyTreeException");
    }

    while (node->rChild != nullptr)
    {
        node = node->rChild;
    }
    return node->value;
}

Tree::Node *Tree::findMax(Node *curr)
{
    Node *node = curr;
    if (node == nullptr)
    {
        throw ("EmptyTreeException");
    }

    while (node->rChild != nullptr)
    {
        node = node->rChild;
    }
    return node;
}

Tree::Node *Tree::findMin(Node *curr)
{
    Node *node = curr;
    if (node == nullptr)
    {
        throw ("EmptyTreeException");
    }

    while (node->lChild != nullptr)
    {
        node = node->lChild;
    }
    return node;
}

void Tree::free()
{
    freeTree(root);
    root = nullptr;
}

void Tree::freeTree(Node* node)
{
    if (node)
    {
        freeTree(node->lChild);
        freeTree(node->rChild);
        delete(node);
    }
}


void Tree::deleteNode(int value)
{
    root = deleteNode(root, value);
}

Tree::Node *Tree::deleteNode(Node *node, int value)
{
    Node *temp = nullptr;

    if (node != nullptr)
    {
        if (node->value == value)
        {
            if (node->lChild == nullptr && node->rChild == nullptr)
            {
                delete node;
                return nullptr;
            }
            else
            {
                if (node->lChild == nullptr)
                {
                    temp = node->rChild;
                    delete node;
                    return temp;
                }

                if (node->rChild == nullptr)
                {
                    temp = node->lChild;
                    delete node;
                    return temp;
                }

                Node *maxNode = findMax(node->lChild);
                int maxValue = maxNode->value;
                node->value = maxValue;
                node->lChild = deleteNode(node->lChild, maxValue);
            }
        }
        else
        {
            if (node->value > value)
            {
                node->lChild = deleteNode(node->lChild, value);
            }
            else
            {
                node->rChild = deleteNode(node->rChild, value);
            }
        }
    }
    return node;
}

int Tree::treeDepth()
{
    return treeDepth(root);
}

int Tree::treeDepth(Node *root)
{
    if (root == nullptr)
        return 0;

    int lDepth = treeDepth(root->lChild);
    int rDepth = treeDepth(root->rChild);

    if (lDepth > rDepth)
        return lDepth + 1;
    else
        return rDepth + 1;
}

bool Tree::isEqual(Tree *T2)
{
    return identical(root, T2->root);
}

bool Tree::identical(Node *node1, Node *node2)
{
    if (node1 == nullptr && node2 == nullptr)
        return true;
    else if (node1 == nullptr || node2 == nullptr)
        return false;
    else
        return (identical(node1->lChild, node2->lChild) &&
                identical(node1->rChild, node2->rChild) &&
                (node1->value == node2->value));
}

Tree::Node *Tree::ancestor(int first, int second)
{
    if (first > second)
    {
        int temp = first;
        first = second;
        second = temp;
    }
    return ancestor(root, first, second);
}

Tree::Node *Tree::ancestor(Node *curr, int first, int second)
{
    if (curr == nullptr)
        return nullptr;

    if (curr->value > first && curr->value > second)
    {
        return ancestor(curr->lChild, first, second);
    }
    if (curr->value < first && curr->value < second)
    {
        return ancestor(curr->rChild, first, second);
    }
    return curr;
}

Tree *Tree::copyTree()
{
    Tree *tree2 = new Tree();
    tree2->root = copyTree(root);
    return tree2;
}

Tree::Node *Tree::copyTree(Node *curr)
{
    Node *temp;
    if (curr != nullptr)
    {
        temp = new Node(curr->value);
        temp->lChild = copyTree(curr->lChild);
        temp->rChild = copyTree(curr->rChild);
        return temp;
    }
    else
    {
        return nullptr;
    }
}

Tree *Tree::copyMirrorTree()
{
    Tree *tree2 = new Tree();
    tree2->root = copyMirrorTree(root);
    return tree2;
}

Tree::Node *Tree::copyMirrorTree(Node *curr)
{
    Node *temp;
    if (curr != nullptr)
    {
        temp = new Node(curr->value);
        temp->rChild = copyMirrorTree(curr->lChild);
        temp->lChild = copyMirrorTree(curr->rChild);
        return temp;
    }
    else
    {
        return nullptr;
    }
}

int Tree::numNodes()
{
    return numNodes(root);
}

int Tree::numNodes(Node *curr)
{
    if (curr == nullptr)
    {
        return 0;
    }
    else
    {
        return (1 + numNodes(curr->rChild) + numNodes(curr->lChild));
    }
}

int Tree::numFullNodesBT()
{
    return numNodes(root);
}

int Tree::numFullNodesBT(Node *curr)
{
    int count;
    if (curr == nullptr)
        return 0;

    count = numFullNodesBT(curr->rChild) + numFullNodesBT(curr->lChild);
    if (curr->rChild != nullptr && curr->lChild != nullptr)
        count++;

    return count;
}

int Tree::maxLengthPathBT()
{
    return maxLengthPathBT(root);
}

int Tree::maxLengthPathBT(Node *curr)
{
    int max;
    int leftPath, rightPath;
    int leftMax, rightMax;

    if (curr == nullptr)
        return 0;

    leftPath = treeDepth(curr->lChild);
    rightPath = treeDepth(curr->rChild);

    max = leftPath + rightPath + 1;

    leftMax = maxLengthPathBT(curr->lChild);
    rightMax = maxLengthPathBT(curr->rChild);

    if (leftMax > max)
        max = leftMax;

    if (rightMax > max)
        max = rightMax;

    return max;
}

int Tree::numLeafNodes()
{
    return numLeafNodes(root);
}

int Tree::numLeafNodes(Node *curr)
{
    if (curr == nullptr)
    {
        return 0;
    }
    if (curr->lChild == nullptr && curr->rChild == nullptr)
    {
        return 1;
    }
    else
    {
        return (numLeafNodes(curr->rChild) + numLeafNodes(curr->lChild));
    }
}

int Tree::sumAllBT()
{
    return sumAllBT(root);
}

int Tree::sumAllBT(Node *curr)
{
    int sum, leftSum, rightSum;
    if (curr == nullptr)
        return 0;

    rightSum = sumAllBT(curr->rChild);
    leftSum = sumAllBT(curr->lChild);
    sum = rightSum + leftSum + curr->value;
    return sum;
}

void Tree::iterativePreOrder()
{
    std::stack<Node*> stk;
    Node *curr;

    if (root != nullptr)
        stk.push(root);

    while (stk.empty() == false)
    {
        curr = stk.top();
        stk.pop();
        std::cout << curr->value << " ";

        if (curr->rChild != nullptr)
            stk.push(curr->rChild);

        if (curr->lChild != nullptr)
            stk.push(curr->lChild);
    }
}

void Tree::iterativePostOrder()
{
    std::stack<Node*> stk;
    std::stack<int> visited;
    Node *curr;
    int vtd;

    if (root != nullptr)
    {
        stk.push(root);
        visited.push(0);
    }

    while (stk.empty() == false)
    {
        curr = stk.top();
        stk.pop();
        vtd = visited.top();
        visited.pop();
        if (vtd == 1)
        {
            std::cout << curr->value << " ";
        }
        else
        {
            stk.push(curr);
            visited.push(1);
            if (curr->rChild != nullptr)
            {
                stk.push(curr->rChild);
                visited.push(0);
            }
            if (curr->lChild != nullptr)
            {
                stk.push(curr->lChild);
                visited.push(0);
            }
        }
    }
}

void Tree::iterativeInOrder()
{
    std::stack<Node*> stk;
    std::stack<int> visited;
    Node *curr;
    int vtd;

    if (root != nullptr)
    {
        stk.push(root);
        visited.push(0);
    }

    while (stk.empty() == false)
    {
        curr = stk.top();
        stk.pop();
        vtd = visited.top();
        visited.pop();
        if (vtd == 1)
        {
            std::cout << curr->value;
        }
        else
        {
            if (curr->rChild != nullptr)
            {
                stk.push(curr->rChild);
                visited.push(0);
            }
            stk.push(curr);
            visited.push(1);
            if (curr->lChild != nullptr)
            {
                stk.push(curr->lChild);
                visited.push(0);
            }
        }
    }
}

bool Tree::isBST3(Node *root)
{
    if (root == nullptr)
    {
        return true;
    }
    if (root->lChild != nullptr && findMax(root->lChild)->value > root->value)
    {
        return false;
    }
    if (root->rChild != nullptr && findMin(root->rChild)->value <= root->value)
    {
        return false;
    }
    return (isBST3(root->lChild) && isBST3(root->rChild));
}

bool Tree::isBST()
{
    return isBST(root, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
}

bool Tree::isBST(Node *curr, int min, int max)
{
    if (curr == nullptr)
        return true;

    if (curr->value < min || curr->value > max)
        return false;

    return isBST(curr->lChild, min, curr->value) && isBST(curr->rChild, curr->value, max);
}

bool Tree::isBST2()
{
    int c;
    return isBST2(root, c);
}

bool Tree::isBST2(Node *root, int& count)
{
    bool ret;
    if (root != nullptr)
    {
        ret = isBST2(root->lChild, count);
        if (!ret)
            return false;

        if (count > root->value)
            return false;

        count = root->value;

        ret = isBST2(root->rChild, count);
        if (!ret)
            return false;
    }
    return true;
}


bool Tree::isCompleteTree()
{
    std::queue<Node*> que;
    Node* temp = nullptr;
    int noChild = 0;
    if (root != nullptr)
        que.push(root);
    while (que.size() != 0)
    {
        temp = que.front();
        que.pop();
        if (temp->lChild != nullptr)
        {
            if (noChild == 1)
                return false;
            que.push(temp->lChild);
        }
        else
            noChild = 1;

        if (temp->rChild != nullptr)
        {
            if (noChild == 1)
                return false;
            que.push(temp->rChild);
        }
        else
            noChild = 1;
    }
    return true;
}

bool Tree::isCompleteTreeUtil(Node* curr, int index, int count)
{
    if (curr == nullptr)
        return true;
    if (index > count)
        return false;
    return isCompleteTreeUtil(curr->lChild, index * 2 + 1, count)
           && isCompleteTreeUtil(curr->rChild, index * 2 + 2, count);
}

bool Tree::isCompleteTree2()
{
    int count = numNodes();
    return isCompleteTreeUtil(root, 0, count);
}

bool Tree::isHeapUtil(Node* curr, int parentValue)
{
    if (curr == nullptr)
        return true;
    if (curr->value < parentValue)
        return false;
    return (isHeapUtil(curr->lChild, curr->value) && isHeapUtil(curr->rChild, curr->value));
}

bool Tree::isHeap()
{
    int infi = -9999999;
    return (isCompleteTree() && isHeapUtil(root, infi));
}

bool Tree::isHeapUtil2(Node* curr, int index, int count, int parentValue)
{
    if (curr == nullptr)
        return true;
    if (index > count)
        return false;
    if (curr->value < parentValue)
        return false;
    return isHeapUtil2(curr->lChild, index * 2 + 1, count, curr->value)
           && isHeapUtil2(curr->rChild, index * 2 + 2, count, curr->value);
}

bool Tree::isHeap2()
{
    int count = numNodes();
    int parentValue = -9999999;
    return isHeapUtil2(root, 0, count, parentValue);
}


Tree::Node *Tree::treeToListRec()
{
    Node *head = treeToListRec(root);
    Node *temp = head;
    return temp;
}

Tree::Node *Tree::treeToListRec(Node *curr)
{
    Node *Head = nullptr, *Tail = nullptr;
    if (curr == nullptr)
        return nullptr;

    if (curr->lChild == nullptr && curr->rChild == nullptr)
    {
        curr->lChild = curr;
        curr->rChild = curr;
        return curr;
    }

    if (curr->lChild != nullptr)
    {
        Head = treeToListRec(curr->lChild);
        Tail = Head->lChild;

        curr->lChild = Tail;
        Tail->rChild = curr;
    }
    else
    {
        Head = curr;
    }

    if (curr->rChild != nullptr)
    {
        Node *tempHead = treeToListRec(curr->rChild);
        Tail = tempHead->lChild;

        curr->rChild = tempHead;
        tempHead->lChild = curr;
    }
    else
    {
        Tail = curr;
    }

    Head->lChild = Tail;
    Tail->rChild = Head;
    return Head;
}

void Tree::printAllPath()
{
    std::vector<int> stk;
    printAllPath(root, stk);
}

void Tree::printAllPath(Node *curr, std::vector<int> &stk)
{
    if (curr == nullptr)
        return;

    stk.push_back(curr->value);

    if (curr->lChild == nullptr && curr->rChild == nullptr)
    {
        for (int i = 0; i < stk.size(); i++)
            std::cout << stk[i] << " ";
        stk.pop_back();
        std::cout << std::endl;
        return;
    }

    printAllPath(curr->rChild, stk);
    printAllPath(curr->lChild, stk);
    stk.pop_back();
}

int Tree::lca(int first, int second)
{
    Node *ans = lca(root, first, second);
    if (ans != nullptr)
    {
        return ans->value;
    }
    else
    {
        throw ("NotFoundException");
    }
}

Tree::Node *Tree::lca(Node *curr, int first, int second)
{
    Node *left, *right;

    if (curr == nullptr)
    {
        return nullptr;
    }

    if (curr->value == first || curr->value == second)
    {
        return curr;
    }

    left = lca(curr->lChild, first, second);
    right = lca(curr->rChild, first, second);

    if (left != nullptr && right != nullptr)
    {
        return curr;
    }
    else if (left != nullptr)
    {
        return left;
    }
    else
    {
        return right;
    }
}

int Tree::lcaBST(int first, int second)
{
    return lcaBST(root, first, second);
}

int Tree::lcaBST(Node *curr, int first, int second)
{
    if (curr == nullptr)
    {
        throw ("NotFoundException");
    }

    if (curr->value > first && curr->value > second)
    {
        return lcaBST(curr->lChild, first, second);
    }
    if (curr->value < first && curr->value < second)
    {
        return lcaBST(curr->rChild, first, second);
    }
    return curr->value;
}

void Tree::trimOutsideRange(int min, int max)
{
    trimOutsideRange(root, min, max);
}

Tree::Node *Tree::trimOutsideRange(Node *curr, int min, int max)
{
    if (curr == nullptr)
        return nullptr;

    curr->lChild = trimOutsideRange(curr->lChild, min, max);
    curr->rChild = trimOutsideRange(curr->rChild, min, max);

    if (curr->value < min)
        return curr->rChild;

    if (curr->value > max)
        return curr->lChild;

    return curr;
}

void Tree::printInRange(int min, int max)
{
    printInRange(root, min, max);
}

void Tree::printInRange(Node *root, int min, int max)
{
    if (root == nullptr)
        return;

    printInRange(root->lChild, min, max);

    if (root->value >= min && root->value <= max)
        std::cout << root->value << " ";

    printInRange(root->rChild, min, max);
}

int Tree::floorBST(int val)
{
    Node *curr = root;
    int floor = std::numeric_limits<int>::max();

    while (curr != nullptr)
    {
        if (curr->value == val)
        {
            floor = curr->value;
            break;
        }
        else if (curr->value > val)
        {
            curr = curr->lChild;
        }
        else
        {
            floor = curr->value;
            curr = curr->rChild;
        }
    }
    return floor;
}

int Tree::ceilBST(int val)
{
    Node *curr = root;
    int ceil = std::numeric_limits<int>::min();

    while (curr != nullptr)
    {
        if (curr->value == val)
        {
            ceil = curr->value;
            break;
        }
        else if (curr->value > val)
        {
            ceil = curr->value;
            curr = curr->lChild;
        }
        else
        {
            curr = curr->rChild;
        }
    }
    return ceil;
}

int Tree::findMaxBT()
{
    int ans = findMaxBT(root);
    return ans;
}

int Tree::findMaxBT(Node *curr)
{
    int left, right;
    if (curr == nullptr)
        return std::numeric_limits<int>::min();

    int max = curr->value;
    left = findMaxBT(curr->lChild);
    right = findMaxBT(curr->rChild);
    if (left > max)
        max = left;

    if (right > max)
        max = right;
    return max;
}

bool Tree::searchBT(Node *root, int value)
{
    bool left, right;

    if (root == nullptr || root->value == value)
        return false;

    left = searchBT(root->lChild, value);
    if (left)
        return true;

    right = searchBT(root->rChild, value);
    if (right)
        return true;

    return false;
}

void Tree::createBinaryTree(int arr[], int size)
{
    root = createBinaryTree(arr, 0, size - 1);
}

Tree::Node *Tree::createBinaryTree(int arr[], int start, int end)
{
    Node *curr = nullptr;
    if (start > end)
        return nullptr;

    int mid = (start + end) / 2;
    curr = new Node(arr[mid]);
    curr->lChild = createBinaryTree(arr, start, mid - 1);
    curr->rChild = createBinaryTree(arr, mid + 1, end);
    return curr;
}

bool isBSTArray(int preorder[], int size)
{
    std::stack<int> stk;
    int value;
    int root = -999999;
    for (int i = 0; i < size; i++)
    {
        value = preorder[i];

        // If value of the right child is less than root.
        if (value < root)
            return false;
        // First left child values will be popped
        // Last popped value will be the root.
        while (stk.size() > 0 && stk.top() < value)
        {
            root = stk.top();
            stk.pop();
        }
        // add current value to the stack.
        stk.push(value);
    }
    return true;
}
