#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
constexpr int LIMIT = 1000002;

int N;
int F[LIMIT];
stack<int> A, s, ans;

void solve()
{
	while (!A.empty())
	{
		int a = A.top();
		A.pop();

		while (!s.empty())
		{
			if (F[s.top()] <= F[a])
			{
				s.pop();
			}
			else
			{
				ans.push(s.top());
				s.push(a);
				break;
			}
		}
		if (s.empty())
		{
			ans.push(-1);
			s.push(a);
		}
	}
}

int main()
{
	cin >> N;

	int n;
	for (int i = 0; i < N; i++)
	{
		cin >> n;
		F[n]++;
		A.push(n);
	}

	solve();

	while (!ans.empty())
	{
		cout << ans.top() << " ";
		ans.pop();
	}
}
