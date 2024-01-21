#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;


vector<string> findRepeatedDnaSequences(const string& s) {
    unordered_set<string> seen;
    unordered_set<string> repeated;

    vector<string> result;

    for (int i = 0; i <= s.length() - 10; ++i) {
        string current_sequence = s.substr(i, 10);

        if (seen.count(current_sequence) > 0) {
            repeated.insert(current_sequence);
        } else {
            seen.insert(current_sequence);
        }
    }

    for (const string& sequence : repeated) {
        result.push_back(sequence);
    }

    return result;
}

int main() {
    string dna_sequence = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    vector<string> result = findRepeatedDnaSequences(dna_sequence);

    cout << "Repeated DNA Sequences: ";
    for (const string& sequence : result) {
        cout << sequence << " ";
    }
    cout << endl;

    return 0;
}
