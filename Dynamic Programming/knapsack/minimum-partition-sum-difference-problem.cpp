# include <bits/stdc++.h> 
using namespace std;

/*
Explaination: we are using basic knapsack fuction and from that we are chaking of every i element from 0 to sum (of the array) 
whether the subset sum of that i exist in the array or not, if it exist, 
=> s1 = i and s2 = sum - i
=> s1-s2 = sum-i-i = sum-2i or 2i-sum

we are finding minimum s1-s2 and returning it
*/

int knapsack(int arr[], int n, int sum){
	int dp[n+1][sum+1]; 
	
	for (int i=0; i<=n; i++)
		dp[i][0] = 1; 
		
	for (int j=1; j<=sum; j++)
		dp[0][j] = 0;
	
	for(int i=1; i<=n; i++) {
		for (int j=1; j<=sum; j++) {
			// edge case
			if (j < arr[i-1])
				dp[i][j] = dp[i-1][j];
				
			else dp[i][j] = ( dp[i-1][j] + dp[i-1][j-arr[i-1]] );
		}
	}

	return dp[n][sum];
}

int check(int arr[], int n) {
	int sum=0; 
	for (int i=0; i<n; i++)
		sum+=arr[i];
	
	int min_diff=INT_MAX;
	
	for (int i=1; i<sum; i++) {
		if (knapsack(arr, n, i)!=0){
			int diff = (sum-i > i)? (sum-2*i):(2*i-sum);
			if (min_diff > diff) 
				min_diff=(sum-i)-i;
		}
	}
	
	return min_diff; 
}

int main(){
	 int n; cin >> n;
	 int arr[n];	 
	 for (int i=0; i<n; i++)
	 	cin >> arr[i];
	 
	 cout << check(arr, n) << " <=\n";  
}
