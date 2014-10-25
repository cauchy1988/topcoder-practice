#include<string.h>
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

class Lottery {
	public:
		struct node {
			int idx;
			unsigned long long value;
			string name;
			node(int i, string str):idx(i),value(0),name(str){};
		};
		static bool mycmp(const node &a, const node &b)
		{
			return a.value < b.value || (a.value == b.value && a.name < b.name);
		}
		static unsigned long long combol(int n, int m) 
		{
			unsigned long long res;
			int k;
			k = m;
			res = 1;
			while (m) {
				res *= n;
				--n;
				--m;
				if (res % k == 0)
					res /= k--;
			}
			while (k)
				res /= k--;
			return res;
		}
		vector<string> sortByOdds(vector<string> rules)
		{
			vector<string> name_vec;
			vector<int> choices_vec;
			vector<int>blanks_vec;
			vector<bool>sorted_vec;
			vector<bool>unique_vec;
			vector<string>res_vec;
			for (vector<string>::iterator iter = rules.begin(); iter != rules.end(); ++iter) {
				int pos;
				pos = iter->find(":");
				name_vec.push_back(string(iter->begin(), iter->begin() + pos));
				pos += 2;
				int n;
				n = 0;
				while ((*iter)[pos] != ' ') {
					n = n * 10 + (*iter)[pos] - '0';
					++pos;
				}
				++pos;
				choices_vec.push_back(n);
				n = 0;
				while ((*iter)[pos] != ' ') {
					n = n * 10 + (*iter)[pos] - '0';
					++pos;
				}
				++pos;
				blanks_vec.push_back(n);
				bool is_sort;
				if ((*iter)[pos] == 'T')
					is_sort = true;
				else
					is_sort = false;
				
				pos += 2;
				sorted_vec.push_back(is_sort);
				bool is_unique;
				if ((*iter)[pos] == 'T') 
					is_unique = true;
				else 
					is_unique = false;
				unique_vec.push_back(is_unique);
			}	
			vector<node> node_vec;
			for (int i = 0; i < name_vec.size(); ++i) {
				node nn(i, name_vec[i]);
				unsigned long long num = 1;
				if (!unique_vec[i] && !sorted_vec[i]) {
					int n, m;
					n = choices_vec[i];
					m = blanks_vec[i];
					while (m) {
						num *= n;
						--m;
					}
				} else if (!sorted_vec[i]) {
					int n, m;
					n = choices_vec[i];
					m = blanks_vec[i];
					while (m) {
						num *= n;
						--n;
						--m;
					}
				} else if (!unique_vec[i]) {
					int n, m;
					n = choices_vec[i];
					m = blanks_vec[i];
					for (int j = 1; j <= m; j++) {
						num += combol(n, j) * combol(m  -  1, j - 1);
					}
					
				} else {
					int n, m;
					n = choices_vec[i];
					m = blanks_vec[i];
					int k = m;
					while (m) {
						num *= n;
						--n;
						--m;
						if (num % k == 0)
							num /= k--;
					}
					while (k) {
						num /= k--;
					}
				}
				nn.value = num;
				node_vec.push_back(nn); 
			}
			sort(node_vec.begin(), node_vec.end(), mycmp);
			for (int i = 0; i < node_vec.size(); i++) {
				res_vec.push_back(node_vec[i].name);
			}
			return res_vec;
		}
};
