#include <iostream>
#include <string>

using namespace std;

constexpr int maxN = 2000001;
int pushData[maxN];
int popData[maxN];

int pushIdx = -1;
int popIdx = -1;

int empty() {
	return ((pushIdx < 0 && popIdx < 0) ? 1 : 0);
}

void slide() {
	while (0 <= pushIdx) {
		popIdx += 1;
		popData[popIdx] = pushData[pushIdx];
		pushIdx -= 1;
	}
}

void push(int X) {
	pushIdx += 1;
	pushData[pushIdx] = X;
}

int front() {
	if (1 == empty()) return -1;

	if (popIdx < 0) {
		return pushData[0];
	}

	return popData[popIdx];
}

int pop() {
	if (1 == empty()) return -1;

	if (popIdx < 0) slide();

	auto result = front();
	popIdx -= 1;

	return result;
}

int size() {
	return pushIdx + popIdx + 2;
}

int back() {
	if (1 == empty()) return -1;

	if (pushIdx < 0) {
		return popData[0];
	}

	return pushData[pushIdx];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	auto N = int{};
	cin >> N;

	while (0 < (N--)) {
		auto op = string{};
		cin >> op;

		if ("push" == op) {
			int X;
			cin >> X;
			push(X);
		}
		else if ("pop" == op) {
			auto v = pop();
			cout << v << '\n';
		}
		else if ("size" == op) {
			cout << size() << '\n';
		}
		else if ("empty" == op) {
			cout << empty() << '\n';
		}
		else if ("front" == op) {
			cout << front() << '\n';
		}
		else if ("back" == op) {
			cout << back() << '\n';
		}
	}

	return 0;
}