#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less


using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
        tree_order_statistics_node_update > PBDS;



#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define rep(i,j,n) for(int i = j; i < n ; i++ )
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()


typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))


// int temp[100000];
void solve();
int main() {
	fastio();
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif

	auto start1 = high_resolution_clock::now();
	int t = 1;
	// cin >> t;
	while (t--) solve();
	auto stop1 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop1 - start1);
#ifndef ONLINE_JUDGE
	cerr << "Time: " << duration . count() / 1000 << endl;
#endif

}


// vector<ll> prefix_sum(100001);

class node {
public:
	int data;
	node *left;
	node *right;

	node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};

void printBT(const std::string& prefix, const node* root, bool isLeft)
{
	if ( root != NULL )
	{
		cout << prefix;

		cout << (isLeft ? "├──" : "└──" );

		// print the value of the node
		cout << root->data << endl;

		// enter the next tree level - left and right branch
		printBT( prefix + (isLeft ? "│   " : "    "), root->left, true);
		printBT( prefix + (isLeft ? "│   " : "    "), root->right, false);
	}
}

//prints tree in pretty way
void printBT(const node* root)
{
	printBT("", root, false);
}

void printKthLevel(node *root, int k) {
	if (root == NULL)
		return;
	if (k == 1) {
		cout << root->data << " ";
		return;
	}
	printKthLevel(root->left, k - 1);
	printKthLevel(root->right, k - 1);

}

int heightOfTree(node* root) {
	if (root == NULL)
		return 0;
	return 1 + max(heightOfTree(root->left), heightOfTree(root->right));
}

void printAllLevel(node* root) {
	int height = heightOfTree(root);
	for (int i = 1; i <= height; i++)
		printKthLevel(root, i);


}




node* buildTree() {
	int d;
	cin >> d;

	if (d == -1)
		return NULL;
	node *root = new node(d);
	root->left = buildTree();
	root->right = buildTree();

	return root;


}

void bfs(node * root) {
	queue<node *> q;
	q.push(root);

	while (!q.empty()) {
		node *f = q.front();
		cout << f ->data << " ";
		if (f->left) q.push(f->left);
		if (f->right) q.push(f->right);
		q.pop();
	}
}


int diameter(node * root) {
	if (root == NULL)
		return 0;
	int h1 = heightOfTree(root->left);
	int h2 = heightOfTree(root->right);

	int op1 = h1 + h2;

	int op2 = diameter(root->left);
	int op3 = diameter(root->right);

	return max(op1, max(op2, op3));



}

class Pair {
public:
	int height;
	int diameter;
};

Pair fastDiameter(node*root) {
	Pair p;
	if (root == NULL) {
		p.diameter = p.height = 0;
		return p;
	}
	//Otherwise
	Pair left = fastDiameter(root->left);
	Pair right = fastDiameter(root->right);

	p.height = max(left.height, right.height) + 1;
	p.diameter = max(left.height + right.height, max(left.diameter, right.diameter));
	return p;
}

class Pair2 {
public:
	int height;
	bool isBalanced;
};

Pair2 isTreeHeightBalanced(node *root) {
	Pair2 p;
	if (root == NULL) {
		p.height = 0;
		p.isBalanced = true;
		return p;
	}
	Pair2 p1 = isTreeHeightBalanced(root->left);
	Pair2 p2 = isTreeHeightBalanced(root->right);

	int h1 = p1.height;
	int h2 = p2.height;

	p.height = 1 + max(h1, h2);

	if (abs(h1 - h2) <= 1 && p1.isBalanced && p2.isBalanced)
		p.isBalanced = true;
	else
		p.isBalanced = false;

	return p;


}

node* buildTreefromArray(int* arr, int s, int e) {
	if (s > e)
		return NULL;
	int mid = s + (e - s) / 2;
	node *root = new node(arr[mid]);
	root->left = buildTreefromArray(arr, s, mid - 1);
	root->right = buildTreefromArray(arr, mid + 1, e);
	return root;


}



void solve() {

	// node *root = buildTree();

	// printBT(root);
	// cout << nline;
	// printAllLevel(root);
	// cout << nline;
	// bfs(root);

	// cout << nline;
	// cout << diameter(root);
	// cout << nline;
	// Pair2 p = isTreeHeightBalanced(root);
	// cout << p.height << " " << p.isBalanced;
	int arr[] = {1, 2, 3, 4, 5, 6, 7};
	printBT(buildTreefromArray(arr, 0, 6));



}
