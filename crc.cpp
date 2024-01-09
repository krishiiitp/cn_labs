#include<iostream>
#include<string.h>
using namespace std;
class CRC{
	string rem="";
     string input,divisor,divident,result;
     int len_divident, len_gen, len_input;
public:
       string fun_xor(string a, string b)
       {
          string result = "";
          if(a[0] == '0')
          {
            return a.substr(1);
          }
          else
          {
            for (int i=0; i<len_gen; i++)
            {
                result = result + (a[i]==b[i] ? '0':'1');
            }
            return result.substr(1);
          }
       }
       void modulo_div()
       {
           string temp_div = divisor;
           string temp_divident = divident.substr(0,len_gen);
           int j = len_gen;
           while (j<len_divident)
           {
            temp_divident = fun_xor(temp_divident,temp_div);
            temp_divident = temp_divident + divident[j];
            j++;

           }
           rem=fun_xor(temp_divident,temp_div);
           result = input + rem;

       }
       void getdata()
    {
        cout<<"enter the data : ";
        cin>>input;
        cout<<"enter the divisor : ";
        cin>>divisor;
        len_gen = divisor.length();
        len_input = input.length();
        divident = input;
        int r = len_gen-1;
        for (int i=0; i<r; i++)
        {
            divident = divident +'0';
        }
        len_divident = divident.length();

        modulo_div();
    }
        void sender_side()
     {
        cout<<"output is Remainder : "<<rem<<endl;
     } 
        void receiver_side()
    {
        string data_rec;
        cout<<"\nEnter Data Received: ";
        cin>>data_rec;

        string temp_div = divisor;
        string temp_divident = data_rec.substr(0,len_gen);
        int j = len_gen;
        while ((j<data_rec.length()))
        {
            temp_divident = fun_xor(temp_divident,temp_div);
            temp_divident = temp_divident +data_rec[j];
            j++;
        }
        string error = fun_xor(temp_divident,temp_div);
        cout<<"remainder is: "<<error;
        
        bool flag =0;
        for (int i = 0; i<len_gen; i++)
        {
            if(error[i]=='1')
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        cout<<"\nno error\n\n";
        else
        cout<<"\nerror\n\n";
    }
};
int main() {
    CRC crc;
    crc.getdata();
    int x;
    while(true){
    	cout<<"where can you send : 1 Sender 2 Receiver 3 EXIT\n\n";
    	cin>>x;
    	if(x==1){
    		crc.sender_side();
		}else if(x==2){
			crc.receiver_side();
		}else{
			cout<<"\nexit";
			break;
		}
	}
    return 0;
}
