#include<string>
#include<vector>
using namespace std;
class BinaryCode {
	public:
	vector<string> decode(string str)
	{
		int aa;
		int bb;
		std::vector<string> res_vec;
		string res_str = str;
		res_str[0] = '0';
		for (int i = 1; i < str.size(); i++) {
			int n;
			n = str[i - 1]  - res_str[i - 1] ;
			if (n < 0) {
				res_str = "NONE";
				break;
			}
			if (i > 1)
				n -= res_str[i - 2] - '0';
			if (n > 1 || n < 0) {
				res_str = "NONE";
				break;
			}
			res_str[i] = n + '0';
		}
		if (str[str.size() - 1] - '0' != res_str[res_str.size() - 1] - '0' + res_str[res_str.size() - 1] - '0')
			res_str = "NONE";
		res_vec.push_back(res_str);
		res_str = str;
		res_str[0] = '1';
		for (int i = 1; i < str.size(); i++) {
			int n;
			n = str[i - 1]  - res_str[i - 1] ;
			if (n < 0) {
				res_str = "NONE";
				break;
			}
			if (i > 1)
				n -= res_str[i - 2] - '0';
			if (n > 1 || n < 0) {
				res_str = "NONE";
				break;
			}
			res_str[i] = n + '0';
		}
		res_vec.push_back(res_str);
		return res_vec;
	}
};
