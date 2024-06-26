#include <iostream>
using namespace std;

class String {
private:
    char* data;
    int length;

public:
    // Default constructor
    String() {
        data = nullptr;
        length = 0;
    }

    // Alternate constructor that initializes length to size and initializes data to a new char array of size.
    String(int size) {
        length = size;
        data = new char[length + 1];
        data[length] = '\0';
    }

    // Alternate constructor that initializes length to size of str, initializes data to a new char array of size length and fills the contents of data with the contents of str.
    String(const char* str) 
	{
        int i = 0;
        while (str[i] != '\0') {
            ++i;
        }
        length = i;
        data = new char[length + 1];
        for (int i = 0; i < length; ++i) {
            data[i] = str[i];
        }
        data[length] = '\0';
    }

    // Copy constructor
    String(const String& str) {
        length = str.length;
        data = new char[length + 1];
        for (int i = 0; i < length; ++i) {
            data[i] = str.data[i];
        }
        data[length] = '\0';
    }


    
    // Get the length of the string
    int strLength() const
	{
        return length;
    }
    
    //empty the string
    void clear() 
	{
        delete[] data;
        data = new char[1];
        data[0] = '\0';
        length = 0;
    }

    // Check if the string object is empty
    bool empty() const
	 {
        return (length == 0);
    }

	// Return the index of the first occurrence of a character
    int charAt(char c) const
	{
        for (int i = 0; i < length; i++) {
            if (data[i] == c) {
                return i;
            }
        }
        return -1; // not found
    }

	// Getter for the actual string
    char* getdata() const
	{
        return data;
    }
	
	bool equals(char*str) const
	{
	    int i = 0;
    while (i < length && data[i] == str[i]) {
        i++;
    }
	if(data[i]=='\0')
	return true;
	else
	return false;	
	}
	
	bool equalsIgnoreCase(char* str) const
	{
		 int i = 0;
    while (data[i] != '\0' && str[i] != '\0') {
        char a = data[i];
        char b = str[i];
        if (a >= 'A' && a <= 'Z') {
            a = a + 22;
        }
        if (b >= 'A' && b <= 'Z') {
            b = b + 22;
        }
        if (a != b) {
            return false;
        }
        i++;
    }
    if (data[i] != str[i]) {
        return false;
    }
    return true;
	}
	
	char* substring(char* substr, int startIndex) const
	 {
    int sublen = 0;
    while (substr[sublen] != '\0') {
        sublen++;
    }
    int i = startIndex;
    while (i < length) {
        int j = 0;
        while (j < sublen && data[i + j] == substr[j]) {
            j++;
        }
        if (j == sublen) {
            char* out = new char[length - i + 1];
            int k = 0;
            while (i < length) {
                out[k] = data[i];
                i++;
                k++;
            }
            out[k] = '\0';
            return out;
        }
        i++;
    }
    return nullptr;
	}
	
	char* substring( char* substr, int startIndex, int endIndex) const
	{
    int sublen = 0;
    while (substr[sublen] != '\0') {
        sublen++;
    }
    int i = startIndex;
    while (i <= endIndex-sublen) {
        int j = 0;
        while (j < sublen && data[i + j] == substr[j]) {
            j++;
        }
        if (j == sublen) {
            char* out = new char[length - i + 2];
            int k = 0;
            while (i <= endIndex) {
                out[k] = data[i];
                i++;
                k++;
            }
            out[k] = '\0';
            return out;
        }
        i++;
    }
    return nullptr;
	}
	
	void print() const  {
    if (length == 0) {
        cout << "NULL" <<endl;
        return;
    }
    for (int i = 0; i < length; i++) {
        cout << data[i];
    }
    cout << endl;
}
	
    // Destructor
    ~String() {
        delete[] data;
    }
    
};

void Inputfun(char  *check,int & size)
{

	cout<<"Enter the string You want to check"<<endl;
	cin.getline(check,size);
}

int main() {
	int size=50;
	char check[size+1];
	
	Inputfun(check,size);
    String s1; // default constructor
    String s2(size); // alternate constructor
    String s3(check); // alternate constructor
    String s4(s3); // copy constructor
    
    // test some member functions
    cout << "s3: ";
    s3.print();
    
    cout << "s3 length: " << s3.strLength() << endl;
    cout<<"The data in th estring is:"<<endl;
    cout<<s3.getdata();
    cout<<endl;
    int clst=0;
	cout<<"Do you want to  clear the string then press 1"<<endl;
    cin>>clst;
    if(clst==1)
    {
    s3.clear();
    cout << "Check if s3 is empty: " << s3.empty() << endl;
    }
    char charch;
	cout<<"Enter the character you want to check "<<endl;
	cin>>charch;
	int index=s3.charAt(charch);
	cout<<"The index at which the character is found "<<index<<endl;
    
    int eq=s3.equals(check);
    if(eq==1)
    cout<<"This is equal"<<endl;
    else
    cout<<"This is NOT equal"<<endl;
    
    int Igca=s3.equalsIgnoreCase(check);
    if(Igca==1)
    cout<<"The case is ignored and equal"<<endl;
    else
    cout<<"The case is ignored and NOT equal"<<endl;
    

    int len=100;
    char substr[len];
	cout<<"Enter the substring you want to check"<<endl;
    cin>>substr;
    int stIn;
    cout<<"Enter the starting address"<<endl;
    cin>>stIn;
    char* sub = s3.substring(substr, stIn);
    if (sub != nullptr) {
        cout << "Substring found: ";
        cout << sub << endl;
        delete[] sub;
    }
    else {
        cout << "Substring not found" << endl;
    }
    
    int le=100;
    char substr2[le];
	cout<<"Enter the substring you want to check"<<endl;
    cin>>substr2;
    int stInd,endInd;
    cout<<"Enter the starting address"<<endl;
    cin>>stInd;
    cout<<"Enter the ending address"<<endl;
    cin>>endInd;
    char* sub2 = s3.substring(substr2, stInd, endInd);
        if (sub2 != nullptr) {
        cout << "Substring found: ";
        cout << sub2 << endl;
        delete[] sub2;
    }
    else {
        cout << "Substring not found" << endl;
    }
    s4.clear();
    cout << "s4 after clear: ";
    s4.print();
    
    return 0;
}
