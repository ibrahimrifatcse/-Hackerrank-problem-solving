#include <iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<fstream>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



long repeatedString(string s, long n) {
int len=s.length();
long running_count[len] ={0};
if(s[0]=='a')
running_count[0]=1;

for(int i=1;i<len;++i)
{
    running_count[i]=running_count[i-1];
    if(s[i]=='a')
       running_count[i]+=1;
       
}

     long k=n/len;
     long remaining_count=(n%len==0)?0:running_count[n%len-1];
     long total_count=k*running_count[len-1]+remaining_count;
     
     return total_count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string n_temp;
    getline(cin, n_temp);

    long n = stol(ltrim(rtrim(n_temp)));

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
