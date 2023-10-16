#include<iostream>
#include<vector>
using namespace std;


void permute(string& s, vector<string>& ans, int index) {
    // If we have reached the end of the string, add the permutation to the result
    if (index == s.length() - 1) {
        ans.push_back(s);
        return;
    }

    // Iterate through the remaining characters in the string
    for (int i = index; i < s.length(); i++) {
        // Swap the current character with the character at the current index
        swap(s[i], s[index]);

        // Recur for the remaining characters
        permute(s, ans, index + 1);

        // Backtrack by restoring the original order of characters as string is passed by reference
        swap(s[i], s[index]);
    }
}

int main() {
    string s;
    cout << "Enter string to find permutations : ";
    getline(cin, s);
    vector<string> ans;

    // Generate permutations
    permute(s, ans, 0);

    // Print the permutations
    cout << "All the permutaions are : ";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
