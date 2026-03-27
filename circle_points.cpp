#include<bits/stdc++.h>
using namespace std;
int main()
{
int radius;
    cout << "Enter Radius Of the circle : ";
    cin >> radius;

    int x = 0;
    int y = radius;
    int dp = 1 - radius;

    while(x <= y)
    {
        points.push_back({ x,  y});
        points.push_back({ y,  x});
        points.push_back({-x,  y});
        points.push_back({-y,  x});
        points.push_back({-x, -y});
        points.push_back({-y, -x});
        points.push_back({ x, -y});
        points.push_back({ y, -x});

        x++;

        if(dp < 0)
            dp = dp + 2*x + 1;
        else
        {
            y--;
            dp = dp + 2*(x - y) + 1;
        }
    }
    
    for(auto &i : points)
    cout<<i[0] << " " << i[1] << endl; 
    return 0;
}
