#include<bits/stdc++.h>
using namespace std;

int steps(int source, int step, int dest)
{
	if (abs(source) > abs(dest)) 
		return INT_MAX;
	if (source == dest) return step;

	int pos = steps(source + step + 1, 
					step + 1, dest);

	int neg = steps(source - step - 1,
					step + 1, dest);

	return min(pos, neg);
}

int main()
{
	int dest = 11;
	cout << "No. of steps required to reach "
							<< dest << " is "
						<< steps(0, 0, dest);
	return 0;
}
