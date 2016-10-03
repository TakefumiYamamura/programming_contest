#include <iostream>

using namespace std;

int check_max(int n, int a[]){
	int max = 0;
	for (int i = 0; i < n; ++i)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
	}
	return max;
}

int main(){
	int n;
	int a[101];
	int check[101] = {0};
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	int max = check_max(n, a);
	int lower_limit;
	if(max % 2 == 0){
		lower_limit =  max / 2;
	} else {
		lower_limit = max / 2 + 1;
	}

	int lowest_num_count = 0;
	for (int i = 0; i < n; ++i)
	{
		if(check[a[i]] == false) {
			check[a[i]] = true;
		}
		if(lower_limit == a[i]){
			lowest_num_count++;
			if (lowest_num_count == 2 && (max%2 ==0))
			{
				cout << "Impossible" << endl;
				return 0;
			}

			if (lowest_num_count == 3 && (max%2 ==1))
			{
				cout << "Impossible" << endl;
				return 0;
			}
		}
		if(lower_limit > a[i]){
			cout << "Impossible" << endl;
			return 0;
		}
	}

	for (int i = lower_limit; i <= max; ++i)
	{
		if (check[i] == false)
		{
			cout << "Impossible" << endl;
			return 0; 
		}
	}


	cout << "Possible" << endl;
	return 0;

}
