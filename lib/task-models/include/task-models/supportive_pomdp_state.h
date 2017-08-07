#include <string>
#include <map>
#include <set>
#include <iostream>
#include <typeinfo>
#include "task_htm.h"

class SupportiveState 
{
private:
    std::vector<Node*> statevector;

    int shiftbody;
    int shiftpref;
    int shifthtm;
    int finalhtm;
    int npreferences;
    int s; //number of the state

public: 

    SupportiveState() {};
    
    SupportiveState(int n_htm_states, int n_preferences, int n_body_features, int n_objects, int s = 0);

    int nObjects();

    int nBodyFeatures();

    int nPreferences();

    int nHTM();

    int HTM();

    void setHTM(int n);

    int nStates();

    bool isFinal();

    int getBit(int i );

    void setBit(int i, int b);

    int hasPreferences(int i);

    void setPreferences(int i, int pref);

    int hasBodyFeatures(int i);

    void setBodyFeatures(int i, int b);

    int to_int();

    std::vector<std::vector<double>> beliefQuotient(std::vector<double> array);

    std::vector<double> beliefPreferences(std::vector<double> array);

    //probably not needed
    //sumAllBut();

    void randomObjectChanges(int p);

    void randomPreferenceChanges(int p);

    ~SupportiveState() {};
};
