#include "a.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <time.h>
#include <stack>

using namespace std;

void a::build(string input, int h)
{
        read(h, input);
	makeRoot(initial);
	success = false;
	tree_node* curr;
	heuristic = 1;
	
	int count = 0;
        while (tacky.size() > 0) {
                curr = tacky.front();
                tacky.erase(tacky.begin());
		insert(curr);
		
		if (curr->distance > count) {
			count = curr->distance;
			cout << "n = " << count << endl;
		}
	}
}
void a::read(int algo, string conf) {
	/*    ifstream        inFile ("in.txt");
	 string            line,
	 item;
	 int                itemnum = 0;
	 
	 while (getline (inFile, line)) {
	 istringstream linestream(line);
	 while (getline (linestream, item, ' ')) {
	 itemnum++;
	 if (itemnum <= 9) {
	 initial.push_back(atoi(item.c_str()));
	 
	 }
	 else {
	 final.push_back(atoi(item.c_str()));
	 }
	 }
	 }*/
    int i,j;
    cout<<"Input for initial configuration"<<endl;
    string stemp;
    stemp = "0";
    for (i = 0; i < 9; i++)
    {
        j = (int)conf[2*i] - (int)stemp[0];
        initial.push_back(j);
        cout<<j<<" ";
    }
    cout<<endl;

    if (!checkSolvability()) {
            cout << "Puzzle is not sovable"<<endl;
            exit(0);
    }
    //cout<<"Input for goal configuration"<<endl;
    while (i < 17)
    {
            j = i - 8;
            final.push_back(j);
            i++;
    }
    final.push_back(0);

    algorithm = (algo == 0) ? 2 : 1;

	for (int i=1; i<9; i++) {
		distanceArray[0][i] = 0;
		distanceArray[i][i-1] = 0;
	}
	distanceArray[0][0] = 0;
	
	distanceArray[1][1] = 1;
	distanceArray[1][2] = 2;
	distanceArray[1][3] = 1;
	distanceArray[1][4] = 2;
	distanceArray[1][5] = 3;
	distanceArray[1][6] = 2;
	distanceArray[1][7] = 3;
	distanceArray[1][8] = 4;
	
	distanceArray[2][0] = 1;
	distanceArray[2][2] = 1;
	distanceArray[2][3] = 2;
	distanceArray[2][4] = 1;
	distanceArray[2][5] = 2;
	distanceArray[2][6] = 3;
	distanceArray[2][7] = 2;
	distanceArray[2][8] = 3;
	
	distanceArray[3][0] = 2;
	distanceArray[3][1] = 1;
	distanceArray[3][3] = 3;
	distanceArray[3][4] = 2;
	distanceArray[3][5] = 1;
	distanceArray[3][6] = 4;
	distanceArray[3][7] = 3;
	distanceArray[3][8] = 2;
	
	distanceArray[4][0] = 1;
	distanceArray[4][1] = 2;
	distanceArray[4][2] = 3;
	distanceArray[4][4] = 1;
	distanceArray[4][5] = 2;
	distanceArray[4][6] = 1;
	distanceArray[4][7] = 2;
	distanceArray[4][8] = 3;
	
	distanceArray[5][0] = 2;
	distanceArray[5][1] = 1;
	distanceArray[5][2] = 2;
	distanceArray[5][3] = 1;
	distanceArray[5][5] = 1;
	distanceArray[5][6] = 2;
	distanceArray[5][7] = 1;
	distanceArray[5][8] = 2;
	
	distanceArray[6][0] = 3;
	distanceArray[6][1] = 2;
	distanceArray[6][2] = 1;
	distanceArray[6][3] = 2;
	distanceArray[6][4] = 1;
	distanceArray[6][6] = 3;
	distanceArray[6][7] = 2;
	distanceArray[6][8] = 1;
	
	distanceArray[7][0] = 2;
	distanceArray[7][1] = 3;
	distanceArray[7][2] = 4;
	distanceArray[7][3] = 1;
	distanceArray[7][4] = 2;
	distanceArray[7][5] = 3;
	distanceArray[7][7] = 1;
	distanceArray[7][8] = 2;
	
	distanceArray[8][0] = 3;
	distanceArray[8][1] = 2;
	distanceArray[8][2] = 3;
	distanceArray[8][3] = 2;
	distanceArray[8][4] = 1;
	distanceArray[8][5] = 3;
	distanceArray[8][6] = 1;
	distanceArray[8][8] = 1;

}
void a::makeRoot(vector<int> state) {
	tree_node* t1 = new tree_node;
	for (int i=0; i<state.size(); i++)
		t1->state.push_back(state[i]);
	t1->cost = costCalculator(t1,algorithm);
	t1->distance = 1;
	t1->link1 = NULL; t1->link2 = NULL; t1->link3 = NULL; t1->link4 = NULL;
	t1->parent = NULL;
	
	for (int i=0; i<state.size(); i++)
	{
		if (state[i] == 0)
		{
			t1->index = i;
		}
	}
	
	if(isEmpty()) {
		root = t1;
                tacky.push_back(root);
	}
}
int a::costCalculator(tree_node* t, int j) {
	int cost = 0;
	if(j==1){
                for (int i=0; i<t->state.size(); i++) {
			cost += distanceArray[t->state[i]][i];
		}
	}
	if (j==2) {
		for (int i=0; i<t->state.size(); i++) {
			if (t->state[i] != final[i]) {
				cost++;
			}
		}
	}
	
	return cost;
}
void a::makeMove(tree_node* curr, tree_node* t, char direction) {
	int temp, index;
	bool badMove = false;
	
	for (int i=0; i<curr->state.size(); i++) {
		if (curr->state[i] == 0) {
			index = i;
		}
		t->state.push_back(curr->state[i]);
	}
	t->index = index;
	
	if (curr->distance > 2) {
		if (index == curr->parent->index) {
			badMove = true;
		}
	}
	
	switch (direction) {
		case 'u' :
			if ((index > 2) && (!badMove)) {
				temp = t->state[index];
				t->state[index] = t->state[index-3];
				t->state[index-3] = temp;
			}
			else
				t->state.erase(t->state.begin(), t->state.end());
			break;
		case 'r' :
			if ((index%3 != 2) && (!badMove)) {
				temp = t->state[index];
				t->state[index] = t->state[index+1];
				t->state[index+1] = temp;
			}
			else
				t->state.erase(t->state.begin(), t->state.end());
			break;
		case 'd' :
			if ((index < 6) && (!badMove)) {
				temp = t->state[index];
				t->state[index] = t->state[index+3];
				t->state[index+3] = temp;
			}
			else
				t->state.erase(t->state.begin(), t->state.end());
			break;
		case 'l' :
			if ((index%3 != 0) && (!badMove)) {
				temp = t->state[index];
				t->state[index] = t->state[index-1];
				t->state[index-1] = temp;
			}
			else
				t->state.erase(t->state.begin(), t->state.end());
			break;
	}
}
void a::insert(tree_node* curr) {
	tree_node* t1 = new tree_node;
	makeMove(curr, t1, 'u');
	t1->distance = curr->distance + 1;
	t1->cost = costCalculator(t1,algorithm) + t1->distance;
	t1->link1 = NULL; t1->link2 = NULL; t1->link3 = NULL; t1->link4 = NULL;
	t1->parent = curr;
        t1->lastmove = 1;
	
	tree_node* t2 = new tree_node;
	makeMove(curr, t2, 'r');
	t2->distance = curr->distance + 1;
	t2->cost = costCalculator(t2,algorithm) + t2->distance;
	t2->link1 = NULL; t2->link2 = NULL; t2->link3 = NULL; t2->link4 = NULL;
	t2->parent = curr;
        t2->lastmove = 2;
	
	tree_node* t3 = new tree_node;
	makeMove(curr, t3, 'd');
	t3->distance = curr->distance + 1;
	t3->cost = costCalculator(t3,algorithm) + t3->distance;
	t3->link1 = NULL; t3->link2 = NULL; t3->link3 = NULL; t3->link4 = NULL;
	t3->parent = curr;
        t3->lastmove = 3;
	
	tree_node* t4 = new tree_node;
	makeMove(curr, t4, 'l');
	t4->distance = curr->distance + 1;
	t4->cost = costCalculator(t4,algorithm) + t4->distance;
	t4->link1 = NULL; t4->link2 = NULL; t4->link3 = NULL; t4->link4 = NULL;
	t4->parent = curr;
        t4->lastmove = 4;
	
	if ((curr->link1 == NULL) && (t1->state.size() > 0)) {
		curr->link1 = t1;
                if (!success) tacky.push_back(curr->link1);
	}
	else
		delete t1;
	if ((curr->link2 == NULL) && (t2->state.size() > 0)) {
		curr->link2 = t2;
                if (!success) tacky.push_back(curr->link2);
	}
	else
		delete t2;
	if ((curr->link3 == NULL) && (t3->state.size() > 0)) {
		curr->link3 = t3;
                if (!success) tacky.push_back(curr->link3);
	}
	else
		delete t3;
	if ((curr->link4 == NULL) && (t4->state.size() > 0)) {
		curr->link4 = t4;
                if (!success) tacky.push_back(curr->link4);
	}
	else
		delete t4;
	
	sort();
	checkSuccess(curr);
}
void a::sort() {
	tree_node* temp;
	
        for (int i=0; i<tacky.size()-1; i++) {
                for (int j=0; j<tacky.size()-1; j++) {
                        if (tacky[j]->cost > tacky[j+1]->cost) {
                                temp = tacky[j];
                                tacky[j] = tacky[j+1];
                                tacky[j+1] = temp;
			}
		}
	}
}
void a::checkSuccess(tree_node* curr) {
	bool    pass1 = true,
	pass2 = true,
	pass3 = true,
	pass4 = true;
	
	for (int i=0; i<final.size(); i++) {
		if (curr->link1 != NULL){
			if (curr->link1->state[i] != final[i])
				pass1 = false;
		}
		else
			pass1 = false;
		if (curr->link2 != NULL) {
			if (curr->link2->state[i] != final[i])
				pass2 = false;
		}
		else
			pass2 = false;
		if (curr->link3 != NULL) {
			if (curr->link3->state[i] != final[i])
				pass3 = false;
		}
		else
			pass3 = false;
		if (curr->link4 != NULL) {
			if (curr->link4->state[i] != final[i])
				pass4 = false;
		}
		else
			pass4 = false;
	}
	if (pass1) {
		success = true;
		cout << "Success!" << endl;
		print(curr->link1);
	}
	else if (pass2) {
		success = true;
		cout << "Success!" << endl;
		print(curr->link2);
	}
	else if (pass3) {
		success = true;
		cout << "Success!" << endl;
		print(curr->link3);
	}
	else if (pass4) {
		success = true;
		cout << "Success!" << endl;
		print(curr->link4);
	}
	
	if (success) {
                while (!tacky.empty())
                        tacky.erase(tacky.begin());
	}
}
void a::pv(tree_node* t) {
	for (int i=0; i<t->state.size(); i++) {
		cout << t->state[i] << " ";
		if (i%3 == 2) cout << endl;
	}
	cout << t->cost << " " << t->distance << endl;
	cout << endl;
}
/*void a::print(tree_node* t) {
	ofstream fout ("out.txt");
	vector<tree_node*> v;
	while (t != NULL) {
		v.push_back(t);
		t = t->parent;
	}
	fout << "Initial State" << endl;
	for (int j=v.size()-1; j>=0; j--) {
		for (int i=0; i<v[j]->state.size(); i++) {
			if (v[j]->state[i] == 0)
				fout << "B ";
			else
				fout << v[j]->state[i] << " ";
			if (i%3 == 2) fout << endl;
		}
		fout << endl;
	}
	fout << "Goal State" << endl;
	fout.close();
}*/

void a::print(tree_node* t){
	vector<tree_node*> v;
	while (t != NULL) {
		v.push_back(t);
		t = t->parent;
	}
        string s;
        for(int i=0;i<35;i++){
            solutionArray[i]=0;
        }
        cout << "Initial State" << endl;
        for (int j=v.size()-1; j>=0; j--) {

                s = "";
                solutionArray[j] = v[j]->lastmove;
                for (int i=0; i<v[j]->state.size(); i++) {
                        cout << v[j]->state[i] << " ";
                        //char temp[2];
                        //sprintf(temp,"%d ", v[j]->state[i]);
                        string temp = convertInt(v[j]->state[i])+" ";
                        s.append(temp);
                        if (i%3 == 2) cout << endl;
                }
                cout << endl;
                //cout << s <<endl;
                sresult.push(s);
        }
	cout << "Goal State" << endl;
}

bool a::checkSolvability(){
	int sum = 0;
	int count;
	for (int i = 0; i<9; i++) {
		count = 0;
		for (int j=i; j<9; j++) {
			if((initial.at(j) < initial[i]) && (initial[j] != 0)) count++;
		}
		sum = sum + count;
	}
        if(sum%2==0) {
		return true;
	}
	else return false;
}

string a::convertInt(int n){
    stringstream s;
    s<<n;
    return s.str();
}


