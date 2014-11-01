#include <deque>
#include "others.h"
#include <iostream>
using namespace std;

bool IsIntMember(vector<int> V, int X){
	bool found = false;
	int i = 0;
	int temp = V.size();
	while (!found && i < temp){
		if (V[i] == X)
			found = true;
		else
			i++;
	}

	return found;
}
void SortStates (deque <state> S){
	
	for (int i = 0; i < S.size(); i++){
		for (int j = i; j < S.size(); j++){
			if (S[i].currentCost > S[j].currentCost){
				//switch
				cout << "before switch icost = " << S[i].currentCost << endl << "before switch jcost = " << S[j].currentCost << endl;
				state stemp;
				stemp = S[i];
				S[i] = S[j];
				S[j] = stemp;
				
				cout << "after switch icost = " << S[i].currentCost << endl << "after switch jcost = " << S[j].currentCost << endl;
			}
		}
	}
}/*
void InsertState(deque <state> S, state X){
	int i = 0;
	cout << "InitialSize: " << S.size() << endl;
	S.push_back(X);
	int temp = S.size();
	cout << "FinalSize: " << S.size() << endl;
	cout << temp - 2 << ": " << S[temp-2].currentCost << endl;
	cout << temp - 1 << ": " << S[temp-1].currentCost << endl;

	for (int i = 0; i < temp; i++){
		for (int j = i; j < temp; j++){
			if (S[i].currentCost > S[j].currentCost){
				//switch
				cout << "before switch icost = " << S[i].currentCost << endl << "before switch jcost = " << S[j].currentCost << endl;
				state stemp;
				stemp = S[i];
				S[i] = S[j];
				S[j] = stemp;
				
				cout << "after switch icost = " << S[i].currentCost << endl << "after switch jcost = " << S[j].currentCost << endl;
			}
		}
	}
}
*/
bool IsStateFinal(state S){
	return (S.Mx.i == S.PassedStates.size());
}