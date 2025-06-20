// ******** Given two arrays A and B of equal size N, the task is to find if given arrays are equal or not. Two arrays are said to be equal if both of them contain same set of elements, arrangements (or permutation) of elements may be different though ********
// Note --> If there are repetitions, then counts of repeated elements must also be same for two array to be equal.

// <======== Example ========>
// Input: N = 5, A[] = {1,2,5,4,0}, B[] = {2,4,5,0,1}
// Output: 1

// Input: N = 3, A[] = {1,2,5}, B[] = {2,4,15}
// Output: 0


// Expected Time Complexity ==> O(N)
// Expected Auxiliary Space ==> O(N)



Approach 1: 
class Solution{
    public:
    bool check(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
        
        for(int i = 0; i < n; i++) {
            if(arr1[i] != arr2[i]) {
                return false;
            }
        }
        
        return true;
    }
};

TC=O(nlogn) SC=O(1)

Approach 2:
bool checkEqual(vector<int>& a, vector<int>& b) {
  	int n = a.size(), m = b.size();
    if (n != m)
        return false;

    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[a[i]]++;

    for (int i = 0; i < n; i++) {
        if (mp.find(b[i]) == mp.end())
            return false;

        if (mp[b[i]] == 0)
            return false;
      
        mp[b[i]]--;
    }
    return true;
}
TC=O(n) SC=O(n)

