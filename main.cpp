// AlgoChat - A DSA-Powered Command-Line Chatbot
// Language: C++

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <stack>
using namespace std;

// ---------------------- Helper Functions ----------------------

vector<int> parseArray(string input) {
    vector<int> result;
    stringstream ss(input);
    int num;
    while (ss >> num) {
        result.push_back(num);
    }
    return result;
}

void printArray(const vector<int>& arr) {
    for (int num : arr) cout << num << " ";
    cout << "\n";
}

// ---------------------- DSA Algorithms ----------------------

vector<int> bubbleSort(vector<int> arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
    return arr;
}

int binarySearch(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

vector<int> reverseArray(const vector<int>& arr) {
    stack<int> s;
    for (int num : arr) s.push(num);
    vector<int> reversed;
    while (!s.empty()) {
        reversed.push_back(s.top());
        s.pop();
    }
    return reversed;
}

// ---------------------- Stack Operations ----------------------

stack<int> myStack;

void stackCommand(string cmd) {
    if (cmd.substr(0, 4) == "push") {
        int num = stoi(cmd.substr(5));
        myStack.push(num);
        cout << "Pushed " << num << "\n";
    } else if (cmd == "pop") {
        if (myStack.empty()) cout << "Stack is empty\n";
        else {
            cout << "Popped " << myStack.top() << "\n";
            myStack.pop();
        }
    } else if (cmd == "top") {
        if (myStack.empty()) cout << "Stack is empty\n";
        else cout << "Top: " << myStack.top() << "\n";
    }
}

// ---------------------- Main Chatbot Logic ----------------------

void processCommand(string input) {
    if (input.substr(0, 4) == "sort") {
        string arrStr = input.substr(5);
        vector<int> arr = parseArray(arrStr);
        arr = bubbleSort(arr);
        cout << "Sorted Array: ";
        printArray(arr);
    }
    else if (input.substr(0, 6) == "search") {
        size_t pos = input.find("in");
        if (pos == string::npos) {
            cout << "Invalid format. Try: search 5 in 1 2 3 4 5\n";
            return;
        }
        int target = stoi(input.substr(7, pos - 7));
        vector<int> arr = parseArray(input.substr(pos + 3));
        int idx = binarySearch(arr, target);
        if (idx != -1)
            cout << "Found at index: " << idx << "\n";
        else
            cout << "Not found\n";
    }
    else if (input.substr(0, 7) == "reverse") {
        vector<int> arr = parseArray(input.substr(8));
        vector<int> rev = reverseArray(arr);
        cout << "Reversed Array: ";
        printArray(rev);
    }
    else if (input.substr(0, 4) == "push" || input == "pop" || input == "top") {
        stackCommand(input);
    }
    else if (input == "help") {
        cout << "\nAvailable Commands:\n"
             << "sort <array>\n"
             << "search <target> in <array>\n"
             << "reverse <array>\n"
             << "push <number>\n"
             << "pop\n"
             << "top\n"
             << "exit\n\n";
    }
    else {
        cout << "Unknown command. Type 'help' for options.\n";
    }
}

int main() {
    cout << "Welcome to AlgoChat - Type 'help' to see commands.\n";
    string input;
    while (true) {
        cout << "\n> ";
        getline(cin, input);
        if (input == "exit") break;
        processCommand(input);
    }
    return 0;
}
