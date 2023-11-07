#pragma once
#ifndef LeetcodeTwoPointer_H
#define LeetCodeTwoPointer_H
#include <stdint.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <algorithm> 
#include <functional> 
#include <bitset> 
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stdexcept>
#include <string>
#include <unordered_map> 
#include <unordered_set> 
#include <vector> 
#include <stack> 
using namespace std;
/// <summary>
/// The class is to implement two pointers  
/// </summary>
class LeetCodeTwoPointer
{
public:
    /// <summary>
    /// Leet Code 11. Container With Most Water
    ///  
    /// Medium
    ///
    /// You are given an integer array height of length n. There are n 
    /// vertical lines drawn such that the two endpoints of the ith 
    /// line are (i, 0) and (i, height[i]).
    ///
    /// Find two lines that together with the x-axis form a container, 
    /// such that the container contains the most water.
    ///
    /// Return the maximum amount of water a container can store.
    /// Notice that you may not slant the container.
    /// 
    /// Example 1:
    /// Input: height = [1,8,6,2,5,4,8,3,7]
    /// Output: 49
    /// Explanation: The above vertical lines are represented by array 
    /// [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue 
    /// section) the container can contain is 49.
    ///
    /// Example 2:
    /// Input: height = [1,1]
    /// Output: 1
    /// 
    /// Constraints:
    /// 1. n == height.length
    /// 2. 2 <= n <= 10^5
    /// 3. 0 <= height[i] <= 10^4
    /// </summary>
    int maxArea(vector<int>& height);

    /// <summary>
    /// Leet Code 42. Trapping Rain Water
    ///  
    /// Hard
    ///
    /// Given n non-negative integers representing an elevation map where the 
    /// width of each bar is 1, compute how much water it can trap after 
    /// raining.
    ///
    /// Example 1:
    /// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
    /// Output: 6
    /// Explanation: The above elevation map (black section) is represented 
    /// by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain 
    /// water (blue section) are being trapped.
    ///
    /// Example 2:
    /// Input: height = [4,2,0,3,2,5]
    /// Output: 9
    /// 
    /// Constraints:
    /// 1. n == height.length
    /// 2. 1 <= n <= 2 * 10^4
    /// 3. 0 <= height[i] <= 10^5
    /// </summary>
    int trap(vector<int>& height);

    /// <summary>
    /// Leet Code 658. Find K Closest Elements
    ///  
    /// Medium
    ///
    /// Given a sorted integer array arr, two integers k and x, return the k 
    /// closest integers to x in the array. The result should also be sorted 
    /// in ascending order.
    ///
    /// An integer a is closer to x than an integer b if:
    ///
    /// |a - x| < |b - x|, or
    /// |a - x| == |b - x| and a < b
    /// 
    /// Example 1:
    /// Input: arr = [1,2,3,4,5], k = 4, x = 3
    /// Output: [1,2,3,4]
    ///
    /// Example 2:
    /// Input: arr = [1,2,3,4,5], k = 4, x = -1
    /// Output: [1,2,3,4]
    /// 
    /// Constraints:
    /// 1. 1 <= k <= arr.length
    /// 2. 1 <= arr.length <= 10^4
    /// 3. arr is sorted in ascending order.
    /// 4. -10^4 <= arr[i], x <= 10^4
    /// </summary>
    vector<int> findClosestElements(vector<int>& arr, int k, int x);

    /// <summary>
    /// Leet Code 680. Valid Palindrome II
    ///  
    /// Easy
    ///
    /// Given a string s, return true if the s can be palindrome after 
    /// deleting at most one character from it.
    /// 
    /// Example 1:
    /// Input: s = "aba"
    /// Output: true
    ///
    /// Example 2:
    /// Input: s = "abca"
    /// Output: true
    /// Explanation: You could delete the character 'c'.
    ///
    /// Example 3:
    /// Input: s = "abc"
    /// Output: false
    /// Constraints:
    /// 1. 1 <= s.length <= 10^5
    /// 2. s consists of lowercase English letters.
    /// </summary>
    bool validPalindrome(string s);

    /// <summary>
    /// Leet code #881. Boats to Save People
    /// 
    /// The i-th person has weight people[i], and each boat can carry a maximum 
    /// weight of limit.
    ///
    /// Each boat carries at most 2 people at the same time, provided the sum of 
    /// the weight of those people is at most limit.
    ///
    /// Return the minimum number of boats to carry every given person.  (It is 
    /// guaranteed each person can be carried by a boat.)
    ///
    /// Example 1:
    ///
    /// Input: people = [1,2], limit = 3
    /// Output: 1
    /// Explanation: 1 boat (1, 2)
    ///
    /// Example 2:
    ///
    /// Input: people = [3,2,2,1], limit = 3
    /// Output: 3
    /// Explanation: 3 boats (1, 2), (2) and (3)
    ///
    /// Example 3:
    /// 
    /// Input: people = [3,5,3,4], limit = 5
    /// Output: 4
    /// Explanation: 4 boats (3), (3), (4), (5)
    /// Note:
    /// 
    /// 1. 1 <= people.length <= 50000
    /// 2. 1 <= people[i] <= limit <= 30000
    /// </summary>
    int numRescueBoats(vector<int>& people, int limit);

    /// <summary>
    /// Leet code #922. Sort Array By Parity II
    /// 
    /// Given an array A of non-negative integers, half of the integers in A are 
    /// odd, and half of the integers are even.
    ///
    /// Sort the array so that whenever A[i] is odd, i is odd; and whenever A[i] 
    /// is even, i is even.
    ///
    /// You may return any answer array that satisfies this condition.
    /// 
    /// Example 1:
    ///
    /// Input: [4,2,5,7]
    /// Output: [4,5,2,7]
    /// Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been 
    /// accepted.
    /// 
    /// Note:
    /// 1. 2 <= A.length <= 20000
    /// 2. A.length % 2 == 0
    /// 3. 0 <= A[i] <= 1000
    /// </summary>
    vector<int> sortArrayByParityII(vector<int>& A);

    /// <summary>
    /// Leet code #1100. Find K-Length Substrings With No Repeated Characters
    /// 
    /// Given a string S, return the number of substrings of length K with no 
    /// repeated characters.
    /// 
    /// Example 1:
    /// Input: S = "havefunonleetcode", K = 5
    /// Output: 6
    /// Explanation: 
    /// There are 6 substrings they are : 'havef','avefu','vefun','efuno',
    /// 'etcod','tcode'.
    ///
    /// Example 2:
    /// Input: S = "home", K = 5
    /// Output: 0
    /// Explanation: 
    /// Notice K can be larger than the length of S. In this case is not 
    /// possible to find any substring.
    /// 
    /// Note:
    /// 1 <= S.length <= 10^4
    /// 2. All characters of S are lowercase English letters.
    /// 3. 1 <= K <= 10^4
    /// </summary>
    int numKLenSubstrNoRepeats(string S, int K);

    /// <summary>
    /// Leet Code 1156. Swap For Longest Repeated Character Substring
    ///  
    /// Medium
    ///
    /// You are given a string text. You can swap two of the characters in the 
    /// text.
    ///
    /// Return the length of the longest substring with repeated characters.
    /// 
    /// Example 1:
    /// Input: text = "ababa"
    /// Output: 3
    /// Explanation: We can swap the first 'b' with the last 'a', or the last 
    /// 'b' with the first 'a'. Then, the longest repeated character 
    /// substring is "aaa" with length 3.
    ///
    /// Example 2:
    /// Input: text = "aaabaaa"
    /// Output: 6
    /// Explanation: Swap 'b' with the last 'a' (or the first 'a'), and we get 
    /// longest repeated character substring "aaaaaa" with length 6.
    ///
    /// Example 3:
    /// Input: text = "aaaaa"
    /// Output: 5
    /// Explanation: No need to swap, longest repeated character substring is 
    /// "aaaaa" with length is 5.
    /// 
    /// Constraints:
    /// 1. 1 <= text.length <= 2 * 10^4
    /// 2. text consist of lowercase English characters only.
    /// </summary>
    int maxRepOpt1(string text);

    /// <summary>
    /// Leet Code 1852. Distinct Numbers in Each Subarray
    ///                                                                 
    /// Medium
    ///
    /// Given an integer array nums and an integer k, you are asked to 
    /// construct the array ans of size n-k+1 where ans[i] is the number 
    /// of distinct numbers in the subarray nums[i:i+k-1] = [nums[i], 
    /// nums[i+1], ..., nums[i+k-1]].
    ///
    /// Return the array ans.
    /// 
    /// Example 1:
    /// Input: nums = [1,2,3,2,2,1,3], k = 3
    /// Output: [3,2,2,2,3]
    /// Explanation: The number of distinct elements in each subarray goes 
    /// as follows:
    /// - nums[0:2] = [1,2,3] so ans[0] = 3
    /// - nums[1:3] = [2,3,2] so ans[1] = 2
    /// - nums[2:4] = [3,2,2] so ans[2] = 2
    /// - nums[3:5] = [2,2,1] so ans[3] = 2
    /// - nums[4:6] = [2,1,3] so ans[4] = 3
    ///
    /// Example 2:
    /// Input: nums = [1,1,1,1,2,3,4], k = 4
    /// Output: [1,2,3,4]
    /// Explanation: The number of distinct elements in each subarray goes 
    /// as follows:
    /// - nums[0:3] = [1,1,1,1] so ans[0] = 1
    /// - nums[1:4] = [1,1,1,2] so ans[1] = 2
    /// - nums[2:5] = [1,1,2,3] so ans[2] = 3
    /// - nums[3:6] = [1,2,3,4] so ans[3] = 4
    ///
    /// Constraints:
    /// 1. 1 <= k <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^5
    /// </summary>
    vector<int> distinctNumbers(vector<int>& nums, int k);

    /// <summary>
    /// Leet Code 2062. Count Vowel Substrings of a String
    ///                                                                 
    /// Easy
    ///
    /// A substring is a contiguous (non-empty) sequence of characters within 
    /// a string.
    ///
    /// A vowel substring is a substring that only consists of vowels 
    /// ('a', 'e', 'i', 'o', and 'u') and has all five vowels present in it.
    /// Given a string word, return the number of vowel substrings in word.
    ///
    /// Example 1:
    /// Input: word = "aeiouu"
    /// Output: 2
    /// Explanation: The vowel substrings of word are as follows (underlined):
    /// - "aeiouu"
    /// - "aeiouu"
    ///
    /// Example 2:
    /// Input: word = "unicornarihan"
    /// Output: 0
    /// Explanation: Not all 5 vowels are present, so there are no vowel 
    /// substrings.
    ///
    /// Example 3:
    /// Input: word = "cuaieuouac"
    /// Output: 7
    /// Explanation: The vowel substrings of word are as follows (underlined):
    /// - "cuaieuouac"
    /// - "cuaieuouac"
    /// - "cuaieuouac"
    /// - "cuaieuouac"
    /// - "cuaieuouac"
    /// - "cuaieuouac"
    /// - "cuaieuouac"
    ///
    /// Example 4:
    /// Input: word = "bbaeixoubb"
    /// Output: 0
    /// Explanation: The only substrings that contain all five vowels also 
    /// contain 
    /// consonants, so there are no vowel substrings.
    /// 
    /// Constraints:
    /// 1. 1 <= word.length <= 100
    /// 2. word consists of lowercase English letters only.
    /// </summary>
    int countVowelSubstrings(string word);

    /// <summary>
    /// Leet Code 2106. Maximum Fruits Harvested After at Most K Steps
    ///                                                                 
    /// Hard
    ///
    /// Fruits are available at some positions on an infinite x-axis. You are 
    /// given a 2D integer array fruits where fruits[i] = [positioni, amounti] 
    /// depicts amounti fruits at the position positioni. fruits is already 
    /// sorted by positioni in ascending order, and each positioni is unique.
    ///
    /// You are also given an integer startPos and an integer k. Initially, 
    /// you are at the position startPos. From any position, you can either 
    /// walk to the left or right. It takes one step to move one unit on the 
    /// x-axis, and you can walk at most k steps in total. For every position 
    /// you reach, you harvest all the fruits at that position, and the 
    /// fruits will disappear from that position.
    ///
    /// Return the maximum total number of fruits you can harvest.
    /// 
    /// Example 1:
    /// Input: fruits = [[2,8],[6,3],[8,6]], startPos = 5, k = 4
    /// Output: 9
    /// Explanation: 
    /// The optimal way is to:
    /// - Move right to position 6 and harvest 3 fruits
    /// - Move right to position 8 and harvest 6 fruits
    /// You moved 3 steps and harvested 3 + 6 = 9 fruits in total.
    ///
    /// Example 2:
    /// Input: fruits = [[0,9],[4,1],[5,7],[6,2],[7,4],[10,9]], 
    /// startPos = 5, k = 4
    /// Output: 14
    /// Explanation: 
    /// You can move at most k = 4 steps, so you cannot reach position 0 
    /// nor 10.
    /// The optimal way is to:
    /// - Harvest the 7 fruits at the starting position 5
    /// - Move left to position 4 and harvest 1 fruit
    /// - Move right to position 6 and harvest 2 fruits
    /// - Move right to position 7 and harvest 4 fruits
    /// You moved 1 + 3 = 4 steps and harvested 7 + 1 + 2 + 4 = 14 
    /// fruits in total.
    ///
    /// Example 3:
    /// Input: fruits = [[0,3],[6,4],[8,5]], startPos = 3, k = 2
    /// Output: 0
    /// Explanation:
    /// You can move at most k = 2 steps and cannot reach any position with 
    /// fruits.
    /// 
    /// Constraints:
    /// 1. 1 <= fruits.length <= 10^5
    /// 2. fruits[i].length == 2
    /// 3. 0 <= startPos, positioni <= 2 * 10^5
    /// 4. positioni-1 < positioni for any i > 0 (0-indexed)
    /// 5. 1 <= amounti <= 10^4
    /// 6. 0 <= k <= 2 * 10^5
    /// </summary>
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k);

    /// <summary>
    /// Leet Code 2107. Number of Unique Flavors After Sharing K Candies
    ///                                                                 
    /// Medium
    ///
    /// You are given a 0-indexed integer array candies, where candies[i] 
    /// represents the flavor of the ith candy. Your mom wants you to share 
    /// these candies with your little sister by giving her k consecutive 
    /// candies, but you want to keep as many flavors of candies as possible.
    ///
    /// Return the maximum number of unique flavors of candy you can keep 
    /// after sharing with your sister.
    /// 
    /// Example 1:
    /// Input: candies = [1,2,2,3,4,3], k = 3
    /// Output: 3
    /// Explanation:
    /// Give the candies in the range [1, 3] (inclusive) with flavors [2,2,3].
    /// You can eat the candies with flavors [1,4,3].
    /// There are 3 unique flavors, so return 3.
    ///
    /// Example 2:
    /// Input: candies = [2,2,2,2,3,3], k = 2
    /// Output: 2
    /// Explanation:
    /// Give the candies in the range [3, 4] (inclusive) with flavors [2,3].
    /// You can eat the candies with flavors [2,2,2,3].
    /// There are 2 unique flavors, so return 2.
    /// Note that you can also share the candies with flavors [2,2] and eat 
    /// the candies with flavors [2,2,3,3].
    ///
    /// Example 3:
    /// Input: candies = [2,4,5], k = 0
    /// Output: 3
    /// Explanation:
    /// You do not have to give any candies.
    /// You can eat the candies with flavors [2,4,5].
    /// There are 3 unique flavors, so return 3.
    ///
    /// Example 4:
    /// Input: candies = [2,4,5], k = 3
    /// Output: 0
    /// Explanation:
    /// You have to give all the candies.
    /// You do not have any candies left over, so return 0.
    /// 
    /// Constraints:
    /// 1. 1 <= candies.length <= 10^5
    /// 2. 1 <= candies[i] <= 10^5
    /// 3. 0 <= k <= candies.length
    /// </summary>
    int shareCandies(vector<int>& candies, int k);

    /// <summary>
    /// Leet Code 2105. Watering Plants II
    ///                                                                 
    /// Medium
    ///
    /// Alice and Bob want to water n plants in their garden. The plants are 
    /// arranged in a row and are labeled from 0 to n - 1 from left to right 
    /// where the ith plant is located at x = i.
    ///
    /// Each plant needs a specific amount of water. Alice and Bob have a 
    /// watering can each, initially full. They water the plants in the 
    /// following way:
    ///
    /// Alice waters the plants in order from left to right, starting from 
    /// the 0th plant. Bob waters the plants in order from right to left, 
    /// starting from the (n - 1)th plant. They begin watering the plants 
    /// simultaneously.
    /// It takes the same amount of time to water each plant regardless of 
    /// how much water it needs.
    /// Alice/Bob must water the plant if they have enough in their can to 
    /// fully water it. Otherwise, they first refill their can 
    /// (instantaneously) then water the plant.
    /// In case both Alice and Bob reach the same plant, the one with more 
    /// water currently in his/her watering can should water this plant. If 
    /// they have the same amount of water, then Alice should water this plant.
    /// Given a 0-indexed integer array plants of n integers, where plants[i] 
    /// is the amount of water the ith plant needs, and two integers capacityA 
    /// and capacityB representing the capacities of Alice's and Bob's 
    /// watering cans respectively, return the number of times they have to 
    /// refill to water all the plants.
    /// 
    /// Example 1:
    /// Input: plants = [2,2,3,3], capacityA = 5, capacityB = 5
    /// Output: 1
    /// Explanation:
    /// - Initially, Alice and Bob have 5 units of water each in their 
    ///   watering cans.
    /// - Alice waters plant 0, Bob waters plant 3.
    /// - Alice and Bob now have 3 units and 2 units of water respectively.
    /// - Alice has enough water for plant 1, so she waters it. Bob does not 
    ///   have enough water for plant 2, so he refills his can then waters it.
    /// So, the total number of times they have to refill to water all the 
    /// plants is 0 + 0 + 1 + 0 = 1.
    ///
    /// Example 2:
    /// Input: plants = [2,2,3,3], capacityA = 3, capacityB = 4
    /// Output: 2
    /// Explanation:
    /// - Initially, Alice and Bob have 3 units and 4 units of water in their 
    ///   watering cans respectively.
    /// - Alice waters plant 0, Bob waters plant 3.
    /// - Alice and Bob now have 1 unit of water each, and need to water 
    ///   plants 1 and 2 respectively.
    /// - Since neither of them have enough water for their current plants, 
    ///   they refill their cans and then water the plants.
    /// So, the total number of times they have to refill to water all the 
    /// plants is 0 + 1 + 1 + 0 = 2.
    ///
    /// Example 3:
    /// Input: plants = [5], capacityA = 10, capacityB = 8
    /// Output: 0
    /// Explanation:
    /// - There is only one plant.
    /// - Alice's watering can has 10 units of water, whereas Bob's can has 8 
    /// units. Since Alice has more water in her can, she waters this plant.
    /// So, the total number of times they have to refill is 0.
    ///
    /// Constraints:
    /// 1. n == plants.length
    /// 2. 1 <= n <= 10^5
    /// 3. 1 <= plants[i] <= 10^6
    /// 4. max(plants[i]) <= capacityA, capacityB <= 10^9
    /// </summary>
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB);

    /// <summary>
    /// Leet Code 2302. Count Subarrays With Score Less Than K
    ///                                                           
    /// Hard
    /// 
    /// The score of an array is defined as the product of its sum and its 
    /// length.
    ///
    /// For example, the score of [1, 2, 3, 4, 5] is 
    /// (1 + 2 + 3 + 4 + 5) * 5 = 75.
    /// Given a positive integer array nums and an integer k, return the 
    /// number of non-empty subarrays of nums whose score is strictly less 
    /// than k.
    ///
    /// A subarray is a contiguous sequence of elements within an array.
    ///  
    /// Example 1:
    /// Input: nums = [2,1,4,3,5], k = 10
    /// Output: 6
    /// Explanation:
    /// The 6 subarrays having scores less than 10 are:
    /// - [2] with score 2 * 1 = 2.
    /// - [1] with score 1 * 1 = 1.
    /// - [4] with score 4 * 1 = 4.
    /// - [3] with score 3 * 1 = 3. 
    /// - [5] with score 5 * 1 = 5.
    /// - [2,1] with score (2 + 1) * 2 = 6.
    /// Note that subarrays such as [1,4] and [4,3,5] are not considered 
    /// because their scores are 10 and 36 respectively, while we need scores 
    /// strictly less than 10.
    ///
    /// Example 2:
    /// Input: nums = [1,1,1], k = 5
    /// Output: 5
    /// Explanation:
    /// Every subarray except [1,1,1] has a score less than 5.
    /// [1,1,1] has a score (1 + 1 + 1) * 3 = 9, which is greater than 5.
    /// Thus, there are 5 subarrays having scores less than 5.
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^5
    /// 3. 1 <= k <= 10^15
    /// </summary>
    long long countSubarrays(vector<int>& nums, long long k);

    /// <summary>
    /// Leet Code 2327. Number of People Aware of a Secret
    ///                                                           
    /// Medium
    ///
    /// On day 1, one person discovers a secret.
    ///
    /// You are given an integer delay, which means that each person will 
    /// share the secret with a new person every day, starting from delay 
    /// days after discovering the secret. You are also given an integer 
    /// forget, which means that each person will forget the secret forget 
    /// days after discovering it. A person cannot share the secret on the 
    /// same day they forgot it, or on any day afterwards.
    ///
    /// Given an integer n, return the number of people who know the secret 
    /// at the end of day n. Since the answer may be very large, return it 
    /// modulo 10^9 + 7.
    ///
    /// Example 1:
    /// Input: n = 6, delay = 2, forget = 4
    /// Output: 5
    /// Explanation:
    /// Day 1: Suppose the first person is named A. (1 person)
    /// Day 2: A is the only person who knows the secret. (1 person)
    /// Day 3: A shares the secret with a new person, B. (2 people)
    /// Day 4: A shares the secret with a new person, C. (3 people)
    /// Day 5: A forgets the secret, and B shares the secret with a new 
    ///        person, D. (3 people)
    /// Day 6: B shares the secret with E, and C shares the secret with 
    ///        F. (5 people)
    ///
    /// Example 2:
    /// Input: n = 4, delay = 1, forget = 3
    /// Output: 6
    /// Explanation:
    /// Day 1: The first person is named A. (1 person)
    /// Day 2: A shares the secret with B. (2 people)
    /// Day 3: A and B share the secret with 2 new people, C and D. (4 people)
    /// Day 4: A forgets the secret. B, C, and D share the secret with 3 new 
    ///        people. (6 people)
    ///
    /// Constraints:
    /// 1. 2 <= n <= 1000
    /// 2. 1 <= delay < forget <= n
    /// </summary>
    int peopleAwareOfSecret(int n, int delay, int forget);

    /// <summary>
    /// Leet Code 2330. Valid Palindrome IV
    ///                                                           
    /// Medium
    ///
    /// You are given a 0-indexed string s consisting of only lowercase 
    /// English letters. In one operation, you can change any character 
    /// of s to any other character.
    ///
    /// Return true if you can make s a palindrome after performing 
    /// exactly one or two operations, or return false otherwise.
    ///
    /// Example 1:
    /// Input: s = "abcdba"
    /// Output: true
    /// Explanation: One way to make s a palindrome using 1 operation is:
    /// - Change s[2] to 'd'. Now, s = "abddba".
    /// One operation could be performed to make s a palindrome so return true.
    /// 
    /// Example 2:
    /// Input: s = "aa"
    /// Output: true
    /// Explanation: One way to make s a palindrome using 2 operations is:
    /// - Change s[0] to 'b'. Now, s = "ba".
    /// - Change s[1] to 'b'. Now, s = "bb".
    /// Two operations could be performed to make s a palindrome so return 
    /// true.
    ///
    /// Example 3:
    ///
    /// Input: s = "abcdef"
    /// Output: false
    /// Explanation: It is not possible to make s a palindrome using one 
    /// or two operations so return false.
    ///
    /// Constraints:
    /// 1. 1 <= s.length <= 10^5
    /// 2. s consists only of lowercase English letters.
    /// </summary>
    bool makePalindrome(string s);

    /// <summary>
    /// Leet Code 2379. Minimum Recolors to Get K Consecutive Black Blocks
    ///                                                           
    /// Easy
    ///
    /// You are given a 0-indexed string blocks of length n, where blocks[i] 
    /// is either 'W' or 'B', representing the color of the ith block. The 
    /// characters 'W' and 'B' denote the colors white and black, respectively.
    /// You are also given an integer k, which is the desired number of 
    /// consecutive black blocks.
    /// In one operation, you can recolor a white block such that it becomes a 
    /// black block.
    ///
    /// Return the minimum number of operations needed such that there is at 
    /// least one occurrence of k consecutive black blocks.
    ///
    /// Example 1:
    /// Input: blocks = "WBBWWBBWBW", k = 7
    /// Output: 3
    /// Explanation:
    /// One way to achieve 7 consecutive black blocks is to recolor the 0th, 
    /// 3rd, and 4th blocks
    /// so that blocks = "BBBBBBBWBW". 
    /// It can be shown that there is no way to achieve 7 consecutive black 
    /// blocks in less than 3 operations.
    /// Therefore, we return 3.
    ///
    /// Example 2:
    /// Input: blocks = "WBWBBBW", k = 2
    /// Output: 0
    /// Explanation:
    /// No changes need to be made, since 2 consecutive black blocks 
    /// already exist.
    /// Therefore, we return 0.
    /// 
    /// Constraints:
    /// 1. n == blocks.length
    /// 2. 1 <= n <= 100
    /// 3. blocks[i] is either 'W' or 'B'.
    /// 4. 1 <= k <= n
    /// </summary>
    int minimumRecolors(string blocks, int k);

    /// <summary>
    /// Leet Code 2422. Merge Operations to Turn Array Into a Palindrome
    ///                                                  
    /// Medium
    ///
    /// You are given an array nums consisting of positive integers.
    ///
    /// You can perform the following operation on the array any number 
    /// of times:
    ///
    /// Choose any two adjacent elements and replace them with their sum.
    /// For example, if nums = [1,2,3,1], you can apply one operation to 
    /// make it [1,5,1].
    /// Return the minimum number of operations needed to turn the array 
    /// into a palindrome.
    ///
    /// Example 1:
    /// Input: nums = [4,3,2,1,2,3,1]
    /// Output: 2
    /// Explanation: We can turn the array into a palindrome in 2 operations 
    /// as follows:
    /// - Apply the operation on the fourth and fifth element of the array, 
    ///   nums becomes equal to [4,3,2,3,3,1].
    /// - Apply the operation on the fifth and sixth element of the array, 
    ///   nums becomes equal to [4,3,2,3,4].
    /// The array [4,3,2,3,4] is a palindrome.
    /// It can be shown that 2 is the minimum number of operations needed.
    ///
    /// Example 2:
    /// Input: nums = [1,2,3,4]
    /// Output: 3
    /// Explanation: We do the operation 3 times in any position, we obtain 
    /// the array [10] at the end which is a palindrome.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^6
    /// </summary>
    int minimumOperations(vector<int>& nums);

    /// <summary>
    /// Leet Code 2461. Maximum Sum of Distinct Subarrays With Length K 
    ///                                                  
    /// Medium
    ///
    /// You are given an integer array nums and an integer k. Find the 
    /// maximum subarray sum of all the subarrays of nums that meet the 
    /// following conditions:
    ///
    /// The length of the subarray is k, and
    /// All the elements of the subarray are distinct.
    /// Return the maximum subarray sum of all the subarrays that meet 
    /// the conditions. If no subarray meets the conditions, return 0.
    ///
    /// A subarray is a contiguous non-empty sequence of elements within 
    /// an array.
    ///
    /// Example 1:
    /// Input: nums = [1,5,4,2,9,9,9], k = 3
    /// Output: 15
    /// Explanation: The subarrays of nums with length 3 are:
    /// - [1,5,4] which meets the requirements and has a sum of 10.
    /// - [5,4,2] which meets the requirements and has a sum of 11.
    /// - [4,2,9] which meets the requirements and has a sum of 15.
    /// - [2,9,9] which does not meet the requirements because the element 9 
    ///   is repeated.
    /// - [9,9,9] which does not meet the requirements because the element 9 
    ///   is repeated.
    /// We return 15 because it is the maximum subarray sum of all the 
    /// subarrays that meet the conditions
    ///
    /// Example 2:
    /// Input: nums = [4,4,4], k = 3
    /// Output: 0
    /// Explanation: The subarrays of nums with length 3 are:
    /// - [4,4,4] which does not meet the requirements because the element 4 
    ///   is repeated.
    /// We return 0 because no subarrays meet the conditions.
    /// 
    /// Constraints:
    /// 1. 1 <= k <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^5
    /// </summary>
    long long maximumSubarraySum(vector<int>& nums, int k);

    /// <summary>
    /// Leet Code 2462. Total Cost to Hire K Workers
    ///                                                  
    /// Medium
    /// 
    /// You are given a 0-indexed integer array costs where costs[i] is the 
    /// cost of hiring the ith worker.
    ///
    /// You are also given two integers k and candidates. We want to hire 
    /// exactly k workers according to the following rules:
    ///
    /// You will run k sessions and hire exactly one worker in each session.
    /// In each hiring session, choose the worker with the lowest cost from 
    /// either the first candidates workers or the last candidates workers. 
    /// Break the tie by the smallest index.
    /// For example, if costs = [3,2,7,7,1,2] and candidates = 2, then in 
    /// the first hiring session, we will choose the 4th worker because they 
    /// have the lowest cost [3,2,7,7,1,2].
    /// In the second hiring session, we will choose 1st worker because they 
    /// have the same lowest cost as 4th worker but they have the smallest 
    /// index [3,2,7,7,2]. Please note that the indexing may be changed in 
    /// the process.
    /// If there are fewer than candidates workers remaining, choose the 
    /// worker with the lowest cost among them. Break the tie by the smallest 
    /// index.
    /// A worker can only be chosen once.
    /// Return the total cost to hire exactly k workers.
    /// 
    /// Example 1:
    /// Input: costs = [17,12,10,2,7,2,11,20,8], k = 3, candidates = 4
    /// Output: 11
    /// Explanation: We hire 3 workers in total. The total cost is 
    /// initially 0.
    /// - In the first hiring round we choose the worker from 
    ///   [17,12,10,2,7,2,11,20,8]. The lowest cost is 2, and we break the tie 
    ///   by the smallest index, which is 3. The total cost = 0 + 2 = 2.
    /// - In the second hiring round we choose the worker from 
    ///   [17,12,10,7,2,11,20,8]. The lowest cost is 2 (index 4). The total 
    ///   cost = 2 + 2 = 4.
    /// - In the third hiring round we choose the worker from 
    ///   [17,12,10,7,11,20,8]. The lowest cost is 7 (index 3). The total 
    ///   cost = 4 + 7 = 11. Notice that the worker with index 3 was common 
    ///  in the first and last four workers.
    /// The total hiring cost is 11.
    ///
    /// Example 2:
    /// Input: costs = [1,2,4,1], k = 3, candidates = 3
    /// Output: 4
    /// Explanation: We hire 3 workers in total. The total cost is initially 0.
    /// - In the first hiring round we choose the worker from [1,2,4,1]. The 
    ///   lowest cost is 1, and we break the tie by the smallest index, which 
    ///   is 0. The total cost = 0 + 1 = 1. Notice that workers with index 1 
    ///   and 2 are common in the first and last 3 workers.
    /// - In the second hiring round we choose the worker from [2,4,1]. The 
    ///   lowest cost is 1 (index 2). The total cost = 1 + 1 = 2.
    /// - In the third hiring round there are less than three candidates. We 
    ///   choose the worker from the remaining workers [2,4]. The lowest cost 
    ///   is 2 (index 0). The total cost = 2 + 2 = 4.
    /// The total hiring cost is 4.
    /// 
    /// Constraints:
    /// 1. 1 <= costs.length <= 10^5
    /// 2. 1 <= costs[i] <= 10^5
    /// 3. 1 <= k, candidates <= costs.length
    /// </summary>
    long long totalCost(vector<int>& costs, int k, int candidates);

    /// <summary>
    /// Leet Code 2448. Minimum Cost to Make Array Equal
    /// 
    /// Hard
    ///	
    /// You are given two 0-indexed arrays nums and cost consisting each of 
    /// n positive integers.
    ///
    /// You can do the following operation any number of times:
    ///
    /// Increase or decrease any element of the array nums by 1.
    /// The cost of doing one operation on the ith element is cost[i].
    ///
    /// Return the minimum total cost such that all the elements of the array 
    /// nums become equal.
    ///
    /// Example 1:
    /// Input: nums = [1,3,5,2], cost = [2,3,1,14]
    /// Output: 8
    /// Explanation: We can make all the elements equal to 2 in the following 
    /// way:
    /// - Increase the 0th element one time. The cost is 2.
    /// - Decrease the 1st element one time. The cost is 3.
    /// - Decrease the 2nd element three times. The cost is 1 + 1 + 1 = 3.
    /// The total cost is 2 + 3 + 3 = 8.
    /// It can be shown that we cannot make the array equal with a smaller 
    /// cost.
    ///
    /// Example 2:
    /// Input: nums = [2,2,2,2,2], cost = [4,2,8,1,3]
    /// Output: 0
    /// Explanation: All the elements are already equal, so no operations are 
    /// needed.
    /// 
    /// Constraints:
    /// 1. n == nums.length == cost.length
    /// 2. 1 <= n <= 10^5
    /// 3. 1 <= nums[i], cost[i] <= 10^6
    /// </summary>
    long long minCost(vector<int>& nums, vector<int>& cost);

    /// <summary>
    /// Leet Code 2537. Count the Number of Good Subarrays
    /// 
    /// Medium
    ///	
    /// Given an integer array nums and an integer k, return the number of 
    /// good subarrays of nums.
    ///
    /// A subarray arr is good if it there are at least k pairs of 
    /// indices (i, j) such that i < j and arr[i] == arr[j].
    ///
    /// A subarray is a contiguous non-empty sequence of elements within an 
    /// array.
    /// 
    /// Example 1:
    /// Input: nums = [1,1,1,1,1], k = 10
    /// Output: 1
    /// Explanation: The only good subarray is the array nums itself.
    ///
    /// Example 2:
    /// Input: nums = [3,1,4,3,2,2,4], k = 2
    /// Output: 4
    /// Explanation: There are 4 different good subarrays:
    /// - [3,1,4,3,2,2] that has 2 pairs.
    /// - [3,1,4,3,2,2,4] that has 3 pairs.
    /// - [1,4,3,2,2,4] that has 2 pairs.
    /// - [4,3,2,2,4] that has 2 pairs.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= nums[i], k <= 10^9
    /// </summary>
    long long countGood(vector<int>& nums, int k);

    /// <summary>
    /// Leet Code 2576. Find the Maximum Number of Marked Indices
    /// 
    /// Medium
    ///	
    /// You are given a 0-indexed integer array nums.
    /// 
    /// Initially, all of the indices are unmarked. You are allowed to make 
    /// this operation any number of times:
    ///
    /// Pick two different unmarked indices i and j such that 
    /// 2 * nums[i] <= nums[j], then mark i and j.
    /// Return the maximum possible number of marked indices in nums using 
    /// the above operation any number of times.
    ///
    /// Example 1:
    /// Input: nums = [3,5,2,4]
    /// Output: 2
    /// Explanation: In the first operation: pick i = 2 and j = 1, the 
    /// operation is allowed because 2 * nums[2] <= nums[1]. Then mark 
    /// index 2 and 1.
    /// It can be shown that there's no other valid operation so the 
    /// answer is 2.
    ///
    /// Example 2:
    /// Input: nums = [9,2,5,4]
    /// Output: 4
    /// Explanation: In the first operation: pick i = 3 and j = 0, the 
    /// operation is allowed because 2 * nums[3] <= nums[0]. Then mark 
    /// index 3 and 0.
    /// In the second operation: pick i = 1 and j = 2, the operation is 
    /// allowed because 2 * nums[1] <= nums[2]. Then mark index 1 and 2.
    /// Since there is no other operation, the answer is 4.
    ///
    /// Example 3:
    /// Input: nums = [7,6,8]
    /// Output: 0
    /// Explanation: There is no valid operation to do, so the answer is 0.
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^9
    /// </summary>
    int maxNumOfMarkedIndices(vector<int>& nums);

    /// <summary>
    /// Leet Code 2555. Maximize Win From Two Segments
    /// 
    /// Medium
    ///	
    /// There are some prizes on the X-axis. You are given an integer array 
    /// prizePositions that is sorted in non-decreasing order, where 
    /// prizePositions[i] is the position of the ith prize. There could be 
    /// different prizes at the same position on the line. You are also given 
    /// an integer k.
    ///
    /// You are allowed to select two segments with integer endpoints. The 
    /// length of each segment must be k. You will collect all prizes whose 
    /// position falls within at least one of the two selected segments 
    /// (including the endpoints of the segments). The two selected segments 
    /// may intersect.
    ///
    /// For example if k = 2, you can choose segments [1, 3] and [2, 4], and 
    /// you will win any prize i that satisfies 1 <= prizePositions[i] <= 3 
    /// or 2 <= prizePositions[i] <= 4.
    /// Return the maximum number of prizes you can win if you choose the two 
    /// segments optimally.
    ///
    /// Example 1:
    /// Input: prizePositions = [1,1,2,2,3,3,5], k = 2
    /// Output: 7
    /// Explanation: In this example, you can win all 7 prizes by selecting 
    /// two segments [1, 3] and [3, 5].
    ///
    /// Example 2:
    /// Input: prizePositions = [1,2,3,4], k = 0
    /// Output: 2
    /// Explanation: For this example, one choice for the segments 
    /// is [3, 3] and [4, 4], and you will be able to get 2 prizes. 
    ///
    /// Constraints:
    /// 1. 1 <= prizePositions.length <= 10^5
    /// 2. 1 <= prizePositions[i] <= 10^9
    /// 3. 0 <= k <= 10^9 
    /// 4. prizePositions is sorted in non-decreasing order.
    /// </summary>
    int maximizeWin(vector<int>& prizePositions, int k);

    /// <summary>
    /// Leet Code 2743. Count Substrings Without Repeating Character
    /// 
    /// Medium
    ///
    /// You are given a string s consisting only of lowercase English letters. 
    /// We call a substring special if it contains no character which has 
    /// occurred at least twice (in other words, it does not contain a 
    /// repeating character). Your task is to count the number of special 
    /// substrings. For example, in the string "pop", the substring "po" is 
    /// a special substring, however, "pop" is not special (since 'p' has 
    /// occurred twice).
    ///
    /// Return the number of special substrings.
    /// 
    /// A substring is a contiguous sequence of characters within a string. 
    /// For example, "abc" is a substring of "abcd", but "acd" is not.
    ///
    /// 
    /// Example 1:
    /// Input: s = "abcd"
    /// Output: 10
    /// Explanation: Since each character occurs once, every substring is a 
    /// special substring. We have 4 substrings of length one, 3 of length 
    /// two, 2 of length three, and 1 substring of length four. So overall 
    /// there are 4 + 3 + 2 + 1 = 10 special substrings.
    ///
    /// Example 2:
    /// Input: s = "ooo"
    /// Output: 3
    /// Explanation: Any substring with a length of at least two contains a 
    /// repeating character. So we have to count the number of substrings of 
    /// length one, which is 3.
    ///
    /// Example 3:
    /// Input: s = "abab"
    /// Output: 7
    /// Explanation: Special substrings are as follows (sorted by their 
    /// start positions):
    /// Special substrings of length 1: "a", "b", "a", "b"
    /// Special substrings of length 2: "ab", "ba", "ab"
    /// And it can be shown that there are no special substrings with a length 
    /// of at least three. So the answer would be 4 + 3 = 7.
    ///
    /// Constraints:
    /// 1. 1 <= s.length <= 10^5
    /// 2. s consists of lowercase English letters
    /// </summary>
    int numberOfSpecialSubstrings(string s);

    /// <summary>
    /// Leet Code 2762. Continuous Subarrays
    /// 
    /// Medium
    ///
    /// You are given a 0-indexed integer array nums. A subarray of nums is 
    /// called continuous if:
    ///
    /// Let i, i + 1, ..., j be the indices in the subarray. Then, for each 
    /// pair of indices i <= i1, i2 <= j, 0 <= |nums[i1] - nums[i2]| <= 2.
    /// Return the total number of continuous subarrays.
    ///
    /// A subarray is a contiguous non-empty sequence of elements within an 
    /// array.
    /// 
    /// Example 1:
    /// Input: nums = [5,4,2,4]
    /// Output: 8
    /// Explanation: 
    /// Continuous subarray of size 1: [5], [4], [2], [4].
    /// Continuous subarray of size 2: [5,4], [4,2], [2,4].
    /// Continuous subarray of size 3: [4,2,4].
    /// Thereare no subarrys of size 4.
    /// Total continuous subarrays = 4 + 3 + 1 = 8.
    /// It can be shown that there are no more continuous subarrays.
    ///
    /// Example 2:
    /// Input: nums = [1,2,3]
    /// Output: 6
    /// Explanation: 
    /// Continuous subarray of size 1: [1], [2], [3].
    /// Continuous subarray of size 2: [1,2], [2,3].
    /// Continuous subarray of size 3: [1,2,3].
    /// Total continuous subarrays = 3 + 2 + 1 = 6.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^9
    /// </summary>
    long long continuousSubarrays(vector<int>& nums);

    /// <summary>
    /// Leet Code 2779. Maximum Beauty of an Array After Applying Operation
    /// 
    /// Medium
    ///
    /// You are given a 0-indexed array nums and a non-negative integer k.
    ///
    /// In one operation, you can do the following:
    ///
    /// Choose an index i that hasn't been chosen before from the range 
    /// [0, nums.length - 1].
    /// Replace nums[i] with any integer from the range 
    /// [nums[i] - k, nums[i] + k].
    /// The beauty of the array is the length of the longest subsequence 
    /// consisting of equal elements.
    ///
    /// Return the maximum possible beauty of the array nums after applying 
    /// the operation any number of times.
    ///
    /// Note that you can apply the operation to each index only once.
    ///
    /// A subsequence of an array is a new array generated from the original 
    /// array by deleting some elements (possibly none) without changing the 
    /// order of the remaining elements.
    ///
    /// Example 1:
    /// Input: nums = [4,6,1,2], k = 2
    /// Output: 3
    /// Explanation: In this example, we apply the following operations:
    /// - Choose index 1, replace it with 4 (from range [4,8]), 
    ///   nums = [4,4,1,2].
    /// - Choose index 3, replace it with 4 (from range [0,4]), 
    ///   nums = [4,4,1,4].
    /// After the applied operations, the beauty of the array nums is 3 
    /// (subsequence consisting of indices 0, 1, and 3).
    /// It can be proven that 3 is the maximum possible length we can achieve.
    ///
    /// Example 2:
    /// Input: nums = [1,1,1,1], k = 10
    /// Output: 4
    /// Explanation: In this example we don't have to apply any operations.
    /// The beauty of the array nums is 4 (whole array).
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 0 <= nums[i], k <= 10^5
    /// </summary>
    int maximumBeauty(vector<int>& nums, int k);


    /// <summary>
    /// Leet Code 2799. Count Complete Subarrays in an Array
    /// 
    /// Medium
    ///
    /// You are given an array nums consisting of positive integers.
    ///
    /// We call a subarray of an array complete if the following condition 
    /// is satisfied:
    ///
    /// The number of distinct elements in the subarray is equal to the 
    /// number of distinct elements in the whole array.
    /// Return the number of complete subarrays.
    ///
    /// A subarray is a contiguous non-empty part of an array.
    ///
    /// Example 1:
    ///
    /// Input: nums = [1,3,1,2,2]
    /// Output: 4
    /// Explanation: The complete subarrays are the following: [1,3,1,2], 
    /// [1,3,1,2,2], [3,1,2] and [3,1,2,2].
    ///
    /// Example 2:
    /// Input: nums = [5,5,5,5]
    /// Output: 10
    /// Explanation: The array consists only of the integer 5, so any 
    /// subarray is complete. The number of subarrays that we can choose is 10.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 1000
    /// 2. 1 <= nums[i] <= 2000
    /// </summary>
    int countCompleteSubarrays(vector<int>& nums);

    /// <summary>
    /// Leet Code 2831. Find the Longest Equal Subarray
    /// 
    /// Medium
    ///
    /// You are given a 0-indexed integer array nums and an integer k.
    ///
    /// A subarray is called equal if all of its elements are equal. Note that 
    /// the empty subarray is an equal subarray.
    ///
    /// Return the length of the longest possible equal subarray after 
    /// deleting at most k elements from nums.
    ///
    /// A subarray is a contiguous, possibly empty sequence of elements within 
    /// an array.
    ///
    /// Example 1:
    /// Input: nums = [1,3,2,3,1,3], k = 3
    /// Output: 3
    /// Explanation: It's optimal to delete the elements at index 2 and 
    /// index 4.
    /// After deleting them, nums becomes equal to [1, 3, 3, 3].
    /// The longest equal subarray starts at i = 1 and ends at j = 3 with 
    /// length equal to 3.
    /// It can be proven that no longer equal subarrays can be created.
    ///
    /// Example 2:
    /// Input: nums = [1,1,2,2,1,1], k = 2
    /// Output: 4
    /// Explanation: It's optimal to delete the elements at index 2 and 
    /// index 3.
    /// After deleting them, nums becomes equal to [1, 1, 1, 1].
    /// The array itself is an equal subarray, so the answer is 4.
    /// It can be proven that no longer equal subarrays can be created.
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= nums.length
    /// 3. 0 <= k <= nums.length
    /// </summary>
    int longestEqualSubarray(vector<int>& nums, int k);

    /// <summary>
    /// Leet Code 2841. Maximum Sum of Almost Unique Subarray
    /// 
    /// Medium
    ///
    /// You are given an integer array nums and two positive integers m and k.
    /// 
    /// Return the maximum sum out of all almost unique subarrays of length k 
    /// of nums. If no such subarray exists, return 0.
    ///
    /// A subarray of nums is almost unique if it contains at least m distinct 
    /// elements.
    ///
    /// A subarray is a contiguous non-empty sequence of elements within an 
    /// array.
    ///
    /// Example 1:
    ///
    /// Input: nums = [2,6,7,3,1,7], m = 3, k = 4
    /// Output: 18
    /// Explanation: There are 3 almost unique subarrays of size k = 4. These 
    /// subarrays are [2, 6, 7, 3], [6, 7, 3, 1], and [7, 3, 1, 7]. Among 
    /// these subarrays, the one with the maximum sum is [2, 6, 7, 3] which 
    /// has a sum of 18.
    ///
    /// Example 2:
    /// Input: nums = [5,9,9,2,4,5,4], m = 1, k = 3
    /// Output: 23
    /// Explanation: There are 5 almost unique subarrays of size k. These 
    /// subarrays are [5, 9, 9], [9, 9, 2], [9, 2, 4], [2, 4, 5], 
    /// and [4, 5, 4]. Among these subarrays, the one with the maximum sum 
    /// is [5, 9, 9] which has a sum of 23.
    ///
    /// Example 3:
    /// Input: nums = [1,2,1,2,1,2,1], m = 3, k = 3
    /// Output: 0
    /// Explanation: There are no subarrays of size k = 3 that contain at 
    /// least m = 3 distinct elements in the given array [1,2,1,2,1,2,1]. 
    /// Therefore, no almost unique subarrays exist, and the maximum sum is 0.
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 2 * 10^4
    /// 2. 1 <= m <= k <= nums.length
    /// 3. 1 <= nums[i] <= 10^9
    /// </summary>
    long long maxSum(vector<int>& nums, int m, int k);

    /// <summary>
    /// Leet Code 2904. Shortest and Lexicographically Smallest Beautiful 
    ///                 String
    /// 
    /// Medium
    ///
    /// You are given a binary string s and a positive integer k.
    ///
    /// A substring of s is beautiful if the number of 1's in it is exactly k.
    ///
    /// Let len be the length of the shortest beautiful substring.
    ///
    /// Return the lexicographically smallest beautiful substring of string s 
    /// with length equal to len. If s doesn't contain a beautiful substring, 
    /// return an empty string.
    ///
    /// A string a is lexicographically larger than a string b (of the same 
    /// length) if in the first position where a and b differ, a has a 
    /// character strictly larger than the corresponding character in b.
    ///
    /// For example, "abcd" is lexicographically larger than "abcc" because 
    /// the first position they differ is at the fourth character, and d is 
    /// greater than c.
    ///  
    /// Example 1:
    /// Input: s = "100011001", k = 3
    /// Output: "11001"
    /// Explanation: There are 7 beautiful substrings in this example:
    /// 1. The substring "100011001".
    /// 2. The substring "100011001".
    /// 3. The substring "100011001".
    /// 4. The substring "100011001".
    /// 5. The substring "100011001".
    /// 6. The substring "100011001".
    /// 7. The substring "100011001".
    /// The length of the shortest beautiful substring is 5.
    /// The lexicographically smallest beautiful substring with 
    /// length 5 is the substring "11001".
    ///
    /// Example 2:
    /// Input: s = "1011", k = 2
    /// Output: "11"
    /// Explanation: There are 3 beautiful substrings in this example:
    /// 1. The substring "1011".
    /// 2. The substring "1011".
    /// 3. The substring "1011".
    /// The length of the shortest beautiful substring is 2.
    /// The lexicographically smallest beautiful substring with length 2 
    /// is the substring "11".
    /// 
    /// Example 3:
    /// Input: s = "000", k = 1
    /// Output: ""
    /// Explanation: There are no beautiful substrings in this example.
    /// 
    /// Constraints:
    /// 1. 1 <= s.length <= 100
    /// 2. 1 <= k <= s.length
    /// </summary>
    string shortestBeautifulSubstring(string s, int k);
};
#endif  // LeetCodeTwoPointer
