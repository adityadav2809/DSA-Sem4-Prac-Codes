/*Given sequence k = k1<; k2<..... kn of n sorted keys, with a search probability
pi for each key ki . Build the Binary search tree that has the least search cost given
the access probability for each key. Test your program for following example
p1 = 3, p2 = 3, p3 = 1, p4 = 1
q0 = 2, q1 = 3, q2 = 1, q3= 1, q4 = 1
*/

#include <iostream>
#include <climits>
using namespace std;

const int N = 1e2;
int w[N][N];
int r[N][N];
int c[N][N];
int p[N];
int q[N];

int main() {
    cout << "ENTER NO. OF ELEMENTS: ";
    int n;
    cin >> n;
    cout << "ENTER SUCCESS PROB: \n";
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    cout << "ENTER UNSUCCESS: \n";
    for(int i = 0; i <= n; i++) {
        cin >> q[i];
    }
    for(int i = 0; i <= n; i++) {
        w[i][i] = q[i];
        r[i][i] = 0;
        c[i][i] = 0;
    }
    for(int i = 0; i < n; i++) {
        w[i][i+1] = q[i] + q[i+1] + p[i+1];
        r[i][i+1] = i+1;
        c[i][i+1] = q[i] + q[i+1] + p[i+1];
    }
    for(int d = 2; d <= n; d++) {
        for(int j = d; j <= n; j++) {
            int i = j - d;
            w[i][j] = w[i][j-1] + p[j] + q[j];
            int mn = INT_MAX;
            int mnk;
            for(int k = i+1; k <= j; k++) {
                int x = c[i][k-1] + c[k][j];
                if(x < mn) {
                    mn = x;
                    mnk = k;
                }
            }
            c[i][j] = w[i][j] + mn;
            r[i][j] = mnk;
        }
    }
    cout << endl;
    cout << "WEIGHT: " << w[0][n] << endl;
    cout << "COST: " << c[0][n] << endl;
    cout << "ROOT: " << r[0][n] << endl;
    int que[100];
    int front = 0, rear = -1;
    que[++rear] = 0;
    que[++rear] = n;
    que[++rear] = r[0][n];
    while(front <= rear) {
        int i = que[front++];
        int j = que[front++];
        int k = que[front++];
        if(r[i][k-1] != 0) {
            cout << "LEFT OF " << k << ": " << r[i][k-1] << endl;
            que[++rear] = i;
            que[++rear] = k-1;
            que[++rear] = r[i][k-1];
        }
        if(r[k][j] != 0) {
            cout << "RIGHT OF " << k << ": " << r[k][j] << endl;
            que[++rear] = k;
            que[++rear] = j;
            que[++rear] = r[k][j];
        }
    }
    return 0;
}
/*Here's the algorithm for the given program:

1. Include necessary libraries: Include `<iostream>` and `<climits>` for input-output operations and handling integer limits.
  
2. Declare constants and variables: Declare constants `N` for the maximum number of elements and variables `w`, `r`, `c`, `p`, and `q` for weights, roots, costs, success probabilities, and unsuccessful probabilities, respectively.

3. Read input:
   - Read the number of elements `n`.
   - Read the success probabilities `p[i]` for each element `i`.
   - Read the unsuccessful probabilities `q[i]` for each element `i`.

4. Initialize matrices:
   - Initialize matrices `w`, `r`, and `c` with appropriate sizes.
   - Initialize diagonal elements of `w`, `r`, and `c` matrices with corresponding `q[i]`, `0`, and `0`.

5. Calculate weights, roots, and costs:
   - Calculate weights `w[i][j]` for each pair of elements `i` and `j`.
   - Calculate roots `r[i][j]` for each pair of elements `i` and `j`.
   - Calculate costs `c[i][j]` for each pair of elements `i` and `j`.

6. Output results:
   - Output the total weight of the binary search tree.
   - Output the total cost of the binary search tree.
   - Output the root of the binary search tree.

7. Perform a breadth-first traversal to output the left and right children of each node in the binary search tree.

8. End.

This algorithm represents how the program works, including reading input, calculating weights, roots, and costs, outputting results, and performing a breadth-first traversal.*/
