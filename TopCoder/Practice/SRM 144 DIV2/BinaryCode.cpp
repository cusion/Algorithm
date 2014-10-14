#include <vector>
#include <string>
using namespace std;

class BinaryCode {
private:
	int decode(int enc, int pre1, int pre2) {
		return enc-pre1-pre2;
	}
	bool checkValid(string dec, string enc) {
		int len = enc.length();
		if (len == 1) {
			return enc[0] == dec[0];
		} else {
			return enc[len-1] == dec[len-1] + dec[len-2] - '0';
		}
	}
public:
	vector <string> decode(string message) {
		vector <string> ret;
		ret.push_back("NONE");
		ret.push_back("NONE");
		if (message.empty()) {
			return ret;
		}
		
		int len = message.length();
		
		for (int exp = 0; exp < 2; ++exp) {		
			string dec = "";
			dec.append(1, exp+'0');
			bool isValid = true;
			for (int i = 0; i < len-1; ++i) {
				int enc = message[i] - '0';
				int pre1 = dec[i] - '0';
				int pre2 = 0;
				if (i > 0) {
					pre2 = dec[i-1] - '0';
				}
				int code = decode(enc, pre1, pre2);
				if (code > 1 || code < 0) {
					isValid = false;
					break;
				}
				dec.append(1, code+'0');
			}
			if (isValid && checkValid(dec, message)) {
				ret[exp] = dec;
			}
		}
		
		return ret;
	}
};
