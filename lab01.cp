/* CISC 2200 Spring 2019
 * Cesar Sanchez
 * LAB 01
 * Professor Hanping Xu
 * This program takes a monetary input from the user
 * in the form of a string. Regardless of how a quantity
 * is entered, from 0 to 9999.99, the quantity is
 * configured to be used in a vector of size 7.
 * The user is given the option to re-enter a quantity if
 * it falls out of bounds.
 * Non digit inputs are also evaluated and terminates the program.
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void ones_case(vector<int>v);
void teens_case(vector<int>v, int decimal_place_1, int decimal_place_2);
void tens_case(vector<int>v, int decimal_place_1);
void hundreds_case(vector<int>v);
void thousands_case(vector<int>v);
void configure_input(string &a);
bool non_digit_input_checker(string a);

const int str_size = 7;

int main()
{
    string a;
    vector<int>v;
    
    for(int i= 0; i< str_size ;i++) //initalizes a vector containing 7 zeroes
        v.push_back(0);
    
    int ones_place = v.size() - 4;
    int tens_place = v.size() - 5;
    v[4] = -2;

    double money_entered;
    char answer = 'Y';
    
    do
    {
        cin.clear();
        cout << "Enter the dollar amount: $";
        cin >> a;
        size_t found= a.find('.');
        if(non_digit_input_checker(a)== false && a[found]!= '.')
        {
            cout << "That is not a number." << endl;
            cout << "Goodbye!" << endl;
            exit(0);
        }
        money_entered = stod(a);
        
        if(money_entered<0)
        {
            cout << "That number is too small." << endl;
            cout << "Try Again?" << endl;
            cout << "[Y]es, [N]o" << endl;
            cin >> answer;
            answer = toupper(answer);
        }
        if(money_entered>9999.99)
        {
            cout << "That number is too large." << endl;
            cout << "Try Again?" << endl;
            cout << "[Y]es, [N]o" << endl;
            cin >> answer;
            answer = toupper(answer);
        }
        
        if(answer == 'N')
            exit(0);
        
    }while((9999.99<money_entered || money_entered<0 ) && answer == 'Y');
    
    
    for(int i= 0; i< str_size;i++)
        v[i]= 0;
    
    configure_input(a);
    
    if(a.length()==7)
        for(int i= (str_size - 7); i< str_size;i++)
            v[i]= a[i] - '0';
   
    int tens = (10 * v[v.size() - 5] + v[v.size() - 4]);
    int decimals = (10 * v[v.size() - 2] + v[v.size() - 1]);
    thousands_case(v);
    hundreds_case(v);
    
    if(9 < tens < 20)
        teens_case(v, tens_place, ones_place);
    
    if(tens> 19)
    {
        tens_case(v, tens_place);
        ones_case(v);
    }
    
    if(tens < 10)
        ones_case(v);
    
    cout << "dollars and ";
    
    
    if( 99 >= decimals >= 20)
        cout << tens << "/100";
    else
        cout << decimals << "/100";
    
    return 0;
}

void ones_case(vector<int>v)
{
    switch(v[v.size()-4])
    {
        case 1:
            cout << "One ";
            break;
            
        case 2:
            cout << "Two ";
            break;
            
        case 3:
            cout << "Three ";
            break;
            
        case 4:
            cout << "Four ";
            break;
            
        case 5:
            cout << "Five ";
            break;
            
        case 6:
            cout << "Six ";
            break;
            
        case 7:
            cout << "Seven ";
            break;
            
        case 8:
            cout << "Eight ";
            break;
            
        case 9:
            cout << "Nine ";
            break;
    }
}

void teens_case(vector<int>v, int decimal_place_1, int decimal_place_2)
{
    switch((10 * v[decimal_place_1] + v[decimal_place_2]))
    {
        case 10:
            cout << "Ten ";
            break;
        case 11:
            cout << "Eleven ";
            break;
            
        case 12:
            cout << "Twelve ";
            break;
            
        case 13:
            cout << "Thirteen ";
            break;
            
        case 14:
            cout << "Fourteen ";
            break;
            
        case 15:
            cout << "Fifthteen ";
            break;
            
        case 16:
            cout << "Sixteen ";
            break;
            
        case 17:
            cout << "Seventeen ";
            break;
            
        case 18:
            cout << "Eighteen ";
            break;
            
        case 19:
            cout << "Nineteen ";
            break;
    }
}

void tens_case(vector<int>v, int decimal_place_1)
{
    switch(v[decimal_place_1])
    {
        case 2:
            cout << "Twenty ";
            break;
            
        case 3:
            cout << "Thirty ";
            break;
            
        case 4:
            cout << "Fourty ";
            break;
            
        case 5:
            cout << "Fifty ";
            break;
            
        case 6:
            cout << "Sixty ";
            break;
            
        case 7:
            cout << "Seventy ";
            break;
            
        case 8:
            cout << "Eighty ";
            break;
            
        case 9:
            cout << "Ninety ";
            break;
    }
}

void hundreds_case(vector<int>v)
{
    switch(v[v.size()-6])
    {
        case 1:
            cout << "One Hundred ";
            break;
            
        case 2:
            cout << "Two Hundred ";
            break;
            
        case 3:
            cout << "Three Hundred ";
            break;
            
        case 4:
            cout << "Four Hundred ";
            break;
            
        case 5:
            cout << "Five Hundred ";
            break;
            
        case 6:
            cout << "Six Hundred ";
            break;
            
        case 7:
            cout << "Seven Hundred ";
            break;
            
        case 8:
            cout << "Eight Hundred ";
            break;
            
        case 9:
            cout << "Nine Hundred ";
            break;
    }
}

void thousands_case(vector<int>v)
{
    switch(v[v.size()-7])
    {
        case 1:
            cout << "One Thousand ";
            break;
            
        case 2:
            cout << "Two Thousand ";
            break;
            
        case 3:
            cout << "Three Thousand ";
            break;
            
        case 4:
            cout << "Four Thousand ";
            break;
            
        case 5:
            cout << "Five Thousand ";
            break;
            
        case 6:
            cout << "Six Thousand ";
            break;
            
        case 7:
            cout << "Seven Thousand ";
            break;
            
        case 8:
            cout << "Eight Thousand ";
            break;
            
        case 9:
            cout << "Nine Thousand ";
            break;
    }
}

void configure_input(string &a)
{
    size_t found= a.find('.');
    if(a.length()==6 && found == 3)
        a.insert(a.begin(), '0');
    
    if(a.length()==6 && found == 4)
        a.insert(a.end(), '0');
    
    if(a.length()==5 && found == 2)
        a.insert(a.begin(),2, '0');
    
    if(a.length()==5 && found == 3)
    {
        a.insert(a.begin(),1, '0');
        a.insert(a.end(), '0');
    }
    
    if(a.length()==5 && found == 4)
        a.insert(a.end(), 2, '0');
    
    if(a.length()==4 && found == 1)
        a.insert(a.begin(),3, '0');
    
    if(a.length()==4 && found == 3)
    {
        a.insert(a.begin(),1, '0');
        a.insert(a.end(),2, '0');
    }
    
    if(a.length()==4 && found == 2)
    {
        a.insert(a.begin(),2, '0');
        a.insert(a.end(),1, '0');
    }
    
    if(a.length()==4)
    {
        a.insert(a.end(), '.');
        a.insert(a.end(),2, '0');
    }
    
    if(a.length()==3 && found == 0)
    {
        cout << "Zero ";
        a.insert(a.begin(),4, '0');
    }
    if(a.length()==3 && found == 1)
    {
        a.insert(a.begin(),3, '0');
        a.insert(a.end(),1, '0');
    }
    if(a.length()==3 && found == 2)
    {
        a.insert(a.begin(),2, '0');
        a.insert(a.end(),2, '0');
    }
    
    if(a.length()==3)
    {
        a.insert(a.begin(),1, '0');
        a.insert(a.end(), '.');
        a.insert(a.end(),2, '0');
    }
    
    if(a.length()==2 && found == 0)
    {
        cout << "Zero ";
        a.insert(a.begin(),4, '0');
        a.insert(a.end(), '0');
    }
    
    if(a.length()==2 && found == 1)
    {
        a.insert(a.begin(),3, '0');
        a.insert(a.end(),2, '0');
    }
    
    if(a.length()==2 && found == 1)
    {
        a.insert(a.begin(),3, '0');
        a.insert(a.end(),2, '0');
    }
    
    if(a.length()==2)
    {
        a.insert(a.begin(),2, '0');
        a.insert(a.end(), '.');
        a.insert(a.end(),2, '0');
    }
    
    if(a.length()==1 && found!=0)
        cout << a[0];
    if(a.length()==1 && found == 0)
        cout << "Zero ";
}

bool non_digit_input_checker(string a)
{
    if(a[0]=='-')
    {
        if(a.size()==0) return false;
        for(int i=0;i<a.size();i++)
            if(((a[i]>='0' && a[i]<='9') || a[0]=='-') == false)
                return false;
        return true;
    }
    
    if(a.size()==0) return false;
    for(int i=0;i<a.size();i++)
        if(((a[i]>='0' && a[i]<='9')) == false)
            return false;
    return true;
}
