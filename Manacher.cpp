string preprocess(string s) {
	int n = s.size();
	if(n == 0) return "^$";
	string res = "^";

	for(int i = 0 ; i < n ; ++i) {
		res += "#" + s.substr(i, 1);
	}

	res += "#$";
	return res;
}

string manacher(string s) {
	string t = preprocess(s);
	int n = t.size();
	int *p = new int[n];
	int c = 0, r = 0;

	for(int i = 1 ; i < n - 1 ; ++i) {
		int i_mirror = 2 * c - i;
		p[i] = (r > i) ? min(r - i, p[i_mirror]) : 0;

		while(t[i + 1 + p[i]] == t[i - 1 - p[i]]) p[i]++;
		if(i + p[i] > r) {
			c = i;
			r = i + p[i];
		}
	}

	int maxlen = 0;
	int ce = 0;
	for(int i = 1 ; i < n - 1 ; ++i) {
		if(p[i] > maxlen) {
			maxlen = p[i];
			ce = i;
		}
	}

	return s.substr((ce - 1 - maxlen) / 2, maxlen);
}
