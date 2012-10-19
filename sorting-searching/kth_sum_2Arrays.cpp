#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define MID(min, max) ( (min) + ( (max - min)>> 1 ) )

int GetSmallerPairsCount(const vector<int>& A,
                         const vector<int>& B,
                         const int sum) {
  int num_smaller_pairs = 0;
  int temp = 0;
  // O(n) loop
  for (int A_index = A.size() - 1, B_index = 0; A_index >= 0; --A_index) {
    for (; B_index < B.size(); ++B_index) {
      if (A[A_index] + B[B_index] <= sum) {
        ++temp;
      } else {
        break;
      }
    }
    num_smaller_pairs += temp;
  }
  return num_smaller_pairs;
}

bool CheckIfSumExists(const vector<int>& A, const vector<int>& B, int sum) {
  // O(n) loop
  for (int a = A.size() - 1, b = 0; a >= 0 && b < B.size();) {
    if (A[a] + B[b] == sum) return true;
    if (A[a] + B[b] < sum) {
      ++b;
    } else {
      --a;
    }
  }
  return false;
}

int FindNextLargestSum(const vector<int>& A,
                       const vector<int>& B,
                       const int sum) {
  int new_sum, n_l = A.back() + B.back();
  // O(n) loop
  for (int A_index = A.size() - 1, B_index = 0;
      A_index >= 0 && B_index < B.size();) {
    new_sum = A[A_index] + B[B_index];
    if ((n_l > new_sum) && (new_sum > sum)) {
      n_l = new_sum;
    }
    if (new_sum <= sum) {
      ++B_index;
    } else {
      --A_index;
    }
  }
  return n_l;
}

int FindPreviousSmallestSum(const vector<int>& A,
                            const vector<int>& B,
                            const int sum) {
  int new_sum, p_s = A.front() + B.front();
  // O(n) loop
  for (int A_index = A.size() - 1, B_index = 0;
      A_index >= 0 && B_index < B.size();) {
    new_sum = A[A_index] + B[B_index];
    if ((p_s < new_sum) && (new_sum < sum)) {
      p_s = new_sum;
    }
    if (new_sum < sum) {
      ++B_index;
    } else {
      --A_index;
    }
  }
  return p_s;
}

// O(n*log(n)) order with O(1) extra space
int KthSmallestPairSum(const vector<int>& A,
                       const vector<int>& B,
                       const int k) {
  int max = A.back() + B.back();
  int min = A.front() + B.front();
  // O(log(n)) loop
  while (1) {
    int curr_mid = CheckIfSumExists(A, B, MID(min, max)) ? MID(min, max) : FindNextLargestSum(A, B, MID(min, max));
    int prev_mid = FindPreviousSmallestSum(A, B, curr_mid);
    int next_mid = FindNextLargestSum(A, B, curr_mid);

    int curr_mid_smaller = GetSmallerPairsCount(A, B, curr_mid);
    int prev_mid_smaller = GetSmallerPairsCount(A, B, prev_mid);
    int next_mid_smaller = GetSmallerPairsCount(A, B, next_mid);

    if (k == prev_mid_smaller) return prev_mid;
    if (prev_mid_smaller < k && next_mid_smaller >= k) {
      if (curr_mid_smaller < k) return next_mid;
      return curr_mid;
    }

    if (prev_mid_smaller > k) {
      max = FindPreviousSmallestSum(A, B, prev_mid);
    } else if (next_mid_smaller < k) {
      min = FindNextLargestSum(A, B, next_mid);
    } else {
      cout << "BUG\n";
      exit(0);
    }
  }
  return -2;
}

int main() {
  int size;
  cout << "Length of first array: " ;
  cin >> size;
  cout << "Enter the elements of first array\n";
  vector<int> A;
  for (int t = -1; size > 0; --size) {
    cin >> t;
    A.push_back(t);
  }
  cout << "Size of second array: ";
  cin >> size;
  vector<int> B;
  for (int t = -1; size > 0; --size) {
    cin >> t;
    B.push_back(t);
  }
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());

  // Build the brute-force solution beforehand to compare
  // the results of our optimized method
  vector<int> brute;
  for (int i = 0; i < A.size(); ++i) {
    for (int j = 0; j < B.size(); ++j) {
      brute.push_back(A[i] + B[j]);
    }
  }
  sort(brute.begin(), brute.end());

  for (int kk = 1; kk <= A.size() * B.size(); ++kk) {
    int k = kk;
    if (k < 1 || k > A.size() * B.size()) {
      cout << "Invalid k. 1 <= k <= " << A.size() * B.size();
    } else {
      int result = KthSmallestPairSum(A, B, k);
      if (result != brute[k-1]) {
        cout << "Method broke. Wake up Avi !!";
        exit(0);
      }
      cout << k << "th smallest pair sum: " << result;
    }
    cout << endl;
  }
  cout << "All Iz Bhel !! " << endl;
  return 0;
}

