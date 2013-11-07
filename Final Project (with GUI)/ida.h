#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <time.h>
#include <queue>
#include <stack>

using namespace std;

class ida {
private:
	struct tree_node{
                tree_node* link1;
                tree_node* link2;
                tree_node* link3;
                tree_node* link4;
                tree_node* parent;
                vector<int> state;
                int lastmove;
                int cost;
                int index;
                int distance;
	};
	vector<int> initial, final;
        vector<tree_node*> tacky;
	tree_node* root;
	int heuristic;
	int algorithm;
	bool success;
	int distanceArray[9][9];
	int fvalue;
	int check;
	int nextf;
	
public:
	ida() {
		root = NULL;
		nextf = 9999;
		check = 1;
	}

        queue<string> a;
        int solutionArray[35];
	
	bool isEmpty() const { return root==NULL; }
	void insert(tree_node*);
	void makeRoot(vector<int>);
        void build(string input, int h);
        void read(int algo, string conf);
	void makeMove(tree_node*, tree_node*, char);
	void print(tree_node*);
	void pv(tree_node*);
	void checkSuccess(tree_node*);
	int costCalculator(tree_node*,int j);
	bool checkSolvability();
	void sort();
        string convertInt(int n);
};
