 /*
 * Copyright (C) 2025 Santosh Mahto
 * All rights reserved.
 *
 * This software is provided as-is, without any express or implied warranty.
 * In no event will the authors be held liable for any damages arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it freely,
 * subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software.
 * 2. If you use this software in a product, an acknowledgment in the product
 *    documentation is required.
 * 3. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 */


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define nums_length 1000 

bool isPrime[nums_length];

// Sieve of Eratosthenes to generate all prime numbers < maxNum
void sieve() {
    fill(isPrime, isPrime + nums_length, true);
     isPrime[0] = false;
     isPrime[1] = false;

    for (int i = 2; i * i < nums_length; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j < nums_length; j += i)
                isPrime[j] = false;
        }

    }
}


bool primeSubtraction(vector<int>& nums) {
    int n = nums.size();

    sieve();

    for(int i = n-2; i >= 0; --i){

        if(nums[i] < nums[i + 1]){
            continue;
        }
        
        for(int p = 2; p < nums[i]; ++p){

            if(!isPrime[p]) continue;

            if(nums[i] - p < nums[i + 1]){
                nums[i] -= p;
                break;
            }
        }
        if(nums[i] >= nums[i + 1]) {
            return false; // If we cannot make nums[i] < nums[i + 1], return false
        }
    }
    return true; // If we can make all elements strictly increasing, return true
}



int main() {
    vector<int> nums1 = {4, 9, 6, 10};
    vector<int> nums2 = {5, 8, 5}; //        2 ,3 , 5

    cout << boolalpha << primeSubtraction(nums1) << endl; // true
    cout << boolalpha << primeSubtraction(nums2) << endl; // true

    return 0;
}
