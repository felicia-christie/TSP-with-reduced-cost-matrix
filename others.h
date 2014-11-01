#include <deque>
#include <vector>
#include "matrix.h"
using namespace std;


typedef struct{
	Matrix Mx;
	vector<int> PassedStates;
	int currentCost;
}state;


bool IsIntMember(vector<int>, int);

void SortStates (deque <state>);
//void InsertState(deque<state>, state);
bool IsStateFinal(state);