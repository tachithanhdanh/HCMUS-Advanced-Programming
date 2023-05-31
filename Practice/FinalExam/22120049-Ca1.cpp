#include <iostream>
#include <algorithm>
#include <fstream>

// pass de: 123456

using std::cout;
using std::cin;

struct Node;
using Node_ptr = Node*;

struct Node {
	int data;
	Node_ptr next;
	Node();
	Node(int data_, Node_ptr next_ = nullptr);
};

struct Pair {
	int first;
	int second;
	Pair(int first_ = 0, int second_ = 0);
};

using Pair_ptr = Pair*;

void addHead(Node_ptr& head, int data);

void sieve(bool*& isPrime, int*& prime, int n, int& numPrime);
void solve();
void problem12();
void displayList(Node_ptr head);
void deleteList(Node_ptr& head);
unsigned int countPrime(Node_ptr head);
void problem3();
Pair_ptr primeFactorization(int num, int* prime, int numPrime, int& numPrimeFactors);
int** createCustomMatrix(Pair_ptr pairArr, int size);
void displayMatrix(int** matrix, int numRows, Pair_ptr pairArr);
void deleteMatrix(int**& matrix, int numRows);

int main()
{
	solve();
	return 0;
}

Node::Node() : data(0), next(nullptr) {}
Node::Node(int data_, Node_ptr next_) : data(data_), next(next_) {}
Pair::Pair(int first_, int second_): first(first_), second(second_) {}

void solve() {
	problem12();
	problem3();
}

void problem12() {
	int n;

	cout << "Cau 1:\n";
	cout << "Moi thay nhap n = ";
	cin >> n;
	Node_ptr head = nullptr;
	for (int i = 1; i < n; ++i) {
		if (n % i == 0) {
			addHead(head, i);
		}
	}
	cout << "Danh sach lien ket don chua cac uoc cua n.\n";
	displayList(head);

	cout << "Cau 2:\n";
	cout << "So luong node trong danh sach lien ket: " << countPrime(head) << "\n";
	deleteList(head);
}

void displayList(Node_ptr head) {
	if (head == nullptr) {
		cout << "Danh sach rong!\n";
		return;
	}
	Node_ptr cur = head;
	cout << "Danh sach lien ket don:\n";
	while (cur->next) {
		cout << cur->data;
		cout << "-->";
		cur = cur->next;
	}
	cout << cur->data;
	cout.put('\n');
}

void addHead(Node_ptr& head, int data) {
	Node_ptr newHead = new Node(data, head);
	head = newHead;
}

void deleteList(Node_ptr& head) {
	Node_ptr oldHead;
	while (head) {
		oldHead = head;
		head = head->next;
		delete oldHead;
	}
}

unsigned int countPrime(Node_ptr head) {
	if (head == nullptr) {
		return 0;
	}
	return 1 + countPrime(head->next);
}

void problem3() {
	cout << "Cau 3:\n";
	int n;
	cout << "Moi thay nhap n = ";
	cin >> n;
	bool* isPrime = nullptr;
	int* prime = nullptr;
	int numPrime = 0;
	sieve(isPrime, prime, n + 10, numPrime);
	int numPrimeFactors = 0;
	Pair_ptr pairArr = primeFactorization(n, prime, numPrime, numPrimeFactors);
	int** primeMatrix = createCustomMatrix(pairArr, numPrimeFactors);
	displayMatrix(primeMatrix, numPrimeFactors, pairArr);
	deleteMatrix(primeMatrix, numPrimeFactors);
	delete[] prime;
	prime = nullptr;
	delete[] isPrime;
	isPrime = nullptr;
}

void sieve(bool*& isPrime, int*& prime, int n, int& numPrime) {
	isPrime = new bool[n + 1]{};
	for (int i = 0; i <= n; ++i) {
		isPrime[i] = true;
	}
	isPrime[0] = false;
	isPrime[1] = false;
	for (int i = 4; i <= n; i += 2) {
		isPrime[i] = false;
	}
	for (int i = 3; i * i <= n; i += 2) {
		if (isPrime[i]) {
			for (int j = i * i; j <= n; j += i) {
				isPrime[j] = false;
			}
		}
	}
	for (int i = 0; i <= n; ++i) {
		numPrime += isPrime[i];
	}
	prime = new int[numPrime];
	int pos = 0;
	for (int i = 0; i <= n; ++i) {
		if (isPrime[i]) {
			prime[pos++] = i;
		}
	}
}

Pair_ptr primeFactorization(int num, int* prime, int numPrime, int& numPrimeFactors) {
	numPrimeFactors = 0;
	for (int i = 0; i < numPrime; ++i) {
		if (num % prime[i] == 0) {
			//cout << prime[i] << std::endl;
			++numPrimeFactors;
		}
	}
	Pair_ptr pairArr = new Pair[numPrimeFactors];
	int curPairPos = 0;
	for (int i = 0; i < numPrime; ++i) {
		if (num < prime[i] || num == 1) {
			break;
		}
		if (num % prime[i] == 0) {
			int count = 0;
			while (num % prime[i] == 0) {
				++count;
				num /= prime[i];
			}
			pairArr[curPairPos++] = Pair(prime[i], count);
		}
	}

	return pairArr;
}

int** createCustomMatrix(Pair_ptr pairArr, int size) {
	int** matrix = new int* [size];
	for (int i = 0; i < size; ++i) {
		int curRowSize = pairArr[i].second + 1;
		matrix[i] = new int[curRowSize];
		int cur = 1;
		for (int j = curRowSize - 1; j >= 0; --j) {
			matrix[i][j] = cur;
			cur *= pairArr[i].first;
		}
	}
	return matrix;
}

void displayMatrix(int** matrix, int numRows, Pair_ptr pairArr) {
	cout << "Ma tran rang cua: \n";
	for (int i = 0; i < numRows; ++i) {
		for (int j = 0; j < pairArr[i].second + 1; ++j) {
			cout << matrix[i][j] << " \n"[j == pairArr[i].second];
		}
	}
}

void deleteMatrix(int**& matrix, int numRows) {
	for (int i = 0; i < numRows; ++i) {
		delete[] matrix[i];
		matrix[i] = nullptr;
	}
	delete[] matrix;
	matrix = nullptr;
}
