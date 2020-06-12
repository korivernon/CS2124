#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

//Class for amounts of money in U.S. currency.
class Money {
public:
    //added friend class to make my life easier :)
    friend ostream& operator<<(ostream& outs, const Money& m);
    // friend istream& operator>>(istream& ins, Money& m);
    friend Money add(Money amount1, Money amount2);
    //added a subtraction class****** 
    friend Money sub(Money amount1, Money amount2);
    friend bool equal(Money amount1, Money amount2);
    Money(long dollars, int cents);
    Money(long dollars);
    Money( );
    double getValue( );
    void input(istream& ins);   
    void output(ostream& outs);
private:
    long allCents;
};
int digitToInt(char c);
Money add(Money amount1, Money amount2)
{
    Money temp;
    temp.allCents = amount1.allCents + amount2.allCents;
    return temp;
}
// making my life easier *** added function
Money sub(Money amount1, Money amount2)
{
    Money temp;
    temp.allCents = amount1.allCents - amount2.allCents;
    return temp;
}
bool equal(Money amount1, Money amount2)
{
    return (amount1.allCents == amount2.allCents);
}

Money::Money(long dollars, int cents)
{
    if(dollars*cents < 0) //If one is negative and one is positive


{
        cout << "Illegal values for dollars and cents.\n";
        exit(1);
    }
    allCents = dollars*100 + cents;
}

Money::Money(long dollars) : allCents(dollars*100)
{
    //Body intentionally blank.
}

Money::Money( ) : allCents(0)
{
    //Body intentionally blank.
}

double Money::getValue( )
{
    return (allCents * 0.01);
}
//Uses iostream, cctype, cstdlib:

void Money::input(istream& ins)
{
    char oneChar, decimalPoint,
         digit1, digit2; //digits for the amount of cents
    long dollars;
    int cents;
    bool negative;//set to true if input is negative.

    ins >> oneChar;
    if (oneChar == '-')
    {
        negative = true;
        ins >> oneChar; //read '$'
    }
    else
        negative = false;
    //if input is legal, then oneChar == '$'

    ins >> dollars >> decimalPoint >> digit1 >> digit2;

    if ( oneChar != '$' || decimalPoint != '.'
         || !isdigit(digit1) || !isdigit(digit2) )


    {
        cout << "Error illegal form for money input\n";
        exit(1);
    }
    cents = digitToInt(digit1)*10 + digitToInt(digit2);

    allCents = dollars*100 + cents;
    if (negative)
        allCents = -allCents;
}
//Uses cstdlib and iostream: 
void Money::output(ostream& outs)

{
    long positiveCents, dollars, cents;
    positiveCents = labs(allCents);
    dollars = positiveCents/100;
    cents = positiveCents%100;

    if (allCents < 0)
        outs << "-$" << dollars << '.';
    else
        outs << "$" << dollars << '.';

    if (cents < 10)
        outs << '0';
    outs << cents;
}

ostream& operator<<(ostream& outs, const Money& m)
{
    long positiveCents, dollars, cents;
    positiveCents = labs(m.allCents);
    dollars = positiveCents/100;
    cents = positiveCents%100;

    if (m.allCents < 0)
        outs << "-$" << dollars << '.';
    else
        outs << "$" << dollars << '.';

    if (cents < 10)
        outs << '0';
    outs << cents;

    return outs;
}
// added istream but realized i didn't really need it
/*
istream& operator>>(istream& ins, Money& m)
{
    char oneChar, decimalPoint,
         digit1, digit2; //digits for the amount of cents
    long dollars;
    int cents;
    bool negative;//set to true if input is negative.

    ins >> oneChar;
    if (oneChar == '-')
    {
        negative = true;
        ins >> oneChar; //read '$'
    }
    else
        negative = false;
    //if input is legal, then oneChar == '$'

    ins >> dollars >> decimalPoint >> digit1 >> digit2;

    if ( oneChar != '$' || decimalPoint != '.'
         || !isdigit(digit1) || !isdigit(digit2) )


    {
        cout << "Error illegal form for money input\n";
        exit(1);
    }
    cents = digitToInt(digit1)*10 + digitToInt(digit2);

    m.allCents = dollars*100 + cents;
    if (negative)
       m. allCents = -m.allCents;
}
*/
int digitToInt(char c)
{
    return (static_cast<int>(c) - static_cast<int>('0') );
}

class Check {
    private:
        int number; // this records the check number
        bool cashed;
        Money amount; // keeps track of the money
    public:
        Check(int newnum, const Money& money, bool cash = false) : number(newnum),amount(money), cashed(cash) {}      
        // getter functions 
        string getCashed() const {
            if (cashed == true){return "Yes";}
            else {return "No";}
        }
        bool getCash() const { return cashed; } // returns whether or not check was cashed
        Money getAmt() const {return amount;}
        int getNum() const {return number;} //check number getter
        friend ostream& operator<<(ostream& outs, const Check& c);

};

ostream& operator<<(ostream& outs, const Check& c){
    // need to output the check
    outs << "Check Number: " << c.getNum() << endl;
    // added ostream class in money to make life easier :)
    outs << "Amount: " << c.getAmt() << endl;
    outs << "Cashed: " << c.getCashed() << endl;
    return outs;
}


class CheckBook{
    private:
        vector<Check> deposit;
        vector<Check> cashed;
        vector<int> checknums; 
        Money total;
    public:
        friend ostream& operator <<(ostream& outs, const CheckBook& cb);
        CheckBook(const Money& newtotal) : total(newtotal) {
            vector<Check> dp;
            vector<int> cn;
            vector<Check> newcash;
            deposit = dp;
            checknums = cn;
            cashed = newcash;
        }
        //fix this.. need to separately keep track of cashed and deposit...
        bool numberCheck(int num){
            for (int i=0; i < checknums.size(); i++){
                if (num == checknums[i]){
                    return true;
                }
            }
            return false;
        }
        void addChk(Check& c){
            if (c.getCash()){
                cashed.push_back(c); 
                checknums.push_back(c.getNum());
                // add this to the check numbers in the checkbook
            } else { 
                deposit.push_back(c);
                checknums.push_back(c.getNum());
            }
        } // deposit
        Money getTotal(){
            Money dep,cash;
            for(int i = 0; i < deposit.size(); i++){
                dep = add(dep, deposit[i].getAmt());            
            }
            for(int i = 0; i < cashed.size(); i++){
                cash = add(cash, cashed[i].getAmt());
            }
            total = add(cash, total);
            total = add(total, dep);
            total = sub(cash, cash);
            return total;
        }
        Check checkd(int index) const {return deposit[index];} // gets the cashed amount for a check
        Money getPrev() const {return total;}
        Check checkc(int index) const {return cashed[index];} // gets the deposit amount for a check
        int getDpSz() const {return deposit.size();} // get deposit size
        int getCSz() const {return cashed.size();} // get cashed size
};

ostream& operator <<(ostream& outs, const CheckBook& cb){
    Money tot, dep, cash;
    
    outs << "========Bank Statement========" << endl;
    outs << "Previous Account Balance: " << cb.getPrev() << endl;
    for(size_t i = 0; i < cb.getCSz(); i++){
        cash = add(cash, cb.checkc(i).getAmt());
    }
    // obtain the amount of checks that are cashed
    outs << "Total Cashed: " << cash << endl;
    for(int i = 0; i < cb.getDpSz(); i++){
        dep = add(dep,cb.checkd(i).getAmt());
    }
    outs << "Total Deposited: " << dep << endl;
    tot = add(cb.getPrev(), dep); // total + deposited + cashed
    tot = add(tot, cash);
    tot = sub(tot, cash); // total + deposited - cashed
    outs << "New Account Balance: " << tot << endl;
    outs << "==============================" << endl;
    outs << "Checks not Cashed: " << endl;
    // this will output all of the deposited checks
    for(size_t i = 0; i < cb.getDpSz(); i++){
        outs << cb.checkd(i) << endl;
    }
    // this will output the cashed checks
    outs << "Cashed Checks: " << endl;
    for(size_t i=0; i < cb.getCSz(); i++){
        outs << cb.checkc(i) << endl;
    }
    outs << "==============================" << endl;
    return outs;
}

void getStatement(){

    // initialize do/while cont variable
    string cont, cash;
    bool cashed;
    long dollars;
    int cents, checknum;
    // ifstream inFile;
    // Money temp, amt;
    // string tempStr;
    // inFile.open("statement.txt");
    // cout << "Hi" << endl; --> this was something i was trying to do
    /*
    if (!inFile){ cout << "Error"; }
    else { 

--> I was trying to grab the money from a different file and input it, but it didn't really work

        while (inFile >> temp){
            amt = temp; // setting the last value to the latest value 
        }
    */
//--> we will begin the check balancing program by entering in the previous account balance so we can use it in the total. 
    cout << "Welcome to the Check Balancing Program."<< endl;
    cout << "Please Begin by entering in your previous account balance!" << endl;
    cout << "==============================" << endl;
    
    cout << "Enter in your previous balance(dollars): ";
    cin >> dollars;
    cout << "Enter in your previous balance(cents): ";
    cin >> cents;
    Money amt(dollars,cents);
    CheckBook cb(amt); //initialize checkbook w/ this
    // inFile.close();
    do {  
        cout << "=========Enter in Checks==========" << endl;
        cout << "Enter in the amount of dollars: ";
        cin >> dollars;
        cout << "Enter in the number of cents: ";
        cin >> cents;
        cout << "Enter in a check number: ";
        cin >> checknum;
        // check if that check number exists
        if (cb.numberCheck(checknum)){
            while (cb.numberCheck(checknum)){
                cout << "That check number exists. Try again: ";
                cin >> checknum;
            }
        }
        cout << "Do you want to cash the check (y/n): ";
        cin >> cash;
        // determine whether or not to cash the check
        if (cash[0]=='y') {cashed = true;}
        else {cashed = false;}
            
         //create money object
        Money temp(dollars, cents);
        //create check object
        Check tempChk(checknum, temp, cashed);
        cb.addChk(tempChk);
        // ask user if they want to continue
        cout << "==============================" << endl;
        cout << "Would you like to add another check (y/n): ";
       
        cin >> cont; 
        } while (cont[0]=='Y'|| cont[0]=='y');
        ofstream outFile;
        outFile.open("fullstatement.txt");
        //we are outputting to a file that contains the complete statement
        // output in "======= Statement ===="
        if (!outFile) {cout << "Error full statement" << endl;}
        else{

            outFile << cb; // output our statement to the file
            cout << cb;
            /*i'm choosing to output to a txtfile and the console. */
            outFile.close(); //close our file
            outFile.clear(); // clear ofstream
            /* --> unneeded
            outFile.open("statement.txt");*/
            cout << "Check 'fullstatement.txt' for your statements." << endl;
        }
        
}
int main() {
    Money kori(182.89);
    cout << "kori: " << kori << endl;
    /*
    Money kori(1,0);
    cout << kori << endl;

    Check kori_check(10604443, kori, false);
    cout << kori_check;

    Money prevBal(1906,73);
    // testing the checkbook
    CheckBook kori_cb(prevBal);
    kori_cb.addChk(kori_check);
    kori_cb.addChk(kori_check);
    
    cout << kori_cb;
    */
    // testing getStatement
    getStatement();
}
