#include "task-models/supportive_pomdp_state.h"


SupportiveState::SupportiveState(int n_htm_states, int n_preferences, int n_body_features, int n_objects, int s)
{
    shiftbody    =                   n_objects;
    shiftpref    = shiftbody + n_body_features;
    shifthtm     =   shiftpref + n_preferences;
    npreferences =               n_preferences;
    finalhtm     =            n_htm_states - 1;  
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

int SupportiveState::HTM()   
{ 
    return s >> shifthtm; 
}

void SupportiveState::setHTM(int n) 
{
    s += (n << shifthtm) - (HTM() << shifthtm); 
}

int SupportiveState::nStates() 
{
    return (finalhtm+1)*pow(2,shifthtm); 
}

bool SupportiveState::isFinal() 
{
    return (HTM() == finalhtm); 
}

int SupportiveState::getBit(int i ) 
{
    return ((s >> i)%2); 
}

void SupportiveState::setBit(int i, int b) 
{
    s += ((b << i) - (getBit(i) << i)); 
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

int SupportiveState::to_int() 
{
    return s; 
}

//ok so this accepting a 1d doubles array; what's being returned here is an 
//array of summations
//this array contains the sums of each row of the reshaped array
//returns a pointer to a double array

std::vector<std::vector<double>> SupportiveState::beliefQuotient(std::vector<double> array)
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
    //double array2d [nHTM()][n];

    std::vector<std::vector<double>> array2d(n, std::vector<double>(nHTM()));
    
    for (int i = 0; i < nHTM(); i++)
    {
        std::vector<double> temp;

        for (int j = 0; j < n; j++)
        {
            if (counter == length)
            {
                break;
            }

            temp.push_back(array.at(counter));
            counter++;
        }
        array2d[i] = temp;
    }

    //sum each row of array2d, return the sums as a 2d array 
    std::vector<std::vector<double>> arraysum(1, std::vector<double>(nHTM()));

    for (int i = 0; i < nHTM(); i++)
    {
        int sum;

        for (int j = 0; j < n; j++)
        {
            sum += array2d[i][j];
        }
        
        arraysum[i][1] = sum;
    }

    return arraysum; 
}

// for this function do not reshape the arrays
// like you did in the previous function. Create an
// algorithm to go through the passed array to extract the
// values you need 
// refer to the whiteboard/photos you took in order to implement this
std::vector<double> SupportiveState::beliefPreferences(std::vector<double> array)
{
    // include some assertion here; just like in the python code
    
    int length = array.size();
    int n_htm = nHTM();
    int segment = length / (n_htm*2);

    int preference1 = 0;
    int preference2 = 0; 


    for (int i = 0; i < n_htm; i++)
    {
        int interval = i*2*segment;
        int interval2 = interval + segment;
        
        for (int j = interval; j < (interval+segment); j++)
        {
            preference1 = array[j];
        }

        for (int k = interval2; k < (interval + segment); k++)
        {
            preference2 = array[k];
        }
    
    }

    std::vector<double> preferencearray;

    preferencearray.push_back(preference1);
    preferencearray.push_back(preference2);

    return preferencearray;
}

void SupportiveState::randomObjectChanges(int p)
{
    std::vector<double> to_change;

    //to_change = np.random.random((self.n_objects)) < p
    //this line in python creates a vector of n elements
    //each element is less than p

    for (int i = 0; i < shiftbody; i++)
    {
        double randomvalue = (double) rand()/RAND_MAX; //generates random value between 0 and 1 

        if (randomvalue < p)
        {
            to_change.push_back(randomvalue); //if less than p, put it in the vector

            if (randomvalue == 0)
            {
                setBit(i, 1 - getBit(i));
            }
        }
        else
        {
            i--; //if greater than p, we need to try again and get a new random value
                 //so we deincrement (this is nessecary to get a vector n_objects long)
        }
    }

}

void SupportiveState::randomPreferenceChanges(int p)
{
    std::vector<double> to_change;

    for (int i = 0; i < npreferences; i++)
    {
        double randomvalue = (double) rand()/RAND_MAX;

        if (randomvalue < p)
        {
            to_change.push_back(randomvalue);

            if (randomvalue == 0)
            {
                setPreferences(i, 1 - hasPreferences(i));
            }
        }
        else
        {
            i--;
        }
    }
}
