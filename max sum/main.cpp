/* This code tackles a maximum sum problem where:
 * 1. we start from the top and move downwards to an adjacent number.
 * 2. we are only allowed to walk downwards and diagonally.
 * 3. we can only walk over NON PRIME NUMBERS.
 * 4. we have to reach at the end of the pyramid as much as possible.
 * 5. we have to treat your input as pyramid.
 * @author: Jana Batiya
 * @since: 06.06.22
 * @version: 1.0
 * */

#include <iostream>
#include <bits/stdc++.h>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

//function to check whether the number is prime or not
bool isPrime(int num)
{
    if(num<=1)
        return false;

    for(int i = 2;i<=num / 2 ;i++)
    {
        if(num%i==0) // i divides num
            return false; // num is not prime
    }

    //num is prime
    return true;
}


int main() {

    //vector of vectors for storing input
    vector<vector<int>> input;


        // getting the input from the 'input.txt' file and pushing it to the vector of vectors
        ifstream in("input.txt");

        if (in) {
            string line;

            while (getline(in, line)) {
                input.emplace_back();

                // Break down the row into column values
                stringstream split(line);
                int value;

                while (split >> value)
                    input.back().push_back(value);
            }
        }

// for checking the Orthogonal triangle input
/*        for (int i = 0; i < input.size(); i++) {
            for (int j = 0; j < input[i].size(); j++)
                std::cout << input[i][j] << ' ';

            std::cout << '\n';
        }*/


    int n = input.size(); //number of rows in the input list

    //initializing the dp table
    vector<vector<int>> dp(n, vector<int>(n, 0));
    int ans = 0;


    //traversing the input matrix row by row
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {

            //if the number is not prime
            if (isPrime(input[i][j])) {
                //we ignore this number
                continue;
            }
            //if first row
            if (i == 0) {
                dp[i][j] = input[i][j];
            } else if (j == 0) {
                //first column
                //we can reach here upwards or diagonally
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j + 1]) + input[i][j];
            } else if (j == i)//last value in the current row
            {
                //we can reach here diagonally
                dp[i][j] = dp[i - 1][j - 1] + input[i][j];
            } else {
                dp[i][j] = max({dp[i - 1][j], dp[i - 1][j - 1], dp[i - 1][j + 1]}) + input[i][j];
            }
        }
    }


    for (int i = 0; i < n; i++) {
        ans = max(ans, dp[n - 1][i]);
    }

    cout << "Maximum sum : " << ans << endl;


    return EXIT_SUCCESS;
}


