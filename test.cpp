#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class solution {
public:

    // 1. Floor in lava (Longest stable path)
    int longeststablepath(vector<int>& arr, int k) {
        int n = arr.size();
        if (n == 0) return 0;

        int maxi = 1, count = 1;
        for (int i = 0; i < n - 1; i++) {
            if (abs(arr[i + 1] - arr[i]) <= k) {
                count++;
                maxi = max(maxi, count);
            } else {
                count = 1;
            }
        }
        return maxi;
    }

    // 2. Missing pages in a book
    vector<string> missingpages(vector<int>& book, int N) {
        vector<string> ans;
        int n = book.size();
        if (n == 0) return ans;

        sort(book.begin(), book.end());

        if (book[0] > 1) {
            if (book[0] == 2)
                ans.push_back("1");
            else
                ans.push_back("1-" + to_string(book[0] - 1));
        }

        for (int i = 0; i < n - 1; i++) {
            if (book[i + 1] - book[i] > 1) {
                if (book[i + 1] - book[i] == 2)
                    ans.push_back(to_string(book[i] + 1));
                else
                    ans.push_back(to_string(book[i] + 1) + "-" + to_string(book[i + 1] - 1));
            }
        }

        if (book[n - 1] < N) {
            if (N - book[n - 1] == 1)
                ans.push_back(to_string(N));
            else
                ans.push_back(to_string(book[n - 1] + 1) + "-" + to_string(N));
        }

        return ans;
    }

    // 3. Encrypted palindrome
    bool palindrome(string str) {
        unordered_map<char, char> mpp = {
            {'a','e'}, {'e','i'}, {'i','o'}, {'o','u'}, {'u','a'}
        };

        for (char& c : str)
            if (mpp.count(c)) c = mpp[c];

        string rev = str;
        reverse(rev.begin(), rev.end());

        return str == rev;
    }

    // 4. Mirror word
    bool mirror(string& str) {
        unordered_map<char, char> mpp = {
            {'b','d'}, {'d','b'}, {'p','q'}, {'q','p'}
        };

        int i = 0, j = str.size() - 1;
        while (i <= j) {
            if (mpp.find(str[i]) == mpp.end() || mpp[str[i]] != str[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    // 5. Candy crush string
    string candy(string s) {
        stack<char> st;
        for (char c : s) {
            if (!st.empty() && abs(st.top() - c) == 32)
                st.pop();
            else
                st.push(c);
        }

        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    // 6. Delete node by value in linked list
    Node* llist(Node* head, int x) {
        Node* dummy = new Node();
        dummy->next = head;
        Node* curr = dummy;

        while (curr->next != NULL) {
            if (curr->next->data == x) {
                Node* temp = curr->next;
                curr->next = temp->next;
                delete temp;
            } else {
                curr = curr->next;
            }
        }

        head = dummy->next;
        delete dummy;
        return head;
    }
};

int main() {
    solution s;
    int choice;

    while (true) {
        cout << "\n1. Floor in lava\n";
        cout << "2. Missing pages\n";
        cout << "3. Encrypted palindrome\n";
        cout << "4. Mirror word\n";
        cout << "5. Candy crush\n";
        cout << "6. Delete node by value\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            int k, n;
            cout << "Enter k: ";
            cin >> k;
            cout << "Enter array size: ";
            cin >> n;

            vector<int> vec(n);
            cout << "Enter elements:\n";
            for (int i = 0; i < n; i++)
                cin >> vec[i];

            cout << s.longeststablepath(vec, k) << endl;
            break;
        }

        case 2: {
            int N, m;
            cout << "Enter total pages: ";
            cin >> N;
            cout << "Enter number of existing pages: ";
            cin >> m;

            vector<int> book(m);
            cout << "Enter page numbers:\n";
            for (int i = 0; i < m; i++)
                cin >> book[i];

            vector<string> res = s.missingpages(book, N);
            for (string& x : res)
                cout << x << " ";
            cout << endl;
            break;
        }

        case 3: {
            string str;
            cout << "Enter string: ";
            cin >> str;
            cout << s.palindrome(str) << endl;
            break;
        }

        case 4: {
            string str;
            cout << "Enter string: ";
            cin >> str;
            cout << s.mirror(str) << endl;
            break;
        }

        case 5: {
            string str;
            cout << "Enter string: ";
            cin >> str;
            cout << s.candy(str) << endl;
            break;
        }

        case 6: {
            Node* head = NULL;
            Node* tail = NULL;

            cout << "Enter linked list elements (-1 to stop): ";
            int num;
            while (true) {
                cin >> num;
                if (num == -1) break;

                Node* newNode = new Node{num, NULL};
                if (!head) {
                    head = tail = newNode;
                } else {
                    tail->next = newNode;
                    tail = newNode;
                }
            }

            int x;
            cout << "Enter value to delete: ";
            cin >> x;

            head = s.llist(head, x);

            cout << "Linked List: ";
            Node* temp = head;
            while (temp) {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
            break;
        }

        case 0:
            cout << "Exiting program...\n";
            return 0;

        default:
            cout << "Invalid choice!\n";
        }
    }
}

