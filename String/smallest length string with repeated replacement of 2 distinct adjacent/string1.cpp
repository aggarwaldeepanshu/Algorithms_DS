#include<bits/stdc++.h>
#define max 100
using namespace std;

class String
{
public:
int findLength(char []);
};

int String::findLength(char str[])
{
int n;
int freq[3]={0};

n=strlen(str);

for(int i=0;i<n;i++)
freq[str[i]-'a']++;

if(freq[0]==n || freq[1]==n || freq[2]==n)
return n;

if((freq[0]%2 == freq[1]%2) && (freq[1]%2)==freq[2]%2)
return 2;

return 1;
}

int main(void)
{
int i;
String ob;

char str[max];
cin.get(str,max);

cout<<ob.findLength(str);
}
