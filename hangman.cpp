#include <iostream>
#include <vector>
#include <stdlib.h>


using namespace std;

vector< string> answer;
string word;
int errors = 0;
int guesses = 0;

void checkWinner(bool result);

void findLetters(char letter,string word)
{
vector< int > arr;
 //cout << "arr length: " << arr.size() << endl;
    //size_t nOffset = word.find (letter, 0); //first instance of letter

    const char chCharToSearch = letter; //letter to find

    size_t nCharacterOffset = word.find (chCharToSearch, 0); //first instance of letter

        if(nCharacterOffset != string::npos){
            //cout << "fisr push: " << nCharacterOffset << endl;
            arr.push_back(nCharacterOffset);

        }


    while (nCharacterOffset != string::npos)
    {
        //cout << "'" << chCharToSearch << "' found";
        //cout << " at position: " << nCharacterOffset << endl;

       // Make the 'find' function search forward from the next character onwards
        size_t nCharSearchOffset = nCharacterOffset + 1;

        nCharacterOffset = word.find(chCharToSearch,nCharSearchOffset);

        if(nCharacterOffset != string::npos){
     //cout << "2nd push: " << nCharacterOffset << endl;

          arr.push_back(nCharacterOffset);

        }
    }

 //cout << arr.size() << endl;


        if(arr.size() != 0){
            for (int i = 0; i < arr.size(); i++){
            int k = arr[i];
            answer[k] = word.at(k);
            guesses++;
            if(i == arr.size() - 1){
              checkWinner(true);
            }
            }
        } else {
        checkWinner(false);
        }


}

void getAnswer(){

    char letter;

    cout <<"\n Type a letter: " << endl;
    cin >> letter;
    findLetters(letter,word);
}

void printAnswer(){

        for (int j = 0; j < answer.size(); j++)
        if(answer[j] == "null"){
         cout << "_ ";
        } else {
          cout << answer[j]+" ";
        }
        getAnswer();
}

void checkWinner(bool result){
if(result == 1) {
  if(guesses == word.length()){
    cout << word << endl;
    cout << "CONGRATS!!!! YOU WON!" << endl;
  } else {
    printAnswer();
  }
}
else{
  errors++;
      if(errors == 7){
            cout << " _________     \n";
            cout << "|         |    \n";
            cout << "|         0    \n";
            cout << "|         |    \n";
            cout << "|        /|\   \n";
            cout << "|        / \   \n";
            cout << "|              \n";
            cout << "GAME OVER!! "<< endl;
        }
        else {
            switch(errors) {
               case 1  :
                 cout << " _________     \n";
                    cout << "|         |    \n";
                    cout << "|         0    \n";
                    cout << "|              \n";
                    cout << "|              \n";
                    cout << "|              \n";
                    cout << "|              \n";
                        printAnswer();
                  break; //optional
               case 2  :
                    cout << " _________     \n";
                    cout << "|         |    \n";
                    cout << "|         0    \n";
                    cout << "|         |    \n";
                    cout << "|              \n";
                    cout << "|              \n";
                    cout << "|              \n";
                        printAnswer();
                  break; //optional
              case 3  :
                    cout << " _________     \n";
                    cout << "|         |    \n";
                    cout << "|         0    \n";
                    cout << "|         |    \n";
                    cout << "|        /     \n";
                    cout << "|              \n";
                    cout << "|              \n";
                        printAnswer();
                  break; //optional
                case 4  :
                    cout << " _________     \n";
                    cout << "|         |    \n";
                    cout << "|         0    \n";
                    cout << "|         |    \n";
                    cout << "|        /|    \n";
                    cout << "|              \n";
                    cout << "|              \n";
                      printAnswer();
                  break; //optional
                case 5  :
                    cout << " _________     \n";
                    cout << "|         |    \n";
                    cout << "|         0    \n";
                    cout << "|         |    \n";
                    cout << "|        /|\   \n";
                    cout << "|              \n";
                    cout << "|              \n";
                      printAnswer();
                  break; //optional
               case 6  :
                    cout << " _________     \n";
                    cout << "|         |    \n";
                    cout << "|         0    \n";
                    cout << "|         |    \n";
                    cout << "|        /|\   \n";
                    cout << "|        /     \n";
                    cout << "|              \n";
                      printAnswer();
                  break; //optional
               // you can have any number of case statements.



            }

        }
}

}




int main()
{
 srand (time(NULL));

    string words[10] = {"penguin","elephant","mexico","walnut","office","juxtaposition","aquamarine","madagascar","ferocious","cupcake"};

    int length = sizeof(words)/sizeof(words[0]);

    int selectWord = rand() %length;

    word = words[selectWord];



    cout << "Welcome to HANGMAN!!! \nAre you ready to play? \n. Good luck!" << endl;
        cout << " _________     \n";
        cout << "|         |    \n";
        cout << "|              \n";
        cout << "|              \n";
        cout << "|              \n";
        cout << "|              \n";
        cout << "|              \n";


     //Print Dashes
    for (int i = 0; i < words[selectWord].length(); i++)
    {
        answer.push_back("null");
        if(i == words[selectWord].length()-1) {
            printAnswer();
        }
    }
}
