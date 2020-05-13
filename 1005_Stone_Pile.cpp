//https://acm.timus.ru/problem.aspx?space=1&num=1005
//You have a number of stones with known weights w1, …, wn. 
//Write a program that will rearrange the stones into two piles such that weight difference between the piles is minimal.
// surprisingly brute force of iterating over all subsets work as long as you use bitmasking 




#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	
	
	int n  ;
	cin >> n;
	vector<int>arr;
	int input;
	while (cin >> input)
		{arr.push_back(input);}
    int results[ ( 1 << n ) ] ;     // ( 1 << n )= 2^n

    //initialize results to 0
    memset( results, 0, sizeof( results ) ) ;

    // iterate through all subsets
	int min  ;
	int total =0;
	for (auto i : arr )
		{total += i;}
	min = total ;
    for( int i = 0 ; i < ( 1 << n ) ; ++ i ) {    // for each subset, O(2^n)
        for ( int j = 0; j < n ; ++ j ) {       // check membership, O(n)
            if  ( i &  1 << j)    // test if bit ‘j’ is turned on in subset ‘i’?
                results[i] += arr[j] ; 
                // if yes, process ‘j’
                
            
        }
	    min = min > abs(total-results[i]*2)?abs(total-results[i]*2):min;
	    
	}
	cout << min<<endl;
	return 0;
	
}
