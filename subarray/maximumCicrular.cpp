#include <iostream>
#include <vector>
using namespace std;
/*

Next Question (Kadane Variant)
🧠 Maximum Subarray in Circular Array
📌 Problem

Given a circular array nums, return the maximum possible sum of a non-empty subarray.

👉 Circular means:

End connects to start
🧪 Example 1
Input:  nums = [1, -2, 3, -2]
Output: 3
Explanation: [3]
🧪 Example 2
Input:  nums = [5, -3, 5]
Output: 10
Explanation: [5, ..., 5]  (wrap around)
🧪 Example 3 (IMPORTANT)
Input:  nums = [-3, -2, -3]
Output: -2
⚠️ Why this is tricky

Normal Kadane only considers:
👉 subarray in straight line

But here:
👉 best answer might be:

[end part] + [start part]
🧠 Hint (Don’t skip thinking)

You need 2 things:

1️⃣ Normal max subarray

👉 already know (Kadane)

2️⃣ Circular case trick

👉 Think:

“If I take everything EXCEPT the worst subarray?”

🔥 Core Idea
maxCircular = totalSum - minSubarray
⚠️ Edge Case (VERY IMPORTANT)

If all numbers are negative:
👉 this formula breaks

So:

if (maxNormal < 0) return maxNormal
🎯 Your Task

Reply like:

Logic:
(Explain normal + circular idea)

Code:
(C++ implementation)
⚡ Small test to check yourself
[3, -1, 2, -1]   → ?
[3, -2, 2, -3]   → ?
[-2, -3, -1]     → ?

Take your time.

This question separates:
👉 “I memorized Kadane”
vs
👉 “I actually understand it” */


int MaximumSuminCircularArray(vector< int >& nums) { 
    int maximum = 0 
    int curr =0  ;
    if (nums)                                                                                                                                                                                                        =
}
int main() {

    
    return 0;
}