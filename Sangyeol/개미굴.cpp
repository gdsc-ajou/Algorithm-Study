//BOJ 14725 °³¹Ì±¼
#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct Node
{
	string feed;
	map<string, int> mp;
	vector<Node*> childs;
};

void print(Node& node, int length) {
	if (node.feed != "") {
		if (length != 0) {
			for (int i = length * 2; i != 0; i--) {
				cout << '-';
			}
		}
		cout << node.feed << '\n';
	}
	for (auto iter : node.mp) {
		print(*node.childs[iter.second], length + 1);
	}
}

int main() {
	int N;
	int K;
	Node root;

	cin >> N;
	while (N--) {
		cin >> K;
		string temp;
		Node* current = &root;
		while (K--)
		{
			cin >> temp;
			auto iter = (*current).mp.find(temp);
			if (iter == (*current).mp.end()) {
				Node* tempNode = new Node;
				tempNode->feed = temp;
				current->mp.insert({ temp, current->childs.size() });
				current->childs.push_back(tempNode);
				current = tempNode;
			}
			else {
				current = current->childs[iter->second];
			}
		}
	}

	print(root, -1);
}