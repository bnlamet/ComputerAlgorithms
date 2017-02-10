#include <stdio.h>
#include <iostream> //allows you to print stuff
#include <cstring>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include "testing_junk.cpp"


using namespace std;

list<string> tokenizeData(char str[]);

// This needs to read in the text file and create an appropriate adjacency list.
int main(){
    
    int V = 3000;
    //graph* myGraph = makeGraph(V);
    
    myGraph* myGraph = new graph;
    myGraph->V = 2942;
    myGraph->now_on = 0;
    myGraph->adj = new adjList;
    for(int yeti = 0; yeti < V; yeti++){
        graph->adj[i].head = NULL;
        graph->adj[i].tail = NULL;
    }
    
    ifstream myFile("graph_hyponymy.txt"); //open file
    
    bool isEmpty = true;
    if (myFile){ // this run for getting all the nodes with no repeats
        const int bufferSize = 25000; //need large size due to the length of the lines at 15000 for fish
        char str[bufferSize];// char[] buffer for string
        while (myFile.getline( str, 25000 )){
            bool isFirst = true;
            node* currNode;
            list<string> tokList = tokenizeData(str);
            bool isCopy;
            int copyInd;
            //code here to handle each line
            for(auto jt = tokList.begin(); jt != tokList.end(); ++jt){
                isCopy = false;
                copyInd = NULL;
               for(int k = 0; k < myGraph->now_on; k++){
                    if (isEmpty){
                        isEmpty = false;
                        goto firstExit; //yep a goto to get outof two loops
                    }
                    else if(*jt == (myGraph->adj[k].head->what)){
                        isCopy = true;
                        copyInd = k;
                    }
                }
                firstExit:
                node* tempNode;
                if (!isCopy){
                    tempNode = new node(*jt);
                    addNode(myGraph, *jt );
                
                    if (isFirst){
                        isFirst = false;
                        currNode = tempNode;
                    }
                    else{
                        addEdge(myGraph, currNode, tempNode);
                    }
                }
                else if(isCopy){
                    addEdge(myGraph, currNode, myGraph->adj[copyInd])
                }
            }
            
            memset(str, 0, sizeof(str));
        }
    }
    myFile.close(); //close file when done, because that's good coding practice
    
    
    //vector<list<Node>> adjList; // going to have to use vector push back, which is O(n)
    
    /*
    if (adjInd == -1){
        adjList.push_back(&Node(strToken));
    }
    else{
        adjList[adjInd].push_back(&Node(strToken));
    }
    */
    

return 0;
} //end main function

list<string> tokenizeData(char str[]){
    
    list<string> data;
    char * token;
    bool contCheck;
    int i;
    token = strtok(str,":,");
    while (token != NULL){ // tokenize each string
        string strToken = string(token);
        i = 0;
                
        //erase spaces and start and end of strTokens, converted to string for erase()
        contCheck = true;
        while (contCheck){
            if (strToken[0] == ' '){
                strToken.erase(0,1);
            }
                
            else if (strToken[strToken.length()-1] == ' '){
                strToken.erase(strToken.length() - 1 ,1);
            }
            else {
                contCheck = false;
            }
        }
        
        for (int i = 0; i < sizeof(strToken); i++){
            if (strToken[i] == '_'){ //find underscores
                strToken[i] = ' '; //replace with spaces
            }
        }
                
        while (strToken[i]){ // set strToken to lowercase
            strToken[i] = tolower(strToken[i]);
            i++;
        }
                
        data.push_back(strToken);
                
        cout << ("%s\n",strToken) << endl; //USE THIS TO CHECK THE TOKENS
        token = strtok (NULL, ":,");
    }
                
    return data;
}

