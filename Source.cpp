#include <SFML\Graphics.hpp>
#include "matrix.h"
#include <iostream>
#include <ctime>
#include "others.h"
#include <deque>

using namespace std;
using namespace sf;

int main(){
	deque<state> Test;
	state FState;
	Matrix X;
	X.InputMatrix();

	clock_t T;
	X.Print();
	//cout << endl;
	//cout << X.LeastValue('V', 1) << endl;
	//cout << X.LeastValue('H', 2) << endl;
	//cout << X.CRD() << endl;

	// akar
	static int NodeCount = 0;
	state Z;
	Z.Mx = X;
	Z.PassedStates.push_back(0);
	Z.currentCost = Z.Mx.VCostReduce();
	Z.Mx = Z.Mx.CostReducing();



	int mothernode = 0;
	int firstnode = 0;
	Test.push_back(Z);
	NodeCount++;
	int temp = 0;
	T = clock();
	//cout << "Size is = " << Test.size() << endl;

	//loop ke cabang-cabang

	while (Test.size() != 0){

		for (int i = 1; i < X.i; i++){
			
			/* for (int A = 0; A < Test[mothernode].PassedStates.size(); A++)
				cout << Test[mothernode].PassedStates[A] << " "; */
			//cout << endl << "check " << i << " in PassedStates" << endl;
			if (IsIntMember(Test[mothernode].PassedStates, i)){
				
			}
			else {
			cout << "Value of i = " << i << endl;
			state tempstate;
			tempstate.Mx = (Test[mothernode]).Mx;
			tempstate.PassedStates = Test[mothernode].PassedStates;
			tempstate.currentCost = Test[mothernode].currentCost;
			int temp = (Test[mothernode]).PassedStates.back();
			tempstate.Mx = tempstate.Mx.NullMatrix('H', temp);
			tempstate.Mx = tempstate.Mx.NullMatrix('V', i);
			tempstate.Mx.M[i][0] = 999;
			
			tempstate.Mx.Print();
			cout << "Previous cost = " << tempstate.currentCost << endl;
			
			if (Test[firstnode].Mx.M[Test[mothernode].PassedStates.back()][i] != 999){
				cout << tempstate.currentCost << "+" << Test[firstnode].Mx.M[Test[mothernode].PassedStates.back()][i] << "+" << tempstate.Mx.VCostReduce() << endl;
				tempstate.currentCost = tempstate.currentCost + Test[firstnode].Mx.M[Test[mothernode].PassedStates.back()][i] + tempstate.Mx.VCostReduce();
				}
			else{
				cout << tempstate.currentCost << "+" << tempstate.Mx.VCostReduce() << endl;
				tempstate.currentCost = tempstate.currentCost  + tempstate.Mx.VCostReduce();
			}
			cout << "Current cost = " << tempstate.currentCost << endl;
			
			(tempstate.PassedStates).push_back(i);
			tempstate.Mx = tempstate.Mx.CostReducing();
			tempstate.Mx.Print();

			cout << endl;
			Test.push_back(tempstate);
			for (int i = 0; i < Test.size(); i++){
				for (int j = i; j < Test.size(); j++){
					if (Test[i].currentCost > Test[j].currentCost){
						//switch
						state stemp;
						stemp = Test[i];
						Test[i] = Test[j];
						Test[j] = stemp;
						
					}
				}
			}
			NodeCount++;
			
			}
		}

		if (IsStateFinal(Test.front())){
			FState = Test.front();

			while (Test.size() != 0){
				//if (Test.front().currentCost > FState.currentCost)
					//NodeCount--;
				Test.pop_front();
			}
		}
		else
			Test.pop_front();


	}
	clock_t T2;
	T2 = clock();

	cout << "NodeCount : " << NodeCount << endl;
	cout << "Total cost : " << FState.currentCost << endl;
	cout << "States Passed : ";
	for (int A = 0; A < FState.PassedStates.size(); A++)
		cout << FState.PassedStates[A] + 1 << " ";
	cout << endl;
	cout << "Total time : " << (((float)(T2 - T))/CLOCKS_PER_SEC) << "sec." << endl;
	RenderWindow Display(VideoMode(800, 600), "GUI Window");
	sf::Vertex vertices[] =
	{
	    sf::Vertex(sf::Vector2f(  0,   0), sf::Color::Red, sf::Vector2f( 0,  0)),
	    sf::Vertex(sf::Vector2f(  0, 100), sf::Color::Red, sf::Vector2f( 0, 10)),
		sf::Vertex(sf::Vector2f(100, 100), sf::Color::Red, sf::Vector2f(10, 10)),
		sf::Vertex(sf::Vector2f(100,   0), sf::Color::Red, sf::Vector2f(10,  0))
	};

	// draw it

	while (Display.isOpen()){
		Event E;
		while (Display.pollEvent(E)){
			if (E.type == Event::Closed)
				Display.close();
		}

		Display.clear();
		Display.draw(vertices, 4, sf::LinesStrip);
		Display.display();
	}

	return 0;
}