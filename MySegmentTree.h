#pragma once
#include<vector>
#include<algorithm>

using namespace std;

class my_segment_tree
{
public:
	my_segment_tree(const vector<int>& input)noexcept;
	int query(int qlow, int qhigh)noexcept;
	void update_node(int index, int value)noexcept;



private:
	int next_pow_2(int n)noexcept;
	int left(int node)noexcept;
	int right(int node)noexcept;
	void build(const vector<int>& input, int node, int low, int high)noexcept;
	int range_minimum_query(int qlow, int qhigh, int low, int high, int node)noexcept;
	void update_node(int node, int low, int high, int index, int value)noexcept;
	vector<int> st;
	int H;

};
//კონსტრუქტორი
my_segment_tree::my_segment_tree(const vector<int>& input) noexcept
{
	int size = next_pow_2(input.size()) * 2;
	H = input.size() - 1;  // შემოსული ვექტორის სიგრძე
	for (int i = 0; i < size; i++)
	{
		st.push_back(1);     //გამრავლების მიმართ ერთეულოვანი ელემენტია 1
	}
	build(input, 1, 0, H);

}
//მოთხოვნა დიაპაზონის ნიშნის დასადგენად
int my_segment_tree::query(int qlow, int qhigh) noexcept
{
	return range_minimum_query(qlow, qhigh, 0, H, 1);
}

//კვანძის განახლება ღია ფუნქცია
void my_segment_tree::update_node(int index, int value) noexcept
{
	update_node(1, 0, H, index, value);
}
//კვანძის განახლება პრივატული ფუნქცია
void my_segment_tree::update_node(int node, int low, int high, int index, int value) noexcept
{
	if (low == high)
		st[node] = value;
	else
	{

		int mid = (low + high) / 2;
		if (index <= mid)
		{
			update_node(left(node), low, mid, index, value);
		}
		else
		{
			update_node(right(node), mid + 1, high, index, value);
		}
		st[node] = st[left(node)] * st[right(node)];
	}
}
//რეკურსიული მოთხოვნა 
int my_segment_tree::range_minimum_query(int qlow, int qhigh, int low, int high, int node) noexcept
{
	if (qlow <= low && qhigh >= high)
		return st[node];
	if (qlow > high || qhigh < low)
		return 1;
	int mid = (low + high) / 2;

	return range_minimum_query(qlow, qhigh, low, mid, left(node)) *
		range_minimum_query(qlow, qhigh, mid + 1, high, right(node));

}
// n-ის შედეგი 2-ის ხარისხი
int my_segment_tree::next_pow_2(int n) noexcept
{

	int k = 1;
	while (k < n)k <<= 1;
	return k;
}

//st ვექტორის აშენება  
void my_segment_tree::build(const vector<int>& input, int node, int low, int high) noexcept
{
	if (low == high)
	{
		st[node] = input[low];

	}
	else
	{
		int mid = (low + high) / 2;
		build(input, left(node), low, mid);  //მარცხენა ქვეხის აშენება
		build(input, right(node), mid + 1, high);  // მარჯვენა ქვეხის აშენება
		st[node] = st[left(node)] * st[right(node)];   // კვანძში მნიშვნელობის ჩასმა
	}

}
//მარცხენა შვილი
int my_segment_tree::left(int node) noexcept
{
	return node << 1;
}
//მარჯვენა შვილი
int my_segment_tree::right(int node) noexcept
{
	return ((node << 1) + 1);
}

//რადგან მხოლოდ ნიშანი გვაინტერესებს ამიტომ მონაცემების
//კონვერტირება უფრო მარტივ რიცხვებზე უკეთესია
//ნამრავლებისთვის რომ გვეყოს int
int convert(int n) noexcept
{
	if (n > 0)return 1;
	else if (n < 0) return -1;
	return 0;
}