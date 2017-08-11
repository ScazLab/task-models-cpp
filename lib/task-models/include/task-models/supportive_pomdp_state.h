#include <string>
#include <map>
#include <set>
#include <iostream>
#include <typeinfo>
#include "task_htm.h"

class SupportiveState 
{
private:

    int shiftbody;
    int shiftpref;
    int shifthtm;
    int finalhtm;
    int npreferences;
    int s;

    int getBit(int i );

    void setBit(int i, int b);


public: 

    SupportiveState() {};
    
    SupportiveState(int n_htm_states, int n_preferences, int n_body_features, int n_objects, int states = 0);

    std::string suppString();
    
    int nObjects();

    int nBodyFeatures();

    int nPreferences();

    int nHTM();

    int getHTM();

    void setHTM(int n);

    bool isFinal();

    int getObject(int i );

    void setObject(int i, int b);

    int hasPreferences(int i);

    void setPreferences(int i, int pref);

    int hasBodyFeatures(int i);

    void setBodyFeatures(int i, int b);

    int toInt();

    void setInt(int state);

    std::vector<double> beliefHTM(std::vector<double> array);

    std::vector<double> beliefPreferences(std::vector<double> array);

    void randomObjectChanges(int p);

    void randomPreferenceChanges(int p);

    ~SupportiveState() {};
};
