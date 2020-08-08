#include <bits/stdc++.h>

using namespace std;

string s;

bool ok(string t){
    int msk = 0;
    
    for(int i = 0; i < int(t.size()); ++i){
	    if(isupper(t[i])) msk |= 1;
	    if(islower(t[i])) msk |= 2;
	    if(isdigit(t[i])) msk |= 4;
	}
	
	return msk == 7;
}

int main() {
	//freopen("input.txt", "r", stdin);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
    	cin >> s;
    	if(ok(s)){
    	    cout << s << endl;
    	    continue;
    	}
    	bool fnd = false;
        for(int i = 0; i < int(s.size()); ++i){
            string t = s;
            
            t[i] = '1';
            if(ok(t)){
    	        cout << t << endl;
    	        fnd = true;
    	        break;
    	    }
            t[i] = 'a';
            if(ok(t)){
    	        cout << t << endl;
    	        fnd = true;
    	        break;
    	    }
    	    t[i] = 'A';
            if(ok(t)){
    	        cout << t << endl;
    	        fnd = true;
    	        break;
    	    }
        }
    	
    	if(fnd) continue;
    	
    	if(isupper(s[2])){
    	    s[0] = 'a';
    	    s[1] = '1';
    	    cout << s << endl;
    	    continue;
    	}
    	if(islower(s[2])){
    	    s[0] = 'A';
    	    s[1] = '1';
    	    cout << s << endl;
    	    continue;
    	}
    	if(isdigit(s[2])){
    	    s[0] = 'a';
    	    s[1] = 'A';
    	    cout << s << endl;
    	    continue;
    	}
	}
	return  0;
}