
#ifndef CONNECTIVITYGRAPH_HPP
#define CONNECTIVITYGRAPH_HPP

#include <vector>
#include <iostream>
#include "Human.hpp"

using namespace std;

struct PersonVertex;

/*this is the struct for each vertex in the graph. */
struct PersonVertex
{
    int id;//will be representative of there name
    vector<PersonVertex*> Edges; //stores edges to adjacent vertices
    bool visited;//boolean if it is visited
    vector<bool>MatchedList;//list to check if they have been matched before
    Human h1;//person object not sure if should be here
    vector< vector<string> > messages;//2d vector for messages
    vector<bool> messagedFirst; //vector to check who has started each conversation
};

class ConnectivityGraph
{
    public:
    ConnectivityGraph(); //constructor that does not need to do anything
    ~ConnectivityGraph();//destructor that will free all memory
    void addEdge(int v1, int v2);//this will connect one person to another
    void addVertex(string name);//will create new Person vertex -add name to names vector
    void displayEdges(); //displays who is connected to who
    int getCurrentAmtOfNames();//will return the current amt of ppl in dating app
    //void printDFT(); //depth first traversal not sure if needed
    //void printBFT(); //breadth first traversal not sure if needed
    void setAllVerticesUnvisited();//this will set all person verteces to not be visited
    string IdToName(int id); //flip the id to name
    int NameToId(string name);//flips the name to the id associated with it
    void updateInfo(int id);//updates Human opject's info
    bool swipedBack(int id_1,int id_2);//check if the person you matched with is connected back
    void Matches(int id);//prints out who is connected back to user(in this case the id that it is called with)
    bool AlreadyMatched(int userID,int comparingId);//return true if both have already matched with eachother
    bool isInGraph(string name);//return if someone is in graph

    //human functions
    bool checkLogin(string ,string ); //will check if a user has the right credentials
    void setNameHuman(string); //will find human and write there name should be implemented in the addVertex function
    void setHumanQualitites(string name,string password,int age,float height,string major,bool gender,bool sexualOrientation,int questionAnswers[10]);
    void printHumanQualities(string name);


    PersonVertex *findVertex(int id);//will find a person vertex in verteces vector

  private:
    vector<PersonVertex> vertices; //stores vertices
    vector<string>names; //stores the names of each person with corresponding id
    int currentAmtOfNames; //will count the current Amt Of Names
    void incrementMatchedList();//will increase the amount in each person's matched list



    //void BFTraversal(vertex *v);//helper BFT
    //void DFTraversal(vertex *v);//helper to DFT

};

#endif // GRAPH_HPP
