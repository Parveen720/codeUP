#include<bits/stdc++.h>
#include<string>
using namespace std;

class parveen{
   public:
//   	to check the string is palindroem or not
   	bool isPalindrome(string s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
        if (s[i] != s[j])
            return false;
           i++;
           j--;
       }
    return true;
     }
     
//   to show the unique palindrome
   void palindrome(string str){
   	int n=str.size();
   	set<string> uniquepalindrome;
   	for(int i=0;i<n;i++){
   		string temp="";
   		for(int j=i;j<n;j++){
   			temp+=str[j];
   			if(isPalindrome(temp))
   			uniquepalindrome.insert(temp);
		   }
    	}
   vector<string> temp(uniquepalindrome.begin(), uniquepalindrome.end());

for (int i = 0; i < temp.size(); i++) {
    cout << temp[i] << endl;
}
   }
   
//   to get the nth number in the fibonacci sequence
   long long fibonacci(int n){
   	if(n<=0)return -1;
   	if(n==1)return 1;
   	long long a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
   }
//   to convert snake case to camel case
   void camelcase(string str){
   	int n=str.size();
   	bool flag=false;
   	string str1;
   	for(int i=0;i<n;i++){
   		char ch=str[i];
   		if(ch=='_'){
   			flag=true;
		   }
		else if(flag==true && i>0){
     		str1 += toupper(ch);
			flag=false;
		}
		else{
			str1+=ch;
		}
	   }
	cout<<str1<<endl;
   }
   
//   to count consonent in a string
    void consonent(string str) {
        int count = 0;
        string consonants = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
        for (int i=0;i<str.size();i++) {
        	char c=str[i];
            if (consonants.find(c) != string::npos)
                count++;
        }
        cout << count << endl;
    }

//	to convert binary ton decimal
    void decimal(string str){
        long long p=1;
	
		int total=0;
		int in1=0;
		for(int i=str.size()-1;i>=0;i--){
			char ch=str[i];
			if(ch=='1'){
				total+=p;
			}
			in1++;
			p=p*pow(2,in1);
		}
		cout<<total<<endl;
			
	}
//	Charcater in a string
  void chartostring(string str) {
     string result = "";
     for (int i = 1; i < str.size(); i += 2) {
        char ch = str[i - 1];
        int count = str[i] - '0';  // convert char digit ? int
        while (count--) {
            result += ch;
        }
    }
    cout << "Expanded string: " << result << endl;
   }

//	charcater frequency in strig
    void freqofchar(string str) {
      string result = "";
      int count = 1;
      int n = str.size();

     for (int i = 1; i <= n; i++) {
         if (i < n && str[i] == str[i - 1]) {
            count++;
         } else {
            result += str[i - 1];
            result += to_string(count);
            count = 1;
         }
     }
    cout << "Character frequency string: " << result << endl;
    }  

	
//	to chech number is prime or not
      void checkerprime(int number){
      	bool flag=true;
      	for(int i=2;i<number;i++){
      		if(number%i==0){ 
      		 flag=false;
      		 break;
      	     }
		  }
		  if(flag){
		  	cout<<"number is prime"<<endl;
		  }
		  else{
		  	cout<<"number is not prime"<<endl;
		  }
	  }	
	  
	  
//	  Number to  word convertor

void numtoword(int n) {
    string result = "";
    string one[] = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };
   string two_less_20[] = { "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
                         "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
   string tens[] = { "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };


    if (n == 0)
        cout<< "Zero"<<endl;

    if (n >= 1000) {
        result += one[n / 1000] + " Thousand ";
        n %= 1000;
    }

    if (n >= 100) {
        result += one[n / 100] + " Hundred ";
        n %= 100;
    }

    if (n >= 20) {
        result += tens[n / 10] + " ";
        n %= 10;
    } 
    else if (n >= 10) {
        result += two_less_20[n - 10] + " ";
        n = 0;
    }

    if (n > 0) {
        result += one[n] + " ";
    }

    cout<<result<<endl;
}

//Longest substring without repeating character

    void longsub(string str){
    	int n=str.size();
    	int start=0;
    	int maxLen=0;
    	unordered_map<char,int> lastseen;
    	
    	for(int end=0;end<n;end++){
    		char ch=s[end];
    		 if (lastSeen.find(ch) != lastSeen.end() && lastSeen[ch] >= start) {
               start = lastSeen[ch] + 1;
               }
               
        lastSeen[ch] = end; 
        maxLen = max(maxLen, end - start + 1);
		}
		cout<<maxLen<<endl;
	} 
	
	
	
	
	
};
int main(){
	
	parveen p;
	
  while(true){
  
   cout<<"Enter 1 for count unique palindrome"<<endl;
   cout<<"Enter 2 for fibonacci sequence-nth number"<<endl;
   cout<<"Enter 3 snake case to camel case converter"<<endl;
   cout<<"Enter 4 count consonents in a string"<<endl;
   cout<<"Enter 5 binary to decimal converter"<<endl;
   cout<<"Enter 6 charcater in a string"<<endl;
   cout<<"Enter 7 charcter frequency in a string"<<endl;
   cout<<"Enter 8 for prime number checker"<<endl;
   cout<<"Enter 9 for number to word converter"<<endl;
   cout<<"Enter 10 Longest substring without repeating character"<<endl;
   cout<<"Enter 11 for Exiting the program"<<endl;
   cout<<"enter your choice"<<endl;
   int choice;
   cin>>choice;
  switch(choice){
    case 1: {
        string str;
        cout<<"Enter the string"<<endl;
        cin>>str;
        cout<<"unique palindrome in a string is: "<<endl;
		p.palindrome(str);
        break;
    }
    case 2: {
        int n;
        cout<<"enter the nth number which you want to get from fibonacci sequence"<<endl;
        cin>>n;
        cout<<"the nth number in the sequence is: "<<endl;
		long long number=p.fibonacci(n);
		cout<<number<<endl;
        break;
    }
    case 3: {
        string str;
        cout<<"Enter the string which you want to convert in camel case"<<endl;
        cin>>str;
        cout<<"converted string is: "<<endl;
		p.camelcase(str);
        break;
    }
    case 4:{
    	string str;
    	cout<<"Enter the string in which you want to coutn the consonent"<<endl;
    	cin>>str;
    	cout<<"Number of consonent are:"<<endl;
		p.consonent(str);
		break;
	}
	case 5:{
		string str;
		cout<<"Enter teh binary string"<<endl;
		cin>>str;
		cout<<"the decimal number is:"<<endl;
		p.decimal(str);
		break;
	}
	case 6:{
		string str;
		cout<<"Enter the string"<<endl;
		cin>>str;
		cout<<"The final string is",p.chartostring(str);
		break;
	}
	case 7:{
		string str;
		cout<<"Enter the string"<<endl;
		cin>>str;
		cout<<"The final string is",p.freqofchar(str);
		break;
	}
	case 8:{
		int number;
		cout<<"enter the number"<<endl;
		cin>>number;
		p.checkerprime(number);
		break;
	}
	case 9:{
		int number;
		cout<<"Enter the number"<<endl;
		cin>>number;
		cout<<"the word converter is"<<endl;
		p.numtoword(number);
		break;
	}
	case 10:{
		string str;
		cout<<"Enter teh string"<<endl;
		cin>>str;
		cout<<"longest substring size is"<<endl;
     	p.longsub(str);
		break;
	}
	case 11:{
		cout<<"Exiting the program"<<endl;
		exit(0);
		break;
	}
	default:{
		cout<<"Not a valid number";
		break;
	}
   } 		   
 } 
}
