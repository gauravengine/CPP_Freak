//WAP for generating next combination in lexicographic order
#include <iostream>

using namespace std;

void Swap(char* a, char* b)
{
    if (*a == *b)
        return;
    //*a ^= *b;
    //*b ^= *a;
    //*a ^= *b;
}
void rev(string& s, int l, int r)
{
    while (l < r)
        Swap(&s[l++], &s[r--]);
}

int bsearch(string& s, int l, int r, int key)
{
    int index = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (s[mid] <= key)
            r = mid - 1;
        else {
            l = mid + 1;
            if (index == -1 || s[index] >= s[mid])
                index = mid;
        }
    }
    return index;
}

bool nextpermutation(string& s)
{
    int len = s.length(), i = len - 2;
    while (i >= 0 && s[i] >= s[i + 1])
        --i;
    if (i < 0)
        return false;
    else {
        int index = bsearch(s, i + 1, len - 1, s[i]);
        Swap(&s[i], &s[index]);
        rev(s, i + 1, len - 1);
        return true;
    }
}

// Driver code
int main()
{
    string s ;
    cout<<"Enter the string : ";
    cin>>s;
    bool val = nextpermutation(s);
    if (val == false)
        cout << "No Word Possible" << endl;
    else
        cout << s << endl;
    return 0;
}
