#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<list>
using std::vector;
using std::list;
using namespace std;
int main()
{
	vector<int>v;
	for (int i = 0; i < 5; i++)
	{
		v.push_back(i);
		
	}
	for (int i = 0; i < 5;)
	{
		v.push_back(i++);
	}
	int i = 0;
	std::generate_n(std::back_inserter(v), 5, [&]() {return i++; });

	//totalling the elements;
	int total = 0;
	for (int index = 0; index < 5; index++)
	{
		total += v[index];
	}
	total = 0;
	for (int elem : v)
	{
		total += elem;
	}
	//total = 0;
	total = std::accumulate(begin(v), end(v), 10);
	int count1 = 0;
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (v[i] == 3)
		{
			count1++;
		}
	}
	int count2 = 0;
	for (auto it = begin(v); it != end(v); it++)
	{
		if (*it == 3)
		{
			count2++;
		}
	}
	int count3 = std::count(begin(v), end(v), 3);
	
	//Removinng the 3's;
	auto v2 = v;
	for (unsigned int index = 0; index < v2.size(); index++)
	{
		if (v2[index] == 3)
		{
			v2.erase(v2.begin() + index);
		}
	}
	/*auto v3 = v;
	for (auto it = begin(v3); it != end(v3); it++)
	{
		if (*it == 3)
		{
			v3.erase(it);
		}
	}*/
	auto v4 = v;
	auto endv4 = std::remove_if(begin(v4), end(v4), [](int elem) {return (elem == 3); });
	v4.erase(endv4, end(v4));
	//v4.erase(std::remove_if(begin(v4), end(v4), [](int elem) {return (elem == 3); }), end(v4));
}