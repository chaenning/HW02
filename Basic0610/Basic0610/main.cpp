#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


void swapRef(int& a, int& b) {
	cout << " - - - - swap - - - -" << endl;
	int temp = a;
	a = b;
	b = temp;
}

void swapP(int* a, int* b) {
	cout << " - - - - swap - - - -" << endl;
	int temp = *a;
	*a = *b;
	*b = temp;
}

vector<int> solution(vector<int> arr, int divisor) {
	vector<int> answer;
	bool isAnswer = false;
	for (int num : arr) {
		if (num % divisor == 0) {
			answer.push_back(num);
			isAnswer = true;
		}
	}

	if (isAnswer) {
		sort(answer.begin(), answer.end());
	}
	else { answer.push_back(-1); }

	return answer;
}


long long solution(long long n) {
	string s = to_string(n);
	sort(s.rbegin(), s.rend());  // 내림차순 정렬
	return stoll(s);
}

int main() {
	//int num1 = 10;
	//int num2 = 99;

	//cout << "num1 : " << num1 << ", num2 : " << num2 << endl;

	//swapP(&num1, &num2);

	//cout << "num1 : " << num1 << ", num2 : " << num2 << endl;

	cout << solution(16815);
	return 0;
}