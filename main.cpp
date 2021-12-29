#include "main.h"

using namespace std;

int main(){

    // decalre input variable
    string getinput;

    // Message display
    cout << endl;
    cout << "This is simple intent recognizer that tries to capture semantic variations of the below three utternaces" << endl;
    cout << "****************************************************************************" << endl;
    cout << "1.What is the weather like today? => Prints (Intent: Get Weather)" << endl;
    cout << "2.What is the weather like in Paris today? => Prints (Intent: Get Weather City)" << endl;
    cout << "3.Tell me an interesting fact. => Prints (Intent: Get Fact)" << endl;
    cout << "****************************************************************************" << endl;
    

    do {
    cout << "I am intent Recognizer, Please type something & I will try to guess your intention!\nTo EXIT type 'ciao'" << endl;
    //clear input 
    getinput.clear();
    getline(cin,getinput);

    // for unifrmity let's change the input into lower case
    transform(getinput.begin(),getinput.end(),getinput.begin(), ::tolower);

    /*
    My ideal solution to this problem would be train an ML model but since the ask is simple command line tool with time constraint, I am using simple if-else with do-while loop

    */

    //LOGIC
     if (
         (regex_search(getinput, regex("atmospheric")) || 
            regex_search(getinput, regex("sunny")) || 
            regex_search(getinput, regex("cloudy")) || 
            regex_search(getinput, regex("rainy")) || 
            regex_search(getinput, regex("atmosphere")) || 
            regex_search(getinput, regex("climate")) || 
            regex_search(getinput, regex("tornadoes")) || 
            regex_search(getinput, regex("airy")) || 
            regex_search(getinput, regex("cold")) || 
            regex_search(getinput, regex("hot")) || 
            regex_search(getinput, regex("chill")) || 
            regex_search(getinput, regex("chilling")) || 
            regex_search(getinput, regex("warm")) || 
            regex_search(getinput, regex("tornado")) || 
            regex_search(getinput, regex("temperature")) || 
            regex_search(getinput, regex("humidity")) || 
            regex_search(getinput, regex("cloud")) || 
            regex_search(getinput, regex("cloudy")) || 
            regex_search(getinput, regex("wind")) || 
            regex_search(getinput, regex("windy")) || 
            regex_search(getinput, regex("meteor")) || 
            regex_search(getinput, regex("air")) || 
            regex_search(getinput, regex("weather")) || 
            regex_search(getinput, regex("nice day"))) &&
         regex_search(getinput, regex("in")))
     
    {
        cout << "Intent: Get Weather City" << endl;
     }

    else if 
    (regex_search(getinput, regex("atmospheric conditions")) || regex_search(getinput, regex("sunny")) || regex_search(getinput, regex("cloudy")) 
        || regex_search(getinput, regex("rainy")) || regex_search(getinput, regex("atmosphere")) || regex_search(getinput, regex("climate")) || regex_search(getinput, regex("tornadoes"))
        || regex_search(getinput, regex("airy")) || regex_search(getinput, regex("cold")) || regex_search(getinput, regex("hot")) || regex_search(getinput, regex("chill"))
        || regex_search(getinput, regex("chilling")) || regex_search(getinput, regex("warm")) || regex_search(getinput, regex("tornado")) || regex_search(getinput, regex("temperature"))
        || regex_search(getinput, regex("humidity")) || regex_search(getinput, regex("cloud")) || regex_search(getinput, regex("cloudy")) || regex_search(getinput, regex("wind"))
        || regex_search(getinput, regex("windy")) || regex_search(getinput, regex("meteor")) || regex_search(getinput, regex("air")) 
        || regex_search(getinput, regex("weather")))
        
    {    
        cout << "Intent: Get Weather" << endl;
    }

    else if 
    (regex_search(getinput, regex("fact")) || regex_search(getinput, regex("something interesting")) || regex_search(getinput, regex("something interesting"))
        || regex_search(getinput, regex("truth")) || regex_search(getinput, regex("actuality")) || regex_search(getinput, regex("reality")) || regex_search(getinput, regex("verity")))
    {
        cout << "Intent: Get Fact" << endl;
    }
        

    else if (regex_search(getinput, regex("ciao")))
    {
        cout << "************************Auf Wierdershen***************************\n" << endl;
    }
        

    else
    {
        cout << "\nI am still learning, Sorry I am not able to find your intention, \nPlease try one more time!\n" << endl;
    }
        

    } while (getinput != "ciao");

    
return 0;
}