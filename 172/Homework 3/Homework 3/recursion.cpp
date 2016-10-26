#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;
double sum(const vector<double>& x, int lo, int hi);
int main()
{

	vector <double> x(10);
	int lo, hi;


	cout<<"RECURSIVE VECTOR: "<<sum(x,x.begin(),x.end())<<endl;


	return 0;
}

double sum(const vector<double>& x, int lo, int hi)
{
	int middle = (hi - lo)/2;
    if (lo != hi)
    {
        int middle = (hi - lo)/2;
        vector<int>::iterator midvector = lo + middle;
        return (sum(lo, midvector) + sum(midvector+1, hi));
    }
    else return lo;
}