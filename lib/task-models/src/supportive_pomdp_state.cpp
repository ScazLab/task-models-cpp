#include "task-models/supportive_pomdp_state.h"


SupportiveState::SupportiveState(int n_htm_states, int n_preferences, int n_body_features, int n_objects, int states)
{
    shiftbody    =                   n_objects;
    shiftpref    = shiftbody + n_body_features;
    shifthtm     =   shiftpref + n_preferences;
    npreferences =               n_preferences;
    finalhtm     =            n_htm_states - 1; 
    s            =                      states;
}
//Private
int SupportiveState::getBit(int i ) 
{
    return ((s >> i) % 2); 
}

void SupportiveState::setBit(int i, int b) 
{
    s += ((b << i) - (getBit(i) << i)); 
}


//Public 
std::string SupportiveState::suppString()
{    
    std::string returnstring = std::to_string(toInt()) + ": "; 
    returnstring = returnstring + std::to_string(getHTM()) + " ";

    for (int i = 0; i < (shifthtm - shiftpref); i++)
    {
        returnstring = returnstring + std::to_string(hasPreferences(i));
    }

    returnstring = returnstring + " ";

    for (int i = 0; i < (shiftpref - shiftbody); i++)
    {
        returnstring = returnstring + std::to_string(hasBodyFeatures(i));
    }

    returnstring = returnstring + " ";

    for (int i = 0; i < shiftbody; i++)
    {
        returnstring = returnstring + std::to_string(getObject(i));
    }
    
    return returnstring;
}

int SupportiveState::nObjects()     
{
    return shiftbody; 
}

int SupportiveState::nBodyFeatures() 
{
    return shiftpref - shiftbody; 
}

int SupportiveState::nPreferences() 
{ 
    return shifthtm - shiftpref; 
}

int SupportiveState::nHTM() 
{
    return finalhtm+1; 
}

int SupportiveState::getHTM()   
{ 
    return s >> shifthtm; 
}

void SupportiveState::setHTM(int n) 
{
    s += (n << shifthtm) - (getHTM() << shifthtm); 
}

bool SupportiveState::isFinal() 
{
    return (getHTM() == finalhtm); 
}

int SupportiveState::getObject(int i)
{
    return getBit(i);
}

void SupportiveState::setObject(int i, int b)
{
    setBit(i, b);
}

int SupportiveState::hasPreferences(int i) 
{
    return getBit(shiftpref+i); 
}

void SupportiveState::setPreferences(int i, int pref) 
{
    setBit(shiftpref+i, pref); 
}

int SupportiveState::hasBodyFeatures(int i) 
{
    return getBit(shiftbody + i ); 
}

void SupportiveState::setBodyFeatures(int i, int b) 
{
    setBit(shiftbody+i, b); 
}

int SupportiveState::toInt() 
{
    return s; 
}

void SupportiveState::setInt(int state)
{
    s = state;
}

std::vector<double> SupportiveState::beliefHTM(std::vector<double> array)
{   
    int n = pow(2, shifthtm);
    //throw in an assertion / exception similar to what's in the python code here 
    
    //first, reshape the array into a 2d array
    int length = array.size();
    int counter = 0;

    // in the future reshaping to a second array isn't really
    // nessecary for summing certain values
    // However for now, just like in the python code,
    // it serves as clarification in regards to what
    // is occuring

    std::vector<std::vector<double>> array2d(n, std::vector<double>(nHTM()));
    
    for (int i = 0; i < nHTM(); i++)
    {
        std::vector<double> temp;

        for (int j = 0; j < n; j++)
        {
            if (length == counter)
            {
                break;
            }

            temp.push_back(array.at(counter));
            counter++;
        }
        array2d[i] = temp;
    }

    double sum = 0;

    //sum each row of array2d, return the sums as a 1d vector 
    std::vector<double> arraysum;

    for (int i = 0; i < nHTM(); i++)
    {
        sum = 0;

        for (int j = 0; j < n; j++)
        {
            sum += array2d[i][j];
        }
        
        arraysum.push_back(sum);
    }
    return arraysum; 
}

std::vector<double> SupportiveState::beliefPreferences(std::vector<double> array)
{
    int length = array.size();  
    int n_htm = nHTM();
    int segment = length / (n_htm*2);

    double preference1 = 0;
    double preference2 = 0; 

    //debugging
  //  std::cout << "length: " << length << std::endl;
  //  std::cout << "n_htm: " << n_htm << std::endl;
  //  std::cout << "segment: " << segment << std::endl;
    //

    for (int i = 0; i < n_htm; i++)
    {
        int interval = i*2*segment;
        int interval2 = interval + segment;
        
        for (int j = interval; j < (interval+segment); j++)
        {
            preference1 += array.at(j); //originally just "=" not "+="
            //debugging
            //std::cout << "Value of array at " << j << " is " << array.at(j) << std::endl;
            //std::cout << "preference 1 at (i, j) " << i << " " << j << " is " << preference1 << std::endl;
            //
        }

        for (int k = interval2; k < (interval2 + segment); k++)
        {
            preference2 += array.at(k);
            //debugging
            //std::cout << "Value of array at " << k << " is " << array.at(k) << std::endl;
            //std::cout << "preference 2 at (i, k) " << i << " " << k << " is " <<preference2 << std::endl;
            //
        }
    
    }

    std::vector<double> preferencearray;

    preferencearray.push_back(preference1);
    preferencearray.push_back(preference2);

    // debugging
    std::cout << "The value of pref1 : pref2 " << preference1 << " " << preference2 << std::endl;
    // 
    return preferencearray;
}

void SupportiveState::randomObjectChanges(int p)
{
    for (int i = 0; i < nObjects(); i++)
    {
        if ((double) rand() / RAND_MAX < p)
        {
            setObject(i, 1 - getObject(i));
        }
    }
}

void SupportiveState::randomPreferenceChanges(int p)
{
    for (int i = 0; i < nPreferences(); i++)
    {
        if ((double) rand() / RAND_MAX < p)
        {
            setPreferences(i, 1 - hasPreferences(i));
        }
    }
}
