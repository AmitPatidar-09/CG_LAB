#include<bits/stdc++.h>
using namespace std;

void Bresenhams(int x1, int y1, int x2, int y2)
{	

	int m_new = 2 * (y2 - y1);  					// m_new = 2 * del(y)
    int slope_error_new = m_new - (x2 - x1); 		// Slope_error_new = m_new - del(x)
   	for (int x = x1, y = y1; x <= x2; x++) {		// Loop till x <= x2. 
   													// x++ isliye ho rha h kyuki decision parameter jo bhi ho  next point x + 1 hi aayega.
   													// Dependancy Y pe h. 
        	cout << "(" << x << "," << y << ")\n";	

        // Add slope to increment angle formed
       		slope_error_new += m_new;

        // Slope error reached limit, time to
        // increment y and update slope error.
			if (slope_error_new >= 0) {
				y++;
				slope_error_new -= 2 * (x2 - x1);
			}
    }
}
int main(){
	int x1,y1,x2,y2;
	cout<<"Enter Initial Point : ";
	cin>>x1>>y1;
	cout<<endl;
	cout<<"Enter End point : ";
	cin>>x2>>y2;
	Bresenhams(x1, y1, x2, y2);
	return 0;
}
