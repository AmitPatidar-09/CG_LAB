#include<bits/stdc++.h>
using namespace std;

int main()
{
	int x1, y1, x2, y2;
	cout << "Enter Point 1 : ";
	cin > x1 >> y1;
	cout << endl;
	cout << "Enter Point 2 : ";
	cin >> x2 >> y2;
	
	float slope = ((y2 - y1) * 1.0) / (x2 - x1);
	
	cout << "The Slope is " << slope << endl;
	return 0;
}
